// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::elevate(float elevation) {

	float delta=GetWorld()->GetTimeSeconds();

	UE_LOG(LogTemp, Warning, TEXT("Elevation %f"), delta)

}
