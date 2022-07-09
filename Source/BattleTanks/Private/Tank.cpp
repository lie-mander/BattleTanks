// Liemander INC

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("[%s] opokop: C++ CONSTRUCT"), *Name);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();

	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("[%s] opokop: C++ BEGIN PLAY"), *Name);
}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if(!ensure(Barrel)) { return; }

	if (isReloaded) {


		// Спавн снаряда в сокете на стволе
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}
