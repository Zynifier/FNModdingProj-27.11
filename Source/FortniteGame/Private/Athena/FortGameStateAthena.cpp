// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortGameStateAthena.h"
#include "Net/UnrealNetwork.h"

bool AFortGameStateAthena::AreSkyTubesEnabled() const
{
	return false;
}

bool AFortGameStateAthena::CanChangeGameplayOptions()
{
	return false;
}

bool AFortGameStateAthena::CanRespawnOnStarterIsland() const
{
	return false;
}

FEvaluationResult AFortGameStateAthena::CanSpawnActor(const AActor* InstigatorActor, AActor* ActorToSpawn, const FVector& Location, const FRotator& Rotation) const
{
	return FEvaluationResult();
}

FEvaluationResult AFortGameStateAthena::CanSpawnActorOfClass(const AActor* InstigatorActor, UClass* ActorClassToSpawn, const FVector& Location, const FRotator& Rotation) const
{
	return FEvaluationResult();
}

bool AFortGameStateAthena::CanUseSlowMotionOnVictory()
{
	return false;
}

void AFortGameStateAthena::DoesPlayerHaveLimitedLives(AFortPlayerState* PlayerState, bool& bPlayerLivesAreLimited, int32& RespawnsRemaining) const
{
}

bool AFortGameStateAthena::EvaluateDBNOMutator(const AFortPlayerState* PS, FDBNOCustomSettings& OutDBNOSetting) const
{
	return false;
}

void AFortGameStateAthena::GatherCustomCharacterPartOverridesFromMutator(AFortPlayerController* FortPC, TArray<UCustomCharacterPart*>& OutOverrides)
{
}

FGameplayTagContainer AFortGameStateAthena::GetAthenaPlaylistContextTags() const
{
	return FGameplayTagContainer();
}

int32 AFortGameStateAthena::GetAvgPlayerMMR() const
{
	return int32();
}

UAthenaBattleBusItemDefinition* AFortGameStateAthena::GetBattleBusForPlayer(AFortPlayerControllerAthena* PC) const
{
	return nullptr;
}

FName AFortGameStateAthena::GetCurrentPlaylistName() const
{
	return FName();
}

int32 AFortGameStateAthena::GetDamageComboHUDMinHits() const
{
	return int32();
}

float AFortGameStateAthena::GetEndGameReturnToMatchmakingOriginDelay() const
{
	return float();
}

int32 AFortGameStateAthena::GetMaxPlaylistPlayers() const
{
	return int32();
}

AFortGameplayMutator* AFortGameStateAthena::GetMutatorByClass_Implementation(const AActor* ContextActor, TSubclassOf<AFortGameplayMutator> MutatorClass)
{
	return nullptr;
}

AFortGameplayMutator* AFortGameStateAthena::GetMutatorByInterface_Implementation(const AActor* ContextActor, UClass* MutatorInterface)
{
	return nullptr;
}

float AFortGameStateAthena::GetOverriddenVehicleTrickScore(const AFortPlayerController* Controller, float InTrickScore)
{
	return float();
}

float AFortGameStateAthena::GetOverridenDamageSelfDamageToDeal(const APawn* Pawn) const
{
	return float();
}

bool AFortGameStateAthena::GetOverridenDamageSelfRequiresNonZeroDamage(const APawn* Pawn) const
{
	return false;
}

FGameplayTagQuery AFortGameStateAthena::GetOverridenDamageSelfTargetQuery(const APawn* Pawn) const
{
	return FGameplayTagQuery();
}

FGameplayTagQuery AFortGameStateAthena::GetOverridenDamageSelfWeaponQuery(const APawn* Pawn) const
{
	return FGameplayTagQuery();
}

float AFortGameStateAthena::GetOverridenSiphonGoldValue(const APawn* Pawn) const
{
	return float();
}

float AFortGameStateAthena::GetOverridenSiphonHealthValue(const APawn* Pawn) const
{
	return float();
}

float AFortGameStateAthena::GetOverridenSiphonMetalValue(const APawn* Pawn) const
{
	return float();
}

float AFortGameStateAthena::GetOverridenSiphonStoneValue(const APawn* Pawn) const
{
	return float();
}

float AFortGameStateAthena::GetOverridenSiphonWoodValue(const APawn* Pawn) const
{
	return float();
}

