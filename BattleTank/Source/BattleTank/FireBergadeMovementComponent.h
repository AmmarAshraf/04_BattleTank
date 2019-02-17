// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "FireBergadeMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API UFireBergadeMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

	private:
	// Called when the game starts
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	
};
