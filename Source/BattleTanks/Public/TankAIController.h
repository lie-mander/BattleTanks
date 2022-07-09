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
	// Радиус от танка игрока, на котором танк ИИ останавливается
	float AcceptanceRadius;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
