// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CommonActivatablePanelLegacy.h"
#include "FrontEnd/Habanero/FortHabaneroDisplayData.h"
#include "Online/FortStatsPageManager.h"
#include "AthenaCareerStatsScreen.generated.h"

class UAthenaReplayBrowserScreenBase;
class UBacchusCloseButton;
class UCommonTextBlock;
class UFortHabaneroDisplayData;
class UFortHabaneroTierWidget;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UAthenaCareerStatsScreen : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void DisplayRankBadge(const FString& HabaneroType, const int32 Habanero);

	UFUNCTION(BlueprintCallable)
	void GetLoadedScreenData(const FString& SeasonName, const bool bRanked, const FString& GameMode, const FString& SubMode, FStatPageData& StatPageData, bool& bSuccess);

	UFUNCTION(BlueprintPure)
	FFortHabaneroTier GetRankDisplayData(const FString& HabaneroType, const int32 Habanero);

	UFUNCTION(BlueprintPure)
	TArray<FString> GetSeasonNames();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleRanksLoaded(const bool Success);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleStatsLoaded(const bool Success);

	UFUNCTION(BlueprintCallable)
	void OpenReplaysScreen();

	UFUNCTION(BlueprintCallable)
	void RequestToUpdateSeasonStatsIfNeeded(const FString& SeasonName);

	UPROPERTY(EditAnywhere, Category="AthenaCareerStatsScreen")
	TSoftClassPtr<UAthenaReplayBrowserScreenBase> ReplayBrowserScreenClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaCareerStatsScreen")
	FDataTableRowHandle BackToSocialTabInputActionRowHandle;

private:
	UFUNCTION(BlueprintPure)
	void GetReplaysButtonDesiredState(bool& bVisible, bool& bEnabled);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_AccountLevel;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBacchusCloseButton> Button_TouchClose;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MobileTabLabel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortHabaneroTierWidget> WBP_Habanero_Icon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaCareerStatsScreen", meta=(AllowPrivateAccess))
	TObjectPtr<UFortHabaneroDisplayData> HabaneroDisplayData;

};

