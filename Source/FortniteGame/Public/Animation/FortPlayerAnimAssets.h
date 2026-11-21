// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPlayerAnimAssets.generated.h"

class UFortFirstPersonAnimAsset;
class UFortLocomotionAnimAsset;
class UFortTacticalStateAnimAsset;

USTRUCT(BlueprintType)
struct FFortPlayerAnimAssets
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortPlayerAnimAssets")
	TObjectPtr<UFortLocomotionAnimAsset> LocomotionAnimAsset;

	UPROPERTY(EditAnywhere, Category="FortPlayerAnimAssets")
	TObjectPtr<UFortTacticalStateAnimAsset> TacticalStateAnimAsset;

	UPROPERTY(EditAnywhere, Category="FortPlayerAnimAssets")
	TObjectPtr<UFortFirstPersonAnimAsset> FirstPersonWeaponAnimAsset;

};

