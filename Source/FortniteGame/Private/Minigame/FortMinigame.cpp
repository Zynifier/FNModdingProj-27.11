// Copyright Epic Games, Inc. All Rights Reserved.

#include "Minigame/FortMinigame.h"
#include "Net/UnrealNetwork.h"

void AFortMinigame::AccumulateTimeAliveForAlivePlayer(FMinigamePlayer& PlayerEntry)
{
}

void AFortMinigame::AddExtensionWidget(const FUIExtension& NewExtension)
{
}

void AFortMinigame::AddMinigameActor(AActor* Actor)
{
}

void AFortMinigame::AddMinigameComponent(UFortMinigameLogicComponent* MinigameComponent)
{
}

void AFortMinigame::AddMinigamePlayer(AFortPlayerState* PlayerState, bool bForceSpawn)
{
}

void AFortMinigame::AddOrOverrideEndCondition(const FFortMinigameStatQuery& StatQuery)
{
}

void AFortMinigame::AddOrOverrideEndConditionForTeam(uint8 TeamIndex, const FFortMinigameStatQuery& StatQuery)
{
}

void AFortMinigame::AddPersistenceRequirement()
{
}

void AFortMinigame::AddPlayerSpawnOverrideDevice(AActor* InOverrideDevice)
{
}

void AFortMinigame::AddToFireVolumesForMinigame(const AGameplayVolume* FireVolume, const EDeviceFireVolumeFireOption FireOption)
{
}

void AFortMinigame::AdvanceState()
{
}

void AFortMinigame::ApplyMutatorsToPlayer(AFortPlayerState* PlayerState, bool bResetCurrentVitals)
{
}

bool AFortMinigame::AreEnoughPlayersLeftToContinueMatch()
{
	return false;
}

bool AFortMinigame::AreTeamsAsymmetrical() const
{
	return false;
}

void AFortMinigame::BroadcastStatsChangedDelegate()
{
}

void AFortMinigame::CancelPendingClassSlotChange(AFortPlayerState* PlayerState, uint8 PendingClassSlot)
{
}

bool AFortMinigame::CanPlayerRespawn(const AFortPlayerState* InPlayerState) const
{
	return false;
}

bool AFortMinigame::CanStartMinigame() const
{
	return false;
}

void AFortMinigame::CheckEndConditions()
{
}

void AFortMinigame::CheckEndConditionsInternal()
{
}

bool AFortMinigame::CheckRemainingLivingPlayersForEndCondition()
{
	return false;
}

AActor* AFortMinigame::ChoosePlayerStart(AController* Player, bool bCheckEnemy, bool bNearTeammates)
{
	return nullptr;
}

void AFortMinigame::ClearFireVolumesForMinigame()
{
}

void AFortMinigame::ClearPlayerInventory(AFortPlayerControllerAthena* PlayerController, bool bPreventDrop)
{
}

void AFortMinigame::ClearTeleportForMinigame(AFortPlayerPawn* InPawn)
{
}

void AFortMinigame::DeclareWinnerImmediately(int32 WinningBucket)
{
}

bool AFortMinigame::DetermineSpawnLocation(AFortPlayerStateAthena* PlayerState, FVector& OutLocation, FRotator& OutRotation, bool& bOutRespawningOnGround)
{
	return false;
}

void AFortMinigame::DisableCustomScoreboard()
{
}

bool AFortMinigame::DoAllPlayersHaveSpawnLocation(EFortMinigamePlayerSpawnLocationSetting SpawnLocation) const
{
	return false;
}

bool AFortMinigame::DoesTimerCountDown() const
{
	return false;
}

void AFortMinigame::EnableCustomScoreboard(const float InDisplayTime)
{
}

void AFortMinigame::EndGame(AFortPlayerController* InstigatorPC, EFortMinigameEnd EndMethod)
{
}

bool AFortMinigame::EvaluateStatQuery(const FMinigameEndCondition& InEndCondition, const int32 PlayerBucketIndex) const
{
	return false;
}

bool AFortMinigame::ForceRespawn(AFortPlayerState* PlayerState, FGameplayTagContainer& RespawnReasons)
{
	return false;
}

FText AFortMinigame::FormatStat(UFortMinigameStatFilter* InStat, int32 InValue)
{
	return FText();
}

