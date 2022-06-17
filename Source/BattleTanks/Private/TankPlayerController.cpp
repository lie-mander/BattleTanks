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

ATank* ATankPlayerController::GetControlledTank() const
{
	// �������� ��������� ����� �����
	return Cast<ATank>(GetPawn());
}
