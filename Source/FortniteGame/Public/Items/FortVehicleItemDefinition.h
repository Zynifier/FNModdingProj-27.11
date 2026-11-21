// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Items/FortWorldItemDefinition.h"
#include "FortVehicleItemDefinition.generated.h"

class AActor;
class USkeletalMesh;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("FrontendPreview", "Functionality", "InventoryLimit", "OwnedTags", "Tooltips", "Rating", "Series"))
class UFortVehicleItemDefinition : public UFortWorldItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="VehicleData")
	FScalableFloat VehicleMinSpawnPercent;

	UPROPERTY(EditAnywhere, Category="VehicleData")
	FScalableFloat VehicleMaxSpawnPercent;

	UPROPERTY(EditAnywhere, Category="VehicleData")
	FScalableFloat MaxNumberCanSpawn;

	UPROPERTY(EditAnywhere, Category="VehicleData")
	FScalableFloat MinPercentWithGas;

	UPROPERTY(EditAnywhere, Category="VehicleData")
	FScalableFloat MaxPercentWithGas;

	UPROPERTY(EditAnywhere, Category="VehicleData")
	FScalableFloat MinPercentInoperable;

	UPROPERTY(EditAnywhere, Category="VehicleData")
	FScalableFloat MaxPercentInoperable;

	UPROPERTY(EditAnywhere, Category="Preview")
	FTransform WrapPreviewTransform;

	UPROPERTY(EditAnywhere, Category="Preview", meta=(Bitmask, BitmaskEnum="/Script/FortniteGame.EItemWrapSectionNames"))
	int32 WrapPreviewSectionMask;

	UPROPERTY(EditAnywhere, Category="Preview")
	uint8 bUseInWrapPreviewList : 1;

protected:
	UPROPERTY(EditAnywhere, Category="VehicleData", meta=(AssetBundles="Equipped"))
	TSoftClassPtr<AActor> VehicleActorClass;

	UPROPERTY(EditAnywhere, Category="Preview")
	TSoftObjectPtr<USkeletalMesh> PreviewSkeletalMesh;

	UPROPERTY(EditDefaultsOnly, AssetRegistrySearchable, Category="Cheat Settings")
	TArray<FString> SpawnVehicleNames;

	UPROPERTY(EditDefaultsOnly, AssetRegistrySearchable, Category="Cheat Settings")
	float MaxSpawnDistance;

	UPROPERTY(EditDefaultsOnly, AssetRegistrySearchable, Category="Cheat Settings", meta=(Categories="Vehicle.Mod"))
	FGameplayTagContainer SpawnWithMods;

};

