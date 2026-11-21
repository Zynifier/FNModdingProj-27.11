// Copyright Epic Games, Inc. All Rights Reserved.

#include "Context/FortGlobalUIContext.h"

bool UFortGlobalUIContext::AllowLogout() const
{
	return false;
}

bool UFortGlobalUIContext::AllowQuit() const
{
	return false;
}

void UFortGlobalUIContext::BindToFeatureStateAndInitialize(EFortUIFeature Feature, FUIFeatureStateChangedListener Delegate)
{
}

bool UFortGlobalUIContext::CanMatchmake(ESubGame SubGame, FText& DenialReason)
{
	return false;
}

bool UFortGlobalUIContext::CanPlay(ESubGame SubGame, FText& DenialReason) const
{
	return false;
}

void UFortGlobalUIContext::CheckFlag(const FString& FlagName, EFlagStatus& OutStatus)
{
}

void UFortGlobalUIContext::ClearLastGameSummaryInfo() const
{
}

void UFortGlobalUIContext::ClearLastMissionReports()
{
}

void UFortGlobalUIContext::ClearRatingWidgetInfo()
{
}

float UFortGlobalUIContext::ContentInstallationProgress(const ESubGame SubGame) const
{
	return float();
}

void UFortGlobalUIContext::CopyToClipboard(const FString& ClipboardText)
{
}

void UFortGlobalUIContext::DisplayStateContent(bool bDisplay)
{
}

void UFortGlobalUIContext::DrawAttention(UWidget* BaseWidget)
{
}

void UFortGlobalUIContext::EnterVehicleDriver()
{
}

void UFortGlobalUIContext::EnterVehiclePassenger()
{
}

void UFortGlobalUIContext::ExitVehicle()
{
}

void UFortGlobalUIContext::ForceSetFeatureState(EFortUIFeature Feature, EFortUIFeatureState ForcedState, EFortUIFeatureStateReason Reason)
{
}

void UFortGlobalUIContext::GenericActionChanged()
{
}

FName UFortGlobalUIContext::GetActionForKey(const FName PresetName, const FKey Key, const EFortInputActionGroup InputActionGroup, const bool bIsUsingGamepad) const
{
	return FName();
}

void UFortGlobalUIContext::GetAllPlayerInputPresetNamesForSubGame(ESubGame SubGame, TArray<FString>& InputPresetNames, TArray<FText>& InputPresetFriendlyNames) const
{
}

FName UFortGlobalUIContext::GetAltInteractionActionName(const ECommonInputType OverrideInputType) const
{
	return FName();
}

bool UFortGlobalUIContext::GetBrushForKey(FKey Key, FSlateBrush& Brush) const
{
	return false;
}

FName UFortGlobalUIContext::GetBuildConfirmActionName(const ECommonInputType OverrideInputType) const
{
	return FName();
}

FName UFortGlobalUIContext::GetChangeMaterialActionName() const
{
	return FName();
}

UFortCollectionBookManager* UFortGlobalUIContext::GetCollectionBookManager() const
{
	return nullptr;
}

FName UFortGlobalUIContext::GetCreativeDespawnModeratorBotName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeFlyDownActionName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeFlyUpActionName() const
{
	return FName();
}

FDateTime UFortGlobalUIContext::GetCreativeModeLimitedAccessEndTime() const
{
	return FDateTime();
}

FName UFortGlobalUIContext::GetCreativeModeratorOpenPhotoModeName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeMoveBuildingsOnGridDuplicateName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeMoveBuildingsOnGridExitName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeMoveBuildingsOnGridMirrorName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeMoveBuildingsOnGridRotateClockwiseName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeMoveBuildingsOnGridRotateCounterclockwiseName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeMoveObjectsFreelyChangePrecisionLevelName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeMoveObjectsFreelyDropToFloorName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeMoveObjectsFreelyDuplicateName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeMoveObjectsFreelyExitName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeMoveObjectsFreelyPullName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeMoveObjectsFreelyPushName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeMoveObjectsFreelyRotateClockwiseName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeMoveObjectsFreelyRotateCounterclockwiseName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeMoveObjectsFreelySwitchAxisName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeMoveToolClearMultiSelectName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeMoveToolEquippedCopyGrabOrDuplicateName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeMoveToolEquippedDeleteName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeMoveToolEquippedGrabOrLetGoName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeMoveToolMultiSelectName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeQuickbarActivateClutchName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeSpawnModeratorBotName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeToggleGhostName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeToggleHeatmapName() const
{
	return FName();
}

FName UFortGlobalUIContext::GetCreativeToggleInvulnerablityName() const
{
	return FName();
}

FString UFortGlobalUIContext::GetCurrentInputPresetName() const
{
	return FString();
}

FString UFortGlobalUIContext::GetCustomGamepadInputPresetName() const
{
	return FString();
}

