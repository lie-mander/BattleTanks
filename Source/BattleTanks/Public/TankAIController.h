// Liemander INC

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	// ������ �� ����� ������, �� ������� ���� �� ���������������
	float AcceptanceRadius;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
