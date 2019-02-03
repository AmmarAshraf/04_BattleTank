// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
class ATank;
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	ATank* GetTankComponent() const;
	virtual void BeginPlay() override;
	//starting moving barrel to shot would hit where crosshair intersect world
	void AimingTowardsCrosshair();
	
	bool GetSightRayHitLocation(FHitResult hitresult);

public:
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation=0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation=0.33;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	bool GetCameraDirection(FVector CrossHairScreenLocation, FVector &CameraDirection);

	bool GetVectorHitLocation(FVector LookDirection, FHitResult hitresult);
};
