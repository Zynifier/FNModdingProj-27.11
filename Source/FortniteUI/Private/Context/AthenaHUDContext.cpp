// Copyright Epic Games, Inc. All Rights Reserved.

#include "Context/AthenaHUDContext.h"

void UAthenaHUDContext::BeginUseFromHUD()
{
}

bool UAthenaHUDContext::CanAutoRun() const
{
	return false;
}

bool UAthenaHUDContext::CanCurrentWeaponAutoFireFromReticle() const
{
	return false;
}

bool UAthenaHUDContext::CanShootInVehicle() const
{
	return false;
}

bool UAthenaHUDContext::CurrentWeaponAllowsTargeting() const
{
	return false;
}

void UAthenaHUDContext::CycleQuickbar() const
{
}

float UAthenaHUDContext::DisplayPlayerWonTime()
{
	return float();
}

bool UAthenaHUDContext::DoesPlaylistUIExtensionSlotContainWidget(EUIExtensionSlot PlaylistSlot) const
{
	return false;
}

void UAthenaHUDContext::EnableAutoRunFromHUD(bool bEnable)
{
}

void UAthenaHUDContext::EndUseFromHUD()
{
}

void UAthenaHUDContext::ExecuteActionNameFromHUD(const FName ActionName)
{
}

void UAthenaHUDContext::ExecuteActionNameFromHUDWithEventType(const FName ActionName, const EInputEvent KeyEvent)
{
}

void UAthenaHUDContext::FireFromHUDStart(int32 TouchIndex, UWidget* DebugWidget)
{
}

void UAthenaHUDContext::FireFromHUDStop(int32 TouchIndex, UWidget* DebugWidget)
{
}

void UAthenaHUDContext::ForceFireFromHUDStop()
{
}

void UAthenaHUDContext::ForceStartPostGameFlow()
{
}

void UAthenaHUDContext::ForceVictoryRoyaleUI()
{
}

void UAthenaHUDContext::ForwardOnSpecialActorListChanged(const FSpecialActorRepData& SpecialActorData)
{
}

float UAthenaHUDContext::GetBatteryLevel() const
{
	return float();
}

TArray<FName> UAthenaHUDContext::GetBoundActions()
{
	return TArray<FName>();
}

bool UAthenaHUDContext::GetCanPTT() const
{
	return false;
}

TSoftObjectPtr<UMaterialInterface> UAthenaHUDContext::GetCustomDBNOReviveMaterial() const
{
	return TSoftObjectPtr<UMaterialInterface>();
}

TSoftClassPtr<UUserWidget> UAthenaHUDContext::GetCustomDBNOWidgetClass() const
{
	return TSoftClassPtr<UUserWidget>();
}

const TArray<FEliminationTimelineEntry>& UAthenaHUDContext::GetEliminationTimeline() const
{
	static TArray<FEliminationTimelineEntry> Dummy;
	return Dummy;
}

float UAthenaHUDContext::GetGameOverDelayTime() const
{
	return float();
}

FText UAthenaHUDContext::GetGliderDisplayName() const
{
	return FText();
}

UFortAthenaHUDInfoDataAsset* UAthenaHUDContext::GetHUDInfoDataAsset() const
{
	return nullptr;
}

bool UAthenaHUDContext::GetInLowPerformanceMode() const
{
	return false;
}

int32 UAthenaHUDContext::GetInteractPressedTouchIndex() const
{
	return int32();
}

int32 UAthenaHUDContext::GetJumpPressedTouchIndex() const
{
	return int32();
}

bool UAthenaHUDContext::GetLocalPlayerWonMatch() const
{
	return false;
}

void UAthenaHUDContext::GetLocalTime(int32& Hours, int32& Minutes) const
{
}

FLinearColor UAthenaHUDContext::GetPlayerColor() const
{
	return FLinearColor();
}

FString UAthenaHUDContext::GetPlayerName() const
{
	return FString();
}

EPTTState UAthenaHUDContext::GetPTTState() const
{
	return EPTTState();
}

int32 UAthenaHUDContext::GetSquadConnectedCount() const
{
	return int32();
}

