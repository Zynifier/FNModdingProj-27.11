// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortRarityEnum.h"
#include "MakeDesignAsset/SFortMakeDesignAssetUtility.h"
#include "SFortMakeDesignTrapAssetForm.generated.h"

class ABuildingActor;
class AFortDecoPreview;
class AFortWeapon;
class UBuildingEditModeMetadata;
class UDataTable;
class UFortWorldItemDefinition;
class USkeletalMesh;
class USoundBase;
class UStaticMesh;
class UTexture2D;

UENUM()
enum class ETrapPlacements : uint8
{
	TP_None = 0 UMETA(DisplayName="None"),
	TP_Ceiling = 1 UMETA(DisplayName="Ceiling"),
	TP_Floor = 2 UMETA(DisplayName="Floor"),
	TP_Wall = 3 UMETA(DisplayName="Wall"),
	TP_MAX = 4,
};

USTRUCT()
struct FTrapItemDefintionDesignerData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Starting Rarity")
	EFortRarity Rarity;

	UPROPERTY(EditAnywhere, Category="Placement")
	ETrapPlacements Placement;

	UPROPERTY(EditAnywhere, Category="Placement")
	TArray<TSoftObjectPtr<UBuildingEditModeMetadata>> AllowedShapes;

	UPROPERTY(EditAnywhere, Category="Building Actor")
	TSoftClassPtr<ABuildingActor> BlueprintClass;

	UPROPERTY(EditDefaultsOnly, Category="Building Actor")
	TSoftClassPtr<AFortDecoPreview> PlacementPreviewClass;

	UPROPERTY(EditAnywhere, Category="Functionality")
	int32 MaxStackSize;

	UPROPERTY(EditAnywhere, Category="Weapon Data")
	TSoftClassPtr<AFortWeapon> WeaponActorClass;

	UPROPERTY(EditAnywhere, Category="Display")
	FText DisplayName;

	UPROPERTY(EditAnywhere, Category="Display")
	FText Description;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TSoftObjectPtr<UTexture2D> SmallPreviewImage;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TSoftObjectPtr<UTexture2D> LargePreviewImage;

	UPROPERTY(EditAnywhere, Category="Pickup")
	TObjectPtr<UStaticMesh> PickupStaticMesh;

	UPROPERTY(EditAnywhere, Category="Pickup")
	TObjectPtr<USkeletalMesh> PickupSkeletalMesh;

	UPROPERTY(EditAnywhere, Category="Sounds")
	TSoftObjectPtr<USoundBase> PickupSound;

	UPROPERTY(EditAnywhere, Category="Sounds")
	TSoftObjectPtr<USoundBase> DropSound;

	UPROPERTY(EditAnywhere, Category="Owned Tags")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(EditAnywhere, Category="Advanced Functionality")
	bool bNeverPersisted;

	UPROPERTY(EditAnywhere, Category="Loot Level Data")
	TSoftObjectPtr<UDataTable> LootLevelData;

	UPROPERTY(EditAnywhere, Category="Loot Level Data")
	FString LootLevelColumnName;

	UPROPERTY(EditAnywhere, Category="Loot Level Data")
	FString LootLevelRowName;

	UPROPERTY(EditAnywhere, Category="Schematic Defaults")
	FCurveAssetForm RatingLookupForm;

	UPROPERTY(EditAnywhere, Category="Schematic Defaults")
	FDataAssetForm WeaponStatHandleForm;

	UPROPERTY(EditAnywhere, Category="Defaults")
	bool bForceIgnoreOverlapTest;

	UPROPERTY(EditAnywhere, Category="Defaults")
	bool bForceIgnoreBuildingOverlaps;

	UPROPERTY(EditAnywhere, Category="Defaults")
	bool bShowDirectionArrowWhenFarOff;

	UPROPERTY(EditAnywhere, Category="Defaults")
	float DisassembleDurabilityDegradeMinLootPercent;

	UPROPERTY(EditAnywhere, Category="Defaults")
	float DisassembleDurabilityDegradeMaxLootPercent;

	UPROPERTY(EditAnywhere, Category="Defaults")
	float MiniMapViewableDistance;

	UPROPERTY(EditAnywhere, Category="Defaults")
	TSoftObjectPtr<UTexture2D> MiniMapIconBrushImage;

	UPROPERTY(EditAnywhere, Category="Defaults")
	FTransform FrontendPreviewMeshOffset;

	UPROPERTY(EditAnywhere, Category="Schematic Defaults")
	FDataAssetForm DisassebmleRecipeForm;

	UPROPERTY(EditAnywhere, Category="Schematic Defaults")
	FDataAssetForm ConversionRecipeForm;

	UPROPERTY(EditAnywhere, Category="Schematic Defaults")
	FDataAssetForm CraftingRecipeForm;

	UPROPERTY(EditAnywhere, Category="Schematic Defaults")
	FCurveAssetForm LevelToXpHandleForm;

	UPROPERTY(EditAnywhere, Category="Schematic Defaults")
	FCurveAssetForm LevelToSacrificeXpForm;

	UPROPERTY(EditAnywhere, Category="Schematic Defaults")
	FDataAssetForm SacrificeRecipeForm;

	UPROPERTY(EditAnywhere, Category="Schematic Defaults")
	FDataAssetForm TransmogSacrificeForm;

	UPROPERTY()
	TSoftObjectPtr<UFortWorldItemDefinition> Result;

};

