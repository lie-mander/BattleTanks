// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and to apply forces to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	// ��������� �������� ��� ������� ����� -1 � 1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	// ������������ ���� �� �������� � ��������
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivindForce = 400000; // 40 ���� * 10 �/�^2
};