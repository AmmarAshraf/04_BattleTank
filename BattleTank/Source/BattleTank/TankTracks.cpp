// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"


void UTankTracks::setThrottle(float value) {

	if (value == 0)
		return;

	auto forceVector = GetForwardVector()*value*TracksMaxDrivingForce;

	auto ComponentLocation = GetComponentLocation();

	Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent())->AddForceAtLocation(forceVector, ComponentLocation);

	//UE_LOG(LogTemp, Warning, TEXT("Component:%s \t force %s"), *GetName(),*forceVector.ToString())
}