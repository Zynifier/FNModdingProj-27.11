// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Layout/Geometry.h"
#include "FortMatchmakingWidgetBase.h"
#include "FortMatchmakingWidgetExtensionInterface.h"
#include "FortPlaylistTypes.h"
#include "FortAthenaMatchmakingWidget.generated.h"

class UAthenaMatchmakingViolator;
class UCommonTextBlock;
class UFortCTAButton;
class UFortCampaignReadyScreen;
class UFortGameActivity;
class UFortHabaneroDisplayData;
class UFortMatchmakingSuggestionWidget;
class UFortPlaylistAthena;
class UFortShowdownDetailView;
class UFortUEKittWidget;
class UHabaneroModeAnimatedMessage;
enum class EFortLobbyType : uint8;
enum class EFortMatchmakingViolatorStyle : uint8;
enum class EHabaneroDisplayState : uint8;

UENUM(BlueprintType)
enum class EHabaneroDisplayState : uint8
{
	Solo = 0,
	Party = 1,
	Hidden = 2,
};

UCLASS(Abstract, Config=Game, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortAthenaMatchmakingWidgetLegacy : public UFortMatchmakingWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	const FGeometry OnGetPlayButtonCachedGeometry() const;

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	bool OnGetPlayButtonEnabled() const;

protected:
	UFUNCTION(BlueprintPure, Category="MatchmakingWidget")
	FGameSelectionButtonInfo GetButtonModeSetTextFromIslandExtension() const;

	UFUNCTION(BlueprintNativeEvent)
	FText GetButtonPrivateMatchText() const;

	UFUNCTION(BlueprintNativeEvent)
	FText GetButtonPublicMatchText() const;

	UFUNCTION(BlueprintPure, Category="MatchmakingWidget")
	FText GetCreativeModeSelectText() const;

	UFUNCTION(BlueprintPure, Category="MatchmakingWidget")
	FText GetFillStatusText() const;

	UFUNCTION(BlueprintPure, Category="MatchmakingWidget")
	FText GetPrivateMatchText() const;

	UFUNCTION(BlueprintPure, Category="MatchmakingWidget")
	FText GetSinglePlayerMatchText() const;

	UFUNCTION(BlueprintCallable, Category="MatchmakingWidget")
	void HandlePrivateMatchClicked();

	UFUNCTION(BlueprintCallable, Category="MatchmakingWidget")
	void HandleSquadFillClicked();

	UFUNCTION(BlueprintPure, Category="MatchmakingWidget")
	bool IsAnyCreativeModeSelectActivity() const;

	UFUNCTION(BlueprintPure)
	bool IsPrivateMatchEnabled() const;

	UFUNCTION(BlueprintPure, Category="MatchmakingWidget")
	bool IsSinglePlayerActivity() const;

	UFUNCTION(BlueprintPure)
	bool IsSquadFillEnabled() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnAvailablePlaylistsUpdated();

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnBlackoutCountdownText(const FText& Text);

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnBlackoutCountdownVisibility(bool bVisible);

	UFUNCTION(BlueprintCallable, Category="MatchmakingWidget")
	void OnCancelClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void OnHabaneroStateUpdated(const bool bIsHabaneroEnabled, const bool bIsHabaneroIsland);

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnIslandChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLocalPlayerPromotedToLeader();

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnLocalPlayerSittingOut();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Matchmaking Finished"))
	void OnMatchmakingFinishedBlueprint(bool bSuccess, const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable, Category="MatchmakingWidget")
	void OnMatchmakingModeButtonClicked();

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnModeLockedVisibility(bool bVisible);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayButtonLockStateChanged(const bool bLockState);

	UFUNCTION(BlueprintCallable, Category="MatchmakingWidget")
	void OnPlayClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreStartMatchmaking();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPrivateMatchButtonEnabledStateUpdated(const bool bIsLocalPlayerPartyLeader, const bool bIsMatchmaking);

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnPrivateMatchTextChanged(const FText& Text);

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnSetCancelButtonEnabled(bool bEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetCancelButtonText(const FText& CancelButtonText);

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnSetCancelButtonVisibility(bool bVisible);

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnSetContentBeaconDownloadVisibility(bool bVisible);

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnSetContentDownloadProgressBar(float Progress);

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnSetContentDownloadProgressText(const FText& Text);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetHabaneroText(const FText& HabaneroString, const EHabaneroDisplayState& State);

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnSetMatchmakingHeaderText(const FText& Text);

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnSetMatchmakingMessageText(const FText& Text);

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnSetMatchmakingModeButtonEnabled(bool bEnabled);

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnSetMatchmakingModeButtonText();

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnSetPartySizeWarningText(const FText& Text);

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnSetPartySizeWarningVisibility(bool bVisible);

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnSetPlayButtonEnabled(bool bEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetPlayButtonSecondaryText(const FText& PlayButtonSecondaryText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetPlayButtonText(const FText& PlayButtonText);

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnSetPlayButtonVisibility(bool bVisible);

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnSetSquadFillButtonEnabled(const bool bEnabled);

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnSetSquadFillText(const FText& Text);

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnSetStartMatchButtonVisibility(bool bVisible);

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnSetViewDetailsButtonVisibility(bool bVisible);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowChildActivityFirstTimeNotification();

	UFUNCTION(BlueprintImplementableEvent, Category="MatchmakingWidget")
	void OnSocialUserSittingOut();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSquadFillButtonEnabledStateUpdated(const bool bIsLocalPlayerPartyLeader, const bool bIsMatchmaking);

	UFUNCTION(BlueprintCallable, Category="MatchmakingWidget")
	void OnStartMatchClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void OnViolatorStyleRefreshed(const EFortMatchmakingViolatorStyle NewViolatorStyle);

	UFUNCTION(BlueprintImplementableEvent)
	void PlaylistActivityChanged(const FPlaylistFrontEndData& NewPlaylist, const FText& ActivityName, EFortLobbyType LobbyType);

	UFUNCTION(BlueprintImplementableEvent)
	void PlaylistChanged(const FPlaylistFrontEndData& NewPlaylist, const FText& PlaylistCMSOverrideName, EFortLobbyType LobbyType);

	UFUNCTION(BlueprintCallable)
	void RequestPlay();

	UFUNCTION(BlueprintImplementableEvent)
	void SetShowingDiscoveryEntryFlowToolTip(bool bShowTooltip);

	UFUNCTION(BlueprintImplementableEvent)
	void SetShowingPartyHabaneroNotification(const bool bShowNotification);

	UFUNCTION(BlueprintImplementableEvent)
	void ShouldShowMatchmakingDetails(bool bShow);

	UFUNCTION(BlueprintCallable, Category="MatchmakingWidget")
	void ShowSelectedActivityDetailsPage();

	UPROPERTY(EditAnywhere, Category="FortAthenaMatchmakingWidgetLegacy")
	TSoftClassPtr<UHabaneroModeAnimatedMessage> HabaneroAnimatedMessageClass;

	UPROPERTY(EditAnywhere, Category="Habanero")
	TObjectPtr<UFortHabaneroDisplayData> HabaneroDisplayData;

	UPROPERTY(EditAnywhere, Category="FortAthenaMatchmakingWidgetLegacy")
	TSubclassOf<UFortUEKittWidget> UEKittWidgetSubclass;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortUEKittWidget> UEKittWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMatchmakingWidgetLegacy", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_FillStatus;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMatchmakingWidgetLegacy", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PrivateMatch;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMatchmakingWidgetLegacy", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_SquadFill;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMatchmakingWidgetLegacy", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_PrivateMatch;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMatchmakingWidgetLegacy", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortShowdownDetailView> ShowdownViolator;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMatchmakingWidgetLegacy", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UAthenaMatchmakingViolator> BasicViolator;

	UPROPERTY(Config)
	int8 MaxMatchmakingReminderTooltips;

	UPROPERTY(Config)
	FText FixedRankedSeasonText;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMatchmakingWidgetLegacy", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortMatchmakingSuggestionWidget> SuggestionWidget;

private:
	UFUNCTION()
	void HandleMatchMakingModeCalled(const FString& IslandMnemonic, const FName InPlaylistName);

	UPROPERTY(Transient)
	TObjectPtr<UFortGameActivity> CachedGameActivity;

	UPROPERTY(EditAnywhere, Category="FortAthenaMatchmakingWidgetLegacy")
	FText RegionLockTitle;

	UPROPERTY(EditDefaultsOnly, Category="Widget References")
	TSoftClassPtr<UFortCampaignReadyScreen> CampaignReadyScreenClass;

	UPROPERTY(BlueprintReadOnly, Category="FortAthenaMatchmakingWidgetLegacy", meta=(AllowPrivateAccess))
	bool bPlaylistHasSquadFillOption;

	UPROPERTY(BlueprintReadOnly, Category="FortAthenaMatchmakingWidgetLegacy", meta=(AllowPrivateAccess))
	bool bPlaylistCanFillWithParty;

	UPROPERTY(BlueprintReadOnly, Category="FortAthenaMatchmakingWidgetLegacy", meta=(AllowPrivateAccess))
	bool bHasPlaylistPrivateMatchOption;

};

