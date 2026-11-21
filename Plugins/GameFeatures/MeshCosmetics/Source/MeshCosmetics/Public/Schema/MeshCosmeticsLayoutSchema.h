// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "FortCustomPartTypeEnum.h"
#include "Items/FortApparelItemDefinitionStubs.h"
#include "MeshCosmeticsLayoutSchema.generated.h"

class UAnimInstance;
class UCustomizableObject;

USTRUCT(BlueprintType)
struct FCosmeticSlotSelector
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MeshCosmetics")
	TEnumAsByte<EFortCustomPartType::Type> LegacyPartType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MeshCosmetics")
	EAthenaCustomizationCategory SourceCategory;


	MESHCOSMETICS_API bool operator==(const FCosmeticSlotSelector& Other) const;
	friend MESHCOSMETICS_API uint32 GetTypeHash(const FCosmeticSlotSelector& Value);
};

USTRUCT(BlueprintType)
struct FCosmeticsLayoutSlot
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MeshCosmetics", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UCustomizableObject> SlottedObject;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MeshCosmetics")
	int32 ComponentIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MeshCosmetics")
	FCosmeticSlotSelector RequiredCosmeticPart;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MeshCosmetics", meta=(AssetBundles="Equipped"))
	TSoftClassPtr<UAnimInstance> ProportionalLayerAnimBP;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MeshCosmetics")
	TMap<int32, FName> LinkedAnimGraphTag;

};

UCLASS(MinimalAPI, HideCategories=("Sacrifice", "Conversion", "LootLevel", "Disassembly", "Level", "Tooltips", "Rating", "Series", "SpecialActor", "AutoEquip", "Functionality", "InventoryLimit"))
class UMeshCosmeticsLayoutSchema : public UFortApparelLayoutItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MeshCosmetics", meta=(AssetBundles="Equipped"))
	TMap<FCosmeticSlotSelector, FCosmeticsLayoutSlot> SlotDataConfig;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MeshCosmetics", meta=(AssetBundles="Equipped", DeprecatedProperty))
	TMap<FCosmeticSlotSelector, TSoftObjectPtr<UCustomizableObject>> SlottedCustomizableObjects;

};

