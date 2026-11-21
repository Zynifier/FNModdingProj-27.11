// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "ConversationContext.h"
#include "Conversation/DataDrivenServiceTypes.h"
#include "FortItemFundBrief.generated.h"

class UCommonTextBlock;
class UFortLazyImage;
class UFortSimpleMaterialProgressBar;
class UFortTransactionStrip;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortItemFundBrief : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void InitializeFromContext(const FConversationContext& ConversationContext);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIntializationComplete();

	UFUNCTION(BlueprintImplementableEvent)
	void OnProgressUpdated(const float CurrentFundingFraction);

private:
	UFUNCTION(BlueprintCallable)
	const FText GetDataForKey(const FString Key, const bool bUseIndexAdjustment = false);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemFundBrief", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TitleBar;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemFundBrief", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ProgressPercent;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemFundBrief", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ProgressCount;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemFundBrief", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortSimpleMaterialProgressBar> Progress_Funding;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemFundBrief", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_Icon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemFundBrief", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortTransactionStrip> TransactionStrip_Main;

	UPROPERTY(EditAnywhere, Category="FortItemFundBrief")
	TMap<FName, FDataDrivenServiceBriefConfig> ServiceConfigs;

};

