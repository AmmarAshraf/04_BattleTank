// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"

UTankTracks::UTankTracks() {
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTracks::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UTankTracks::OnCompHit);
}

void UTankTracks::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {


}

void UTankTracks::setThrottle(float value) {

	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + value, -1, 1);

}

void UTankTracks::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {


	DriveTrack();
	ApplySlipeSideWays();
	CurrentThrottle = 0;

}

void UTankTracks::ApplySlipeSideWays() {
	auto SlipperySpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceleration = -SlipperySpeed / DeltaTime * GetRightVector();

	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass()*CorrectionAcceleration) / 2;
	TankRoot->AddForce(CorrectionForce);
	//UE_LOG(LogTemp, Warning, TEXT("Correction force %s"), *CorrectionForce.ToString())
}

void UTankTracks::DriveTrack() {
	if (CurrentThrottle == 0)
		return;

	auto forceVector = GetForwardVector()*CurrentThrottle*TracksMaxDrivingForce;

	auto ComponentLocation = GetComponentLocation();

	Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent())->AddForceAtLocation(forceVector, ComponentLocation);
}