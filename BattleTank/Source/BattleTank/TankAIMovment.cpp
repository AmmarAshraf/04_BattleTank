// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIMovment.h"
#include "TankTracks.h"

void UTankAIMovment::IntentMovment(float data) {

	//UE_LOG(LogTemp, Warning, TEXT("Intent movment"))
	leftTankTrack->setThrottle(data);
	rightTankTrack->setThrottle(data);

}

void UTankAIMovment::IntentTurnRight(float data)
{
	leftTankTrack->setThrottle(-data);
	rightTankTrack->setThrottle(data);
}

void UTankAIMovment::IntentTurnLeft(float data)
{
	leftTankTrack->setThrottle(data);
	rightTankTrack->setThrottle(-data);
}

void UTankAIMovment::intitialize(UTankTracks* leftTankTrackToSetup, UTankTracks* rightTankTrackToSetup) {
	leftTankTrack = leftTankTrackToSetup;
	rightTankTrack = rightTankTrackToSetup;
}

