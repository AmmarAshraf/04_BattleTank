// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "SpawnPoint.h"
#include "TankTracks.generated.h"

/**
 * 
 */

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()

public :

		UFUNCTION(BlueprintCallable, Category = Setup)
		void setThrottle(float value);
	
		UPROPERTY(EditAnyWhere, Category = Setup)
			//40000 is weight where 10 is acceration or 1g
			float TracksMaxDrivingForce=40000*10;
private :
	UTankTracks();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void BeginPlay() override;
	void DriveTrack(float CurrentThrottle);
	TArray<USceneComponent*> GetWheels();

};
