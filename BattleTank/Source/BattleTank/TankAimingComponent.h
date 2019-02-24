// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM(BlueprintType)
enum class ELoadStates : uint8 {
	VE_RELOAD UMETA(DisplayName = "Reload"),

	VE_AIMING UMETA(DisplayName = "Aiming"),

	VE_LOCKED UMETA(DisplayName = "Locked")
};

class UTankBarrel;
class UTankTurret;
//Hold barrel properties and elevate methods
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void AimAt(FHitResult hitVector);

	void AIAimAt(FVector vector);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void setAimingBarrelComponenet(UTankBarrel* barrelToSetup, float launchSpeed);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void setAimingTurretComponenet(UTankTurret* turret);

	void moveBarrel(FVector aimTarget);
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditAnyWhere)
		float launchSpeed = 10;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UTankBarrel * barrel=nullptr;
	UTankTurret * turret = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
		ELoadStates LoadStates;

};
