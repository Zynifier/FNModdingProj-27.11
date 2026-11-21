// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "SpatialStyleChallengeUnlockReason.generated.h"

class UCommonRichTextBlock;
class UHorizontalBox;
class UProgressBar;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaSpatialStyleChallengeUnlockReason : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnUnlockReasonUpdated(bool bInUnlocked);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowBattlepassLevelReason(int32 InLevel);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowBattlepassPurchaseReason(const FText& InSeason);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateMissionProgressCount(int32 CompletedCount, int32 RequiredCount);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpatialStyleChallengeUnlockReason", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HBox_MissionProgress;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UProgressBar> ProgressBar_PercentComplete_Front;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UProgressBar> ProgressBar_PercentComplete_Back;

};

