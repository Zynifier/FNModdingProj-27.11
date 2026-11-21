// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Weapons/Projectiles/FortAttachableProjectileDeprecated.h"
#include "FortTowHookAttachableProjectile.generated.h"

class AFortPhysicsTowHook;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation", "Replication", "Navigation", "Replication", "Navigation", "Navigation", "Game|Damage"))
class AFortTowHookAttachableProjectile : public AFortAttachableProjectileDeprecated
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void DestroyProjectile();

	UFUNCTION(BlueprintPure)
	FVector GetRopeAttachLocation() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortTowHookAttachableProjectile")
	FName RopeAttachSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortTowHookAttachableProjectile")
	FName CollisionProfileNameOverride;

private:
	UPROPERTY(Replicated)
	TObjectPtr<AFortPhysicsTowHook> OwningTowHook;

};

