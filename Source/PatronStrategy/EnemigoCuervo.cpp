// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoCuervo.h"


AEnemigoCuervo::AEnemigoCuervo()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> Malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
    if (Malla.Succeeded())
    {
        MeshEnemigo->SetStaticMesh(Malla.Object);
    }
}

void AEnemigoCuervo::BeginPlay()
{
    Super::BeginPlay();
}

void AEnemigoCuervo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AEnemigoCuervo::AlterarManiobras(AActor* MiEstrategiaBatalla)
{
    Super::AlterarManiobras(MiEstrategiaBatalla);
}

void AEnemigoCuervo::Ensamblar()
{
    Super::Ensamblar();
}