void UFortGlobalUIContext::GetFeatureState(const EFortUIFeature Feature, EFortUIFeatureState& OutFeatureState, EFortUIFeatureStateReason& OutReason)
{
}

FText UFortGlobalUIContext::GetFeedbackTitle() const
{
	return FText();
}

FName UFortGlobalUIContext::GetFireActionName() const
{
	return FName();
}

bool UFortGlobalUIContext::GetHidePerkRecombobulatorHelp() const
{
	return false;
}

bool UFortGlobalUIContext::GetHideStwItemRefundHelp() const
{
	return false;
}

FName UFortGlobalUIContext::GetHoagieBoostName(const ECommonInputType OverrideInputType) const
{
	return FName();
}

bool UFortGlobalUIContext::GetInputActionGroup(const FName& ActionName, EFortInputActionGroup& OutInputActionGroup) const
{
	return false;
}

int32 UFortGlobalUIContext::GetInputPriority(EInputPriority Priority) const
{
	return int32();
}

UTexture2D* UFortGlobalUIContext::GetInputTypeIcon(ECommonInputType InputType)
{
	return nullptr;
}

FName UFortGlobalUIContext::GetJumpActionName() const
{
	return FName();
}

void UFortGlobalUIContext::GetKBMPlayerInputPresetDescriptionForSubGame(ESubGame SubGame, int32 CurrentPreset, FText& InputPresetDescription, FText& InputPresetSubDescription) const
{
}

void UFortGlobalUIContext::GetKBMPlayerInputPresetNamesForSubGame(ESubGame SubGame, TArray<FString>& InputPresetNames, TArray<FText>& InputPresetFriendlyNames) const
{
}

FKey UFortGlobalUIContext::GetKeyForAction(FName Action, const bool bForceGamepadKey, FName PresetNameOverride) const
{
	return FKey();
}

FGameSummaryInfo UFortGlobalUIContext::GetLastGameSummaryInfo() const
{
	return FGameSummaryInfo();
}

UFortUIRewardReport* UFortGlobalUIContext::GetLastMissionRewardReport()
{
	return nullptr;
}

UFortUIMessageManager* UFortGlobalUIContext::GetMessageManager(FName ManagerName, bool& bCreatedNew)
{
	return nullptr;
}

FString UFortGlobalUIContext::GetModuleIdAndVersion() const
{
	return FString();
}

FName UFortGlobalUIContext::GetPerformBuildingEditInteractionActionName(const ECommonInputType OverrideInputType) const
{
	return FName();
}

FName UFortGlobalUIContext::GetPerformBuildingImprovementInteractionActionName(const ECommonInputType OverrideInputType) const
{
	return FName();
}

FName UFortGlobalUIContext::GetPickerCancelActionName(EFortPickerMode PickerMode) const
{
	return FName();
}

FName UFortGlobalUIContext::GetPickerConfirmActionName(EFortPickerMode PickerMode) const
{
	return FName();
}

UFortQuestManager* UFortGlobalUIContext::GetQuestManager(ESubGame SubGame) const
{
	return nullptr;
}

FName UFortGlobalUIContext::GetRotatePrimitiveClockwiseActionName(const ECommonInputType OverrideInputType) const
{
	return FName();
}

UFortUIScoreReport* UFortGlobalUIContext::GetScoreReport()
{
	return nullptr;
}

FString UFortGlobalUIContext::GetSessionConnectString() const
{
	return FString();
}

FString UFortGlobalUIContext::GetSessionId() const
{
	return FString();
}

ESubGame UFortGlobalUIContext::GetSubGame() const
{
	return ESubGame();
}

FName UFortGlobalUIContext::GetSwitchQuickBarActionName(ECommonInputType OverrideInputType) const
{
	return FName();
}

FName UFortGlobalUIContext::GetTargetActionName(const ECommonInputType OverrideInputType) const
{
	return FName();
}

FName UFortGlobalUIContext::GetToggleInventoryActionName() const
{
	return FName();
}

void UFortGlobalUIContext::GetTopLevelHelpItems(TArray<UFortHelpItem*>& ActiveHelpEntries)
{
}

FName UFortGlobalUIContext::GetTrapConfirmActionName(const ECommonInputType OverrideInputType) const
{
	return FName();
}

FName UFortGlobalUIContext::GetTrapHotbarActionName(const ECommonInputType OverrideInputType) const
{
	return FName();
}

FName UFortGlobalUIContext::GetTrapPickerActionName(const ECommonInputType OverrideInputType) const
{
	return FName();
}

FName UFortGlobalUIContext::GetUseActionName(const ECommonInputType OverrideInputType) const
{
	return FName();
}

void UFortGlobalUIContext::HandleVehicleSeatChanged(const int32 SeatIndex)
{
}

void UFortGlobalUIContext::HideBang(EFortBangType Type)
{
}

