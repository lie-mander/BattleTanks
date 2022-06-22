// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	auto PlayerTank = GetPlayerTank();

	UE_LOG(LogTemp, Warning, TEXT("AI Tank find player tank %s"), *PlayerTank->GetName());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!GetPlayerTank()) { return; }

	// TODO Двигаться к игроку

	// Целимся в игрока
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

	// Стреляем, если готовы
}

ATank* ATankAIController::GetControlledTank() const
{
	if (!GetPawn()) { return nullptr; }

	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) 
	{ 
		UE_LOG(LogTemp, Warning, TEXT("AI Tank can`t find player tank"))
		return nullptr; 
	}

	return Cast<ATank>(PlayerPawn);
}

