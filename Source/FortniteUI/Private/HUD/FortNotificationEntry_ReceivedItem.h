// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HUD/FortNotificationEntry.h"
#include "FortNotificationEntry_ReceivedItem.generated.h"

class UCommonTextBlock;
class UFortItemDefinition;
class UFortLazyImage;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortNotificationEntry_ReceivedItem : public UFortNotificationEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateVisuals(const UFortItemDefinition* RewardItem, int32 ItemQuantity);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RewardType;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortNotificationEntry_ReceivedItem", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Header;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Reward_Preview;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Reward_Preview_Shadow;

};

