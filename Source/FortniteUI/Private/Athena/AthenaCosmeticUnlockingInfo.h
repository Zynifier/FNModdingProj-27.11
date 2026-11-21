// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "AthenaCosmeticUnlockingInfo.generated.h"

class UAthenaCosmeticItemDefinition;
class UCommonRichTextBlock;
class UFortItemDefinition;
class UProgressBar;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaCosmeticUnlockingInfo : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void HideUnlockingInfo();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUnlockingInfoSet(bool bShowProgression);

	UFUNCTION(BlueprintCallable)
	void ShowSeasonUnlockingInfo(int32 SeasonNumber, int32 TierNumber);

	UFUNCTION(BlueprintCallable)
	void ShowUnlockingInfo(UAthenaCosmeticItemDefinition* UnlockItem, UFortItemDefinition* UnlockSource);

	UFUNCTION(BlueprintCallable)
	void ShowUnlockingInfoForCosmetic(const UAthenaCosmeticItemDefinition* InCosmeticItemDef);

	UFUNCTION(BlueprintCallable)
	void ShowUnlockingInfoForCosmeticVariant(const UAthenaCosmeticItemDefinition* InCosmeticItemDef, const FGameplayTag& InVariantChannel, const FGameplayTag& InVariant);

protected:
	UFUNCTION(BlueprintCallable)
	void OutroAnimFinished();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void RequestIntroAnim();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void RequestOutroAnim();

	UFUNCTION(BlueprintImplementableEvent)
	void RequestUpdateAnim();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_StaticUnlockingText;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_UnlockingText;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UProgressBar> ProgressBar_StepsCompleted;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_ProgressCompletion;

	UPROPERTY(EditDefaultsOnly, Category="Style")
	FString EmphasisStyle;

	UPROPERTY(EditDefaultsOnly, Category="Style")
	FString ProgressCompletionNumericStyle;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaCosmeticItemDefinition> CosmeticItemDef;

};

