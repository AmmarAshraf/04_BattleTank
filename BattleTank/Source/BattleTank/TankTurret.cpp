// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

// Sets default values for this component's properties
UTankTurret::UTankTurret()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankTurret::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankTurret::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankTurret::moveTurret(float relativeSpeed) {

	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1, 1);

	float delta = relativeSpeed*barrelDegrees* GetWorld()->GetTimeSeconds();

	auto rawRotation = RelativeRotation.Yaw + delta;

	auto elevation = FMath::Clamp<float>(rawRotation, 0, 360);

	SetRelativeRotation(FRotator(0, elevation, 0));

    //UE_LOG(LogTemp, Warning, TEXT("%s owner:Rotation %f"), *GetOwner()->GetName(), elevation)
}

