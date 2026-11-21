// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Cosmetics/Variants/FortCosmeticVariantInfo.h"
#include "Items/FortAccountItemDefinition.h"
#include "Items/FortItemProfileTypes.h"
#include "FortVariantTokenType.generated.h"

class UFortItemDefinition;

UENUM()
enum class EFortVariantTokenEquipRule : uint8
{
	// Will only equip the primary variant this token grants. Default functionality on MCP.

	EquipBaseVariantOnly = 0,
	// Will equip the primary + additional variants this token grants. Not supported on MCP.

	AlsoEquipAdditionalGrants = 1,
	// Will equip the primary variant this token grants, along with any preview variants that are currently owned. Not supported on MCP.

	AlsoEquipPreviewGrantsIfOwned = 2,
	// Will equip the primary + additional variants this token grants, along with any preview variants that are currently owned. Not supported on MCP.

	EquipAllExceptUnowned = 3,
};

UCLASS(MinimalAPI)
class UFortVariantTokenType : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Variant Token")
	UFortItemDefinition* GetCosmeticItem() const;

	UFUNCTION(BlueprintPure, Category="Variant Token")
	FGameplayTag GetVariantChannelTag() const;

	UFUNCTION(BlueprintPure, Category="Variant Token")
	FGameplayTag GetVariantNameTag() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortVariantTokenType")
	EItemProfileType ProfileType;

	UPROPERTY(EditAnywhere, Category="Variant Token")
	TObjectPtr<UFortItemDefinition> cosmetic_item;

	UPROPERTY(EditAnywhere, Category="Variant Token", meta=(Categories="Cosmetics.Variant.Channel"))
	FGameplayTag VariantChannelTag;

	UPROPERTY(EditAnywhere, Category="Variant Token", meta=(Categories="Cosmetics.Variant.Property"))
	FGameplayTag VariantNameTag;

	UPROPERTY(EditAnywhere, Category="Variant Token")
	TArray<FCosmeticVariantInfo> AdditionalVariantsToGrant;

	UPROPERTY(EditAnywhere, Category="Variant Token Preview Overrides")
	TArray<FCosmeticVariantInfo> VariantPreviewOverrides;

	UPROPERTY(EditAnywhere, Category="Variant Token")
	bool bAutoEquipVariant;

	UPROPERTY(EditAnywhere, Category="Variant Token")
	EFortVariantTokenEquipRule VariantEquipRules;

	UPROPERTY(EditAnywhere, Category="Variant Token")
	bool bMarkItemUnseen;

	UPROPERTY(EditAnywhere, Category="Variant Token")
	bool bCreateGiftbox;

	UPROPERTY(EditAnywhere, Category="Variant Token")
	bool bGrantBaseItem;

	UPROPERTY(EditAnywhere, Category="Variant Token")
	bool bUseDisplayNameInGiftbox;

	UPROPERTY(EditAnywhere, Category="Variant Token")
	FString CustomGiftbox;

};

