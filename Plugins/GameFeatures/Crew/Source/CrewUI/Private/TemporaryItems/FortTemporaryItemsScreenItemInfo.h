// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortTemporaryItemsScreenItemInfo.generated.h"

class UAthenaRewardItemTypeRarityTag;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UFortSubscriptionVM;
class UFortTemporaryItemsRewardVM;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortTemporaryItemsScreenItemInfo : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetData(const UFortSubscriptionVM* SubscriptionVM, const UFortTemporaryItemsRewardVM* RewardVM);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDataSet(bool bValidItem, bool bIsSubscribed, bool IsOwned);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortTemporaryItemsScreenItemInfo", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaRewardItemTypeRarityTag> Widget_ItemTypeRarityTag;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTemporaryItemsScreenItemInfo", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Description;

};

