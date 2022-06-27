// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 максимальная скорость движения при опускании, +1 - при подъёме
	void BarrelElevate(float RelativeSpeed);

private:

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegressPerSecond = 10;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevateDegress = 15;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevateDegress = -10;
};
