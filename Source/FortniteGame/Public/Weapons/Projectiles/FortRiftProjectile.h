// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/FortVehicleTeleportPortal.h"
#include "Weapons/Projectiles/FortProjectileBase.h"
#include "FortRiftProjectile.generated.h"

class AActor;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation", "Navigation", "Navigation", "Game|Damage"))
class AFortRiftProjectile : public AFortProjectileBase, public IVehicleTeleportPortal
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void NotifyTeleportedVehicle(AActor* VehicleActor);

	UFUNCTION(BlueprintCallable)
	void TeleportVehicle(AActor* Vehicle, const FVector& TeleportLocation);

};

