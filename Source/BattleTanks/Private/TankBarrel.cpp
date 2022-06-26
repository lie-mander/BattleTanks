// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::BarrelElevate(float RelativeSpeed)
{
	// Двигаем пушки на верный объём в этом кадре
	// С данной максильной скоросью подъёма и время кадра
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed * MaxDegressPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = GetRelativeRotation().Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevateDegress, MaxElevateDegress);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
