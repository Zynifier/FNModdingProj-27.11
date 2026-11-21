// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Weapons/FortWeaponRangedForVehicle.h"
#include "FortWeaponRangedOctopusTowhook.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTowhookTargetUpdatedDelegate, const FVector&, TargetLocation);

UCLASS(HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortWeaponRangedOctopusTowhook : public AFortWeaponRangedForVehicle
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const FVector& GetTowhookTargetLocation() const;

	UPROPERTY(BlueprintAssignable)
	FTowhookTargetUpdatedDelegate OnTargetUpdated;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponRangedOctopusTowhook")
	FScalableFloat TowhookFuelCost;

};

