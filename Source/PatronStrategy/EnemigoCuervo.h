// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoCuervo.generated.h"

/**
 * 
 */
UCLASS()
class PATRONSTRATEGY_API AEnemigoCuervo : public AEnemigo
{
	GENERATED_BODY()
public:
	AEnemigoCuervo();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;

	void AlterarManiobras(AActor* MiEstrategiaBatalla) override;
	virtual void Ensamblar() override;
	
};