bool AFortMinigame::GetAirSpawnLocation(FVector& OutLocation, FRotator& OutRotation, AFortPlayerStateAthena* PlayerState)
{
	return false;
}

int32 AFortMinigame::GetBucketForPlayerId(const FUniqueNetIdRepl& PlayerId, bool bMatchCurrentTeam) const
{
	return int32();
}

int32 AFortMinigame::GetBucketForPlayerState(const APlayerState* PlayerState, bool bMatchCurrentTeam) const
{
	return int32();
}

int32 AFortMinigame::GetBucketForTeamIndex(int32 TeamIndex) const
{
	return int32();
}

bool AFortMinigame::GetBucketWinCount(int32& WinCount, const int32 BucketIndex) const
{
	return false;
}

FName AFortMinigame::GetClassScopeForPlayer(const AFortPlayerState* PlayerState) const
{
	return FName();
}

uint8 AFortMinigame::GetClassSlotForActor(const AActor* Actor, const bool bUseDeathInfo) const
{
	return uint8();
}

uint8 AFortMinigame::GetClassSlotForPlayer(const AFortPlayerState* PlayerState, const bool bUseDeathInfo) const
{
	return uint8();
}

bool AFortMinigame::GetClassSlotInventory(uint8 ClassSlotIndex, TArray<FItemAndCount>& InventoryItems) const
{
	return false;
}

FText AFortMinigame::GetClassSlotName(uint8 ClassSlotIndex) const
{
	return FText();
}

bool AFortMinigame::GetClassSlotVisibleInUI(uint8 ClassSlotIndex) const
{
	return false;
}

void AFortMinigame::GetColumnSortedScoreboardRows(TArray<FMinigameScoreboardBucketRow>& OutScoreboardRows, const TArray<UFortMinigameStatFilter*>& RowSortOrder, const TArray<UFortMinigameStatFilter*>& ColumnSortOrder, bool bGameTotal, bool bHighlighting, bool bCountWins, bool bIsCareerScoreboard, EMinigameScoreboardStates ScoreboardState) const
{
}

int32 AFortMinigame::GetCurrentRoundWinner() const
{
	return int32();
}

bool AFortMinigame::GetCurrentRoundWinnerName(FText& OutName) const
{
	return false;
}

void AFortMinigame::GetCustomScoreboardSettings(bool& bOutCustomScoreboardEnabled, float& OutCustomScoreboardDisplayTime) const
{
}

uint8 AFortMinigame::GetDefaultClassSlot(const AFortPlayerState* PlayerState) const
{
	return uint8();
}

bool AFortMinigame::GetEndConditionForStatIfAny(const uint8 TeamNumber, UFortMinigameStatFilter* InStat, FMinigameEndCondition& OutEndCondition)
{
	return false;
}

bool AFortMinigame::GetEndConditionValueForStatIfAny(const uint8 TeamNumber, UFortMinigameStatFilter* InStat, int32& OutValue)
{
	return false;
}

int32 AFortMinigame::GetInitTeamSizeWeight(uint8 TeamIndex) const
{
	return int32();
}

int32 AFortMinigame::GetMaxInitTeamSize(uint8 TeamIndex) const
{
	return int32();
}

int32 AFortMinigame::GetMaxLivesForPlayer(const AFortPlayerState* PlayerState) const
{
	return int32();
}

void AFortMinigame::GetMinigameComponentsByTagQuery(TArray<UFortMinigameLogicComponent*>& OutComponents, const FGameplayTagQuery& TagQuery) const
{
}

EMinigameFullscreenMapWidgetType AFortMinigame::GetMinigameMapPanelDisplayType() const
{
	return EMinigameFullscreenMapWidgetType();
}

int32 AFortMinigame::GetMinigameNumTeams() const
{
	return int32();
}

bool AFortMinigame::GetOrderedMinigameStatsRows(TArray<FMinigameStatRow>& OutStats)
{
	return false;
}

void AFortMinigame::GetParticipatingPlayers(TArray<AFortPlayerState*>& OutPlayers) const
{
}

void AFortMinigame::GetParticipatingPlayersForMinigame(TArray<AFortPlayerState*>& OutPlayers) const
{
}

void AFortMinigame::GetPersistencePlayers(TArray<AFortPlayerState*>& PersistencePlayers) const
{
}

int32 AFortMinigame::GetPlayerCount(bool bIncludeSpectators) const
{
	return int32();
}

