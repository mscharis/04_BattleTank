// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Yaw(float RelativeSpeed)
{
	// Move the turret the right amount this frame
	// given a max yawn speed and the frame time

	auto YawChange = FMath::Clamp<float>(RelativeSpeed, -1, +1) * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewYaw = RelativeRotation.Yaw + YawChange;
	SetRelativeRotation(FRotator(0,NewYaw,0));
}