int32 UAthenaHUDContext::GetSquadSize() const
{
	return int32();
}

ETouchInteractMode UAthenaHUDContext::GetTouchInteractMode() const
{
	return ETouchInteractMode();
}

USoundCue* UAthenaHUDContext::GetVictoryStinger() const
{
	return nullptr;
}

FText UAthenaHUDContext::GetVictoryText() const
{
	return FText();
}

void UAthenaHUDContext::GetWinnerText(FText& ReturnText, const FText& WinnerName)
{
}

void UAthenaHUDContext::HandleLocalPlayerBeginSkydiving()
{
}

void UAthenaHUDContext::HandleLocalPlayerDBNOStateChanged(AFortPawn* FortPawn, bool bIsDBNO)
{
}

void UAthenaHUDContext::HandleOnNPCConvertEvent(AFortPawn* ConvertedFortPawn)
{
}

void UAthenaHUDContext::HandleOnNPCUnconvertEvent(AFortPawn* UnconvertedFortPawn, EUnconvertReason UnconvertReason)
{
}

void UAthenaHUDContext::HandlePawnEmoteStopped(const UFortItemDefinition* MontageItemDef, AFortPawn* PawnEmoting)
{
}

void UAthenaHUDContext::HandleSpectatorViewTargetChanged()
{
}

void UAthenaHUDContext::HandleUIGameplayCue(FName CueName, EGameplayCueEvent::Type EventType, const FGameplayCueParameters& Parameters)
{
}

void UAthenaHUDContext::HandleWeaponChanged(AFortPawn* InPawn, AFortWeapon* InNewWeapon, AFortWeapon* InPlayerWeapon)
{
}

bool UAthenaHUDContext::HasAutofireTarget() const
{
	return false;
}

bool UAthenaHUDContext::HasFiringTouch() const
{
	return false;
}

bool UAthenaHUDContext::HasLockOnTarget() const
{
	return false;
}

bool UAthenaHUDContext::HasWifi() const
{
	return false;
}

void UAthenaHUDContext::HideGameModeMessage() const
{
}

bool UAthenaHUDContext::IsActionBound(const FName ActionName)
{
	return false;
}

bool UAthenaHUDContext::IsAutoRunEnabled() const
{
	return false;
}

bool UAthenaHUDContext::IsCrouching() const
{
	return false;
}

bool UAthenaHUDContext::IsCurrentWeaponChargeable() const
{
	return false;
}

bool UAthenaHUDContext::IsCurrentWeaponFiring() const
{
	return false;
}

bool UAthenaHUDContext::IsFiringFromTouch(int32 TouchIndex) const
{
	return false;
}

bool UAthenaHUDContext::IsInBuildMode() const
{
	return false;
}

bool UAthenaHUDContext::IsInSelectWidgetToMoveMode() const
{
	return false;
}

bool UAthenaHUDContext::IsMovingSelectedWidget() const
{
	return false;
}

bool UAthenaHUDContext::IsOperatingTurret() const
{
	return false;
}

bool UAthenaHUDContext::IsRunningOnBattery() const
{
	return false;
}

bool UAthenaHUDContext::IsTargeting() const
{
	return false;
}

bool UAthenaHUDContext::IsUsingScope() const
{
	return false;
}

bool UAthenaHUDContext::IsVictoryUICinematic() const
{
	return false;
}

void UAthenaHUDContext::JumpFromHudEnd()
{
}

void UAthenaHUDContext::JumpFromHudStart(int32 TouchIndex)
{
}

void UAthenaHUDContext::LookFireFromHUDStart(int32 TouchIndex, UWidget* DebugWidget)
{
}

void UAthenaHUDContext::LookFireFromHUDStop(int32 TouchIndex, UWidget* DebugWidget)
{
}

void UAthenaHUDContext::OnAllWinnersAnnounced()
{
}

void UAthenaHUDContext::OnReadyForWinnerInfoDisplay()
{
}

void UAthenaHUDContext::OverrideInventoryPanel(UUserWidget* Widget) const
{
}

