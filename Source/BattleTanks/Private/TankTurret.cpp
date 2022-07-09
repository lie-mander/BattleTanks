// Liemander INC

#include "TankTurret.h"

void UTankTurret::TurretTurn(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto TurnChange = RelativeSpeed * MaxDegressPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Turn = GetRelativeRotation().Yaw + TurnChange;
	SetRelativeRotation(FRotator(0, Turn, 0));
}
