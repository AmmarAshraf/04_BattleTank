// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankAIMovment.generated.h"

/**
 * 
 */
class UTankTracks;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankAIMovment : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	void intitialize(UTankTracks* leftTankTrackToSetup,UTankTracks* rightTankTrackToSetup);

	UFUNCTION(BlueprintCallable)
	void IntentMovment(float data);

	UFUNCTION(BlueprintCallable)
		void IntentTurnRight(float data);

	UFUNCTION(BlueprintCallable)
		void IntentTurnLeft(float data);

	UFUNCTION(BlueprintCallable)
		void DragRight(float data);

	UFUNCTION(BlueprintCallable)
		void DragLeft(float data);

private:
	UTankTracks* leftTankTrack;
	UTankTracks* rightTankTrack;
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

};