int32 AFortMinigame::GetPlayerPlacement(const APlayerState* PlayerState) const
{
	return int32();
}

const TArray<AFortPlayerState*> AFortMinigame::GetPlayersOrdered() const
{
	return TArray<AFortPlayerState*>();
}

const TArray<AActor*>& AFortMinigame::GetPlayerSpawnOverrideDevices() const
{
	static TArray<AActor*> Dummy;
	return Dummy;
}

void AFortMinigame::GetPlayerStartComponentsByTagQuery(TArray<UFortMinigamePlayerStartComponent*>& OutPlayerStartComponents, const FGameplayTagQuery& TagQuery)
{
}

void AFortMinigame::GetPlayersWithClassSlot(uint8 ClassSlot, TArray<AFortPlayerState*>& OutPlayers) const
{
}

float AFortMinigame::GetPostGameResetDelay(EFortMinigameEnd EndMethod) const
{
	return float();
}

float AFortMinigame::GetPostGameTimeRemaining() const
{
	return float();
}

int32 AFortMinigame::GetRoundBasedGameWinnerName(FText& OutName) const
{
	return int32();
}

int32 AFortMinigame::GetRoundBasedGameWinnerNameOrTeam(FText& OutName) const
{
	return int32();
}

int32 AFortMinigame::GetRoundWinner(int32 Round) const
{
	return int32();
}

float AFortMinigame::GetRuntime() const
{
	return float();
}

bool AFortMinigame::GetScoreboardRowForPlayer(const AFortPlayerState* PlayerState, FMinigameScoreboardPlayerRow& OutScoreboardRow, const TArray<UFortMinigameStatFilter*>& SortOrder, bool bGameTotal, bool bHighlighting, bool bCountWins, EMinigameScoreboardStates ScoreboardState, bool bIncludeInactivePlayers) const
{
	return false;
}

void AFortMinigame::GetScoreboardStateTimes(TArray<float>& OutStateTimes)
{
}

bool AFortMinigame::GetSpawnLocationByTag(FVector& OutLocation, FRotator& OutRotation, AFortPlayerStateAthena* PlayerState, const FGameplayTag& SpawnTag, bool bUseVolumeOnFail) const
{
	return false;
}

EFortMinigamePlayerSpawnLocationSetting AFortMinigame::GetSpawnLocationSetting(const AFortPlayerState* PlayerState) const
{
	return EFortMinigamePlayerSpawnLocationSetting();
}

int32 AFortMinigame::GetStandingsForPlayer(const AFortPlayerState* InPlayerState, UFortMinigameStatFilter* InFilter, TArray<FMinigameStatRow>& OutStatRows, int32 RowsReturned)
{
	return int32();
}

FGameplayTagQuery AFortMinigame::GetStartQueryForPlayer_Implementation(APlayerState* Player)
{
	return FGameplayTagQuery();
}

int32 AFortMinigame::GetTeamColorIndex(uint8 TeamIndex) const
{
	return int32();
}

uint8 AFortMinigame::GetTeamIndexForCosmeticDetails(uint8 TeamIndex) const
{
	return uint8();
}

void AFortMinigame::GetTeamMembers(uint8 TeamIndex, TArray<AFortPlayerState*>& OutTeamMembers) const
{
}

FText AFortMinigame::GetTeamName(uint8 TeamIndex) const
{
	return FText();
}

uint8 AFortMinigame::GetTeamToSwapToWhenOutOfSpawns(const AFortPlayerState* PlayerState) const
{
	return uint8();
}

UFortCreativeTeleporterManagerComponent* AFortMinigame::GetTeleporterManagerComponent()
{
	return nullptr;
}

float AFortMinigame::GetTimeRemaining() const
{
	return float();
}

float AFortMinigame::GetTimeRemainingUntilAutoStart() const
{
	return float();
}

bool AFortMinigame::GetVehiclesDamageObjectsMiniGame() const
{
	return false;
}

bool AFortMinigame::GetVehiclesDamageVehiclesMiniGame() const
{
	return false;
}

float AFortMinigame::GetWarmupTimeRemaining() const
{
	return float();
}

uint8 AFortMinigame::GetWinningTeamIndexFromTeamIndex(const uint8 InTeamIndex) const
{
	return uint8();
}

void AFortMinigame::HandleMinigameComponentAdded_Implementation(UFortMinigameLogicComponent* MinigameComponent)
{
}

