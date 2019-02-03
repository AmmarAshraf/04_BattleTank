// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public :
	void elevate(float ElevatePerSeconds);

	UPROPERTY(EditDefaultsOnly, Category=Setup)
	float barrelDegrees=1;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float maxElevation=40;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float minElevation=20;


};
