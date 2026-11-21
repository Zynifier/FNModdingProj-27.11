// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CommonActivatablePanelLegacy.h"
#include "Online/FortStatsPageManager.h"
#include "AthenaCareerScreen.generated.h"

class UAthenaFeatTimelineListView;
class UAthenaLeaderboardScreenBase;
class UAthenaReplayBrowserScreenBase;
class UBacchusCloseButton;
class UCommonButtonBase;
class UCommonTextBlock;
class UImage;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UAthenaCareerScreen : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	TArray<FString> GetSeasonNames();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleStatsLoaded(const bool Success);

	UFUNCTION(BlueprintCallable)
	void OpenReplaysScreen();

	UFUNCTION(BlueprintImplementableEvent)
	void PopulateScreenData(const FStatPageData Data);

	UFUNCTION(BlueprintCallable)
	FStatPageData RequestScreenData(const FString& SeasonName, const bool bRanked, const FString& GameMode, const FString& SubMode);

	UFUNCTION(BlueprintCallable)
	void RequestToUpdateSeasonStatsIfNeeded(const FString& SeasonName);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowFeats(bool bHasCompletedFeats);

	UPROPERTY(EditAnywhere, Category="AthenaCareerScreen")
	TSoftClassPtr<UAthenaLeaderboardScreenBase> LeaderboardsScreenClass;

	UPROPERTY(EditAnywhere, Category="AthenaCareerScreen")
	TSoftClassPtr<UAthenaReplayBrowserScreenBase> ReplayBrowserScreenClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaCareerScreen")
	FDataTableRowHandle BackToSocialTabInputActionRowHandle;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_AccountLevel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Leaderboards;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Replays;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaFeatTimelineListView> ListView_FeatTimeline;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ChapterContext;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBacchusCloseButton> Button_TouchClose;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MobileTabLabel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_LeftFill;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_RightFill;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Gradient;

};