void AFortMinigame::HandleMinigameComponentInPlayChanged_Implementation(UFortMinigameLogicComponent* MinigameComponent)
{
}

void AFortMinigame::HandleMinigameComponentRemoved_Implementation(UFortMinigameLogicComponent* MinigameComponent)
{
}

void AFortMinigame::HandleMinigameEnded_Implementation()
{
}

void AFortMinigame::HandleMinigameStarted_Implementation()
{
}

void AFortMinigame::HandleMinigameWarmup_Implementation()
{
}

void AFortMinigame::HandlePostMinigameStarted_Implementation()
{
}

void AFortMinigame::HandleReplicationComplete(AFortPlayerControllerAthena* PlayerController)
{
}

bool AFortMinigame::HasMinigameStarter() const
{
	return false;
}

bool AFortMinigame::HasPlayerStartPads_Implementation(const AFortPlayerState* InPlayerState) const
{
	return false;
}

bool AFortMinigame::HasStarted() const
{
	return false;
}

bool AFortMinigame::HasTimeLimit() const
{
	return false;
}

void AFortMinigame::HighlightTopStats(TArray<FMinigameScoreboardBucketRow>& InOutScoreboardRows)
{
}

bool AFortMinigame::IsActorPositionInsideTerrain(AActor* Actor, FHitResult& OutHit)
{
	return false;
}

bool AFortMinigame::IsAnyPlayerSpawnLimited() const
{
	return false;
}

bool AFortMinigame::IsCuratedHub() const
{
	return false;
}

bool AFortMinigame::IsGameSessionInBackfillMode() const
{
	return false;
}

bool AFortMinigame::IsGameWinnerShown() const
{
	return false;
}

bool AFortMinigame::IsHub() const
{
	return false;
}

bool AFortMinigame::IsInPlayMode() const
{
	return false;
}

bool AFortMinigame::IsInProgress() const
{
	return false;
}

bool AFortMinigame::IsInSetup() const
{
	return false;
}

bool AFortMinigame::IsInWarmup() const
{
	return false;
}

bool AFortMinigame::IsLastRound() const
{
	return false;
}

bool AFortMinigame::IsLocationBlockedForTeleport(AFortPlayerState* PlayerState, FVector LocationToCheck, FRotator RotationToCheck)
{
	return false;
}

bool AFortMinigame::IsLocationInsideTerrain(FVector Location, FHitResult& OutHit)
{
	return false;
}

bool AFortMinigame::IsMinigameActor(AActor* Actor) const
{
	return false;
}

bool AFortMinigame::IsMinigameComponent(UFortMinigameLogicComponent* MinigameComponent) const
{
	return false;
}

bool AFortMinigame::IsMinigameStarter(AFortPlayerController* PlayerController) const
{
	return false;
}

bool AFortMinigame::IsMinigameStarting() const
{
	return false;
}

bool AFortMinigame::IsPlayerInMinigame(const AFortPlayerState* PlayerState, bool bCheckSpectatingPlayers) const
{
	return false;
}

bool AFortMinigame::IsPlayerInMinigameByNetId(const FUniqueNetIdRepl& UniqueNetId, bool bCheckSpectatingPlayers) const
{
	return false;
}

bool AFortMinigame::IsPlayerInOurVolume(AFortPlayerState* PlayerState) const
{
	return false;
}

bool AFortMinigame::IsPlayerLocationBlockedForTeleport(AFortPlayerPawnAthena* PlayerPawn)
{
	return false;
}

bool AFortMinigame::IsPlayerOnGameWinningTeam(AFortPlayerState* PlayerState) const
{
	return false;
}

bool AFortMinigame::IsPlayerOnRoundWinningTeam(AFortPlayerState* PlayerState) const
{
	return false;
}

bool AFortMinigame::IsPlayerOutOfLives(const AFortPlayerState* InPlayerState, const bool bOnlyMinigamePlayers) const
{
	return false;
}

bool AFortMinigame::IsPlayerSpectatingMinigame(const AFortPlayerState* PlayerState) const
{
	return false;
}

FPlayerStartCompatibilityInfo AFortMinigame::IsPlayerStartCompatibleWithPlayer(AController* Player, AFortPlayerStartCreative* PlayerStart) const
{
	return FPlayerStartCompatibilityInfo();
}

