// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
class ATank;
class UTankAimingComponent;
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:

	virtual void BeginPlay() override;
	//starting moving barrel to shot would hit where crosshair intersect world
	void AimingTowardsCrosshair();
	
	bool GetSightRayHitLocation(FHitResult hitresult);

public:
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation=0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation=0.5;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 100000;

	bool GetCameraDirection(FVector2D CrossHairScreenLocation, FVector &CameraDirection);

	bool GetVectorHitLocation(FVector LookDirection, FHitResult hitresult);

	
	void OnTankDeath();

	
	virtual void SetPawn(APawn* InPawn) override;

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void NotifyAinmingComponentCreated(UTankAimingComponent* utank);

};
