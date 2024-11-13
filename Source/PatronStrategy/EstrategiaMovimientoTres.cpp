// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaMovimientoTres.h"
#include "PatronStrategyCharacter.h"

#include "Enemigo.h"
#include "Kismet/GameplayStatics.h"
#include "EnemigoLeon.h"

// Sets default values
AEstrategiaMovimientoTres::AEstrategiaMovimientoTres()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Velocidad = 500.0f;
	DistanciaObjetivo = 1500.0f; // Distancia de alejamiento tras dejar la bomba
	ColocoBomba = false;

}

// Called when the game starts or when spawned
void AEstrategiaMovimientoTres::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaMovimientoTres::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AActor* Enemigo = GetOwner();
	if (Enemigo)
	{
		Maniobra(DeltaTime,Enemigo);
	}
}

void AEstrategiaMovimientoTres::Maniobra(float DeltaTime, AActor* Enemigo)
{
	/*GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Emerald,
		FString::Printf(TEXT("A toda Velocidad somos muy rapidos")));*/



    APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (!Player) return;

    // Calcular la distancia entre el BattleShip y el jugador
    float Distancia = FVector::Dist(Player->GetActorLocation(), Enemigo->GetActorLocation());

    // Calcular la dirección hacia el jugador
    FVector Direccion = Player->GetActorLocation() - Enemigo->GetActorLocation();
    Direccion.Normalize();

    if (!ColocoBomba)
    {
        // Si está cerca del jugador (menos de 100 unidades), colocar la bomba
        if (Distancia < 100.0f)
        {
            DetectarJugadorYAtacar(Enemigo);
        }
        else
        {
            // Moverse hacia el jugador si aún no está a distancia para dejar la bomba
            FVector NuevaPosicion = Enemigo->GetActorLocation() + Direccion * Velocidad * DeltaTime;
            Enemigo->SetActorLocation(NuevaPosicion);
        }
    }
    else
    {
        // Si la bomba ya fue colocada, alejarse hasta estar a 800 unidades del jugador
        FVector DireccionOpuesta = -Direccion;
        FVector NuevaPosicion = Enemigo->GetActorLocation() + DireccionOpuesta * Velocidad * DeltaTime;
        Enemigo->SetActorLocation(NuevaPosicion);

        // Comprobar si ya está a 800 unidades o más del jugador
        if (Distancia >= DistanciaObjetivo)
        {
            ColocoBomba = false; // Resetear para permitir acercarse de nuevo
        }
    }
}

void AEstrategiaMovimientoTres::DetectarJugadorYAtacar(AActor* Enemigo)
{
	AEnemigo* Enemigos = Cast<AEnemigo>(Enemigo);
	if (Enemigos)
	{
		// Llamar a la función DejarBomba y mostrar el mensaje en pantalla
		Enemigos->DejarBomba();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Se dejó la bomba"));

		// Marcar que la bomba ya fue colocada
		ColocoBomba = true;
	}
}

