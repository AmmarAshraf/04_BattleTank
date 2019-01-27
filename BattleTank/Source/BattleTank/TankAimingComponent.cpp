// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
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


void UTankAimingComponent::AimAt(FVector hitVector)
{

	FVector location=barrel->GetSocketLocation(FName("LaunchPoint"));
	FVector outTossVelocity=FVector(0);
	
	bool ret= UGameplayStatics::SuggestProjectileVelocity(
		this,
		outTossVelocity,
		location,
		hitVector,
		launchSpeed,
		0,0,false,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (ret) {

		//UTankAimingComponent();
		auto UnitVector = outTossVelocity.GetSafeNormal();
		auto OwnerName = GetOwner()->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("%s Component hit barrel %s"), *OwnerName, *UnitVector.ToString())
			//barrel->elevate(1);
		moveBarrel(hitVector);
	}
	else {
		if(Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn())== Cast<ATank>(GetOwner()))
		 UE_LOG(LogTemp, Warning, TEXT("No aiming solution found"))
	}
	
}

void UTankAimingComponent::setAimingBarrelComponenet(UTankBarrel * barrelToSetup, float launchSpeedToSetup)
{
	barrel = barrelToSetup;
	launchSpeed = launchSpeedToSetup;
}

void UTankAimingComponent::moveBarrel(FVector aimTarget) {

	if (Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn()) == Cast<ATank>(GetOwner())) {
	auto RotationDifference = aimTarget.Rotation() - barrel->GetForwardVector().Rotation();
	barrel->elevate(RotationDifference.Pitch);
    }

}