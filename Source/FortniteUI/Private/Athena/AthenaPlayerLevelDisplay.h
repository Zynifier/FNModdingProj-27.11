// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Foundation/FortAccountWidgetBase.h"
#include "AthenaPlayerLevelDisplay.generated.h"

class UAthenaSeasonItemRewardIcon;
class UCommonTextBlock;
class UFortItem;
class UTexture2D;
enum class EBPStatus : uint8;

UENUM()
enum class EBPStatus : uint8
{
	UnpurchasedBP = 0,
	PurchasedBP = 1,
};

UCLASS(BlueprintType, Blueprintable)
class UAthenaPlayerLevelDisplay : public UFortAccountWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateRewardIcon(const UFortItem* RewardItem, const TSoftObjectPtr<UTexture2D>& RewardTexture, bool bHasAdditionalStylesToDisplay, int32 RewardLevel, bool bRequiresBattlePass);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateXpBar(float Progress, bool bIsMaxLevel);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateBPStatus(EBPStatus Status);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPlayerLevelDisplay", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Level;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaPlayerLevelDisplay", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UAthenaSeasonItemRewardIcon> RewardIcon;

};

