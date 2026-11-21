// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "Blueprint/UserWidget.h"
#include "FortEventRewardTracksWidget.generated.h"

class UDynamicEntryBox;
class UFortEventScreenData;

UCLASS(Abstract, NotBlueprintable, meta=(DisableNativeTick))
class UFortEventListViewWidgetBase : public UUserWidget, public IUserListEntry
{
	GENERATED_BODY()

public:
	UFortEventListViewWidgetBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortEventRewardTracksWidget : public UFortEventListViewWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Event Screen Data Set"))
	void BPOnEventScreenDataSet(const UFortEventScreenData* InEventScreenData);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Set Reward Item"))
	void BPOnSetRewardItem(const int32 RequiredProgress, const int32 RemainingProgress, const float RewardProgressPercent, const float PreviewProgressPercent, const float OverallProgressPercent, const bool bInPreviewMode);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Set All Rewards Collected"))
	void BPSetAllRewardsCollected(const bool bAllCollected);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Set Progress Percent"))
	void BPSetProgressPercent(const float Percent);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventRewardTracksWidget", meta=(BindWidget, EditInline="true"))
	UDynamicEntryBox* DynamicEntryBox_RewardTracks;

	UPROPERTY(BlueprintReadOnly, Category="FortEventRewardTracksWidget")
	bool bPreviewMode;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortEventSpacerWidget : public UFortEventListViewWidgetBase
{
	GENERATED_BODY()

};

