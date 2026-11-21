// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "Engine/DataTable.h"
#include "InputCoreTypes.h"
#include "Math/MathFwd.h"
#include "Misc/DateTime.h"
#include "Frontend/Lobby/FortLobby.h"
#include "Frontend/Lobby/FrontendLobbyData.h"
#include "Input/FortSwipeDetector.h"
#include "AthenaLobbyBase.generated.h"

class AFortPlayerController;
class UCatalogMessaging;
class UCommonActivatableWidget;
class UCommonBorder;
class UCommonButtonBase;
class UCommonWidgetSwitcherLegacy;
class UContentWidget;
class UEmergencyNoticeBase;
class UFortActivityViewModel;
class UFortAthenaMatchmakingWidgetLegacy;
class UFortDivisionLobbyPanel;
class UFortEmotePicker;
class UFortGlobalSeasonResourceWidget;
class UFortHabaneroLobbyWidget;
class UFortPlaylistAthena;
class UFortSquadSelectionMenu;
class UFortTournamentLobbyPanel;
class UOverlay;
class UStoreToastRequest;
class UUserWidget;
class UVerticalBox;
class UWidget;
enum class EFortLobbyType : uint8;
enum class EFortPickerMode : uint8;

UCLASS(Abstract, Config=Game, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaLobbyBase : public UFortLobbyWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void DisplayGlyphQuestUpdated(int32 NewGlyphs);

	UFUNCTION(BlueprintImplementableEvent)
	void DisplayStoreUpdated(UStoreToastRequest* StoreUpdatedRequest);

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	bool GetIsRightSideFocused(const AFortPlayerController* FortPC) const;

	UFUNCTION(BlueprintPure)
	bool GetSurvivorTierWidgetAllowed() const;

	UFUNCTION(BlueprintImplementableEvent)
	void HandleUnseenQuestsChanged(bool bHasUnseenQuests);

	UFUNCTION(BlueprintPure)
	bool HasUnseenQuests() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnLobbyChanged(const EFortLobbyType LobbyType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLobbyDataChanged(const FFrontendLobbyData LobbyData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingWidgetChanged();

	UFUNCTION(BlueprintImplementableEvent)
	bool OnNavigateDownOnPedestalRight(const AFortPlayerController* FortPC);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNavigateRightFromPedestal(const AFortPlayerController* FortPC);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNavigateUpOnPedestalRight(const AFortPlayerController* FortPC);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlaylistChanged(EFortLobbyType LobbyType, const UFortPlaylistAthena* PlaylistData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnQuestsButtonVisibilityChanged(ESlateVisibility NewVisibility);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRankedProgressDisplayUpdated(const bool bPlayingRanked);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSwipeDown();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSwipeUp();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateGenericLinkText(const FText& NewText);

private:
	UFUNCTION(BlueprintCallable)
	bool ExitDiscover();

	UFUNCTION(BlueprintCallable, meta=(AllowPrivateAccess))
	TSoftClassPtr<UUserWidget> GetMotdTeaserClass();

	UFUNCTION()
	void HandleActiveWidgetChanged(UWidget* NewActiveWidget, int32 WidgetIndex);

	UFUNCTION()
	void HandleHideLobbySeasonResources(bool bShouldHide);

	UFUNCTION()
	void HandlePickerOpenRequest(EFortPickerMode Mode, int32 InitialOption, bool bIgnoreFirstAccept);

	UFUNCTION()
	void HandlePlayerTouchInput(ETouchType::Type Type, const FVector2D& TouchLocation, float Force, FDateTime DeviceTimestamp, uint32 TouchpadIndex, bool& bOutHandled);

	UFUNCTION()
	void HandleToggleFullscreenMap(bool bVisible);

	UFUNCTION(BlueprintCallable)
	bool NavigateToDiscover();

	UFUNCTION(BlueprintCallable)
	void SetHomeBarShownOnActivated();

	UFUNCTION(BlueprintCallable)
	bool ShouldShowHomeBarOnActivated();

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLobbyBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UContentWidget> Content_MatchmakingWidget;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UEmergencyNoticeBase> Notice_Emergency;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UContentWidget> Content_MotdTeaserWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLobbyBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> LobbyDetails_Default;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLobbyBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortTournamentLobbyPanel> LobbyDetails_Tournament;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLobbyBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortDivisionLobbyPanel> LobbyDetails_ShowdownDivision;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLobbyBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_LobbyDetailsMode;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLobbyBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_GenericLink;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLobbyBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Quests;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ShadowPlayHighlights;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VerticalBox_LobbyDetails;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UVerticalBox> VerticalBox_LobbyDetails_ExtensionHolder;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_DynamicExtensions;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_Discover;

	UPROPERTY(EditDefaultsOnly, Category="Emote Picker")
	TSoftClassPtr<UFortEmotePicker> NewEmotePicker;

	UPROPERTY(EditDefaultsOnly, Category="AthenaLobbyBase")
	TObjectPtr<UCatalogMessaging> CatalogMessaging;

	UPROPERTY(EditDefaultsOnly, Category="AthenaLobbyBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle SquadFormationInputAction;

	UPROPERTY(EditDefaultsOnly, Category="AthenaLobbyBase")
	TSubclassOf<UFortSquadSelectionMenu> SquadFormationClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaLobbyBase")
	TSubclassOf<UUserWidget> MotdTeaserWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaLobbyBase")
	TSubclassOf<UFortAthenaMatchmakingWidgetLegacy> DefaultMatchmakingWidgetClass;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="AthenaLobbyBase", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<UFortAthenaMatchmakingWidgetLegacy> MatchmakingWidget;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="AthenaLobbyBase", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<UFortGlobalSeasonResourceWidget> SeasonalResources;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortHabaneroLobbyWidget> HabaneroDisplayWidget;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCommonActivatableWidget> Discover;

	UPROPERTY(Config)
	bool bEnableNavigationRight;

	UPROPERTY(BlueprintReadOnly, Category="AthenaLobbyBase", meta=(AllowPrivateAccess))
	FFortSwipeDetector SwipeDetector;

	UPROPERTY()
	TObjectPtr<UFortActivityViewModel> CurrentActivityVM;

};

