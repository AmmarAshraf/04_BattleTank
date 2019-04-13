// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"

UTankTracks::UTankTracks() {
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTracks::BeginPlay()
{

}

void UTankTracks::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {


}

void UTankTracks::setThrottle(float value) {

	//CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + value, -1, 1);
	DriveTrack(value);
}

void UTankTracks::DriveTrack(float CurrentThrottle) {
	if (CurrentThrottle == 0)
		return;

	auto forceVector = CurrentThrottle*TracksMaxDrivingForce;

	FVector forwardVector = FVector(forceVector, 0,0);
	UE_LOG(LogTemp, Warning, TEXT("# of wheels %i"), GetWheels().Num())
	for (auto wheel:GetWheels()) {

		USpawnPoint* spawnPoint= Cast<USpawnPoint>(wheel);
	
		if (spawnPoint != nullptr) {
			ASprungWheel* sprungWheel= spawnPoint->GetSprungWheel();

		
			sprungWheel->GetWheel()->AddForce(forwardVector, NAME_None);
		
			
			
		}
	}

}

TArray<USceneComponent*> UTankTracks::GetWheels() {
	
	 TArray<USceneComponent*> comp;

	 GetChildrenComponents(true, comp);

	return comp;

}