// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * Responsible from driving the tank tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:

	// Связывание намерения движения игрока с самим движением
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMoveForwardOrBackward(float Throw);

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendTurnRight(float Throw);

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendTurnLeft(float Throw);

	UFUNCTION(BlueprintCallable, Category = Input)
	void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

private:

	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
	
};
