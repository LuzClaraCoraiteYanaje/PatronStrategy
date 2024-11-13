// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PatronStrategyGameMode.generated.h"

UCLASS(minimalapi)
class APatronStrategyGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APatronStrategyGameMode();

protected:
	virtual void BeginPlay() override;
public:

		virtual void Tick(float DeltaTime) override;
};



