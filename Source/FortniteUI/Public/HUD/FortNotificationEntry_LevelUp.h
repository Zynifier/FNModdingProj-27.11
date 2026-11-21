// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HUD/FortNotificationEntry.h"
#include "FortNotificationEntry_LevelUp.generated.h"

class UCommonRichTextBlock;
class UCommonTextBlock;
class UFortItemDefinition;
class UFortLazyImage;
enum class EFortRarity : uint8;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortNotificationEntry_LevelUp : public UFortNotificationEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateLevelUpVisuals(const UFortItemDefinition* RewardItem);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateQuestRewardVisuals(const UFortItemDefinition* RewardItem, EFortRarity QuestRarity);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortNotificationEntry_LevelUp", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_Header;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RewardType;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Reward_Preview;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Reward_Preview_Shadow;

};

