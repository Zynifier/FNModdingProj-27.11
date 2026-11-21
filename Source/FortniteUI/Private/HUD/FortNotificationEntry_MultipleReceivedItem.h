// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "HUD/FortNotificationEntry.h"
#include "FortNotificationEntry_MultipleReceivedItem.generated.h"

class UCommonTextBlock;
class UFortItemDefinition;
class UFortLazyImage;
class UFortMultipleReceivedItemWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortMultipleReceivedItemWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateVisuals(const UFortItemDefinition* RewardItem, int32 ItemQuantity);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="FortMultipleReceivedItemWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Reward_Preview;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="FortMultipleReceivedItemWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Reward_Preview_Shadow;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortNotificationEntry_MultipleReceivedItem : public UFortNotificationEntry
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortNotificationEntry_MultipleReceivedItem", meta=(BindWidget))
	bool bWillReceiveBonus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="FortNotificationEntry_MultipleReceivedItem", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Header;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="FortNotificationEntry_MultipleReceivedItem", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMultipleReceivedItemWidget> DisplayItem_1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="FortNotificationEntry_MultipleReceivedItem", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMultipleReceivedItemWidget> DisplayItem_2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="FortNotificationEntry_MultipleReceivedItem", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMultipleReceivedItemWidget> DisplayItem_3;

};

