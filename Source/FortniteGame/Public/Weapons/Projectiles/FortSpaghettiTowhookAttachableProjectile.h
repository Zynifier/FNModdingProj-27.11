// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Weapons/Projectiles/FortAttachableProjectileDeprecated.h"
#include "FortSpaghettiTowhookAttachableProjectile.generated.h"

class AFortSpaghettiVehicle;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation", "Replication", "Navigation", "Replication", "Navigation", "Navigation", "Game|Damage"))
class AFortSpaghettiTowhookAttachableProjectile : public AFortAttachableProjectileDeprecated
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void DestroyProjectile();

	UFUNCTION(BlueprintPure)
	FVector GetRopeAttachLocation() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSpaghettiTowhookAttachableProjectile")
	FName RopeAttachSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSpaghettiTowhookAttachableProjectile")
	FName CollisionProfileNameOverride;

private:
	UPROPERTY(Replicated)
	TObjectPtr<AFortSpaghettiVehicle> OwningVehicle;

};