bool AFortMinigame::IsPlayerTeleportingOrRespawningForGameplay(AFortPlayerStateAthena* PlayerToCheck) const
{
	return false;
}

bool AFortMinigame::IsPlayerUsingClassSlot(AFortPlayerState* PlayerState, uint8 ClassSlot) const
{
	return false;
}

bool AFortMinigame::IsPostGame() const
{
	return false;
}

bool AFortMinigame::IsPregame() const
{
	return false;
}

bool AFortMinigame::IsTeamMinigame() const
{
	return false;
}

bool AFortMinigame::IsTransitioning() const
{
	return false;
}

bool AFortMinigame::IsWaitingForCameras() const
{
	return false;
}

bool AFortMinigame::IsWinningPlayerId(const FUniqueNetIdRepl& PlayerId) const
{
	return false;
}

bool AFortMinigame::IsWinningPlayerState(const APlayerState* PlayerState) const
{
	return false;
}

void AFortMinigame::K2_EnteredVolumeEvent_Implementation(AFortPlayerState* PlayerState)
{
}

void AFortMinigame::K2_ExitedVolumeEvent_Implementation(AFortPlayerState* LeftPlayerState)
{
}

void AFortMinigame::K2_HasStarted(EFortMinigameExec& OutExec)
{
}

void AFortMinigame::K2_IsInProgress(EFortMinigameExec& OutExec)
{
}

void AFortMinigame::LTMFlowSetMatchmakingBackfillAndJoinInProgress(bool bEnable, bool bDisableBeaconRequests)
{
}

void AFortMinigame::MinigamePlayerNameReplicated(const FUniqueNetIdRepl& NetId)
{
}

void AFortMinigame::MoveMinigamePlayerToSpectate(AFortPlayerState* PlayerState)
{
}

void AFortMinigame::NativeEnteredVolumeEvent(AFortPlayerState* PlayerState)
{
}

void AFortMinigame::NativeExitedVolumeEvent(AFortPlayerState* LeftPlayerState)
{
}

void AFortMinigame::OnAllMinigamePlayerBotsSpawned()
{
}

void AFortMinigame::OnBeginSpectating(AFortPlayerStateZone* FPSZ)
{
}

bool AFortMinigame::OnCheckIfClientIsSafeToRespawn(AFortPlayerControllerAthena* PlayerController)
{
	return false;
}

void AFortMinigame::OnClientFinishTeleportingForMinigame(AFortPlayerPawn* InPawn)
{
}

void AFortMinigame::OnEndGameReturnPlayersFromMatchmaking()
{
}

void AFortMinigame::OnFortPlayerDied(AFortPlayerPawnAthena* FortPlayerPawnAthena)
{
}

void AFortMinigame::OnInGameLoadScreenChanged(AFortPlayerControllerAthena* PlayerController, bool bEnableLoadScreen, FText HUDReasonText)
{
}

void AFortMinigame::OnMinigameStatChanged(AController* InStatOwner, UFortMinigameStatFilter* TrackedStatClass, int32 Count)
{
}

void AFortMinigame::OnPawnTeleported(AFortPawn* FortPawn)
{
}

void AFortMinigame::OnPlayerPawnPossessedDuringMinigame(APawn* PlayerPawn)
{
}

void AFortMinigame::OnPlayerPawnPossessedDuringTransition(APawn* PlayerPawn)
{
}

void AFortMinigame::OnPlayerStateTeamIndexChanged()
{
}

void AFortMinigame::OnRep_AllowPartyMemberJoinInProgress()
{
}

void AFortMinigame::OnRep_bPipHudAdEnabled()
{
}

void AFortMinigame::OnRep_bRequestPostGameResetUI()
{
}

void AFortMinigame::OnRep_ClassSlotArray()
{
}

void AFortMinigame::OnRep_CurrentRound()
{
}

void AFortMinigame::OnRep_CurrentState()
{
}

void AFortMinigame::OnRep_MinigamePlayer()
{
}

void AFortMinigame::OnRep_PlayerBuckets()
{
}

void AFortMinigame::OnRep_PlayerSpawnOverrideDevices()
{
}

void AFortMinigame::OnRep_ServerTime()
{
}

void AFortMinigame::OnRep_StatsChanged()
{
}

void AFortMinigame::OnRep_TeamArray()
{
}

void AFortMinigame::OnRep_UIExtensionTags()
{
}

