// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "Blueprint/UserWidget.h"
#include "CommonInputTypeEnum.h"
#include "FortEventScreenData.h"
#include "FortEventRewardWidget.generated.h"

class UCommonButtonBase;
class UFortCosmeticItemCard;
class UFortEventScreenData;
class UTexture2D;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortEventRewardWidget : public UUserWidget, public IUserListEntry
{
	GENERATED_BODY()

public:
	UFortEventRewardWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRewardWidgetReset();

	UFUNCTION(BlueprintImplementableEvent)
	void SetAllRewardsCollected(const bool bAllCollected);

	UFUNCTION(BlueprintImplementableEvent)
	void SetDoubleWidth(const bool bDoubleWidth);

	UFUNCTION(BlueprintImplementableEvent)
	void SetInPreviewedState(const bool bPreviewed);

	UFUNCTION(BlueprintImplementableEvent)
	void SetInSelectedState(const bool bSelected);

	UFUNCTION(BlueprintImplementableEvent)
	void SetProgressPercent(const float Percent);

protected:
	UFUNCTION(BlueprintPure)
	const UFortEventScreenData* GetEventScreenData() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnEventScreenDataSet(const UFortEventScreenData* InEventScreenData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnInputMethodChanged(const ECommonInputType NewInputType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetRewardItem(const int32 RequiredProgress, const int32 RemainingProgress, const float RewardProgressPercent, const float PreviewProgressPercent, const float OverallProgressPercent, const bool bInPreviewMode);

	UFUNCTION(BlueprintImplementableEvent)
	void SetCustomItemIcon(const UTexture2D* CustomItemIcon);

	UFUNCTION(BlueprintImplementableEvent)
	void SetInPremiumUpgradeState(const bool bHighlighted);

	UFUNCTION(BlueprintImplementableEvent)
	void SetInPreviewSelectedState(const bool bSelected);

	UFUNCTION(BlueprintImplementableEvent)
	void SetIsBannerItem(const bool bIsBanner);

	UFUNCTION(BlueprintImplementableEvent)
	void SetTrackData(const FEventScreenTrackData& TrackData, const bool bIsOwned);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventRewardWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_RewardPreview;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventRewardWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCosmeticItemCard> UserWidget_ItemCard;

	UPROPERTY(BlueprintReadOnly, Category="FortEventRewardWidget")
	bool bIsTrackOwned;

	UPROPERTY(BlueprintReadOnly, Category="FortEventRewardWidget")
	bool bPreviewMode;

	UPROPERTY(BlueprintReadOnly, Category="FortEventRewardWidget")
	bool bInPreviewSelectedState;

	UPROPERTY(BlueprintReadOnly, Category="FortEventRewardWidget")
	bool bInPremiumUpgradeState;

};

