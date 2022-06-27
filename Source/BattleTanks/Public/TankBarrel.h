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
	// -1 ������������ �������� �������� ��� ���������, +1 - ��� �������
	void BarrelElevate(float RelativeSpeed);

private:

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegressPerSecond = 10;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevateDegress = 15;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevateDegress = -10;
};