void AFortMinigame::OnRep_Volume()
{
}

void AFortMinigame::OnTimeLimitElapsed()
{
}

void AFortMinigame::OnVolumeStateChanged(FEventMessageTag Channel, const FSpatialGamePlayActorLoadingStateUpdatedContext& StateContext)
{
}

bool AFortMinigame::OverridePlayerSpawnLocation_Implementation(APawn* PlayerPawn, AFortPlayerStateAthena* PlayerState, FVector& OutLocation, FRotator& OutRotation, bool& bOutRespawningOnGround)
{
	return false;
}

void AFortMinigame::PostGameReset_Guard(FEventMessageTag Channel, const FSpatialGamePlayActorLoadingStateUpdatedContext& StateContext)
{
}

void AFortMinigame::PostGameResetPlayers()
{
}

void AFortMinigame::PutPlayerControllerIntoStasis(AFortPlayerController* PlayerController)
{
}

void AFortMinigame::PutPlayerIntoStasis(APawn* PlayerPawn)
{
}

void AFortMinigame::QueueAllAIForDespawn()
{
}

void AFortMinigame::RecheckInventory(APawn* PlayerPawn)
{
}

void AFortMinigame::RefreshGameRulesPreview()
{
}

void AFortMinigame::RefreshIndicatorPlayersCache()
{
}

void AFortMinigame::RefreshVoiceForPlayer(AFortPlayerState* PlayerState)
{
}

void AFortMinigame::RefreshVoiceForPlayers()
{
}

void AFortMinigame::RegisterVolumeAsNavigationObserver()
{
}

void AFortMinigame::ReleasePlayerFromStasis(APawn* PlayerPawn)
{
}

void AFortMinigame::RemoveEndCondition(const FFortMinigameStatQuery& StatQuery)
{
}

void AFortMinigame::RemoveEndConditionForTeam(uint8 TeamIndex, const FFortMinigameStatQuery& StatQuery)
{
}

void AFortMinigame::RemoveExtensionWidget(const FUIExtension& ExtensionToRemove)
{
}

void AFortMinigame::RemoveFromFireVolumesForMinigame(const AGameplayVolume* FireVolume)
{
}

void AFortMinigame::RemoveMinigameActor(AActor* Actor)
{
}

void AFortMinigame::RemoveMinigameComponent(UFortMinigameLogicComponent* MinigameComponent)
{
}

void AFortMinigame::RemoveMinigamePlayer(AFortPlayerState* PlayerState)
{
}

void AFortMinigame::RemovePersistenceRequirement()
{
}

void AFortMinigame::RemovePlayerSpawnOverrideDevice(AActor* InOverrideDevice)
{
}

void AFortMinigame::ResetStats()
{
}

void AFortMinigame::RestartMinigame_Implementation(AFortPlayerController* InstigatorPC)
{
}

void AFortMinigame::ServerEventLogMinigameState(EFortMinigameState NewState, int32 Duration)
{
}

void AFortMinigame::ServerEventLogRoundEnded(AFortPlayerController* InstigatorPC, EFortMinigameEnd EndMethod, EFortMinigameState NextState)
{
}

void AFortMinigame::ServerEventLogScoreChanged(EFortQuestObjectiveStatEvent Type, UObject* TargetObject, AFortPlayerController* PlayerController, const FGameplayTagContainer& TargetTags, const FGameplayTagContainer& SourceTags, const FGameplayTagContainer& ContextTags, int32 Count)
{
}

bool AFortMinigame::SetClassSlotForPlayer(AFortPlayerState* PlayerState, uint8 NewClassSlot, FOnPlayerChangedClass OnComplete, bool bRespawnPlayer, bool bResetCurrentVitals, bool bClearAllItems, float ClassSwitchDelay)
{
	return false;
}

void AFortMinigame::SetClassSlotInventory(uint8 ClassSlotIndex, const TArray<FItemAndCount>& InventoryItems)
{
}

void AFortMinigame::SetClassSlotName(uint8 ClassSlotIndex, const FText& ClassName)
{
}

void AFortMinigame::SetClassSlotVisibleInUI(uint8 ClassSlotIndex, const bool bVisibleInUI)
{
}

void AFortMinigame::SetInitTeamSizeWeightForTeam(uint8 TeamIndex, int32 TeamSizeWeight)
{
}

