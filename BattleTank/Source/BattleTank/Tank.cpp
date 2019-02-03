// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	utankAimingCompnent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}



// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


UTankAimingComponent* ATank::GetAimingComponent() {
	return utankAimingCompnent;
}

void ATank::setAimingBarrelComponenet(UTankBarrel * barrelToSetup)
{
	GetAimingComponent()->setAimingBarrelComponenet(barrelToSetup, launchSpeed);
	barrel = barrelToSetup;
}

void ATank::setAimingTurretComponenet(UTankTurret * turretSetup)
{
	GetAimingComponent()->setAimingTurretComponenet(turretSetup);
}

void ATank::Fire() {
	
	auto socket= barrel->GetSocketByName(FName("LaunchPoint"));
	auto location = barrel->GetSocketLocation(FName("LaunchPoint"));
	auto rotation = barrel->GetSocketRotation(FName("LaunchPoint"));
	  
	auto spawnedProjectile=GetWorld()->SpawnActor<AProjectile>(projectile, location,rotation, FActorSpawnParameters());
	spawnedProjectile->LaunchProjectile(launchSpeed);

}



