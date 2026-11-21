// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintContextBase.h"
#include "AthenaAccountContext.generated.h"

class UAthenaSeasonItemDefinition;

UCLASS()
class FORTNITEUI_API UAthenaAccountContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void GetBattleBookPurchaseLimit(int32& MaxNumLevelsPossibleToPurchase, int32& BonusLevelsGranted);

	UFUNCTION(BlueprintPure)
	FText GetCurrentChapterAndSeasonText() const;

	UFUNCTION(BlueprintPure)
	FText GetCurrentChapterNumberAsText(bool bFullText = true) const;

	UFUNCTION(BlueprintCallable)
	UAthenaSeasonItemDefinition* GetCurrentSeasonDefinition();

	UFUNCTION(BlueprintPure)
	int32 GetCurrentSeasonNumber() const;

	UFUNCTION(BlueprintPure)
	FText GetCurrentSeasonNumberAsText(bool bFullText = true) const;

	UFUNCTION(BlueprintPure)
	bool IsAtMaxBattlePassTier() const;

	UFUNCTION(BlueprintPure)
	bool ShouldReplaceBattleStarsWithAlternateReward() const;

	UFUNCTION(BlueprintCallable)
	void SimulateBattleBookPurchase(int32 NumLevelsToPurchase, int32& BonusLevelsGranted, bool& bOverLimit);

};

