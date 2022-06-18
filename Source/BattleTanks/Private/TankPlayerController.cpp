// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	auto Controlledtank = GetControlledTank();

	// Защита указателя
	if (!Controlledtank) { UE_LOG(LogTemp, Warning, TEXT("Tank not found")); }
	else { UE_LOG(LogTemp, Warning, TEXT("Tank: %s"), *Controlledtank->GetName()); }
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	// Передаем указателю АТанк пешку
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Внешний параметр
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
		UE_LOG(LogTemp, Warning, TEXT("1"));
		// TODO Контролируемый танк наводил прицел на точку
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Находим положение прицела
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	FVector CameraLookDirection;
	if (GetLookDirection(ScreenLocation, CameraLookDirection))
	{
		GetLookVectorHitLocation(CameraLookDirection, HitLocation);
	}

	return true;
}

// Дипроекция положение прицела на экране в мировое направление
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& CameraLookDirection) const
{
	FVector CameraWorldLocation; // Должно передаваться

	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		CameraLookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult Hit;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		Hit,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		) 
	{
		HitLocation = Hit.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}