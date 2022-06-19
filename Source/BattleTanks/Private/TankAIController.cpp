// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	auto PlayerTank = GetPlayerTank();

	if(!PlayerTank) { UE_LOG(LogTemp, Warning, TEXT("AI Tank can`t find player tank")) }

	UE_LOG(LogTemp, Warning, TEXT("AI Tank find player tank %s"), *PlayerTank->GetName());

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!GetPlayerTank()) { return; }

	// TODO ��������� � ������

	// ������� � ������
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

	// ��������, ���� ������
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);
}

