// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DrawDebugHelpers.h"
#include "Engine.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAimingComponent* utankAimingCompnent;
	
public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UTankAimingComponent* GetAimingComponent();
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void setAimingBarrelComponenet(UTankBarrel* barrelToSetup);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void setAimingTurretComponenet(UTankTurret* turretSetup);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void Fire();

	UPROPERTY(BlueprintReadOnly)
		float launchSpeed = 100000; //km/s 

	UPROPERTY(EditAnyWhere, Category = Setup)
		TSubclassOf<AProjectile> projectile;
private:
	UTankBarrel* barrel;

};
