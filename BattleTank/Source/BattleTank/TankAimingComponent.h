// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Components/ActorComponent.h"
#include "Projectile.h"
#include "TankAimingComponent.generated.h"


UENUM(BlueprintType)
enum class ELoadStates : uint8 {
	VE_RELOAD UMETA(DisplayName = "Reload"),

	VE_AIMING UMETA(DisplayName = "Aiming"),

	VE_LOCKED UMETA(DisplayName = "Locked")
};

class UTankBarrel;
class UTankTurret;
class AProjectile;
//Hold barrel properties and elevate methods
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable)
	void intitialize(UTankBarrel* tankBarrelToSetup, UTankTurret* tankTurretToSetup);
	// Sets default values for this component's properties
	UTankAimingComponent();
	void AimAt(FHitResult hitVector);

	void AIAimAt(FVector vector);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void moveBarrel(FVector aimTarget);
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float launchSpeed = 4000; //km/s 

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> projectile;


	UFUNCTION(BlueprintCallable, Category = Setup)
		void Fire();


	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float fireDelay = 3;

	UFUNCTION(BlueprintCallable, Category = Setup)
		ELoadStates GetTankState();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UTankBarrel * barrel=nullptr;
	UTankTurret * turret = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
		ELoadStates LoadStates;

	bool isBarrelReloaded;
	double lastTime;
	bool isBarrelMoving();
	FVector AimDirection;

};
