// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIMovment.h"
#include "TankTracks.h"

void UTankAIMovment::IntentMovment(float data) {

	if (leftTankTrack == nullptr && rightTankTrack == nullptr || data == 0) {
		return;
	}

	leftTankTrack->setThrottle(data);
	rightTankTrack->setThrottle(data);
	//UE_LOG(LogTemp, Warning, TEXT("%s forward: %f"), *GetOwner()->GetName(), data)
}

void UTankAIMovment::IntentTurnRight(float data)
{
	if (leftTankTrack == nullptr && rightTankTrack == nullptr || data == 0) {
		return;
	}

	leftTankTrack->setThrottle(-data);
	rightTankTrack->setThrottle(data);
	//UE_LOG(LogTemp, Warning, TEXT("%s Right: %f"),*GetOwner()->GetName(), data)
}

void UTankAIMovment::IntentTurnLeft(float data)
{
	if(leftTankTrack==nullptr&&rightTankTrack==nullptr || data == 0) {
		return;
	}

	leftTankTrack->setThrottle(data);
	rightTankTrack->setThrottle(-data);
	//UE_LOG(LogTemp, Warning, TEXT("%s Left: %f"), *GetOwner()->GetName(), data)
}

void UTankAIMovment::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed){

	UE_LOG(LogTemp, Warning, TEXT("Request to direct move called"))
	auto mineVector=GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIVector = MoveVelocity.GetSafeNormal();

	auto result= FVector::DotProduct(mineVector, AIVector);

	IntentMovment(result);

	auto crossProduct=FVector::CrossProduct(mineVector, AIVector);

	//if (crossProduct.GetSafeNormal().Z > 0) {
		IntentTurnRight(crossProduct.GetSafeNormal().Z);
	
	auto Owner = GetOwner()->GetName();

	UE_LOG(LogTemp, Warning, TEXT("%s owner:Veclocity %s"), *Owner, *MoveVelocity.ToString())

}

void UTankAIMovment::intitialize(UTankTracks* left, UTankTracks* right) {
	leftTankTrack = left;
	rightTankTrack = right;
}

void UTankAIMovment::DragRight(float data) {
	if (rightTankTrack == nullptr || data == 0) {
		return;
	}

	rightTankTrack->setThrottle(data);
	UE_LOG(LogTemp, Warning, TEXT("%s Right Drag: %f"), *GetOwner()->GetName(), data)
}

void UTankAIMovment::DragLeft(float data) {
	if (leftTankTrack == nullptr || data == 0) {
		return;
	}

	leftTankTrack->setThrottle(data);
	UE_LOG(LogTemp, Warning, TEXT("%s Left Drag: %f"), *GetOwner()->GetName(), data)
}