void AFortMinigame::SetLapTimeStat(AFortPlayerController* PlayerController, const float LapTimeSeconds)
{
}

void AFortMinigame::SetMaxInitTeamSizeForTeam(uint8 TeamIndex, int32 TeamSize)
{
}

void AFortMinigame::SetMinigameNumTeams(int32 InNumTeams)
{
}

void AFortMinigame::SetPipHudAdEnabled(const bool bInEnable)
{
}

void AFortMinigame::SetPlayerHealthStat(AFortPlayerState* FortPlayerState, const int32 Health)
{
}

bool AFortMinigame::SetPvPTeamForPlayer(AFortPlayerState* PlayerState, int32 Team, bool bTemporary)
{
	return false;
}

void AFortMinigame::SetRaceProgressStat(AFortPlayerController* PlayerController, const float NormalizedRaceProgress)
{
}

void AFortMinigame::SetRaceTimeStat(AFortPlayerController* PlayerController, const float RaceTimeSeconds)
{
}

void AFortMinigame::SetRoundVictoryAnimation(const ERoundVictoryAnimation NewRoundVictoryAnimation)
{
}

void AFortMinigame::SetShouldShowPreGameCountdownBars(const bool bInShowPreGameCountdownBars)
{
}

void AFortMinigame::SetTeamColorIndexForTeam(uint8 TeamIndex, int32 TeamColorIndex)
{
}

bool AFortMinigame::SetTeamForPlayer(AFortPlayerState* PlayerState, uint8 NewTeam, bool bTemporary, bool bChangeTeamWithoutRespawn, bool bResetVitalsOnSwitch)
{
	return false;
}

void AFortMinigame::SetUseTeamScore(uint8 TeamIndex, bool bUseTeamScore)
{
}

void AFortMinigame::SetVehiclesDamageObjectsMiniGame(const bool bInVehiclesDamageObjectsMinigame)
{
}

void AFortMinigame::SetVehiclesDamageVehiclesMiniGame(const bool bInVehiclesDamageVehiclesMinigame)
{
}

void AFortMinigame::SetWinningTeamIndex(const uint8 InWinningTeamIndex)
{
}

bool AFortMinigame::ShouldDropOrDestroyItem_Implementation(bool& bShouldDrop, bool& bShouldDestroy, AController* PC, const UFortWorldItemDefinition* ItemDef) const
{
	return false;
}

bool AFortMinigame::ShouldRotateTeams() const
{
	return false;
}

bool AFortMinigame::ShouldShowPreGameCountdownBars() const
{
	return false;
}

void AFortMinigame::StartMinigame_Implementation(AFortPlayerController* InstigatorPC)
{
}

void AFortMinigame::ToggleAutoRestartMinigame()
{
}

void AFortMinigame::UnregisterVolumeAsNavigationObserver(USceneComponent* RegisteredComponent)
{
}

void AFortMinigame::UpdateTimeAliveForAlivePlayers()
{
}

void AFortMinigame::UpdateTimeAliveStat(AController* PlayerController, const bool bAccumulate)
{
}

bool AFortMinigame::UseTeamScore(uint8 TeamIndex) const
{
	return false;
}

bool AFortMinigame::UseTeamScoring() const
{
	return false;
}

bool AFortMinigame::WasInProgress() const
{
	return false;
}

