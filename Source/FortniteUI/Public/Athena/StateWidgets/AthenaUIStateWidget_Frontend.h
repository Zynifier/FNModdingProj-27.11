// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/PrimaryAssetId.h"
#include "Social/FortSocialPanelContainerInterface.h"
#include "UIManager/FortUIStateWidgetBase.h"
#include "AthenaUIStateWidget_Frontend.generated.h"

class AFortFrontEndMiniMapManager;
class UApolloIntroLoadingPanel;
class UAthenaConfirmationWindow;
class UAthenaMapScreenContainer;
class UAthenaTopBar;
class UCommonButtonLegacy;
class UCommonUserWidget;
class UEnableMultiFactorModal;
class UFireModeSelectionReminderModal;
class UFireModeSelectionScreen;
class UFortActivatableChatWidget;
class UFortActivatableMovieWidget;
class UFortAthenaTabsScreenBase;
class UFortDiscoverSurfaceCache;
class UFortDualBladeMenu;
class UFortEnterCabinModal;
class UFortGiftBoxItem;
class UFortMPLobbyOnboardingModal;
class UFortPlayerBanned;
class UFortReviewYourSettingsModal;
class UFortSocialImportPanel;
class UFortStreamMediaSource;
class UGuidedTutorialLoadingScreen;
class UHabaneroIntroModal;
class UMediaPlayer;
class UOverlay;
class UResolutionChangeModal;
class USocialParty;
class UUserWidget;
enum class EFrontendVisibilityMode : uint8;

UENUM()
enum class EOptionalFlowSteps : uint8
{
	TryShowMobileGuidedTutorial = 0,
	TryPlaySeasonTrailer = 1,
	TryPlayBattlePassTrailer = 2,
	TryShowMOTDs = 3,
	TryShowNormalBanModal = 4,
	TryShowSocialBanModal = 5,
	TryShowMFAModal = 6,
	TryShowCrossplayDialog = 7,
	TryShowSocialImport = 8,
	TryShowSurveys = 9,
	TryShowFireModeModal = 10,
	TryShowBadMatchPopup = 11,
	TryShowMobileInGameAppRating = 12,
	TryShowSamsungSensorWarning = 13,
	TryShowBattlePassPurchaseScreen = 14,
	TryShowMultipleSubscriptionsAlert = 15,
	TryPushGiftingScreen = 16,
	TryPushMessagingScreen = 17,
	TryGoToBattlePassTab = 18,
	TryShowRefundTokenNotification = 19,
	TryShowPriceChangeAcknowledgeNotification = 20,
	TryShowFireModeSelectionReminderModal = 21,
	TryShowSettingsChangeAcknowledgementScreen = 22,
	TryShowMatchmaking = 23,
	TryShowEnterCabinModeScreen = 24,
	TryShowHabaneroIntroModal = 25,
	TryShowVoiceReportingIntroModal = 26,
	TryShowContentGatingIntroModal = 27,
	TryShowResolutionChangeModal = 28,
};

