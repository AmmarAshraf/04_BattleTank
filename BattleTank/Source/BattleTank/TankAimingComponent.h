// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Components/ActorComponent.h"

#include "TankAimingComponent.generated.h"

class UTankBarrel;
//Hold barrel properties and elevate methods
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void AimAt(FVector hitVector);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void setAimingBarrelComponenet(UTankBarrel* barrelToSetup, float launchSpeed);
	void moveBarrel(FVector aimTarget);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UTankBarrel * barrel=nullptr;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditAnyWhere)
	float launchSpeed=20000;
		
};