AFortPartyRiftPortalManager* AFortGameStateAthena::GetPartyRiftPortalManager() const
{
	return nullptr;
}

FPlayersLeft AFortGameStateAthena::GetPlayersLeft() const
{
	return FPlayersLeft();
}

FPlayersLeft AFortGameStateAthena::GetPlayersLeftForUI() const
{
	return FPlayersLeft();
}

bool AFortGameStateAthena::GetPlaylistTeams(TArray<uint8>& OutTeams) const
{
	return false;
}

EFortPlaylistType AFortGameStateAthena::GetPlaylistType() const
{
	return EFortPlaylistType();
}

FGameplayTagContainer AFortGameStateAthena::GetPoiGridTagsForLocation(const FVector& Location) const
{
	return FGameplayTagContainer();
}

float AFortGameStateAthena::GetScoringModeWinningGoal()
{
	return float();
}

bool AFortGameStateAthena::GetShouldDisplayCountdownTimerText() const
{
	return false;
}

bool AFortGameStateAthena::GetShouldPlayRespawnTimerSFX() const
{
	return false;
}

TArray<AFortPlayerStateAthena*> AFortGameStateAthena::GetSquadMemberPlayerStates(AFortPlayerStateAthena* InstigatingPlayerState, const bool bIncludeSelf) const
{
	return TArray<AFortPlayerStateAthena*>();
}

FText AFortGameStateAthena::GetTeamPOIName(uint8 Team) const
{
	return FText();
}

float AFortGameStateAthena::GetTimedWinConditionTime() const
{
	return float();
}

FTotalPlayers AFortGameStateAthena::GetTotalPlayers() const
{
	return FTotalPlayers();
}

void AFortGameStateAthena::HandleContextTutorialGameModeMessageRequest(FAthenaGameMessageData MessageData, UFortContextualTutorialController* OwnedController)
{
}

void AFortGameStateAthena::HandleGameModeHideMarker(int32 PlayerID, int32 InstanceID)
{
}

void AFortGameStateAthena::HandleGameModeMessageDefaultPosition()
{
}

void AFortGameStateAthena::HandleGameModeMessageReposition(FVector2D Position, EHorizontalAlignment HorizontalAlignment, EVerticalAlignment VerticalAlignment)
{
}

void AFortGameStateAthena::HandleGameModeMessageRequest(FAthenaGameMessageData MessageData)
{
}

void AFortGameStateAthena::HandleGameModeMessageSuccess(AFortPlayerController* OwnerController)
{
}

void AFortGameStateAthena::HandleGameModeShowMarker(int32 PlayerID, int32 InstanceID)
{
}

void AFortGameStateAthena::HandleHideGameModeMessageRequest(const EAthenaGameMsgType MsgType, const bool bInstantHide, const bool bClearQueue, int32 MessageChannel)
{
}

bool AFortGameStateAthena::HasValidFocalPointActor() const
{
	return false;
}

void AFortGameStateAthena::InitializeAnimationSharing(const UFortPlaylistAthena* FortAthenaPlaylist)
{
}

bool AFortGameStateAthena::IsAnyCreativePlaylist() const
{
	return false;
}

bool AFortGameStateAthena::IsAsyncPhysicsPlaylist() const
{
	return false;
}

bool AFortGameStateAthena::IsBattleRoyalePlaylist(bool bExplicitCheck) const
{
	return false;
}

bool AFortGameStateAthena::IsCompetitivePlaylist() const
{
	return false;
}

bool AFortGameStateAthena::IsCreativeLTMPlaylist() const
{
	return false;
}

bool AFortGameStateAthena::IsCreativeMMPlaylist() const
{
	return false;
}

bool AFortGameStateAthena::IsCreativeModePlaylist() const
{
	return false;
}

bool AFortGameStateAthena::IsCreativeOrPlaygroundModePlaylist() const
{
	return false;
}

bool AFortGameStateAthena::IsCreativeRoyalePlaylist() const
{
	return false;
}

bool AFortGameStateAthena::IsCreativeUtilitySpawningAllowedPlaylist() const
{
	return false;
}

bool AFortGameStateAthena::IsExperiencePlayOnly() const
{
	return false;
}

bool AFortGameStateAthena::IsGamePhaseNotificationSkipped(EAthenaGamePhaseStep GamePhaseToSkip) const
{
	return false;
}

