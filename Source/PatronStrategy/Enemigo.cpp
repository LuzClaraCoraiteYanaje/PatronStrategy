// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AEnemigo::AEnemigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaEnemigo"));
	RootComponent = MeshEnemigo;

	SetActorScale3D(FVector(1.0f, 0.2f, 1.0f));
}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (EstrategiaMovimiento)
	{
		EstrategiaMovimiento->Maniobra(DeltaTime, this);
	}
}

void AEnemigo::AlterarManiobras(AActor* MiEstrategiaBatalla)
{
	EstrategiaMovimiento = Cast<IEstrategias>(MiEstrategiaBatalla);
		if (!EstrategiaMovimiento)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red,
				FString::Printf(TEXT("Cast no Valido en ABattleShipHijo! Consulta el registro de salida para más detalles")));
			UE_LOG(LogTemp, Error,
				TEXT("ABattleShipHijo::AlterarManiobras(): ¡El Actor no es una BattleShipStrategy! ¿Estás seguro de que el Actor implementa esa interfaz?"));
		}
		else
		{
			// Aquí puedes agregar lógica adicional si el casteo es exitoso en la clase hija
			UE_LOG(LogTemp, Log, TEXT("Casteo exitoso en ABattleShipHijo, estrategia asignada correctamente."));
		}
}

void AEnemigo::Ensamblar()
{
	if (!EstrategiaMovimiento) {
		UE_LOG(LogTemp, Error, TEXT("Engage():BattleStrategy is NULL, make sure it's initialized.")); return;
	}
	//Execute the current Strategy Maneuver
	EstrategiaMovimiento->Maniobra(0.0f, this);
}

void AEnemigo::DejarBomba()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Emerald,
		FString::Printf(TEXT("se esta dejando la bomba")));

}

