// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActionHandlerInterface.h"
#include "CommonInputTypeEnum.h"
#include "Engine/DataTable.h"
#include "Engine/TimerHandle.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "InputCoreTypes.h"
#include "Misc/DateTime.h"
#include "Styling/SlateBrush.h"
#include "BlueprintContext/FortLocalPlayerSubsystem.h"
#include "Feature/FortUIFeature.h"
#include "FortSubGameTypes.h"
#include "GameSummaryInfo.h"
#include "Player/FortPlayerController.h"
#include "FortGlobalUIContext.generated.h"

class AFortScriptedAction;
class UAthenaMatchReadyDesktopPopup;
class UFortCollectionBookManager;
class UFortHelpItem;
class UFortQuestManager;
class UFortUIMessageManager;
class UFortUIRewardReport;
class UFortUIScoreReport;
class UObject;
class UTexture2D;
class UUserWidget;
class UWidget;
enum class EFlagStatus : uint8;
enum class EFortBangType : uint8;
enum class EFortInputActionGroup : uint8;
enum class EFortInputMode : uint8;
enum class EFortPickerMode : uint8;
enum class EFortUIFeature : uint8;
enum class EFortUIFeatureState : uint8;
enum class EFortUIFeatureStateReason : uint8;
enum class EFortUrlType : uint8;
enum class EInputPriority : uint8;
enum class ESubGame : uint8;

UENUM(BlueprintType)
enum class EFlagStatus : uint8
{
	/** The flag is present on the command line */
	FlagPresent = 0,
	/** The flag is NOT present on the command line */
	FlagNotPresent = 1,
};

UENUM()
enum class EFortInputMode : uint8
{
	Frontend = 0,
	InGame = 1,
	InGameCursor = 2,
};

UENUM(BlueprintType)
enum class EFortUrlType : uint8
{
	/** Use this for web-pages that are not required to viewed to play the game */
	NormalWebLink = 0,
	/** Use this for web-pages that are required to create an account */
	AccountCreationLink = 1,
	/** Use this for web-pages that are help-related content */
	HelpLink = 2,
	/** Use this for web-pages that are EULA-related content */
	EULALink = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FConsoleAccountPickerResult, const int32, ControllerIndex, const bool, bUserSwitched);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE(FCreativeDownloadDialogResult);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortGlobalUIContextGenericChange, UObject*, Source);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCloseBladesMenuRequested);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnContextHelpItemsChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGenericActionChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemReceivedNotificationShown, bool, IsActive);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnKeybindsChangedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRefreshHUDForRespawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnScoreReportChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShowPIPPanel, bool, bShowing);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSubGameChanged, ESubGame, SubGame);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUpdateFrontendBangs);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FUIFeatureStateChangedDelegate, EFortUIFeature, ChangedFeature, EFortUIFeatureState, NewState, EFortUIFeatureStateReason, StateReason);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FUIFeatureStateChangedListener, EFortUIFeature, ChangedFeature, EFortUIFeatureState, NewState, EFortUIFeatureStateReason, StateReason);

USTRUCT()
struct FFortBackendVersion
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortUIFeatureStruct
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EFortUIFeatureState CurrentState;

	UPROPERTY()
	EFortUIFeatureState ForcedState;

	UPROPERTY()
	EFortUIFeatureStateReason ForcedStateReason;

	UPROPERTY()
	FUIFeatureStateChangedDelegate ChangeDelegate;

};

UCLASS(MinimalAPI)
class UFortGlobalUIContext : public UFortLocalPlayerSubsystem
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoadingScreenVisibilityChangedDelegate, bool, IsVisible);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLocalPlayerControllerConnectionChangedDelegate, bool, bConnected);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQueryFortBackendVersionDelegate, FFortBackendVersion, FortBackendVersion);

