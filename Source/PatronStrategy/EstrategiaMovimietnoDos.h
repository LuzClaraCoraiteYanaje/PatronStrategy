// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estrategias.h"
#include "EstrategiaMovimietnoDos.generated.h"

UCLASS()
class PATRONSTRATEGY_API AEstrategiaMovimietnoDos : public AActor , public  IEstrategias
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstrategiaMovimietnoDos();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Maniobra(float DeltaTime, AActor* Enemigo) override;
};
