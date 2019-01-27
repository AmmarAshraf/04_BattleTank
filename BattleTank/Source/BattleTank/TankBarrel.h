// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories= ("collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public :
	void elevate(float ElevatePerSeconds);

	UPROPERTY(EditAnyWhere, Category=Setup)
	float barrelDegrees;

	UPROPERTY(EditAnyWhere, Category = Setup)
	float maxElevation;

	UPROPERTY(EditAnyWhere, Category = Setup)
	float minElevation;


};