bool AFortGameStateAthena::IsGuidedTutorialPlaylist() const
{
	return false;
}

bool AFortGameStateAthena::IsLargePreviewDisabledOnMobile() const
{
	return false;
}

bool AFortGameStateAthena::IsLastManStandingCN() const
{
	return false;
}

bool AFortGameStateAthena::IsNoBuildBRPlaylist() const
{
	return false;
}

bool AFortGameStateAthena::IsPapayaPlaylist() const
{
	return false;
}

bool AFortGameStateAthena::IsPlayerClearPersistanceIslandDataAllowed(const APawn* SwitchingPawn) const
{
	return false;
}

bool AFortGameStateAthena::IsPlayerTriggeredRespawnAllowed(const AFortPlayerState* PlayerState) const
{
	return false;
}

bool AFortGameStateAthena::IsPlayerTriggeredRespawnAllowedByPlaylist() const
{
	return false;
}

bool AFortGameStateAthena::IsPlaygroundModePlaylist() const
{
	return false;
}

bool AFortGameStateAthena::IsSpatialGameplayExperience() const
{
	return false;
}

bool AFortGameStateAthena::IsTeamSwitchAllowed(const APawn* SwitchingPawn) const
{
	return false;
}

bool AFortGameStateAthena::IsTeleportToCreativeHubAllowed(const AFortPlayerState* PlayerState) const
{
	return false;
}

bool AFortGameStateAthena::IsTherePersistenceDevices(const APawn* SwitchingPawn) const
{
	return false;
}

bool AFortGameStateAthena::IsVKEditPlaylist() const
{
	return false;
}

bool AFortGameStateAthena::IsVKPlayPlaylist() const
{
	return false;
}

bool AFortGameStateAthena::IsWeaponReticleWidgetVisible(const AFortPlayerController* Controller, const AFortWeapon* Weapon) const
{
	return false;
}

bool AFortGameStateAthena::IsWorldResourceWidgetVisible(const AFortPlayerController* Controller, const EFortResourceType::Type ResourceType) const
{
	return false;
}

void AFortGameStateAthena::OnDownloadedAnyAdditionalContent(bool bSuccess)
{
}

void AFortGameStateAthena::OnLoadedAllAdditionalContent(bool bSuccess)
{
}

void AFortGameStateAthena::OnRep_AICharacterPartsPreloadData()
{
}

void AFortGameStateAthena::OnRep_AIPawnCustomizationPreloadData()
{
}

void AFortGameStateAthena::OnRep_BroadcastSpectatorInfo()
{
}

void AFortGameStateAthena::OnRep_ClientItemDefsToLoad()
{
}

void AFortGameStateAthena::OnRep_CurrentHighScore()
{
}

void AFortGameStateAthena::OnRep_CurrentPlaylistId()
{
}

void AFortGameStateAthena::OnRep_CurrentPlaylistInfo()
{
}

void AFortGameStateAthena::OnRep_EndGameKickPlayerTime()
{
}

void AFortGameStateAthena::OnRep_EventTournamentRound()
{
}

void AFortGameStateAthena::OnRep_FocalPointActor()
{
}

void AFortGameStateAthena::OnRep_GoldenPoiLocationTags()
{
}

void AFortGameStateAthena::OnRep_IsUsingDownloadOnDemand()
{
}

void AFortGameStateAthena::OnRep_MapInfo()
{
}

void AFortGameStateAthena::OnRep_MeshNetworkStatus()
{
}

void AFortGameStateAthena::OnRep_MutatorEventData()
{
}

void AFortGameStateAthena::OnRep_MutatorGenericInt_0()
{
}

void AFortGameStateAthena::OnRep_MutatorGenericInt_1()
{
}

void AFortGameStateAthena::OnRep_MutatorGenericInt_2()
{
}

void AFortGameStateAthena::OnRep_PlayerBotsLeft()
{
}

void AFortGameStateAthena::OnRep_PlayersLeft()
{
}

void AFortGameStateAthena::OnRep_PlayersLoaded()
{
}

void AFortGameStateAthena::OnRep_ReticulatedSplineDefinitions()
{
}

void AFortGameStateAthena::OnRep_ServerChangelistNumber()
{
}

