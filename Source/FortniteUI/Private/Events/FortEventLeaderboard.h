// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Events/FortCompetitiveLeaderboardScreen.h"
#include "Online/FortTournamentManagerTypes.h"
#include "FortEventLeaderboard.generated.h"

class UCommonActionWidget;
class UCommonButtonBase;
class UCommonButtonGroupBase;
class UScrollBox;

USTRUCT()
struct FFortLeaderboardRequestIds
{
	GENERATED_BODY()

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortEventLeaderboardScreen : public UFortCompetitiveLeaderboardScreen
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void InitializeTabButton(UCommonButtonBase* TabButton, const FText& TabText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDetailsPanelUpdate(bool bShowDetailsPanel);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowLeaderboard();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTabVisibilityChange(bool bIsVisible);

	UPROPERTY(BlueprintReadOnly, Category="Event")
	ETournamentDisplayType EventDisplayType;

	UPROPERTY(EditDefaultsOnly, Category="FortEventLeaderboardScreen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle TabViewLeftAction;

	UPROPERTY(EditDefaultsOnly, Category="FortEventLeaderboardScreen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle TabViewRightAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_ViewButtons;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> ActionWidget_TabLeft;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> ActionWidget_TabRight;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventLeaderboardScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ViewLiveGames;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortEventLeaderboardScreen")
	TObjectPtr<UCommonButtonGroupBase> ViewButtonGroup;

	UPROPERTY(EditDefaultsOnly, Category="FortEventLeaderboardScreen")
	TSubclassOf<UCommonButtonBase> TabsClass;

private:
	UFUNCTION()
	void HandleViewTabSelectionChanged(UCommonButtonBase* TabButton, int32 TabIdx);

	UPROPERTY()
	TMap<TObjectPtr<UCommonButtonBase>, FFortLeaderboardRequestIds> TabButtonsToLeaderboardsIds;

	UPROPERTY(BlueprintReadOnly, Category="FortEventLeaderboardScreen", meta=(AllowPrivateAccess="true"))
	bool bIsMainLeaderboardNonWindow;

};

