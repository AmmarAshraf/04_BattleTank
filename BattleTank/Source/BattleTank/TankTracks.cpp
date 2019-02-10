// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"


void UTankTracks::setThrottle(float value) {

	auto forceVector = GetForwardVector()*value*TracksMaxDrivingForce;

	auto ComponentLocation = GetComponentLocation();

	Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent())->AddForceAtLocation(forceVector, ComponentLocation);

}