UCLASS(Abstract, Config=Game, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaUIStateWidget_Frontend : public UFortUIStateWidgetBase, public IFortSocialPanelContainerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsFrontendFree() const;

	UFUNCTION(BlueprintPure)
	bool IsLobbyVisible() const;

	UFUNCTION(BlueprintCallable)
	void ShowGameTabGroup(bool bShow);

	UFUNCTION(BlueprintCallable)
	void TryShowingMPLobbyOnboardingModal();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void DisplayDebugFlowText(const FText& DebugFlowText);

	UFUNCTION(BlueprintImplementableEvent)
	void HideDebugFlowText();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetFrontendVisibilityMode(EFrontendVisibilityMode InFrontendVisibilityMode);

	UFUNCTION(BlueprintCallable)
	void SetVideoActive(bool bActive);

	UFUNCTION(BlueprintImplementableEvent)
	void StartTrailerTransitionAudioCheck(UMediaPlayer* MediaPlayer);

	UFUNCTION(BlueprintImplementableEvent)
	void StopTrailerTransitionAudioCheck();

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	FText BadMatchPopupTitle;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend", meta=(MultiLine="TRUE"))
	FText BadMatchPopupDescription;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend", meta=(AllowPrivateAccess, Categories="ERG.Screen"))
	FGameplayTag BattlepassScreenTag;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	TSoftClassPtr<UFireModeSelectionReminderModal> FireModeSelectionReminderModalClass;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	TSoftClassPtr<UFireModeSelectionScreen> FireModeSelectionScreenClass;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	TSoftClassPtr<UUserWidget> MotdWidgetClass;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	TSubclassOf<UFortReviewYourSettingsModal> SettingsUpdatedClass;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	TSubclassOf<UFortEnterCabinModal> EnterCabinClass;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	TSoftClassPtr<UFortActivatableMovieWidget> VideoPlayerClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaUIStateWidget_Frontend")
	TObjectPtr<UFortStreamMediaSource> VideoStream_Source;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	TSoftClassPtr<UEnableMultiFactorModal> MFAModalClass;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	TSubclassOf<UFortSocialImportPanel> SocialImportPanelClass;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	TSubclassOf<UAthenaConfirmationWindow> ConfirmationWindowClass;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	TSubclassOf<AFortFrontEndMiniMapManager> MiniMapManagerClass;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	TSubclassOf<UAthenaMapScreenContainer> MapScreenContainerClass;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	TSubclassOf<UHabaneroIntroModal> HabaneroIntroModalClass;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	TSoftClassPtr<UResolutionChangeModal> ResolutionChangeModalClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaUIStateWidget_Frontend")
	TSubclassOf<UFortMPLobbyOnboardingModal> MPLobbyOnboardingModalClass;

private:
	UFUNCTION()
	void HandleToggleFullscreenMap(bool bFullscreenMapVisible);

	UPROPERTY(Config)
	TArray<FString> DefaultFlowStepArray;

	UPROPERTY(Config)
	TArray<FString> FirstTimeSeasonFlowStepArray;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	TSubclassOf<UGuidedTutorialLoadingScreen> GuidedTutorialFakeLoadingScreenClass;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	FPrimaryAssetId GuidedTutorialPlaylistId;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortGiftBoxItem>> PendingRemovalGiftboxes;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortAthenaTabsScreenBase> AthenaTabsScreen;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	TSubclassOf<UFortPlayerBanned> PlayerBannedScreenClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaMapScreenContainer> MapScreen;

	UPROPERTY(BlueprintReadWrite, Category="AthenaUIStateWidget_Frontend", meta=(AllowPrivateAccess="TRUE"))
	bool bVideoActive;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaUIStateWidget_Frontend", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaTopBar> TopBar_Widget;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaUIStateWidget_Frontend", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonUserWidget> BottomBar;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaUIStateWidget_Frontend", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortActivatableChatWidget> ChatPanel_Widget;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaUIStateWidget_Frontend", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_ToggleChat;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDualBladeMenu> DualBladeMenu_Widget;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_DynamicExtensions;

	UPROPERTY(Transient)
	TObjectPtr<UFortGiftBoxItem> NextGiftBox;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<UFortGiftBoxItem>> RequestedGiftBoxesToDisplay;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	FPrimaryAssetId ApolloIntroPlaylist_CurrentPlayerId;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	FPrimaryAssetId ApolloIntroPlaylist_PastPlayerId;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	FPrimaryAssetId ApolloIntroPlaylist_NewPlayerId;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	FPrimaryAssetId ApolloIntroPlaylist_05H95BId;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	FPrimaryAssetId ApolloIntroPlaylist_20H80BId;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	FPrimaryAssetId ApolloIntroPlaylist_30H70BId;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	FPrimaryAssetId ApolloIntroPlaylist_40H60BId;

	UPROPERTY(EditAnywhere, Category="AthenaUIStateWidget_Frontend")
	TSoftClassPtr<UApolloIntroLoadingPanel> ApolloIntroFakeLoadingScreenClass;

	UPROPERTY()
	USocialParty* CurrentSocialParty;

	UPROPERTY(Transient)
	TObjectPtr<UFortDiscoverSurfaceCache> DiscoverSurfaceCache;

};

