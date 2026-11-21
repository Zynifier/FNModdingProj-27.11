// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/DataDrivenServiceTypes.h"
#include "FortConversationOptionBrief.h"
#include "FortDataDrivenServiceBrief.generated.h"

class UCommonRichTextBlock;
class UCommonTextBlock;
class UFortItem;
class UFortTransactionStrip;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortDataDrivenServiceBrief : public UFortConversationOptionBrief
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnAbleToPurchase();

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnTransactionInfoReceived(UFortItem* Item);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnUnableToPurchase(const FText& Reason);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TitleBar;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_StockRemaining;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortTransactionStrip> TransactionStrip_Main;

	UPROPERTY(EditAnywhere, Category="FortDataDrivenServiceBrief")
	TMap<FName, FDataDrivenServiceBriefConfig> ServiceConfigs;

};

