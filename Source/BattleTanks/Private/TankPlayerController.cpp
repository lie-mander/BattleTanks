// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	auto Controlledtank = GetControlledTank();

	// ������ ���������
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
	// �������� ��������� ����� �����
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // ������� ��������
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
		UE_LOG(LogTemp, Warning, TEXT("1"));
		// TODO �������������� ���� ������� ������ �� �����
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// ������� ��������� �������
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

// ���������� ��������� ������� �� ������ � ������� �����������
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& CameraLookDirection) const
{
	FVector CameraWorldLocation; // ������ ������������

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