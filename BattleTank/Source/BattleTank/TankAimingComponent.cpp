// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Tank.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	LoadStates = ELoadStates::VE_LOCKED;
	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UTankAimingComponent::AimAt(FHitResult hitVector)
{
	if (barrel==nullptr) { return; }

	auto hitName = hitVector.GetActor() != nullptr ? hitVector.GetActor()->GetName() : "";

	FVector location=barrel->GetSocketLocation(FName("LaunchPoint"));
	FVector outTossVelocity=FVector(0);
	
	bool ret= UGameplayStatics::SuggestProjectileVelocity(
		this,
		outTossVelocity,
		location,
		hitVector.Location,
		launchSpeed,
		false, 0, 0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (ret) {

		auto UnitVector = outTossVelocity.GetSafeNormal();
		auto OwnerName = GetOwner()->GetName();

		auto hitName = hitVector.GetActor() != nullptr ? hitVector.GetActor()->GetName() : "";

		moveBarrel(UnitVector);
	
	}
	
	
}

void UTankAimingComponent::AIAimAt(FVector PlayerLocation)
{

	if (barrel == nullptr) { return; }

	FVector location = barrel->GetSocketLocation(FName("LaunchPoint"));
	FVector outTossVelocity = FVector(0);

	bool ret = UGameplayStatics::SuggestProjectileVelocity(
		GetWorld(),
		outTossVelocity,
		location,
		PlayerLocation,
		launchSpeed,
		false, 0, 0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (ret) {

		auto UnitVector = outTossVelocity.GetSafeNormal();
		auto OwnerName = GetOwner()->GetName();

		//moveBarrel(UnitVector);

	}
	
}

void UTankAimingComponent::moveBarrel(FVector aimTarget) {

	if (barrel == nullptr&&turret==nullptr) { return; }

	auto RotationDifference =  aimTarget.Rotation()- barrel->GetForwardVector().Rotation();
	barrel->elevate(RotationDifference.Pitch);
	turret->moveTurret(RotationDifference.Yaw);

}

void UTankAimingComponent::intitialize(UTankBarrel* tankBarrelToSetup, UTankTurret* tankTurretToSetup) {
	barrel = tankBarrelToSetup;
	turret = tankTurretToSetup;
}
