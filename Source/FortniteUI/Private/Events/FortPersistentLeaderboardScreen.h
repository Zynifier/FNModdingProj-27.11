// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CommonButtonLegacy.h"
#include "Events/FortCompetitiveLeaderboardScreen.h"
#include "Showdown/FortShowdownDetailView.h"
#include "FortPersistentLeaderboardScreen.generated.h"

class UCommonActionWidget;
class UCommonActivatableWidgetSwitcher;
class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortArenaPersonalViewTab;

UCLASS(Abstract, meta=(DisableNativeTick))
class UChallengeScreenCategoryTab : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TabName;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortPersistentLeaderboardScreen : public UFortCompetitiveLeaderboardScreen
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnColorize(FFortTournamentDisplayInfo ColorInfo);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLeaderboardTabsLoaded(bool bNoLeaderboardTabs);

	UFUNCTION(BlueprintImplementableEvent)
	void SetupForEvent(const FString& EventId, const FString& EventWindowId);

	UPROPERTY(EditAnywhere, Category="FortPersistentLeaderboardScreen")
	bool bAllowMeTab;

	UPROPERTY(EditDefaultsOnly, Category="FortPersistentLeaderboardScreen", meta=(RowType="/Script/FortniteUI.FortEventStyleInfo"))
	FDataTableRowHandle ColorSchemeRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="FortPersistentLeaderboardScreen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle TabViewLeftAction;

	UPROPERTY(EditDefaultsOnly, Category="FortPersistentLeaderboardScreen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle TabViewRightAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Close;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPersistentLeaderboardScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="ChallengeScreenCategoryTab"))
	TObjectPtr<UDynamicEntryBox> EntryBox_ViewButtons;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> ActionWidget_TabLeft;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> ActionWidget_TabRight;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_ViewTabs;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPersistentLeaderboardScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortArenaPersonalViewTab> ActivatableContent_MeViewTab;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> GlobalTabButton;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> MeTabButton;

private:
	UFUNCTION()
	void HandleViewTabSelectionChanged(UCommonButtonLegacy* TabButton, int32 TabIdx);

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupLegacy> ViewButtonGroup;

};