public:
	UFUNCTION(BlueprintPure, Category="Global UI Context")
	bool AllowLogout() const;

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	bool AllowQuit() const;

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void BindToFeatureStateAndInitialize(EFortUIFeature Feature, FUIFeatureStateChangedListener Delegate);

	UFUNCTION(BlueprintPure, Category="Global UI Context|Sub Game")
	bool CanMatchmake(ESubGame SubGame, FText& DenialReason);

	UFUNCTION(BlueprintPure, Category="Global UI Context|Sub Game")
	bool CanPlay(ESubGame SubGame, FText& DenialReason) const;

	UFUNCTION(BlueprintCallable, Category="Global UI Context", meta=(ExpandEnumAsExecs="OutStatus"))
	static void CheckFlag(const FString& FlagName, EFlagStatus& OutStatus);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Global UI Context")
	void ClearLastGameSummaryInfo() const;

	UFUNCTION(BlueprintCallable, Category="Global UI Context|Mission Rewards")
	void ClearLastMissionReports();

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void ClearRatingWidgetInfo();

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	float ContentInstallationProgress(const ESubGame SubGame = ESubGame::Campaign) const;

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void CopyToClipboard(const FString& ClipboardText);

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void DisplayStateContent(bool bDisplay);

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	static void DrawAttention(UWidget* BaseWidget);

	UFUNCTION()
	void EnterVehicleDriver();

	UFUNCTION()
	void EnterVehiclePassenger();

	UFUNCTION()
	void ExitVehicle();

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void ForceSetFeatureState(EFortUIFeature Feature, EFortUIFeatureState ForcedState, EFortUIFeatureStateReason Reason);

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void GenericActionChanged();

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="Keybinds")
	FName GetActionForKey(const FName PresetName, const FKey Key, const EFortInputActionGroup InputActionGroup, const bool bIsUsingGamepad) const;

	UFUNCTION(BlueprintPure, Category="Input")
	void GetAllPlayerInputPresetNamesForSubGame(ESubGame SubGame, TArray<FString>& InputPresetNames, TArray<FText>& InputPresetFriendlyNames) const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetAltInteractionActionName(const ECommonInputType OverrideInputType = ECommonInputType::Count) const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="Keybinds")
	bool GetBrushForKey(FKey Key, FSlateBrush& Brush) const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetBuildConfirmActionName(const ECommonInputType OverrideInputType = ECommonInputType::Count) const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetChangeMaterialActionName() const;

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	UFortCollectionBookManager* GetCollectionBookManager() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeDespawnModeratorBotName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeFlyDownActionName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeFlyUpActionName() const;

	UFUNCTION(BlueprintPure, Category="Global UI Context|Sub Game")
	FDateTime GetCreativeModeLimitedAccessEndTime() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeModeratorOpenPhotoModeName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeMoveBuildingsOnGridDuplicateName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeMoveBuildingsOnGridExitName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeMoveBuildingsOnGridMirrorName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeMoveBuildingsOnGridRotateClockwiseName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeMoveBuildingsOnGridRotateCounterclockwiseName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeMoveObjectsFreelyChangePrecisionLevelName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeMoveObjectsFreelyDropToFloorName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeMoveObjectsFreelyDuplicateName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeMoveObjectsFreelyExitName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeMoveObjectsFreelyPullName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeMoveObjectsFreelyPushName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeMoveObjectsFreelyRotateClockwiseName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeMoveObjectsFreelyRotateCounterclockwiseName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeMoveObjectsFreelySwitchAxisName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeMoveToolClearMultiSelectName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeMoveToolEquippedCopyGrabOrDuplicateName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeMoveToolEquippedDeleteName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeMoveToolEquippedGrabOrLetGoName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeMoveToolMultiSelectName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeQuickbarActivateClutchName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeSpawnModeratorBotName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeToggleGhostName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeToggleHeatmapName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetCreativeToggleInvulnerablityName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FString GetCurrentInputPresetName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FString GetCustomGamepadInputPresetName() const;

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	void GetFeatureState(const EFortUIFeature Feature, EFortUIFeatureState& OutFeatureState, EFortUIFeatureStateReason& OutReason);

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	FText GetFeedbackTitle() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetFireActionName() const;

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	bool GetHidePerkRecombobulatorHelp() const;

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	bool GetHideStwItemRefundHelp() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetHoagieBoostName(const ECommonInputType OverrideInputType = ECommonInputType::Count) const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="Keybinds")
	bool GetInputActionGroup(const FName& ActionName, EFortInputActionGroup& OutInputActionGroup) const;

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	int32 GetInputPriority(EInputPriority Priority) const;

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	UTexture2D* GetInputTypeIcon(ECommonInputType InputType);

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetJumpActionName() const;

	UFUNCTION(BlueprintPure, Category="Input")
	void GetKBMPlayerInputPresetDescriptionForSubGame(ESubGame SubGame, int32 CurrentPreset, FText& InputPresetDescription, FText& InputPresetSubDescription) const;

	UFUNCTION(BlueprintPure, Category="Input")
	void GetKBMPlayerInputPresetNamesForSubGame(ESubGame SubGame, TArray<FString>& InputPresetNames, TArray<FText>& InputPresetFriendlyNames) const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="Keybinds")
	FKey GetKeyForAction(FName Action, const bool bForceGamepadKey = false, FName PresetNameOverride = NAME_None) const;

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	FGameSummaryInfo GetLastGameSummaryInfo() const;

	UFUNCTION(BlueprintCallable, Category="Global UI Context|Mission Rewards")
	UFortUIRewardReport* GetLastMissionRewardReport();

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	UFortUIMessageManager* GetMessageManager(FName ManagerName, bool& bCreatedNew);

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	FString GetModuleIdAndVersion() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetPerformBuildingEditInteractionActionName(const ECommonInputType OverrideInputType = ECommonInputType::Count) const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetPerformBuildingImprovementInteractionActionName(const ECommonInputType OverrideInputType = ECommonInputType::Count) const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetPickerCancelActionName(EFortPickerMode PickerMode) const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetPickerConfirmActionName(EFortPickerMode PickerMode) const;

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	UFortQuestManager* GetQuestManager(ESubGame SubGame = ESubGame::Invalid) const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetRotatePrimitiveClockwiseActionName(const ECommonInputType OverrideInputType = ECommonInputType::Count) const;

	UFUNCTION(BlueprintCallable, Category="Scoring")
	UFortUIScoreReport* GetScoreReport();

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	FString GetSessionConnectString() const;

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	FString GetSessionId() const;

	UFUNCTION(BlueprintPure, Category="Global UI Context|Sub Game")
	ESubGame GetSubGame() const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetSwitchQuickBarActionName(ECommonInputType OverrideInputType = ECommonInputType::Count) const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetTargetActionName(const ECommonInputType OverrideInputType = ECommonInputType::Count) const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetToggleInventoryActionName() const;

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void GetTopLevelHelpItems(TArray<UFortHelpItem*>& ActiveHelpEntries);

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetTrapConfirmActionName(const ECommonInputType OverrideInputType = ECommonInputType::Count) const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetTrapHotbarActionName(const ECommonInputType OverrideInputType = ECommonInputType::Count) const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetTrapPickerActionName(const ECommonInputType OverrideInputType = ECommonInputType::Count) const;

	UFUNCTION(BlueprintPure, Category="Input")
	FName GetUseActionName(const ECommonInputType OverrideInputType = ECommonInputType::Count) const;

	UFUNCTION()
	void HandleVehicleSeatChanged(const int32 SeatIndex);

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void HideBang(EFortBangType Type);

	UFUNCTION()
	void InputActionHoldStarted(FName InputActionName, float HoldDuration);

	UFUNCTION()
	void InputActionHoldStopped(FName InputActionName, bool bCompletedSuccessfully);

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	bool IsAllContentInstalled(const ESubGame SubGame = ESubGame::Campaign);

	UFUNCTION(BlueprintPure, Category="Global UI Context|Sub Game")
	bool IsCreativeModeAccessLimited() const;

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	bool IsCurrentlyShowingLoadingScreen() const;

	UFUNCTION(BlueprintPure, Category="Input")
	bool IsCustomGamepadConfig(const int32 ConfigIndex) const;

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	bool IsDesktopPlatform();

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	bool IsGamepadAttached() const;

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	bool IsInOutpostZone() const;

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	bool IsInZone() const;

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	bool IsMobileApp() const;

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	bool IsPendingLogout() const;

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	bool IsUsingGamepad() const;

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void Logout();

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void QuitGame();

	UFUNCTION()
	void RefreshHUDForRespawn();

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void RegisterInputAction(const UUserWidget* UserWidget, FDataTableRowHandle InputActionRow, FCommonActionCommited CommitedEvent, int32 InFilterPriority);

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void RegisterScriptedAction(const TSubclassOf<AFortScriptedAction>& ScriptedAction);

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void RegisterScriptedActions(const TArray<TSubclassOf<AFortScriptedAction>>& ScriptedActions);

	UFUNCTION(BlueprintCallable, Category="Global UI Context|Sub Game")
	void ReturnToSubGameSelect();

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void RunLauncherWithOptions(const FString& Options);

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void SendExperienceRatingAnalytic(const FString& RatingType, const FString& FeedbackSentBy, const FText& RatingQuestion, const int32& StarCount, const FString& GameSessionID, const FString& Comment);

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void SendLeaveZoneAnalytic();

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void SetContextHelpItem(UFortHelpItem* ContextSpecificHelpItem);

	UFUNCTION(BlueprintCallable, Category="Input")
	void SetCurrentCustomInputTemplatePresetName(const FString& InputPresetName);

	UFUNCTION(BlueprintCallable, Category="Input")
	void SetCurrentInputPresetName(const FString& InputPresetName);

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void SetHidePerkRecombobulatorHelp(bool bInHideHelp);

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void SetHideStwItemRefundHelp(bool bInHideHelp);

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void SetInputMode(EFortInputMode InMode);

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void SetRatingWidgetFeedbackTitle(const FText& Title);

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	bool ShouldShowRateWidget() const;

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void ShowConsoleAccountPicker(const int32 ControllerIndex, const FConsoleAccountPickerResult& CompletionDelegate);

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	bool ShowCreativeContentDownloadDialog(const FCreativeDownloadDialogResult& OnSubGameContentReadyCallback, const FCreativeDownloadDialogResult& OnSubGameContentCanceledCallback);

	UFUNCTION(BlueprintPure, Category="Global UI Context")
	bool ShowVehicleHealthBarOnPlayerHUD() const;

	UFUNCTION(Category="Global UI Context")
	bool ShowWebURL(const FString& URL, const EFortUrlType URLType);

	UFUNCTION()
	void TetherChanged(bool bIsTethered);

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void UnbindToFeatureState(EFortUIFeature Feature, FUIFeatureStateChangedListener Delegate);

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void UnregisterInputAction(const UUserWidget* UserWidget, FDataTableRowHandle InputActionRow);

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void UnregisterScriptedAction(const TSubclassOf<AFortScriptedAction>& ScriptedAction);

	UFUNCTION(BlueprintCallable, Category="Global UI Context")
	void UnregisterScriptedActions(const TArray<TSubclassOf<AFortScriptedAction>>& ScriptedActions);

	UPROPERTY(BlueprintAssignable, Category="Global UI Context|Sub Game")
	FOnSubGameChanged SubGameChanged;

	UPROPERTY(BlueprintReadWrite, Category="Global UI Context")
	bool bShouldSubgameSelectStartOnCampaignUpsell;

	UPROPERTY(BlueprintAssignable, Category="Keybinds")
	FOnKeybindsChangedDelegate OnKeybindsChanged;

	UPROPERTY(BlueprintAssignable, Category="Inventory")
	FOnInputActionHoldStarted OnInputActionHoldStarted;

	UPROPERTY(BlueprintAssignable, Category="Inventory")
	FOnInputActionHoldStopped OnInputActionHoldStopped;

	UPROPERTY(BlueprintAssignable, Category="Respawn")
	FOnRefreshHUDForRespawn OnRefreshHUDForRespawn;

	UPROPERTY(BlueprintAssignable, Category="Global UI Context")
	FOnGenericActionChanged OnGenericActionChanged;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnEnterVehicleDriver OnEnterVehicleDriver;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnEnterVehiclePassenger OnEnterVehiclePassenger;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnExitVehicle OnExitVehicle;

	UPROPERTY(BlueprintAssignable, Category="Vehicle")
	FOnVehicleSeatChanged OnVehicleSeatChanged;

	UPROPERTY(BlueprintAssignable, Category="Global UI Context")
	FOnScoreReportChanged OnScoreReportChanged;

	UPROPERTY(BlueprintAssignable, Category="Global UI Context")
	FOnLoadingScreenVisibilityChangedDelegate OnLoadingScreenVisibilityChanged;

	UPROPERTY(BlueprintAssignable, Category="Global UI Context")
	FOnLocalPlayerControllerConnectionChangedDelegate OnLocalPlayerControllerConnectionChanged;

