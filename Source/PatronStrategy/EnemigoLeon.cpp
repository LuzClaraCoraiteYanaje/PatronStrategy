// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoLeon.h"

AEnemigoLeon::AEnemigoLeon()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> Malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
    if (Malla.Succeeded())
    {
        MeshEnemigo->SetStaticMesh(Malla.Object);
    }
}

void AEnemigoLeon::BeginPlay()
{
    Super::BeginPlay();
}

void AEnemigoLeon::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AEnemigoLeon::AlterarManiobras(AActor* MiEstrategiaBatalla)
{
    Super::AlterarManiobras(MiEstrategiaBatalla);  
}

void AEnemigoLeon::Ensamblar()
{
    Super::Ensamblar();
}

void AEnemigoLeon::DejarBomba()
{
}
