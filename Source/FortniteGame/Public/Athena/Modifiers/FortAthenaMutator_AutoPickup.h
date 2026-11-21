// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_AutoPickup.generated.h"

UENUM(BlueprintType)
enum class EFortCreativeAutoPickupSetting : uint8
{
	IsFalse = 0 UMETA(DisplayName="No"),
	IsTrue = 1 UMETA(DisplayName="Yes"),
	AutoOnly = 2,
	Unset = 255 UMETA(DisplayName="Default"),
};

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_AutoPickup : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UPROPERTY(Replicated)
	EFortCreativeAutoPickupSetting AutoPickupDefaultItems;

	UPROPERTY(Replicated)
	EFortCreativeAutoPickupSetting AutoPickupAmmoItems;

	UPROPERTY(Replicated)
	EFortCreativeAutoPickupSetting AutoPickupConsumableItems;

	UPROPERTY(Replicated)
	EFortCreativeAutoPickupSetting AutoPickupGadgetItems;

	UPROPERTY(Replicated)
	EFortCreativeAutoPickupSetting AutoPickupTrapItems;

	UPROPERTY(Replicated)
	EFortCreativeAutoPickupSetting AutoPickupWeaponItems;

	UPROPERTY(Replicated)
	EFortCreativeAutoPickupSetting AutoPickupWorldResourceItems;

};

