// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Tank.h"
#define OUT

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if(AimingComponent!=nullptr)
	NotifyAinmingComponentCreated(AimingComponent);
	else
	UE_LOG(LogTemp, Warning, TEXT("Aiming component not found"))


}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimingTowardsCrosshair();
}

void ATankPlayerController::AimingTowardsCrosshair() {

	if (GetPawn() != nullptr) {

		FHitResult hitLocation;

		GetSightRayHitLocation(hitLocation);
		
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FHitResult hitLocation) {

	int32 SizeX;
	int32 SizeY;

	GetViewportSize(OUT SizeX, OUT SizeY);

	auto CrossHairScreenLocation =FVector2D(SizeX*CrossHairXLocation, SizeY*CrossHairYLocation);

	FVector direction;

	if (GetCameraDirection(CrossHairScreenLocation, direction)) {
		
		//UE_LOG(LogTemp, Warning, TEXT("Camera Direction %s"),*direction.ToString())

		if(GetVectorHitLocation(direction, hitLocation)){
			//UE_LOG(LogTemp, Warning, TEXT("Enter Dragon %s"),*hitLocation.Location.ToString())
    	    
		}
		//else
		//UE_LOG(LogTemp, Warning, TEXT("No hit"))

	}
	
	return false;

}

bool ATankPlayerController::GetCameraDirection(FVector2D CrossHairScreenLocation, FVector &CameraDirection) {

	FVector  outLocation;

	return DeprojectScreenPositionToWorld(CrossHairScreenLocation.X, CrossHairScreenLocation.Y, outLocation, CameraDirection);
	
}

bool ATankPlayerController::GetVectorHitLocation(FVector LookDirection, FHitResult hitresult) {

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (AimingComponent == nullptr){
		return false;
	}

	auto CameraLocation= PlayerCameraManager->GetCameraLocation();

	auto EndLocation = (CameraLocation + (LookDirection * LineTraceRange));


	if(GetWorld()->LineTraceSingleByChannel(
		OUT hitresult,        //result
		CameraLocation,        //start
		EndLocation, //end
		ECollisionChannel::ECC_Camera)){
    	
		AimingComponent->AimAt(hitresult);
		return true;
		
	}
	else {
		hitresult = FHitResult();
		hitresult.Location = FVector(0);
		AimingComponent->AimAt(hitresult);
		return false;
	}


}


void ATankPlayerController::SetPawn(APawn* InPawn) {
	Super::SetPawn(InPawn);
	if (InPawn) {

		auto possesedTank = Cast<ATank>(InPawn);

		if (possesedTank == nullptr) {
			return;
		}
		else {
			//subscribe
			possesedTank->fTankDelegate.AddUniqueDynamic(this, &ATankPlayerController::OnTankDeath);

		}

	}
}


void ATankPlayerController::OnTankDeath() {
	StartSpectatingOnly();
}

