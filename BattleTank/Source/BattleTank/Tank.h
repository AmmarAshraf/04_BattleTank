// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DrawDebugHelpers.h"
#include "Engine.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankTracks;
class AProjectile;
class UTankAIMovment;

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

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = Setup)
		void Fire();

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float launchSpeed = 4000; //km/s 

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> projectile;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float fireDelay =3;


private:
	UTankBarrel* barrel;

	bool isBarrelReloaded;
	double lastTime;
	
};