void UFortGlobalUIContext::InputActionHoldStarted(FName InputActionName, float HoldDuration)
{
}

void UFortGlobalUIContext::InputActionHoldStopped(FName InputActionName, bool bCompletedSuccessfully)
{
}

bool UFortGlobalUIContext::IsAllContentInstalled(const ESubGame SubGame)
{
	return false;
}

bool UFortGlobalUIContext::IsCreativeModeAccessLimited() const
{
	return false;
}

bool UFortGlobalUIContext::IsCurrentlyShowingLoadingScreen() const
{
	return false;
}

bool UFortGlobalUIContext::IsCustomGamepadConfig(const int32 ConfigIndex) const
{
	return false;
}

bool UFortGlobalUIContext::IsDesktopPlatform()
{
	return false;
}

bool UFortGlobalUIContext::IsGamepadAttached() const
{
	return false;
}

bool UFortGlobalUIContext::IsInOutpostZone() const
{
	return false;
}

bool UFortGlobalUIContext::IsInZone() const
{
	return false;
}

bool UFortGlobalUIContext::IsMobileApp() const
{
	return false;
}

bool UFortGlobalUIContext::IsPendingLogout() const
{
	return false;
}

bool UFortGlobalUIContext::IsUsingGamepad() const
{
	return false;
}

void UFortGlobalUIContext::Logout()
{
}

void UFortGlobalUIContext::QuitGame()
{
}

void UFortGlobalUIContext::RefreshHUDForRespawn()
{
}

void UFortGlobalUIContext::RegisterInputAction(const UUserWidget* UserWidget, FDataTableRowHandle InputActionRow, FCommonActionCommited CommitedEvent, int32 InFilterPriority)
{
}

void UFortGlobalUIContext::RegisterScriptedAction(const TSubclassOf<AFortScriptedAction>& ScriptedAction)
{
}

void UFortGlobalUIContext::RegisterScriptedActions(const TArray<TSubclassOf<AFortScriptedAction>>& ScriptedActions)
{
}

void UFortGlobalUIContext::ReturnToSubGameSelect()
{
}

void UFortGlobalUIContext::RunLauncherWithOptions(const FString& Options)
{
}

void UFortGlobalUIContext::SendExperienceRatingAnalytic(const FString& RatingType, const FString& FeedbackSentBy, const FText& RatingQuestion, const int32& StarCount, const FString& GameSessionID, const FString& Comment)
{
}

void UFortGlobalUIContext::SendLeaveZoneAnalytic()
{
}

void UFortGlobalUIContext::SetContextHelpItem(UFortHelpItem* ContextSpecificHelpItem)
{
}

void UFortGlobalUIContext::SetCurrentCustomInputTemplatePresetName(const FString& InputPresetName)
{
}

void UFortGlobalUIContext::SetCurrentInputPresetName(const FString& InputPresetName)
{
}

void UFortGlobalUIContext::SetHidePerkRecombobulatorHelp(bool bInHideHelp)
{
}

void UFortGlobalUIContext::SetHideStwItemRefundHelp(bool bInHideHelp)
{
}

void UFortGlobalUIContext::SetInputMode(EFortInputMode InMode)
{
}

void UFortGlobalUIContext::SetRatingWidgetFeedbackTitle(const FText& Title)
{
}

bool UFortGlobalUIContext::ShouldShowPhoenixDisplay() const
{
	return false;
}

bool UFortGlobalUIContext::ShouldShowRateWidget() const
{
	return false;
}

void UFortGlobalUIContext::ShowConsoleAccountPicker(const int32 ControllerIndex, const FConsoleAccountPickerResult& CompletionDelegate)
{
}

bool UFortGlobalUIContext::ShowCreativeContentDownloadDialog(const FCreativeDownloadDialogResult& OnSubGameContentReadyCallback, const FCreativeDownloadDialogResult& OnSubGameContentCanceledCallback)
{
	return false;
}

bool UFortGlobalUIContext::ShowVehicleHealthBarOnPlayerHUD() const
{
	return false;
}

bool UFortGlobalUIContext::ShowWebURL(const FString& URL, const EFortUrlType URLType)
{
	return false;
}

void UFortGlobalUIContext::TetherChanged(bool bIsTethered)
{
}

void UFortGlobalUIContext::UnbindToFeatureState(EFortUIFeature Feature, FUIFeatureStateChangedListener Delegate)
{
}

void UFortGlobalUIContext::UnregisterInputAction(const UUserWidget* UserWidget, FDataTableRowHandle InputActionRow)
{
}

void UFortGlobalUIContext::UnregisterScriptedAction(const TSubclassOf<AFortScriptedAction>& ScriptedAction)
{
}

void UFortGlobalUIContext::UnregisterScriptedActions(const TArray<TSubclassOf<AFortScriptedAction>>& ScriptedActions)
{
}
