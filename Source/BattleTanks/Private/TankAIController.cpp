// Liemander INC

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

	if (ensure(AIPawn && PlayerPawn))
	{
		// ��������� � ������
		MoveToActor(PlayerPawn, AcceptanceRadius); // TODO ��������� � ��� ���������� ����������

		// ������� � ������
		AIPawn->AimAt(PlayerPawn->GetActorLocation());

		AIPawn->Fire();
	}
}



