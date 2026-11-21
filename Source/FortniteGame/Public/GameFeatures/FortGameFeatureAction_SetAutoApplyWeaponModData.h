// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_SetAutoApplyWeaponModData.generated.h"

class UFortWeaponPickupSpawnModData;

UCLASS(MinimalAPI, meta=(DisplayName="Set Auto Apply Weapon Mod Data"))
class UFortGameFeatureAction_SetAutoApplyWeaponModData : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Spawn Mod Data", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortWeaponPickupSpawnModData> AutoApplyModDataAsset;

};

