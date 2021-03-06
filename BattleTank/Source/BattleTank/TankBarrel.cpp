// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::elevate(float relativeSpeed) {

	relativeSpeed=FMath::Clamp<float>(relativeSpeed, -1, 1);

	float delta= relativeSpeed* barrelDegrees* GetWorld()->DeltaTimeSeconds;

	auto rawElevation= RelativeRotation.Pitch+delta;

	auto elevation = FMath::Clamp<float>(rawElevation, minElevation, maxElevation);

	SetRelativeRotation(FRotator(elevation,0,0));

}