void AFortGameStateAthena::OnRep_SkyTubesDisabled()
{
}

void AFortGameStateAthena::OnRep_SkyTubesShuttingDown()
{
}

void AFortGameStateAthena::OnRep_SpecialActorData()
{
}

void AFortGameStateAthena::OnRep_SpectateAPartyMemberAvailable()
{
}

void AFortGameStateAthena::OnRep_SupplyDropWaveStartedSoundCue()
{
}

void AFortGameStateAthena::OnRep_TeamsLeft()
{
}

void AFortGameStateAthena::OnRep_UtcTimeStartedMatch(const FDateTime& OldUtcTimeStartedMatch)
{
}

void AFortGameStateAthena::OnRep_VolumeManager()
{
}

void AFortGameStateAthena::OnRep_WantsHoldoverPluginOnClient()
{
}

void AFortGameStateAthena::OnRep_WinningPlayerList()
{
}

void AFortGameStateAthena::OnRep_WinningPlayerState()
{
}

void AFortGameStateAthena::OnRep_WinningScore()
{
}

void AFortGameStateAthena::OnRep_WinningTeam()
{
}

void AFortGameStateAthena::OnRep_WinningTeamsCN()
{
}

void AFortGameStateAthena::OverrideAllLocations_StateFontMaterial(UMaterialInterface* Mat, EMapLocationStateType State)
{
}

void AFortGameStateAthena::OverrideLocation_StateFontMaterial(const FGameplayTag& LocationTag, UMaterialInterface* Mat, EMapLocationStateType State)
{
}

bool AFortGameStateAthena::OverrideSpawnPercentage(const TSubclassOf<ABuildingContainer> BuildingContainerClass, const float SpawnPercentage)
{
	return false;
}

void AFortGameStateAthena::PauseFPSChartTimer()
{
}

void AFortGameStateAthena::RunPerfMemCheatScript_Client_Replicated_Implementation(bool bStartStatFiles)
{
}

void AFortGameStateAthena::SetAllLocations_StateColor(const FLinearColor& Color, EMapLocationStateType State)
{
}

void AFortGameStateAthena::SetCanSpawnLoot(const bool bInCanSpawnLoot)
{
}

void AFortGameStateAthena::SetDefaultParachuteDeployTraceForGroundDistance(const float InDefaultParachuteDeployTraceForGroundDistance)
{
}

void AFortGameStateAthena::SetFloatingIslandInformation(FVector WorldPosition, bool bActivated)
{
}

void AFortGameStateAthena::SetFocalPointActor(AActor* InFocalPointActor, FVector InFocalPointOffset, float InFocalPointFOV, float InDuration, float InInterpSpeed)
{
}

void AFortGameStateAthena::SetKillFeedFilter(const FGameplayTagContainer& NewFilter)
{
}

void AFortGameStateAthena::SetLocation_StateColor(const FGameplayTag& LocationTag, const FLinearColor& Color, EMapLocationStateType State)
{
}

void AFortGameStateAthena::SetLocationColor(const FGameplayTag& LocationTag, FLinearColor Color)
{
}

void AFortGameStateAthena::SetLocationColorInState(const FGameplayTag& LocationTag, FLinearColor Color, EMapLocationStateType State)
{
}

void AFortGameStateAthena::SetLocationFont(const FGameplayTag& LocationTag, const FSlateFontInfo& Font)
{
}

void AFortGameStateAthena::SetLocationFontInAllStates(const FGameplayTag& LocationTag, const FSlateFontInfo& Font)
{
}

void AFortGameStateAthena::SetLocationFontInState(const FGameplayTag& LocationTag, const FSlateFontInfo& Font, EMapLocationStateType State)
{
}

void AFortGameStateAthena::SetLocationText(const FGameplayTag& LocationTag, const FText& Text, EMapLocationStateType State)
{
}

void AFortGameStateAthena::SetLocationTextWorldPosition(const FGameplayTag& LocationTag, FVector Location)
{
}

bool AFortGameStateAthena::ShouldAllowKeepPlayingTogether()
{
	return false;
}

bool AFortGameStateAthena::ShouldAllowPartyRift()
{
	return false;
}

bool AFortGameStateAthena::ShouldAllowSquadSizeTracking()
{
	return false;
}

bool AFortGameStateAthena::ShouldBlockQuestProgressReport() const
{
	return false;
}