bool UAthenaHUDContext::OwnerOrWeaponHasTag(FGameplayTag InTag) const
{
	return false;
}

void UAthenaHUDContext::PushGameOverEmoteInput()
{
}

void UAthenaHUDContext::RecoverFromPostGameMenu() const
{
}

void UAthenaHUDContext::ReloadFromHUD()
{
}

void UAthenaHUDContext::SelectWidgetToMove(UWidget* Widget)
{
}

void UAthenaHUDContext::SetLocalPlayerWonMatch(bool bLocalPlayerWon)
{
}

void UAthenaHUDContext::SetLockOnStickCoords(const FVector2D& LockOnCoords)
{
}

void UAthenaHUDContext::SetPostGameWidgetPlacement(FName WidgetPlacement)
{
}

void UAthenaHUDContext::SetPTTState(EPTTState NewPushToTalkState)
{
}

void UAthenaHUDContext::SetResourceMaterial(EFortResourceType::Type NewMaterial)
{
}

void UAthenaHUDContext::SetSelectedInventoryItem(UFortItem* Item)
{
}

void UAthenaHUDContext::SetSelectWidgetToMoveMode(bool bSet)
{
}

void UAthenaHUDContext::SetTargetingToggleable(const bool bNewValue)
{
}

bool UAthenaHUDContext::ShouldAlwaysDisplaySquadInfo()
{
	return false;
}

bool UAthenaHUDContext::ShouldDisplayPlacement()
{
	return false;
}

bool UAthenaHUDContext::ShouldDisplayScoreUI()
{
	return false;
}

bool UAthenaHUDContext::ShouldPlayCustomEndScreenAtLoss() const
{
	return false;
}

bool UAthenaHUDContext::ShouldVictoryUIPushEmoteInput() const
{
	return false;
}

void UAthenaHUDContext::ShowGameModeMessage() const
{
}

void UAthenaHUDContext::ShowMarkerGameModeMessage(int32 PlayerID, int32 InstanceID) const
{
}

void UAthenaHUDContext::ShowMobilePicker()
{
}

void UAthenaHUDContext::ShowUrgentQuestMessage(const FUrgentQuestData& UrgentQuestData)
{
}

void UAthenaHUDContext::SimpleFireStart()
{
}

void UAthenaHUDContext::SimpleFireStop()
{
}

void UAthenaHUDContext::StartPostGameMenu() const
{
}

void UAthenaHUDContext::StopItemSelectionInputFromHUD(const int32 TouchIndex, const int32 SlotIdx, EFortQuickBars InQuickBar)
{
}

void UAthenaHUDContext::StopTargettingFromHUD()
{
}

void UAthenaHUDContext::SwapQuickBarFocusFromHUD(EFortQuickBars InQuickBar, int32 SlotOverride)
{
}

void UAthenaHUDContext::SwitchToPrimaryQuickbar()
{
}

void UAthenaHUDContext::TakeItemSelectionInputFromHUD(const int32 TouchIndex, const int32 SlotIdx, bool& bIsUsing, EFortQuickBars InQuickBar, bool bReloadOrUseIfAlreadySelected, bool bStopUseImmediately)
{
}

void UAthenaHUDContext::TakeLookInputFromHUD(FRotator LookRotator)
{
}

void UAthenaHUDContext::TakeLookStickInputFromHUD(const FVector2D LookStickPosition)
{
}

void UAthenaHUDContext::TakeMovementInputFromHUD(FVector2D MoveVector)
{
}

void UAthenaHUDContext::TryBestUseForActor(AActor* ActorToUse)
{
}

void UAthenaHUDContext::UpdateSelectedWidgetMoveOffsetVector(const FVector2D& VectorOffset, float fMoveScale)
{
}

void UAthenaHUDContext::UseOrRleoadFromHUDStart()
{
}

void UAthenaHUDContext::UseOrRleoadFromHUDStop()
{
}

bool UAthenaHUDContext::UseTapToShoot() const
{
	return false;
}

float UAthenaHUDContext::VictoryStingerTimeUntilFadeOut() const
{
	return float();
}
