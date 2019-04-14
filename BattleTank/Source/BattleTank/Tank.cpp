// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"

#include "TankAIMovment.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}



// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) {
	int32 DamagePoint = FPlatformMath::RoundToInt(DamageAmount);
	auto DamageToTake = FMath::Clamp(DamagePoint, 0, CurrentHealth);

	
	if (CurrentHealth <= 0) {
		
		fTankDelegate.Broadcast();
	}
	else {

		CurrentHealth = CurrentHealth -DamageToTake;
	
		if (CurrentHealth < 0) {
			CurrentHealth = 0;
		}

	}

	return DamageToTake;
}

float ATank::GetHealthPercent() {
	
	return (float(CurrentHealth) / float(StartingHealth));
}








