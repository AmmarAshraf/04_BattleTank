// Fill out your copyright notice in the Description page of Project Settings.

#include "FireBergade.h"

// Sets default values
AFireBergade::AFireBergade()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFireBergade::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFireBergade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFireBergade::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

