// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "FortItemPresentationEntry.generated.h"

class UCommonTextBlock;
class UFortCosmeticItemCard;
class UFortItem;
class UTexture2D;

UCLASS(Abstract)
class UFortItemPresentationEntry : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnInitialIconAnimation();

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsPaidBattlePassRewardSet(bool bIsPaidBattlePassReward);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPresentationEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortCosmeticItemCard> ItemCard;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPresentationEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Count;

	UPROPERTY()
	TObjectPtr<UFortItem> FortItem;

	UPROPERTY()
	TSoftObjectPtr<UTexture2D> RewardTexture;

};