private:
	UFUNCTION(BlueprintPure, Category="Global UI Context")
	bool ShouldShowPhoenixDisplay() const;

	UPROPERTY(Transient)
	TMap<FName, TObjectPtr<UFortUIMessageManager>> MessageManagersByName;

	UPROPERTY(Transient)
	TMap<EFortUIFeature, FFortUIFeatureStruct> Features;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaMatchReadyDesktopPopup> AthenaMatchReadyNotificationWidget;

	UPROPERTY(Transient)
	TObjectPtr<UFortHelpItem> ActiveContextSpecificHelpItem;

	UPROPERTY(Transient)
	bool bIsUIVisible;

	UPROPERTY(Transient)
	bool bShowRateWidget;

	UPROPERTY(Transient)
	TMap<ESubGame, bool> IsAllContentInstalledCacheMap;

	UPROPERTY(Transient)
	FText FeedbackTitle;

	UPROPERTY(Transient)
	FDateTime FirstLoginTime;

	UPROPERTY(Transient)
	FTimerHandle AddictionMsgTimer;

	UPROPERTY(Transient)
	FUniqueNetIdRepl CurrentLocalPlayerUniqueNetId;

	UPROPERTY(Transient)
	bool bQuestMapTabRequested;

	UPROPERTY(Transient)
	FGameplayTag QuestMapChallengeTabRequested;

};

