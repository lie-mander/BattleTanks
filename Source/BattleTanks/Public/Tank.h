// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

private:

	// Sets default values for this pawn's properties
	ATank();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000; // TODO найти скорость выстрела


public:

	void AimAt(FVector HitLocatio);

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimingComponent* TankAimingComponent = nullptr;
};
