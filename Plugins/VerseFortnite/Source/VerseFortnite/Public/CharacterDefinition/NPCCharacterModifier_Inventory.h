// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetRegistry/AssetData.h"
#include "GameplayTagContainer.h"
#include "CharacterDefinition/NPCCharacterModifier.h"
#include "NPCCharacterModifier_Inventory.generated.h"

class UFortItemDefinition;

USTRUCT(BlueprintType)
struct FCharacterModifierInventoryItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Category="Item", meta=(GetAssetFilter="ShouldFilterAsset"))
	TSoftObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item", meta=(ClampMin="1", UIMin="1"))
	int32 ItemQuantity;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UNPCCharacterModifier_Inventory : public UNPCCharacterModifier
{
	GENERATED_BODY()

public:
#if WITH_EDITOR
	UFUNCTION(Category="Inventory")
	bool ShouldFilterAsset(const FAssetData& AssetData) const;
#endif

protected:
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Inventory", meta=(AllowPrivateAccess="true"))
	TArray<FCharacterModifierInventoryItem> Items;

	UPROPERTY(EditDefaultsOnly, Category="Inventory", meta=(AllowPrivateAccess="true"))
	FGameplayTagContainer SupportedItemTags;

};