void AFortMinigame::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortMinigame, UIExtensionTags);
	DOREPLIFETIME(AFortMinigame, TimeLimit);
	DOREPLIFETIME(AFortMinigame, CurrentRound);
	DOREPLIFETIME(AFortMinigame, TotalRounds);
	DOREPLIFETIME(AFortMinigame, PlayerArray);
	DOREPLIFETIME(AFortMinigame, InactivePlayerArray);
	DOREPLIFETIME(AFortMinigame, SpectatingPlayerArray);
	DOREPLIFETIME(AFortMinigame, EndConditionArray);
	DOREPLIFETIME(AFortMinigame, bIncludePlayersWhoLeftGameInScoreboard);
	DOREPLIFETIME(AFortMinigame, bAllowPartyMemberJoinInProgress);
	DOREPLIFETIME(AFortMinigame, PlayerSpawnOverrideDevices);
	DOREPLIFETIME(AFortMinigame, DisplayName);
	DOREPLIFETIME(AFortMinigame, AutoStartDelay);
	DOREPLIFETIME(AFortMinigame, SpawnLocationSetting);
	DOREPLIFETIME(AFortMinigame, PostGameSpawnLocationSetting);
	DOREPLIFETIME(AFortMinigame, SpawnPadSelection);
	DOREPLIFETIME(AFortMinigame, WarmupDuration);
	DOREPLIFETIME(AFortMinigame, PostGameResetDelay);
	DOREPLIFETIME(AFortMinigame, GameWinnerDisplayTime);
	DOREPLIFETIME(AFortMinigame, GameScoreDisplayTime);
	DOREPLIFETIME(AFortMinigame, RoundWinnerDisplayTime);
	DOREPLIFETIME(AFortMinigame, RoundScoreDisplayTime);
	DOREPLIFETIME(AFortMinigame, bTimerCountsDown);
	DOREPLIFETIME(AFortMinigame, bSlowMotionOnEndOfRound);
	DOREPLIFETIME(AFortMinigame, RoundVictoryAnimation);
	DOREPLIFETIME(AFortMinigame, TeamArray);
	DOREPLIFETIME(AFortMinigame, ClassSlotArray);
	DOREPLIFETIME(AFortMinigame, CurrentState);
	DOREPLIFETIME(AFortMinigame, bRequestPostGameResetUI);
	DOREPLIFETIME(AFortMinigame, MaxLivesForPlayer);
	DOREPLIFETIME(AFortMinigame, ServerTime);
	DOREPLIFETIME(AFortMinigame, bStopwatchMode);
	DOREPLIFETIME(AFortMinigame, Volume);
	DOREPLIFETIME(AFortMinigame, bSortScoreboardEntries);
	DOREPLIFETIME(AFortMinigame, bTeamMinigame);
	DOREPLIFETIME(AFortMinigame, bTeamsAreStable);
	DOREPLIFETIME(AFortMinigame, NumTeams);
	DOREPLIFETIME(AFortMinigame, bAllowJoinInProgress);
	DOREPLIFETIME(AFortMinigame, MinigameStarter);
	DOREPLIFETIME(AFortMinigame, TeamRotationCount);
	DOREPLIFETIME(AFortMinigame, bStableTeamCosmetics);
	DOREPLIFETIME(AFortMinigame, MinigameMapWidget);
	DOREPLIFETIME(AFortMinigame, bShowMapWidget);
	DOREPLIFETIME(AFortMinigame, bShowScoreboardMapWidget);
	DOREPLIFETIME(AFortMinigame, bShowCareerScoreboardMapWidget);
	DOREPLIFETIME(AFortMinigame, bShowPreGameCountdownBars);
	DOREPLIFETIME(AFortMinigame, WinCondition);
	DOREPLIFETIME(AFortMinigame, MinigamePlayerPawnType);
	DOREPLIFETIME(AFortMinigame, bOnlyAllowRespawningIfPlayerStartPadsFound);
	DOREPLIFETIME(AFortMinigame, GameEndCallout);
	DOREPLIFETIME(AFortMinigame, VictoryAudioIndex);
	DOREPLIFETIME(AFortMinigame, DrawAudioIndex);
	DOREPLIFETIME(AFortMinigame, DefeatAudioIndex);
	DOREPLIFETIME(AFortMinigame, bShowCumulativeScoreboard);
	DOREPLIFETIME(AFortMinigame, PostGameSettings);
	DOREPLIFETIME(AFortMinigame, bIsSpawningBotsForMinigameStart);
	DOREPLIFETIME(AFortMinigame, bAllowFriendlyFire);
	DOREPLIFETIME(AFortMinigame, bForceIndividualScoresInTeamGame);
	DOREPLIFETIME(AFortMinigame, bVehiclesDamageObjectsMinigame);
	DOREPLIFETIME(AFortMinigame, bVehiclesDamageVehiclesMinigame);
	DOREPLIFETIME(AFortMinigame, NumMinigameComponentsServer);
	DOREPLIFETIME(AFortMinigame, bVolumeNavigationHasBuilt);
	DOREPLIFETIME(AFortMinigame, RoundWinHistory);
	DOREPLIFETIME(AFortMinigame, PlayerBuckets);
	DOREPLIFETIME(AFortMinigame, bPipHudAdEnabled);
	DOREPLIFETIME(AFortMinigame, PersistenceRequiredDevices);
}
