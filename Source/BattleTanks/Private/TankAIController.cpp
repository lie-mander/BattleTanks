// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto AIPawn = Cast<ATank>(GetPawn());
	auto PlayerPawn = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (AIPawn && PlayerPawn)
	{
		// ��������� � ������
		MoveToActor(PlayerPawn, AcceptanceRadius); // TODO ��������� � ��� ���������� ����������

		// ������� � ������
		AIPawn->AimAt(PlayerPawn->GetActorLocation());

		AIPawn->Fire();
	}
}