bool AFortGameStateAthena::ShouldBlockTrapPlacement(const APawn* Pawn) const
{
	return false;
}

bool AFortGameStateAthena::ShouldDBNOTeamInfoFlash() const
{
	return false;
}

bool AFortGameStateAthena::ShouldEnterSpawningStartup() const
{
	return false;
}

bool AFortGameStateAthena::ShouldHaveInfiniteResources(const APawn* Pawn) const
{
	return false;
}

bool AFortGameStateAthena::ShouldPlayDeathSoundEffects(const AActor* Victim) const
{
	return false;
}

bool AFortGameStateAthena::ShouldReturnToMatchmakingOriginOnMatchEnd() const
{
	return false;
}

void AFortGameStateAthena::UpdateAllGoldenPoiColor(FLinearColor Color, const FSlateFontInfo& Font)
{
}

void AFortGameStateAthena::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortGameStateAthena, bIsGrassFireBoundsUpdateEnabled);
	DOREPLIFETIME(AFortGameStateAthena, bIsUsingDownloadOnDemand);
	DOREPLIFETIME(AFortGameStateAthena, bWantsHoldoverPluginOnClient);
	DOREPLIFETIME(AFortGameStateAthena, bSkyTubesShuttingDown);
	DOREPLIFETIME(AFortGameStateAthena, bSkyTubesDisabled);
	DOREPLIFETIME(AFortGameStateAthena, ServerChangelistNumber);
	DOREPLIFETIME(AFortGameStateAthena, SpecialActorData);
	DOREPLIFETIME(AFortGameStateAthena, ReplOverrideData);
	DOREPLIFETIME(AFortGameStateAthena, EndGameStartTime);
	DOREPLIFETIME(AFortGameStateAthena, EndGameKickPlayerTime);
	DOREPLIFETIME(AFortGameStateAthena, TotalPlayers);
	DOREPLIFETIME(AFortGameStateAthena, PlayersLeft);
	DOREPLIFETIME(AFortGameStateAthena, PlayersLoaded);
	DOREPLIFETIME(AFortGameStateAthena, ClientVehicleClassesToLoad);
	DOREPLIFETIME(AFortGameStateAthena, ClientItemDefsToLoad);
	DOREPLIFETIME(AFortGameStateAthena, FocalPointActor);
	DOREPLIFETIME(AFortGameStateAthena, FocalPointRotationInterpSpeed);
	DOREPLIFETIME(AFortGameStateAthena, FocalPointOffset);
	DOREPLIFETIME(AFortGameStateAthena, FocalPointFOV);
	DOREPLIFETIME(AFortGameStateAthena, bCheatRespawnEnabled);
	DOREPLIFETIME(AFortGameStateAthena, TeamXPlayersLeft);
	DOREPLIFETIME(AFortGameStateAthena, WinningPlayerList);
	DOREPLIFETIME(AFortGameStateAthena, TeamsLeft);
	DOREPLIFETIME(AFortGameStateAthena, WinningTeamsCN);
	DOREPLIFETIME(AFortGameStateAthena, ServerToClientPreloadList);
	DOREPLIFETIME(AFortGameStateAthena, DefaultBattleBus);
	DOREPLIFETIME(AFortGameStateAthena, bAllowUserPickedCosmeticBattleBus);
	DOREPLIFETIME(AFortGameStateAthena, TeamFlightPaths);
	DOREPLIFETIME(AFortGameStateAthena, FlightPathMidLine);
	DOREPLIFETIME(AFortGameStateAthena, UtcTimeStartedMatch);
	DOREPLIFETIME(AFortGameStateAthena, bIsLargeTeamGame);
	DOREPLIFETIME(AFortGameStateAthena, WinningPlayerState);
	DOREPLIFETIME(AFortGameStateAthena, WinningTeam);
	DOREPLIFETIME(AFortGameStateAthena, WinningScore);
	DOREPLIFETIME(AFortGameStateAthena, CurrentHighScore);
	DOREPLIFETIME(AFortGameStateAthena, CurrentHighScoreTeam);
	DOREPLIFETIME(AFortGameStateAthena, SupplyDropWaveStartedSoundCue);
	DOREPLIFETIME(AFortGameStateAthena, bStormReachedFinalPosition);
	DOREPLIFETIME(AFortGameStateAthena, FriendlyFireType);
	DOREPLIFETIME(AFortGameStateAthena, SpectateAPartyMemberAvailable);
	DOREPLIFETIME(AFortGameStateAthena, GameMemberInfoArray);
	DOREPLIFETIME(AFortGameStateAthena, ActiveTeamNums);
	DOREPLIFETIME(AFortGameStateAthena, CurrentPlaylistId);
	DOREPLIFETIME(AFortGameStateAthena, MapInfo);
	DOREPLIFETIME(AFortGameStateAthena, BroadcastSpectatorInfo);
	DOREPLIFETIME(AFortGameStateAthena, AICharacterPartsPreloadData);
	DOREPLIFETIME(AFortGameStateAthena, AIPawnCustomizationPreloadData);
	DOREPLIFETIME(AFortGameStateAthena, ReasonWereInSetupPhase);
	DOREPLIFETIME(AFortGameStateAthena, EventTournamentRound);
	DOREPLIFETIME(AFortGameStateAthena, bIsCustomMatch);
	DOREPLIFETIME(AFortGameStateAthena, CurrentPlaylistInfo);
	DOREPLIFETIME(AFortGameStateAthena, TotalPlayersBots);
	DOREPLIFETIME(AFortGameStateAthena, PlayerBotsLeft);
	DOREPLIFETIME(AFortGameStateAthena, LobbyAction);
	DOREPLIFETIME(AFortGameStateAthena, MutatorEventData);
	DOREPLIFETIME(AFortGameStateAthena, MutatorObjectDataArray);
	DOREPLIFETIME(AFortGameStateAthena, MutatorGenericInt_0);
	DOREPLIFETIME(AFortGameStateAthena, MutatorGenericInt_1);
	DOREPLIFETIME(AFortGameStateAthena, MutatorGenericInt_2);
	DOREPLIFETIME(AFortGameStateAthena, DefaultGliderRedeployCanRedeploy);
	DOREPLIFETIME(AFortGameStateAthena, DefaultRedeployGliderLateralVelocityMult);
	DOREPLIFETIME(AFortGameStateAthena, DefaultRedeployGliderHeightLimit);
	DOREPLIFETIME(AFortGameStateAthena, DefaultParachuteDeployTraceForGroundDistance);
	DOREPLIFETIME(AFortGameStateAthena, DefaultAllowNeutralWallEditing);
	DOREPLIFETIME(AFortGameStateAthena, SignalInStormRegenSpeed);
	DOREPLIFETIME(AFortGameStateAthena, SignalInStormLostSpeed);
	DOREPLIFETIME(AFortGameStateAthena, StormCNDamageVulnerabilityLevel0);
	DOREPLIFETIME(AFortGameStateAthena, StormCNDamageVulnerabilityLevel1);
	DOREPLIFETIME(AFortGameStateAthena, StormCNDamageVulnerabilityLevel2);
	DOREPLIFETIME(AFortGameStateAthena, StormCNDamageVulnerabilityLevel3);
	DOREPLIFETIME(AFortGameStateAthena, MeshNetworkStatus);
	DOREPLIFETIME(AFortGameStateAthena, VolumeManager);
	DOREPLIFETIME(AFortGameStateAthena, PartyRiftPortalManager);
	DOREPLIFETIME(AFortGameStateAthena, LocalizationService);
	DOREPLIFETIME(AFortGameStateAthena, GoldenPoiLocationTags);
	DOREPLIFETIME(AFortGameStateAthena, RolledLootGroupTags);
	DOREPLIFETIME(AFortGameStateAthena, bEnvironmentDamageBlocked);
	DOREPLIFETIME(AFortGameStateAthena, ReticulatedSplineDefinitions);
	DOREPLIFETIME(AFortGameStateAthena, ReticulatedSplineIds);
	DOREPLIFETIME(AFortGameStateAthena, bDamageComboHUDEnabled);
	DOREPLIFETIME(AFortGameStateAthena, DamageComboHUDMinHits);
	DOREPLIFETIME(AFortGameStateAthena, MatchesProxyMatchId);
	DOREPLIFETIME(AFortGameStateAthena, DelayMovementInputReplicated);
	DOREPLIFETIME(AFortGameStateAthena, bCraftingEnabled);
}
