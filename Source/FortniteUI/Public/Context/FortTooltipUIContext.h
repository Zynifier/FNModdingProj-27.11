// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayTagContainer.h"
#include "BlueprintContextBase.h"
#include "FortMultiSize.h"
#include "FortUITypes.h"
#include "Items/FortTagDataLookupTable.h"
#include "FortTooltipUIContext.generated.h"

class UFortTooltipContext;
class UFortTooltipLoadingWrapper;
class UObject;

UCLASS()
class FORTNITEUI_API UFortTooltipUIContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="TooltipUIContext")
	bool GetCombinedDescription(const UObject* Object, const UFortTooltipContext* TooltipContext, FText& OutDescription, bool bSummaryDescription = false) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="TooltipUIContext")
	TArray<FFortDisplayAttribute> GetComparisonStats(const UObject* Object, const UObject* ComparisonObject, const UFortTooltipContext* TooltipContext, bool bUseSummaryTooltip = false) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="TooltipUIContext")
	bool GetDescription(const UObject* Object, const UFortTooltipContext* TooltipContext, TArray<FText>& OutDescription, bool bSummaryDescription = false) const;

	UFUNCTION(BlueprintPure, Category="TooltipUIContext")
	bool GetDisplayNameAndMultiBrushForTag(const FGameplayTag& Tag, FText& OutDisplayName, FFortMultiSizeBrush& OutBrush) const;

	UFUNCTION(BlueprintCallable, Category="TooltipUIContext")
	TArray<FGameplayAttribute> GetTooltipAttributes(const UObject* Object);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="TooltipUIContext")
	UFortTooltipLoadingWrapper* GetTooltipLoadingWrapper(const UObject* Object, bool bSummaryDescription = false) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="TooltipUIContext")
	bool GetTooltipStat(const UObject* Object, UFortTooltipContext* TooltipContext, const FGameplayTag Token, FFortDisplayAttribute& OutDisplayAttribute, bool bUseSummaryTooltip = false) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="TooltipUIContext")
	TArray<FFortDisplayAttribute> GetTooltipStats(const UObject* Object, const UFortTooltipContext* TooltipContext, bool bSummaryStats = false) const;

	UFUNCTION(BlueprintPure, Category="TooltipUIContext")
	bool GetUIDataForTag(const FGameplayTag& Tag, FFortTagUIData& OutData) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="TooltipUIContext")
	TArray<FFortDisplayAttribute> GetUpgradeStats(const UObject* Object, UFortTooltipContext* TooltipContext, const int32 UpgradeLevelDelta, bool bUseSummaryTooltip = false) const;

	UFUNCTION(BlueprintCallable, Category="TooltipUIContext")
	bool HasTooltipStats(const UObject* Object);

};

