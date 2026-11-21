// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Weapons/Projectiles/FortAttachableProjectileDeprecated.h"
#include "FortOctopusTowhookAttachableProjectile.generated.h"

class AFortOctopusVehicle;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation", "Replication", "Navigation", "Replication", "Navigation", "Navigation", "Game|Damage"))
class AFortOctopusTowhookAttachableProjectile : public AFortAttachableProjectileDeprecated
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void DestroyProjectile();

	UFUNCTION(BlueprintPure)
	FVector GetRopeAttachLocation() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortOctopusTowhookAttachableProjectile")
	FName RopeAttachSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortOctopusTowhookAttachableProjectile")
	FName CollisionProfileNameOverride;

private:
	UPROPERTY(Replicated)
	TObjectPtr<AFortOctopusVehicle> OwningVehicle;

};

