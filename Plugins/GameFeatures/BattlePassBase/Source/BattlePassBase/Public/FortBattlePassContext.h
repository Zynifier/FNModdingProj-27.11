// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintContextBase.h"
#include "Items/AthenaSeasonItemDefinition.h"
#include "SeasonPass/BattlePassTypes.h"
#include "FortBattlePassContext.generated.h"

class UFortPersistentResourceItemDefinition;

USTRUCT()
struct FSeasonalResourceList
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<UFortPersistentResourceItemDefinition>> SeasonalResources;

};

UCLASS()
class BATTLEPASSBASE_API UFortBattlePassContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool CanPurchaseBattlePassLevel() const;

	UFUNCTION(BlueprintPure)
	FText GetCurrentChapterAsText(const bool bFullText = false) const;

	UFUNCTION(BlueprintPure)
	FText GetCurrentSeasonNumberAsText(const bool bFullText = false) const;

	UFUNCTION(BlueprintPure)
	FText GetDefaultDisclaimerText() const;

	UFUNCTION(BlueprintPure)
	FText GetLevelPurchaseDisclaimerText() const;

	UFUNCTION(BlueprintPure)
	TArray<FSeasonCurrencyMcpData> GetSeasonalCurrencies() const;

private:
	UPROPERTY()
	TArray<TObjectPtr<UFortPersistentResourceItemDefinition>> CustomizationPageSeasonalResources;

	UPROPERTY()
	TArray<TObjectPtr<UFortPersistentResourceItemDefinition>> AllSeasonalResources;

	UPROPERTY()
	TMap<ERewardPageType, FSeasonalResourceList> RewardPageSeasonalResources;

};

