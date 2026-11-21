// Copyright Epic Games, Inc. All Rights Reserved.

#include "Context/FortHUDContext.h"

void UFortHUDContext::AddPointOfInterest(AActor* PointOfInterest, FText DisplayText, UTexture2D* DisplayImage, bool bSpecifyColor, FLinearColor ImageColor)
{
}

bool UFortHUDContext::AreHUDElementsVisible(const FGameplayTagContainer& HUDElementTags) const
{
	return false;
}

bool UFortHUDContext::AreIndicatorsEnabled() const
{
	return false;
}

void UFortHUDContext::EnterCameraMode()
{
}

void UFortHUDContext::EnterCursorMode(FName ActionName, UUserWidget* CursorModeWidget)
{
}

void UFortHUDContext::ForwardOnAbilityDecisionWindowStackUpdated()
{
}

void UFortHUDContext::ForwardOnMissionsUpdated()
{
}

void UFortHUDContext::ForwardOnNumSurvivorsRescuedChanged(int32 NumSurvivorsRescued)
{
}

void UFortHUDContext::ForwardOnWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon)
{
}

void UFortHUDContext::ForwardOnWeaponHudKeyActionUpdated(AFortWeapon* Weapon)
{
}

void UFortHUDContext::ForwardOnWeaponUnEquipped()
{
}

void UFortHUDContext::GetAccountLevelUpRewards(TArray<FFortItemQuantityPair>& Rewards, int32 AccountLevel) const
{
}

AFortBluGloManager* UFortHUDContext::GetBluGloManager() const
{
	return nullptr;
}

bool UFortHUDContext::GetBuildingActorInfo(ABuildingActor* BuildingActor, FFortFocusedBuildingInfo& OutBuildingInfo) const
{
	return false;
}

bool UFortHUDContext::GetCurrentBasicMissionInfo(FFortBasicMissionInfo& BasicMissionInfo) const
{
	return false;
}

ABuildingActor* UFortHUDContext::GetCurrentFocusedBuilding() const
{
	return nullptr;
}

UFortHero* UFortHUDContext::GetCurrentHero() const
{
	return nullptr;
}

const FFortHUDState& UFortHUDContext::GetCurrentHUDState() const
{
	static FFortHUDState Dummy;
	return Dummy;
}

FGameplayTagContainer UFortHUDContext::GetCurrentPrimaryMissionTags() const
{
	return FGameplayTagContainer();
}

void UFortHUDContext::GetDifficultyIncreaseRewards(int32 DifficultyIncreaseTier, TArray<FFortItemDelta>& DifficultyIncreaseRewards) const
{
}

void UFortHUDContext::GetDifficultyIncreaseRewardsDifference(int32 BaseDifficultyIncreaseTier, int32 ComparedDifficultyIncreaseTier, TArray<FFortItemDelta>& RewardDeltaInfo) const
{
}

int32 UFortHUDContext::GetDifficultyIncreaseRewardsTier() const
{
	return int32();
}

const TArray<FEarnedBadgeEntry> UFortHUDContext::GetEarnedBadges() const
{
	return TArray<FEarnedBadgeEntry>();
}

bool UFortHUDContext::GetFocusedBuildingInfo(FFortFocusedBuildingInfo& OutBuildingInfo) const
{
	return false;
}

AFortMission* UFortHUDContext::GetFocusedMission() const
{
	return nullptr;
}

AFortGameStateZone* UFortHUDContext::GetGameStateZone() const
{
	return nullptr;
}

void UFortHUDContext::GetHUDElementWidgetsForTags(const FGameplayTagContainer& HUDElementTags, TArray<UFortHUDElementWidget*>& OutWidgets)
{
}

EFortIndicatorState UFortHUDContext::GetIndicatorsState() const
{
	return EFortIndicatorState();
}

bool UFortHUDContext::GetLocalPlayerHasLosingPlacement() const
{
	return false;
}

bool UFortHUDContext::GetLocalPlayerHasPlacement() const
{
	return false;
}

bool UFortHUDContext::GetLocalPlayerHasWinningPlacement() const
{
	return false;
}

int32 UFortHUDContext::GetLocalPlayerPlacement() const
{
	return int32();
}

AFortMissionManager* UFortHUDContext::GetMissionManager() const
{
	return nullptr;
}

TArray<FZoneLoadingScreenHeadingConfig> UFortHUDContext::GetMissionOverviewObjectives() const
{
	return TArray<FZoneLoadingScreenHeadingConfig>();
}

void UFortHUDContext::GetMissionRewards(TArray<UFortItem*>& MissionRewards, TArray<UFortItem*>& MissionAlertRewards) const
{
}

