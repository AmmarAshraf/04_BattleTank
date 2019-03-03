// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAIMovment.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//utankAimingCompnent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

	UE_LOG(LogTemp, Warning, TEXT("C++ Tank Constuctor"))
}



// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("C++ Tank Begin Play"))

	utankAimingCompnent = FindComponentByClass<UTankAimingComponent>();

	if (utankAimingCompnent==nullptr) {

		UE_LOG(LogTemp, Warning, TEXT("Aim Conpnent Not found"))
		return;
	}

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ATank::AimAt(FHitResult hitVector) {
	if (utankAimingCompnent== nullptr) { return; }

	utankAimingCompnent->AimAt(hitVector);

	//UE_LOG(LogTemp, Warning, TEXT("Fire"))

}

void ATank::Fire() {
	if (barrel==nullptr) { return; }

		if ((FPlatformTime::Seconds() - lastTime) > fireDelay) {

			lastTime = FPlatformTime::Seconds();

			auto socket = barrel->GetSocketByName(FName("LaunchPoint"));
			auto location = barrel->GetSocketLocation(FName("LaunchPoint"));
			auto rotation = barrel->GetSocketRotation(FName("LaunchPoint"));

			auto spawnedProjectile = GetWorld()->SpawnActor<AProjectile>(projectile, location, rotation, FActorSpawnParameters());
			spawnedProjectile->LaunchProjectile(launchSpeed);
		}
	
}







