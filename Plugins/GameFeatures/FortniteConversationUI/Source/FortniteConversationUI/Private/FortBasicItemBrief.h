// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/DataDrivenServiceTypes.h"
#include "FortConversationOptionBrief.h"
#include "FortBasicItemBrief.generated.h"

class UCommonTextBlock;
class UFortItem;
class UFortTransactionStrip;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortBasicItemBrief : public UFortConversationOptionBrief
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnAbleToUse(const bool bShowWarningMessage);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnItemInfoReceived(UFortItem* Item, int32 StackSize);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnUnableToUse(const FText& Reason);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnUpdateDescriptionText(const FText& DescriptionText);

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TitleBar;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBasicItemBrief", meta=(AllowPrivateAccess="true", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortTransactionStrip> TransactionStrip_Main;

	UPROPERTY(Transient)
	TObjectPtr<UFortItem> DisplayItem;

	UPROPERTY(EditAnywhere, Category="FortBasicItemBrief")
	TMap<FName, FDataDrivenServiceBriefConfig> ServiceConfigs;

};

