// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Map/AthenaGoalsPageBaseCard.h"
#include "ChallengeBundles/FortChallengeBundleItemDefinition.h"
#include "AthenaGoalsPageQuestCard.generated.h"

class UCommonTextBlock;
class UFortQuestItem;

UCLASS(BlueprintType, Blueprintable)
class UAthenaGoalsPageQuestCard : public UAthenaGoalsPageBaseCard
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool GetIsSelectable();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void PopulateBattlePassRequirement(const bool bBattlePassRequired);

	UFUNCTION(BlueprintImplementableEvent)
	void PopulateHeader(const FBundleGoalCardDisplayData& GoalCardDisplayData);

	UFUNCTION(BlueprintImplementableEvent)
	void PopulateIsSelectable(const bool bCardIsSelectable);

	UPROPERTY(EditAnywhere, Category="Text", meta=(DisplayName="Expired Goals Page Quest Card"))
	FText TextExpired;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_BundleID;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortQuestItem>> PrevQuestList;

};