int32 UFortHUDContext::GetNumAllowedDifficultyIncreases() const
{
	return int32();
}

AFortPlayerStateZone* UFortHUDContext::GetPlayerStateZone() const
{
	return nullptr;
}

const TArray<FFortBadgeCount> UFortHUDContext::GetPotentialBadges() const
{
	return TArray<FFortBadgeCount>();
}

float UFortHUDContext::GetScoreDisplayFactor() const
{
	return float();
}

float UFortHUDContext::GetTimeToDelayEndOfDayZoneWidgetDisplay() const
{
	return float();
}

void UFortHUDContext::HandleActorFocusedForCreative(AActor* NewActor)
{
}

void UFortHUDContext::HandleBuildingModeChanged(bool bEntering)
{
}

void UFortHUDContext::HandleFocusedBuildingAbilitySystemComponentInitialized()
{
}

void UFortHUDContext::HandleLocalPawnDied(const FFortPlayerDeathReport& DeathReport)
{
}

void UFortHUDContext::HandleLocalPawnRevived(const AController* EventInstigator)
{
}

void UFortHUDContext::HandleLocalPawnSpawned()
{
}

void UFortHUDContext::HandleLocalPlayerBuildCostChanged()
{
}

void UFortHUDContext::HandleLocalPlayerKillsChanged()
{
}

void UFortHUDContext::HandleLocalPlayerPlaceChanged()
{
}

void UFortHUDContext::HandleLocalPlayerViewTargetChanged()
{
}

void UFortHUDContext::HandlePersonalVehicleModeChanged(bool bEnteredVehicle)
{
}

void UFortHUDContext::HandleSpectatorViewTargetChanged()
{
}

void UFortHUDContext::HandleToggledBattleMapLive(ABattleMapPawnLive* NewSpectatorPawn)
{
}

void UFortHUDContext::HandleUIGameplayCue(FName CueName, EGameplayCueEvent::Type EventType, const FGameplayCueParameters& Parameters)
{
}

void UFortHUDContext::HandleVehicleStateChanged(AFortPlayerPawn* PlayerPawn, AActor* NewVehicle, AActor* OldVehicle)
{
}

void UFortHUDContext::HideAerialFeedback()
{
}

bool UFortHUDContext::IsContextTutorialActive(FGameplayTag TutorialType) const
{
	return false;
}

bool UFortHUDContext::IsInCursorMode() const
{
	return false;
}

bool UFortHUDContext::IsInEditMode() const
{
	return false;
}

bool UFortHUDContext::IsLocalChallengesVisible() const
{
	return false;
}

bool UFortHUDContext::IsPreparingMgmtMenu() const
{
	return false;
}

bool UFortHUDContext::PreviewItemPickUp(const UFortItem* InItem, const EFortQuickBars InQuickBarType, int32& OutSlotIndex, TMap<int32, int32>& OutItemsToPush, TArray<int32>& OutItemsToDrop)
{
	return false;
}

void UFortHUDContext::RemovePointOfInterest(AActor* PointOfInterest)
{
}

void UFortHUDContext::RequestMgmtMenuTab(FName TabName)
{
}

void UFortHUDContext::RequestPromptDisplay(const FFortHUDTagPromptData& PromptData, const FGameplayTag& Tag)
{
}

void UFortHUDContext::SendFocusedBuildingDynamicData(const UFocusedBuildingDynamicData* DynamicData) const
{
}

void UFortHUDContext::SetCursorModeLocked(bool bLocked)
{
}

void UFortHUDContext::SetHUDElementVisibility(const FGameplayTagContainer& HUDElementTags, bool bHideElements, const FName& ReasonName)
{
}

void UFortHUDContext::SetIndicatorsAllowed(bool bIndicatorsAllowed)
{
}

void UFortHUDContext::SetIndicatorsState(EFortIndicatorState NewState)
{
}

void UFortHUDContext::SetIsLocalChallengesVisible(bool bIsVisible)
{
}

void UFortHUDContext::SetPreparingMgmtMenu(bool bPreparing)
{
}

bool UFortHUDContext::ShouldOnlyShowNextPrevBuildingSlotKeybinds() const
{
	return false;
}

void UFortHUDContext::ShowAerialFeedback(const FName BoundActionName, const FText& FeedbackText)
{
}

void UFortHUDContext::ToggleFullscreenMap() const
{
}

void UFortHUDContext::TriggerCooldownUpdate()
{
}

void UFortHUDContext::UpdateTrapAttachedToBuilding()
{
}
