// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


#define OUT
ATank* ATankPlayerController:: GetTankComponent() const{

	return Cast<ATank>(GetPawn());

}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (GetTankComponent() == NULL) {
	UE_LOG(LogTemp,Warning,TEXT("Tank component not found"))
	}
	else {
	UE_LOG(LogTemp, Warning, TEXT("Tank component found"))
	}

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimingTowardsCrosshair();
}

void ATankPlayerController::AimingTowardsCrosshair() {

	if (GetTankComponent() != nullptr) {

		FVector hitLocation;

		GetSightRayHitLocation(hitLocation);
		
			

		
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& hitLocation) {

	int32 SizeX;
	int32 SizeY;

	GetViewportSize(OUT SizeX, OUT SizeY);

	auto CrossHairScreenLocation =FVector(SizeX*CrossHairXLocation, SizeY*CrossHairYLocation,0);

	FVector direction;

	if (GetCameraDirection(CrossHairScreenLocation, direction)) {
		

		if(GetVectorHitLocation(direction, hitLocation)){
    	//UE_LOG(LogTemp, Warning, TEXT("Component hit %s"), *hitLocation.ToString())
			GetTankComponent()->GetAimingComponent()->AimAt(hitLocation);
		}
		else
		UE_LOG(LogTemp, Warning, TEXT("No hit"))


	}

	
	return false;

}

bool ATankPlayerController::GetCameraDirection(FVector CrossHairScreenLocation, FVector &CameraDirection) {

	FVector  outLocation;

	return DeprojectScreenPositionToWorld(CrossHairScreenLocation.X, CrossHairScreenLocation.Y, outLocation, CameraDirection);
	
}

bool ATankPlayerController::GetVectorHitLocation(FVector LookDirection,FVector& hitLocation) {


	auto CameraLocation= PlayerCameraManager->GetCameraLocation();

	auto EndLocation = (CameraLocation + (LookDirection * LineTraceRange));

	FHitResult hitresult;

	if(GetWorld()->LineTraceSingleByChannel(
		OUT hitresult,        //result
		CameraLocation,        //start
		EndLocation, //end
		ECollisionChannel::ECC_Visibility)){
		hitLocation= hitresult.Location;
    	return true;
	}
	else {
		hitLocation = FVector(0.f);
		return false;
	}

}
