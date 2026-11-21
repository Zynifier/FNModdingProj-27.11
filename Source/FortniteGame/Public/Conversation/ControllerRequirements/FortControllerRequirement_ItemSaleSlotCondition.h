// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Conversation/FortConversationControllerRequirement.h"
#include "Conversation/FortThresholdTestConfig.h"
#include "FortRarityEnum.h"
#include "FortWeaponEnums.h"
#include "Items/FortItemTypeEnum.h"
#include "FortControllerRequirement_ItemSaleSlotCondition.generated.h"

USTRUCT(BlueprintType)
struct FItemSaleSlotRarityRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Rarity")
	EFortRarity Rarity;

	UPROPERTY(EditAnywhere, Category="Rarity")
	EThresholdRequirement RarityRequirement;

};

USTRUCT(BlueprintType)
struct FSlotSelectionMethod
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Config")
	bool bDetermineSlotAutomatically;

	UPROPERTY(EditAnywhere, Category="Config", meta=(ClampMax="5", ClampMin="1", EditCondition="!bDetermineSlotAutomatically", EditConditionHides, UIMax="5", UIMin="1"))
	int32 SellSlot;

};

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Item Sale Slot Type Filter"))
class UFortControllerRequirement_ItemSaleSlotCondition_TypeFilter : public UFortControllerRequirement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Config")
	FSlotSelectionMethod SellSlot;

	UPROPERTY(EditAnywhere, Category="Config")
	bool bRequireSpecificItem;

	UPROPERTY(EditAnywhere, Category="Config", meta=(EditCondition="bRequireSpecificItem", EditConditionHides))
	TArray<FString> PersistentItemNames;

	UPROPERTY(EditAnywhere, Category="Filtering", meta=(EditCondition="!bRequireSpecificItem", EditConditionHides))
	TArray<EFortItemType> AllowedItemTypes;

	UPROPERTY(EditAnywhere, Category="Filtering", meta=(EditCondition="!bRequireSpecificItem", EditConditionHides))
	TArray<EFortWeaponType> AllowedWeaponTypes;

	UPROPERTY(EditAnywhere, Category="Filtering", meta=(EditCondition="!bRequireSpecificItem", EditConditionHides))
	FGameplayTagContainer RequiredGameplayTags_ExactMatch;

	UPROPERTY(EditAnywhere, Category="Filtering", meta=(EditCondition="!bRequireSpecificItem", EditConditionHides))
	FGameplayTagContainer RequiredGameplayTags_PartialMatch;

};

