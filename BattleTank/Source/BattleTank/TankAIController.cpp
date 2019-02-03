// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"


ATankAIController::ATankAIController()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	UE_LOG(LogTemp, Warning, TEXT("Keep firing"))
	
	ATank* thisTank= Cast<ATank>(GetPawn());

	auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (playerPawn != nullptr && thisTank != nullptr){
		 ATank* playerTank= Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

		 thisTank->GetAimingComponent()->AIAimAt(playerTank->GetActorLocation());
	
		 thisTank->Fire();
	
	}
}
