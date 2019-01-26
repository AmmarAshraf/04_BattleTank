// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATank* ATankAIController::GetTankComponent() const {

	return Cast<ATank>(GetPawn());

}

ATank* ATankAIController::GetPlayerTankComponent() const {

	auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (playerPawn == nullptr)
		return nullptr;
	else
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (GetTankComponent() == NULL) {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank component not found"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank component found"))
	}

	if (GetPlayerTankComponent() == NULL) {
		UE_LOG(LogTemp, Warning, TEXT("You have not been found"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("you have been found"))
	}

}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	GetPlayerTankComponent()->GetAimingComponent()->AimAt(GetPlayerTankComponent()->GetActorLocation());

}
