// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortConversationOptionBrief.h"
#include "FortRarityData.h"
#include "FortQuestBrief.generated.h"

class UCommonLazyImage;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UOverlay;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortQuestBrief : public UFortConversationOptionBrief
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnQuestExpirationTimeSet(const bool bDisplayExpirationTime);

	UFUNCTION(BlueprintImplementableEvent)
	void OnQuestInformationRecieved(const FText& Objective, const FFortRarityItemData& RarityData, const FGameplayTag& CategoryTag, int32 XPReward, int32 MoneyReward);

	UPROPERTY(EditAnywhere, Category="FortQuestBrief")
	FText ThisMatchOnlyQuestText;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestBrief", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_Objective;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestBrief", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MoneyReward;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestBrief", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_XpReward;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestBrief", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ExpirationTime;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestBrief", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> LazyImage_QuestProviderImage;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestBrief", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_QuestProvider;

};

