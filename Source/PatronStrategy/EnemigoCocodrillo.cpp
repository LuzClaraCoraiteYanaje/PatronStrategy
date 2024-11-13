// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoCocodrillo.h"

AEnemigoCocodrillo::AEnemigoCocodrillo()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> Malla(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube_Chamfer.1M_Cube_Chamfer'"));
    if (Malla.Succeeded())
    {
        MeshEnemigo->SetStaticMesh(Malla.Object);
    }
}

void AEnemigoCocodrillo::BeginPlay()
{
    Super::BeginPlay();
}

void AEnemigoCocodrillo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AEnemigoCocodrillo::AlterarManiobras(AActor* MiEstrategiaBatalla)
{
    Super::AlterarManiobras(MiEstrategiaBatalla);
}

void AEnemigoCocodrillo::Ensamblar()
{
    Super::Ensamblar();
}
