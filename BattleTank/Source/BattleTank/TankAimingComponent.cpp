// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "Tank.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	LoadStates = ELoadStates::VE_RELOAD;
	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	//we are doing this so first fire will be after reload
	lastTime = FPlatformTime::Seconds();
	
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//if (GetFireCount() == 0) {
	//	LoadStates = ELoadStates::VE_OUT_OF_AMMO;
	//}
	//else if ((FPlatformTime::Seconds() - lastTime) < fireDelay) {
	//	LoadStates = ELoadStates::VE_RELOAD;
	//}
	//else if (isBarrelMoving()) {
	//	LoadStates = ELoadStates::VE_AIMING;
	//}
	//else {		
	//	LoadStates = ELoadStates::VE_LOCKED;
	//}

	//UE_LOG(LogTemp, Warning, TEXT("delay %f"), (FPlatformTime::Seconds() - lastTime))
	
}


void UTankAimingComponent::AimAt(FHitResult hitVector)
{
	/*if (barrel==nullptr) { return; }

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

		AimDirection = outTossVelocity.GetSafeNormal();
		auto OwnerName = GetOwner()->GetName();

		moveBarrel(AimDirection);
	
	}*/
	
	
}

void UTankAimingComponent::AIAimAt(FVector PlayerLocation)
{

	//if (barrel == nullptr) { return; }

	//FVector location = barrel->GetSocketLocation(FName("LaunchPoint"));
	//FVector outTossVelocity = FVector(0);

	//bool ret = UGameplayStatics::SuggestProjectileVelocity(
	//	GetWorld(),
	//	outTossVelocity,
	//	location,
	//	PlayerLocation,
	//	launchSpeed,
	//	false, 0, 0,
	//	ESuggestProjVelocityTraceOption::DoNotTrace
	//);

	//if (ret) {

	//	AimDirection = outTossVelocity.GetSafeNormal();
	//	auto OwnerName = GetOwner()->GetName();

	//	moveBarrel(AimDirection);

	//}
	
}

void UTankAimingComponent::moveBarrel(FVector aimTarget) {

	//if (barrel == nullptr&&turret==nullptr) { return; }

	//auto RotationDifference =  aimTarget.Rotation()- barrel->GetForwardVector().Rotation();
	//barrel->elevate(RotationDifference.Pitch);
	////Always aim shortest way
	//if (RotationDifference.Yaw < 180) {
	//	turret->moveTurret(RotationDifference.Yaw);
	//}
	//else {
	//	turret->moveTurret(-RotationDifference.Yaw);
	//}
}

void UTankAimingComponent::intitialize(UTankBarrel* tankBarrelToSetup, UTankTurret* tankTurretToSetup) {
	barrel = tankBarrelToSetup;
	turret = tankTurretToSetup;
}

void UTankAimingComponent::Fire() {
	

	if (LoadStates!= ELoadStates::VE_RELOAD&& fireCount>0) {

	/*	if (barrel == nullptr) { return; }

		if (projectile == nullptr) { return; }


		LoadStates = ELoadStates::VE_RELOAD;
		
		auto socket = barrel->GetSocketByName(FName("LaunchPoint"));
		auto location = barrel->GetSocketLocation(FName("LaunchPoint"));
		auto rotation = barrel->GetSocketRotation(FName("LaunchPoint"));

		auto spawnedProjectile = GetWorld()->SpawnActor<AProjectile>(projectile, location, rotation, FActorSpawnParameters());
		spawnedProjectile->LaunchProjectile(launchSpeed);
		fireCount = fireCount - 1;		
		lastTime = FPlatformTime::Seconds();*/
	}

	

}


bool UTankAimingComponent::isBarrelMoving() {

	if (!ensure(barrel)) {
		return false;
	}
	else {
		auto forwardVector = barrel->GetForwardVector();
		return forwardVector.Equals(AimDirection, 0.01);
	}

}

ELoadStates UTankAimingComponent::GetTankState() {
	return LoadStates;
}


float UTankAimingComponent::GetFireCount() {
	return fireCount;
}