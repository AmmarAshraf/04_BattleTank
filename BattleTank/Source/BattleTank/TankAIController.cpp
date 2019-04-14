// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "TankAimingComponent.h"
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
	
	
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!(PlayerTank && ControlledTank)) { return; }

	// Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm
	
	ATank* thisTank= Cast<ATank>(GetPawn());

	auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (playerPawn != nullptr && thisTank != nullptr){

		auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
		if (AimingComponent == nullptr) {
			return;
		}
		 ATank* playerTank= Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

		 AimingComponent->AIAimAt(playerTank->GetActorLocation());
	
		 AimingComponent->Fire();
	
	}


	
}


void ATankAIController::SetPawn(APawn* InPawn) {
	Super::SetPawn(InPawn);
	if (InPawn) {

		auto possesedtank = Cast<ATank>(InPawn);

		if (possesedtank == nullptr) {
			return;
		}
		else {
			//subscribe
			possesedtank->fTankDelegate.AddUniqueDynamic(this, &ATankAIController::OnTankDeath);

		}

	}
}


void ATankAIController::OnTankDeath() {
	    UE_LOG(LogTemp, Warning, TEXT("Tank Died Recieved"))
        GetPawn()->DetachFromControllerPendingDestroy();
}