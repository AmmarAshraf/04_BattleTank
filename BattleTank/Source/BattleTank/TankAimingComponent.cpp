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

	UE_LOG(LogTemp, Warning, TEXT(" Hit Compnenet %s Name %s"), *hitVector.Location.ToString(), *hitName)

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

		//UE_LOG(LogTemp, Warning, TEXT("Toss Velocty %s Hit Compnenet %s Name %s"), *outTossVelocity.ToString(),*UnitVector.ToString(),*hitName)

		moveBarrel(UnitVector);
	
	}
	
	
}

void UTankAimingComponent::AIAimAt(FVector PlayerLocation)
{

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

void UTankAimingComponent::setAimingBarrelComponenet(UTankBarrel * barrelToSetup, float launchSpeedToSetup)
{
	barrel = barrelToSetup;
	launchSpeed = launchSpeedToSetup;
}

void UTankAimingComponent::setAimingTurretComponenet(UTankTurret * turretToSetup)
{
	turret = turretToSetup;
}

void UTankAimingComponent::moveBarrel(FVector aimTarget) {

	auto RotationDifference =  aimTarget.Rotation()- barrel->GetForwardVector().Rotation();
	barrel->elevate(RotationDifference.Pitch);
	turret->moveTurret(RotationDifference.Yaw);

}