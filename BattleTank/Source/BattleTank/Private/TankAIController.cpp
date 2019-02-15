// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Tank.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank)
	{
		auto ControlledTank = Cast<ATank>(GetPawn());
	
		// TODO Move towards the player

		// Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
	
		// Fire projectile
		ControlledTank->Fire(); // TODO don't fire every frame
	}
}