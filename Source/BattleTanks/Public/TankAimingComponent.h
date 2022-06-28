// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel; // Forward Declaration
class UTankTurret;
class UTankTrack;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed);

	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurretReference(UTankTurret* TurretToSet);
	void SetTrackReference(UTankTrack* TrackToSet);

private:
	
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	UTankTrack* Track = nullptr;


	void MoveTurretAndBarrelTowards(FVector AimDirection);
};
