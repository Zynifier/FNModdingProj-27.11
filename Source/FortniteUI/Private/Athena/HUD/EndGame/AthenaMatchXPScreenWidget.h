// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Misc/Timespan.h"
#include "Athena/HUD/EndGame/FortPostGameScreen.h"
#include "AthenaMatchXPScreenWidget.generated.h"

class UAthenaIGMSquadDisplayWidget;
class UAthenaPostMatchPanel;
class UAthenaPreserveSquadButton;
class UAthenaSkewedTabButton;
class UCommonButtonBase;
class UCommonTextBlock;
class UCommonUserWidget;
class UCommonVisibilitySwitcher;
class UFortCTAButton;
class UFortPostGameMenuListView;
class UHorizontalBox;
class USizeBox;
class UUserWidget;
class UVerticalBox;
class UWidget;
enum class EKeepPlayingTogetherVotingStatus : uint8;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UAthenaMatchXPScreenWidget : public UFortPostGameScreen
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnXPScreenFinishedLoading);

protected:
	UFUNCTION(BlueprintCallable)
	void AutoAdvanceToNextTab();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Toggle Spectating"))
	void BP_OnToggleSpectating();

	UFUNCTION(BlueprintCallable)
	void FocusOnDesiredTarget();

	UFUNCTION()
	void HandleActiveTabWidgetReady(UAthenaPostMatchPanel* PostMatchPanel);

	UFUNCTION()
	void HandleResurrectingNow(bool bResurrectingNow);

	UFUNCTION()
	void HandleToggleFullscreenMap(bool bFullscreenMapVisible);

	UFUNCTION()
	void HandleXPRecapFadeOutOverlay();

	UFUNCTION(BlueprintImplementableEvent)
	void OnAutoAdvanceSequenceFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnAutoAdvanceTimeRemainingUpdated(int32 TimeRemaining);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCancelReadyUp();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDefaultTabWidgetReady();

	UFUNCTION(BlueprintImplementableEvent)
	void OnExitToLobbyCountdownProgressed(int32 CountdownValue);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingCancelled();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingCountdownProgressed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingCountdownStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingErrorMessage(const FText& Message);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingFinished(bool bSuccess);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingUpdate(FTimespan ElapsedTime);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Show Tabs Set"))
	void OnShowTabsSet(bool bShowTabs);

	UFUNCTION(BlueprintCallable)
	void SelectActiveTabWidget();

	UFUNCTION(BlueprintImplementableEvent)
	void SetMemberOptedOutState(const EKeepPlayingTogetherVotingStatus& Status, const FText& MainContext, const FText& SecondaryContext);

	UFUNCTION(BlueprintImplementableEvent)
	void SetStatButtonText(const FText& InText);

	UFUNCTION(BlueprintNativeEvent)
	bool ShouldShowReadyUp() const;

	UFUNCTION()
	void SpectatorStreamingChanged(bool bSpectatorStreaming);

	UPROPERTY(EditAnywhere, Category="AthenaMatchXPScreenWidget")
	bool bAutoTransitionScreen;

private:
	UFUNCTION(BlueprintPure)
	bool IsSpectating() const;

	UFUNCTION()
	void UpdateElementsVisibility();

	UFUNCTION()
	void UpdateTabVisibility();

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMatchXPScreenWidget", meta=(AllowPrivateAccess))
	TWeakObjectPtr<UCommonUserWidget> DefaultTabWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMatchXPScreenWidget", meta=(AllowPrivateAccess, EditInline="true"))
	TMap<FName, TObjectPtr<UAthenaSkewedTabButton>> TabButtons;

	UPROPERTY(EditAnywhere, Category="AthenaMatchXPScreenWidget")
	FText ReadyUpStartText;

	UPROPERTY(EditAnywhere, Category="AthenaMatchXPScreenWidget")
	FFortPostGameScreenConfig SpectatePostGameScreenConfig;

	UPROPERTY(EditAnywhere, Category="AthenaMatchXPScreenWidget")
	TArray<TSoftClassPtr<UUserWidget>> DefaultTabs;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMatchXPScreenWidget", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle NextTabInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMatchXPScreenWidget", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PreviousTabInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMatchXPScreenWidget", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle NextPlayerInputAction_ModularProgression;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMatchXPScreenWidget", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PreviousPlayerInputAction_ModularProgression;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMatchXPScreenWidget", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle NextTeammateInputAction_ModularProgression;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMatchXPScreenWidget", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PreviousTeammateInputAction_ModularProgression;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMatchXPScreenWidget", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ReturnToIslandInputAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> VisibilitySwitcher_Content;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MatchmakingStatus;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMatchXPScreenWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> TabButtonsContainer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMatchXPScreenWidget", meta=(AllowPrivateAccess="TRUE"))
	TSubclassOf<UUserWidget> TabButtonClass;

	UPROPERTY(EditAnywhere, Category="AthenaMatchXPScreenWidget")
	FDataTableRowHandle ToggleMapInputAction;

	UPROPERTY(Transient)
	int32 NumWidgetsFinished;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaPreserveSquadButton> Button_StayTogether;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> VisibilitySwitcher_NextMatch;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_NextMatch;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PlayWithNewTeam;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PrevPlayer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_NextPlayer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PrevTeam;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_NextTeam;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Cancel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Leto_IGMMWrapper;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UVerticalBox> VBox_MatchMaking;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UVerticalBox> VBox_NavButtons;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMatchXPScreenWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBoxNavigationOptions;

	UPROPERTY(EditDefaultsOnly, Category="AthenaMatchXPScreenWidget")
	int32 ToLobbyDelayOnError;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCTAButton> MenuEntry_DisabledStayWithSquad;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMatchXPScreenWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortPostGameMenuListView> ListView_KeepPlayingTogetherMenu;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMatchXPScreenWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortPostGameMenuListView> ListView_PostGameMenu;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMatchXPScreenWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Content_MemberOptedOut;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_DisplayTooltip;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_ReadyUpTooltip;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaIGMSquadDisplayWidget> SquadDisplayWidget;

};

