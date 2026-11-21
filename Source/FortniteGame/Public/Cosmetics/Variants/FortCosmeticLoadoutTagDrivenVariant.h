// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Misc/Guid.h"
#include "UObject/NoExportTypes.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Cosmetics/Variants/FortAppliedSwapItemAndVariantStateEnum.h"
#include "Cosmetics/Variants/FortCosmeticVariant.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "FortCosmeticLoadoutTagDrivenVariant.generated.h"

class UAthenaCosmeticItemDefinition;
class UFortLoadoutTagDrivenVariantScript;

UENUM(BlueprintType)
enum class ECosmeticMetaTagRequirementCategory : uint8
{
	None = 0,
	Glider = 1,
	Pickaxe = 2,
	Backpack = 3,
	Character = 4,
	FullLoadout = 5,
	MAX = 6 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct FCosmeticMetaTagCondition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Requirements")
	ECosmeticMetaTagRequirementCategory ItemCategory;

	UPROPERTY(EditAnywhere, Category="Requirements")
	TSoftObjectPtr<UAthenaCosmeticItemDefinition> SpecificItem;

	UPROPERTY(EditAnywhere, Category="CosmeticMetaTagCondition")
	FGameplayTagQuery MetaTagQuery;

	UPROPERTY(VisibleAnywhere, Category="Requirements")
	FGameplayTagContainer RequiredMetaTags;

	UPROPERTY(VisibleAnywhere, Category="Requirements")
	FGameplayTagContainer ExcludedMetaTags;

};

USTRUCT(BlueprintType)
struct FFortCosmeticDependentSwapData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Requirements", meta=(TitleProperty="ItemCategory"))
	TArray<FCosmeticMetaTagCondition> SwapRequirements;

	UPROPERTY(EditAnywhere, Category="Swap")
	TArray<FFortSwapItemAndVariantData> SwapData;

	UPROPERTY(EditAnywhere, Category="Swap")
	EFortAppliedSwapItemAndVariantState ForcedSwapState;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Swap")
	FGuid SwapId;

};

USTRUCT()
struct FTagDrivenVariantDef : public FPartVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def", meta=(TitleProperty="ToSwapFrom"))
	TArray<FEmoteMontageSwap> MontageSwaps;

	UPROPERTY(VisibleAnywhere, Category="Variant Def")
	FGameplayTagContainer RequiredMetaTags;

	UPROPERTY(VisibleAnywhere, Category="Variant Def")
	FGameplayTagContainer ExcludedMetaTags;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FCosmeticMetaTagCondition> RequiredConditions;

	UPROPERTY(EditAnywhere, Category="Variant Def")
	TArray<FCosmeticMetaTagCondition> ExcludedConditions;

};

UCLASS()
class UFortCosmeticLoadoutTagDrivenVariant : public UFortCosmeticVariantBackedByArray
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Cosmetic Variant", meta=(TitleProperty="VariantName"))
	TArray<FTagDrivenVariantDef> Variants;

	UPROPERTY(EditAnywhere, Category="Cosmetic Variant")
	TSubclassOf<UFortLoadoutTagDrivenVariantScript> TagScript;

	UPROPERTY(EditAnywhere, Category="Cosmetic Variant")
	bool bUseDefaultIfNoConditionsAreSatisfied;

};

UCLASS(Abstract, Const, BlueprintType, Blueprintable)
class UFortLoadoutTagDrivenVariantScript : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	FGameplayTag DetermineVariantSelection(const FFortAthenaLoadout& Loadout) const;

};

