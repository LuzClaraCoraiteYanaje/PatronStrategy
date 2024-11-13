// Copyright Epic Games, Inc. All Rights Reserved.

#include "PatronStrategyGameMode.h"
#include "PatronStrategyCharacter.h"
#include "UObject/ConstructorHelpers.h"

#include "EnemigoCocodrillo.h"
#include "EnemigoCuervo.h"
#include "EnemigoLeon.h"

#include "EstrategiaMovimientoUno.h"
#include "EstrategiaMovimientoTres.h"
#include "EstrategiaMovimietnoDos.h"

APatronStrategyGameMode::APatronStrategyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void APatronStrategyGameMode::BeginPlay()
{
	Super::BeginPlay();
	FVector BattleShipPosition(1190.0f, -70.0f, 150.0f);  // Cambia estos valores a la posición deseada
	FRotator BattleShipRotation(0.0f, 90.0f, 0.0f);      // Cambia estos valores a la rotación deseada

	// Crea y posiciona el BattleShip
	//PARA LA CLASE HIJA 3 -----------------------------
	AEnemigoCocodrillo* cocodrillo = GetWorld()->SpawnActor<AEnemigoCocodrillo>(AEnemigoCocodrillo::StaticClass(), BattleShipPosition, BattleShipRotation);

	AEstrategiaMovimientoUno* fuerzaBruta = GetWorld()->SpawnActor<AEstrategiaMovimientoUno>(AEstrategiaMovimientoUno::StaticClass());
	if (cocodrillo && fuerzaBruta)
	{
		cocodrillo->AlterarManiobras(fuerzaBruta);
		cocodrillo->Ensamblar();
	}

	// PARA LA CLASE HIJA      2 --------------------------
	FVector BattleShipDosPosition(1190.0f, -1370.0f, 410.0f);  // Cambia estos valores a la posición deseada
	FRotator BattleShipDosRotation(0.0f, 90.0f, 0.0f);
	AEnemigoCuervo* cuervo = GetWorld()->SpawnActor<AEnemigoCuervo>(AEnemigoCuervo::StaticClass(), BattleShipDosPosition, BattleShipDosRotation);
	AEstrategiaMovimietnoDos* correr = GetWorld()->SpawnActor<AEstrategiaMovimietnoDos>(AEstrategiaMovimietnoDos::StaticClass());

	if (cuervo && correr)
	{
		cuervo->AlterarManiobras(correr);
		cuervo->Ensamblar();
	}
	// PARA LA CLASE HIJA TRES 3 -----------------------------
	FVector BattleShipTresPosition(1190.0f, -181.0f, 710.0f);  // Cambia estos valores a la posición deseada
	FRotator BattleShipTresRotation(0.0f, 90.0f, 0.0f);
	AEnemigoLeon* Leon = GetWorld()->SpawnActor<AEnemigoLeon>(AEnemigoLeon::StaticClass(), BattleShipTresPosition, BattleShipTresRotation);
	AEstrategiaMovimientoTres* rapido = GetWorld()->SpawnActor<AEstrategiaMovimientoTres>(AEstrategiaMovimientoTres::StaticClass());

	if (rapido && Leon)
	{
		Leon->AlterarManiobras(rapido);
		Leon->Ensamblar();
	}

}

void APatronStrategyGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
