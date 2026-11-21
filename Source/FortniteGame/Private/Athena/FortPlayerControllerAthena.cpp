// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortPlayerControllerAthena.h"
#include "Net/UnrealNetwork.h"

void AFortPlayerControllerAthena::BroadcastDeviceButtonComponentClickedDelegate(const UFortCreativeDeviceButtonComponent* DeviceButtonComponent)
{
}

void AFortPlayerControllerAthena::BroadcastOnHUDMessageToggled(const FHUDMessageData& HUDMessageData, bool bShowMessage)
{
}

void AFortPlayerControllerAthena::BroadcastOnPickupProjectileCreated(UFortItemDefinition* ItemDefinition)
{
}

void AFortPlayerControllerAthena::CancelCreativeMatchmakingReadyCheck() const
{
}

void AFortPlayerControllerAthena::CancelMatchmaking(EMatchmakingCancelReasonV2 CancelReason)
{
}

bool AFortPlayerControllerAthena::CanFollowSpecialActor() const
{
	return false;
}

bool AFortPlayerControllerAthena::CanPlayerCreateInCurrentVolume(AFortVolume*& OutCurrentVolume) const
{
	return false;
}

void AFortPlayerControllerAthena::CheckIfClientLoadedLTM()
{
}

void AFortPlayerControllerAthena::CheckIfLevelStreamingCompleteForHandshake()
{
}

void AFortPlayerControllerAthena::CheckIfSafeToRespawn()
{
}

void AFortPlayerControllerAthena::CheckIfSafeToTurnOnCamera()
{
}

void AFortPlayerControllerAthena::ClearDroppableItems(bool bAllowShouldDropItemOverride)
{
}

void AFortPlayerControllerAthena::ClearInventorySpaces(int32 NumSpaces)
{
}

void AFortPlayerControllerAthena::ClearPendingMinigameSpawnData()
{
}

void AFortPlayerControllerAthena::ClearRespawnAfterDeathTimer()
{
}

void AFortPlayerControllerAthena::Client_DisplayQuestUpdate_Implementation(const TArray<FFortDisplayQuestUpdateData>& UpdateData)
{
}

void AFortPlayerControllerAthena::Client_DisplayReceivedMultipleInstanceLoot_Implementation(const TArray<FGiftUINotificationInfo>& ItemsReceived)
{
}

void AFortPlayerControllerAthena::ClientAddProfileGoCollection_Implementation(const FString& CollectionName, const TArray<FProfileGoScenario>& NewScenarios)
{
}

void AFortPlayerControllerAthena::ClientAlertForcedOffIsland_Implementation()
{
}

void AFortPlayerControllerAthena::ClientAlertLeaveIsland_Implementation()
{
}

void AFortPlayerControllerAthena::ClientAlertPortalDoneTeleporting_Implementation()
{
}

void AFortPlayerControllerAthena::ClientAutoEquipFirstItem_Implementation(FGuid ItemGuid, bool bForceExecution)
{
}

void AFortPlayerControllerAthena::ClientBotStartDogpile_Implementation(FVector DogpilePosition)
{
}

void AFortPlayerControllerAthena::ClientBotStopDogpile_Implementation()
{
}

void AFortPlayerControllerAthena::ClientBroadcastOnDestroyCreativePlotFinished_Implementation(bool bSuccess, const FText& Reason)
{
}

void AFortPlayerControllerAthena::ClientBroadcastOnDuplicateCreativePlotFinished_Implementation(bool bSuccess, const FText& Reason)
{
}

void AFortPlayerControllerAthena::ClientBroadcastOnMakeNewCreativePlotFinished_Implementation(bool bSuccess, const FText& Reason)
{
}

void AFortPlayerControllerAthena::ClientBroadcastOnRestoreCreativePlotFinished_Implementation(bool bSuccess, const FText& Reason)
{
}

void AFortPlayerControllerAthena::ClientBroadcastOnUpdateCreativeDescriptionTags_Implementation(bool bSuccess, const FText& Reason)
{
}

void AFortPlayerControllerAthena::ClientBroadcastOnUpdateCreativePlotName_Implementation(bool bSuccess, const FText& Reason)
{
}

void AFortPlayerControllerAthena::ClientBroadcastPlotItemID_Implementation(const FString& PlotID)
{
}

void AFortPlayerControllerAthena::ClientChangeCustomGamepadActionBindings_Implementation(const TArray<FFortActionKeyMapping>& Mappings)
{
}
bool AFortPlayerControllerAthena::ClientChangeCustomGamepadActionBindings_Validate(const TArray<FFortActionKeyMapping>& Mappings)
{
	return true;
}

void AFortPlayerControllerAthena::ClientCheckIfSafeToTurnOnCamera_Implementation()
{
}

void AFortPlayerControllerAthena::ClientCreativeTimerDeviceClearRequested_Implementation(AFortCreativeTimerDevice* TimerDevice)
{
}

void AFortPlayerControllerAthena::ClientCreativeTimerDeviceUpdateRequested_Implementation(AFortCreativeTimerDevice* TimerDevice, uint8 CurrentState, float ServerTimeFinished)
{
}

void AFortPlayerControllerAthena::ClientCycleQuickBarToCreativeItem_Implementation(const FGuid& CreativeItemGuid, const UFortWorldItemDefinition* CreativeItemDef)
{
}

void AFortPlayerControllerAthena::ClientDownloadedContentForLinkCodeResult_Implementation(const FOnlineLinkId& LinkId, bool bSuccess, const FString& ErrorMessage)
{
}
bool AFortPlayerControllerAthena::ClientDownloadedContentForLinkCodeResult_Validate(const FOnlineLinkId& LinkId, bool bSuccess, const FString& ErrorMessage)
{
	return true;
}

void AFortPlayerControllerAthena::ClientEnterCameraMode_Implementation()
{
}

void AFortPlayerControllerAthena::ClientFadeCameraForScoreScreen_Implementation()
{
}

void AFortPlayerControllerAthena::ClientFadeCameraPreMinigameTeleport_Implementation()
{
}

void AFortPlayerControllerAthena::ClientFinishTeleportingForMinigame_Implementation(FRotator Rotation)
{
}

void AFortPlayerControllerAthena::ClientHideScreenWhileRespawning_Implementation(const FText& HUDReasonText)
{
}

void AFortPlayerControllerAthena::ClientMarkSkydivePathsComplete_Implementation()
{
}

void AFortPlayerControllerAthena::ClientMutatorEvent_Implementation(AFortGameplayMutator* Mutator, int32 EventId, int32 PayloadData)
{
}

void AFortPlayerControllerAthena::ClientNotifyAbortRespawn_Implementation()
{
}

void AFortPlayerControllerAthena::ClientNotifyLost_Implementation(APawn* WinningPawn, EEndOfMatchReason LostReason)
{
}

void AFortPlayerControllerAthena::ClientNotifyTeamLost_Implementation()
{
}

void AFortPlayerControllerAthena::ClientNotifyTeamWon_Implementation(APawn* FinisherPawn, const UFortWeaponItemDefinition* FinishingWeapon, EDeathCause DeathCause)
{
}

void AFortPlayerControllerAthena::ClientNotifyWon_Implementation(APawn* FinisherPawn, const UFortWeaponItemDefinition* FinishingWeapon, EDeathCause DeathCause)
{
}

void AFortPlayerControllerAthena::ClientOnCreativePlotReported_Implementation(bool bWasSuccessful, const FOnlineLinkId& LinkId)
{
}

void AFortPlayerControllerAthena::ClientPreviewScreenshotModeActivated_Implementation(bool bSuccess, bool bForceQuit)
{
}

void AFortPlayerControllerAthena::ClientPublishCreativePlotComplete_Implementation(const FString& ResultErrorCode, const FString& LinkJson)
{
}

void AFortPlayerControllerAthena::ClientReceiveSquadQuickChatMessage_Implementation(FAthenaQuickChatActiveEntry ChatEntry, AFortPlayerController* SenderPC)
{
}

void AFortPlayerControllerAthena::ClientReportPhaseFound_Implementation(const FString& Phase)
{
}

void AFortPlayerControllerAthena::ClientReportTournamentPlacementPointsScored_Implementation(int32 Placement, int32 PointsEarned)
{
}

void AFortPlayerControllerAthena::ClientRequestLevelStreamingHandshake_Implementation()
{
}

void AFortPlayerControllerAthena::ClientSendDebugPoiLocationTags_Implementation(const FGameplayTagContainer& InPoiTags)
{
}

void AFortPlayerControllerAthena::ClientSendDebugPoiVolumeData_Implementation(const FString& PoiVolumes)
{
}

void AFortPlayerControllerAthena::ClientSendEndBattleRoyaleMatchForPlayer_Implementation(bool bSuccess, const FAthenaRewardResult& Result)
{
}

void AFortPlayerControllerAthena::ClientSendEndMatchReportHeartbeat_Implementation()
{
}

void AFortPlayerControllerAthena::ClientSendMatchStatsForPlayer_Implementation(const FAthenaMatchStats& Stats)
{
}

void AFortPlayerControllerAthena::ClientSendStateEncryptionKey_Implementation(const FPlayerStateEncryptionKey& Key)
{
}

void AFortPlayerControllerAthena::ClientSendTeamStatsForPlayer_Implementation(const FAthenaMatchTeamStats& TeamStats)
{
}

void AFortPlayerControllerAthena::ClientSetDeathReport_Implementation(FFortPlayerDeathReport InDeathReport)
{
}

void AFortPlayerControllerAthena::ClientSetStreamingTestStreamingLevels_Implementation(bool streaming)
{
}

void AFortPlayerControllerAthena::ClientSignalPortalLoadCompleteViaDelegate_Implementation(const FAsyncTaskResult& Result)
{
}

void AFortPlayerControllerAthena::ClientStartRespawnPreparation_Implementation(FVector RespawnLoc, FRotator RespawnRot, float RespawnCameraDist, FName InRespawnCameraBehavior, const FText& HUDReasonText)
{
}

void AFortPlayerControllerAthena::ClientStartWaitLTMLoading_Implementation()
{
}

void AFortPlayerControllerAthena::ClientStopWaitLTMLoading_Implementation()
{
}

void AFortPlayerControllerAthena::ClientSwitchToCreatorCustomController_Implementation(const FString& ConfigName, const TArray<FFortActionKeyMapping>& Mappings)
{
}
bool AFortPlayerControllerAthena::ClientSwitchToCreatorCustomController_Validate(const FString& ConfigName, const TArray<FFortActionKeyMapping>& Mappings)
{
	return true;
}

void AFortPlayerControllerAthena::ClientTeleportToPlaygroundLobbyIsland_Implementation()
{
}

void AFortPlayerControllerAthena::ClientTryEndRebootInteraction_Implementation()
{
}

void AFortPlayerControllerAthena::ClientUnloadedContentForLinkCodeResult_Implementation(const FOnlineLinkId& LinkId, bool bSuccess, const FString& ErrorMessage)
{
}
bool AFortPlayerControllerAthena::ClientUnloadedContentForLinkCodeResult_Validate(const FOnlineLinkId& LinkId, bool bSuccess, const FString& ErrorMessage)
{
	return true;
}

void AFortPlayerControllerAthena::ClientUpdateDuel_Implementation(const EDuelState DuelState, const FDuelOverlayData& DuelOverlayData)
{
}

void AFortPlayerControllerAthena::ClientUpdateGeneratedSkydivePath_Implementation(const FString& LocationStr, const FVector& DropLocationStr, const FVector& GlideLocationStr, const FVector& LandingLocationStr)
{
}

void AFortPlayerControllerAthena::ClientVkSessionModeratorLinkCodeReceived_Implementation(bool bSuccess, const FOnlineLinkId& OnlineLink)
{
}

void AFortPlayerControllerAthena::DestroyCreativePlot_Implementation(const FString& IslandId)
{
}
bool AFortPlayerControllerAthena::DestroyCreativePlot_Validate(const FString& IslandId)
{
	return true;
}

void AFortPlayerControllerAthena::DuplicateCreativePlot_Implementation(const FString& IslandId, const FString& Locale, const FString& Title)
{
}
bool AFortPlayerControllerAthena::DuplicateCreativePlot_Validate(const FString& IslandId, const FString& Locale, const FString& Title)
{
	return true;
}

void AFortPlayerControllerAthena::EnableCreativeContentManagerBasedOnPlaylist()
{
}

void AFortPlayerControllerAthena::FollowSpecialActor()
{
}

int32 AFortPlayerControllerAthena::GetCachedHighlightCount()
{
	return int32();
}

AFortVolume* AFortPlayerControllerAthena::GetCreativePlotLinkedVolume() const
{
	return nullptr;
}

UCreativeUserContentManager* AFortPlayerControllerAthena::GetCreativeUserContentManager() const
{
	return nullptr;
}

EFortVolumeType AFortPlayerControllerAthena::GetCurrentExperienceType() const
{
	return EFortVolumeType();
}

AFortVolume* AFortPlayerControllerAthena::GetCurrentVolumeOrCreativePlotLinkedVolume() const
{
	return nullptr;
}

AFortGameStateAthena* AFortPlayerControllerAthena::GetGameStateAthena() const
{
	return nullptr;
}

bool AFortPlayerControllerAthena::GetIgnoreSpectatorViewRotation() const
{
	return false;
}

int32 AFortPlayerControllerAthena::GetInventorySpace() const
{
	return int32();
}

bool AFortPlayerControllerAthena::GetIsSpectating() const
{
	return false;
}

UAthenaPlayerMatchReport* AFortPlayerControllerAthena::GetMatchReport()
{
	return nullptr;
}

int32 AFortPlayerControllerAthena::GetMaxNumberOfPlots()
{
	return int32();
}

int32 AFortPlayerControllerAthena::GetOverflowCountIfItemWasAddedToInventory(const FFortItemEntry& ItemEntry) const
{
	return int32();
}

AFortAthenaPartyRiftPortal* AFortPlayerControllerAthena::GetPartyRiftPortal() const
{
	return nullptr;
}

const FText& AFortPlayerControllerAthena::GetPlaylistGameTypeText() const
{
	static FText Dummy;
	return Dummy;
}

UFortPlaysetItemDefinition* AFortPlayerControllerAthena::GetPlayset() const
{
	return nullptr;
}

void AFortPlayerControllerAthena::GetPlaysetSize(int32& SizeX, int32& SizeY, int32& SizeZ) const
{
}

int32 AFortPlayerControllerAthena::GetProfilePlotEntries(bool bIncludeDeleted)
{
	return int32();
}

void AFortPlayerControllerAthena::GetSquadKills(TArray<int32>& Kills) const
{
}

int32 AFortPlayerControllerAthena::GetSquadKillsCount() const
{
	return int32();
}

TArray<AFortPlayerStateAthena*> AFortPlayerControllerAthena::GetSquadMemberPlayerStates(const bool bIncludeSelf) const
{
	return TArray<AFortPlayerStateAthena*>();
}

void AFortPlayerControllerAthena::GetTrackedVictims(AFortPlayerStateAthena*& EliminatedVictim, AFortPlayerStateAthena*& DownedVictim) const
{
}

UFortControllerComponent_TransientQuests* AFortPlayerControllerAthena::GetTransientQuestsComponent() const
{
	return nullptr;
}

void AFortPlayerControllerAthena::HandlePlayersLeftChanged(int32 NumPlayersLeft)
{
}

bool AFortPlayerControllerAthena::HasItems(const TArray<EFortItemType>& ExcludedItemTypes) const
{
	return false;
}

bool AFortPlayerControllerAthena::HasPartyRiftPortal() const
{
	return false;
}

bool AFortPlayerControllerAthena::HasPendingMinigameSpawnData() const
{
	return false;
}

void AFortPlayerControllerAthena::HighlightNumberReturned(int32 NumHighlights)
{
}

bool AFortPlayerControllerAthena::IsClientNotifiedOfLoss() const
{
	return false;
}

bool AFortPlayerControllerAthena::IsClientNotifiedOfTeamWin() const
{
	return false;
}

bool AFortPlayerControllerAthena::IsClientNotifiedOfWin() const
{
	return false;
}

bool AFortPlayerControllerAthena::IsInPublicMatchmadeCreativeMinigame() const
{
	return false;
}

bool AFortPlayerControllerAthena::IsLoadingScreenActive()
{
	return false;
}

bool AFortPlayerControllerAthena::IsMatchmaking() const
{
	return false;
}

bool AFortPlayerControllerAthena::IsOnPublishedIsland() const
{
	return false;
}

bool AFortPlayerControllerAthena::IsPartyMemberReadyCheckStatusInProgress() const
{
	return false;
}

bool AFortPlayerControllerAthena::IsPiPFullScreen() const
{
	return false;
}

bool AFortPlayerControllerAthena::IsPlayerInAMinigame() const
{
	return false;
}

bool AFortPlayerControllerAthena::IsPlayerInAVolumeTheyCanCreateIn() const
{
	return false;
}

bool AFortPlayerControllerAthena::IsPlayerInFeaturedExperience() const
{
	return false;
}

bool AFortPlayerControllerAthena::IsPlayerInPublishedExperience() const
{
	return false;
}

bool AFortPlayerControllerAthena::IsPlayerInReadOnlyExperience() const
{
	return false;
}

bool AFortPlayerControllerAthena::IsPlayerRebootingNow() const
{
	return false;
}

bool AFortPlayerControllerAthena::IsTeleportingToLobby() const
{
	return false;
}

bool AFortPlayerControllerAthena::IsTryToFireRestrictedByTypeCooldowns() const
{
	return false;
}

bool AFortPlayerControllerAthena::IsUnderPlotLimit(int32& MaxIslands, int32& NumIslands, bool bIncludeDeleted)
{
	return false;
}

void AFortPlayerControllerAthena::MakeNewCreativePlot_Implementation(const UFortCreativeRealEstatePlotItemDefinition* PlotType, const FString& Locale, const FString& Title)
{
}
bool AFortPlayerControllerAthena::MakeNewCreativePlot_Validate(const UFortCreativeRealEstatePlotItemDefinition* PlotType, const FString& Locale, const FString& Title)
{
	return true;
}

void AFortPlayerControllerAthena::MakeNewCreativePlotFromLinkCode_Implementation(const FString& LinkCode, const FString& Locale, const FString& Title)
{
}
bool AFortPlayerControllerAthena::MakeNewCreativePlotFromLinkCode_Validate(const FString& LinkCode, const FString& Locale, const FString& Title)
{
	return true;
}

void AFortPlayerControllerAthena::MultiKillExpired()
{
}

void AFortPlayerControllerAthena::NotifyCinematicCameraSkipped_Implementation()
{
}
bool AFortPlayerControllerAthena::NotifyCinematicCameraSkipped_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::OnClientEnterVolume(APlayerState* InPlayerState, AFortVolume* InVolume)
{
}

void AFortPlayerControllerAthena::OnClientVolumeManagerReplicated()
{
}

void AFortPlayerControllerAthena::OnCreativePlotLinkedVolumeMinigameChanged(AFortMinigame* Minigame)
{
}

void AFortPlayerControllerAthena::OnFortPlayerPawnAthenaDied(AFortPlayerPawnAthena* FortPlayerPawnAthena)
{
}

void AFortPlayerControllerAthena::OnMatchmakingPartyReady() const
{
}

void AFortPlayerControllerAthena::OnMinigameEnded()
{
}

void AFortPlayerControllerAthena::OnMinigameStarted()
{
}

void AFortPlayerControllerAthena::OnPostGameForced_Implementation()
{
}
bool AFortPlayerControllerAthena::OnPostGameForced_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::OnRep_CreativeIslands()
{
}

void AFortPlayerControllerAthena::OnRep_CreativePlotLinkedVolume()
{
}

void AFortPlayerControllerAthena::OnRep_FocalPoint()
{
}

void AFortPlayerControllerAthena::OnRep_SkydiveLeader()
{
}

void AFortPlayerControllerAthena::OnRep_TrackedVictimsShared()
{
}

void AFortPlayerControllerAthena::OnServerMarkerAdded(const FFortWorldMarkerData& MarkerData)
{
}

void AFortPlayerControllerAthena::PartyLeaderReadyUpOrStartMatchmaking(const FOnlineLinkId& LinkId, bool& bOutDidStartMatchmakingImmediately, const bool bIsPrivateMatch)
{
}

void AFortPlayerControllerAthena::PostLobbyIslandTeleport(AFortPlayerPawn* PlayerPawn)
{
}

void AFortPlayerControllerAthena::PreLobbyIslandTeleport()
{
}

void AFortPlayerControllerAthena::PrepareClientForRespawning()
{
}

void AFortPlayerControllerAthena::PublishCreativePlot_Implementation(AFortVolume* VolumeToPublish, FCreativePublishOptions MyPublishOptions)
{
}
bool AFortPlayerControllerAthena::PublishCreativePlot_Validate(AFortVolume* VolumeToPublish, FCreativePublishOptions MyPublishOptions)
{
	return true;
}

void AFortPlayerControllerAthena::QuickWeapon1()
{
}

void AFortPlayerControllerAthena::QuickWeapon2()
{
}

void AFortPlayerControllerAthena::QuickWeapon3()
{
}

void AFortPlayerControllerAthena::QuickWeapon4()
{
}

void AFortPlayerControllerAthena::RecordContentDownloadModules()
{
}

void AFortPlayerControllerAthena::RecordMatchStats()
{
}

void AFortPlayerControllerAthena::RecordTeamStats()
{
}

void AFortPlayerControllerAthena::ReduceDroppableResources(const float ReductionPercentage)
{
}

void AFortPlayerControllerAthena::RemoveAllInventoryItems()
{
}

void AFortPlayerControllerAthena::RemoveDroppableItems()
{
}

void AFortPlayerControllerAthena::RemoveDroppableTaggedItems(const FGameplayTagContainer GameplayTagContainer)
{
}

void AFortPlayerControllerAthena::ReportCreativePlot_Implementation(const FString& PrivateIslandOwnerID, const FString& PlotInstanceId)
{
}
bool AFortPlayerControllerAthena::ReportCreativePlot_Validate(const FString& PrivateIslandOwnerID, const FString& PlotInstanceId)
{
	return true;
}

void AFortPlayerControllerAthena::RequestFocalPoint_Implementation(AActor* InFocalPoint, FVector InFocalPointOffset, float InFocalPointFOV)
{
}
bool AFortPlayerControllerAthena::RequestFocalPoint_Validate(AActor* InFocalPoint, FVector InFocalPointOffset, float InFocalPointFOV)
{
	return true;
}

void AFortPlayerControllerAthena::ResetMyCurrentCreativePlot_Implementation()
{
}
bool AFortPlayerControllerAthena::ResetMyCurrentCreativePlot_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::RespawnPlayerAfterDeath(bool bEnterSkydiving)
{
}

void AFortPlayerControllerAthena::RespawnTurnCameraBackOn()
{
}

void AFortPlayerControllerAthena::RestoreCreativePlot_Implementation(const FString& IslandId)
{
}
bool AFortPlayerControllerAthena::RestoreCreativePlot_Validate(const FString& IslandId)
{
	return true;
}

void AFortPlayerControllerAthena::SendClientPhysicsBallStateToServer_Implementation(AFortPhysicsPawnObject* PhysicsObject, const float ClientPing, const FTimeStampedPhysicsPawnState ClientBallState)
{
}
bool AFortPlayerControllerAthena::SendClientPhysicsBallStateToServer_Validate(AFortPhysicsPawnObject* PhysicsObject, const float ClientPing, const FTimeStampedPhysicsPawnState ClientBallState)
{
	return true;
}

void AFortPlayerControllerAthena::SendPhysicsBallHitToServer_Implementation(AFortPhysicsPawnObject* PhysicsObject, const float ClientPing, APawn* HittingPawn, const FVector VelocityOfHitter, const FVector HitNormal, const FTimeStampedPhysicsPawnState ClientBallState)
{
}
bool AFortPlayerControllerAthena::SendPhysicsBallHitToServer_Validate(AFortPhysicsPawnObject* PhysicsObject, const float ClientPing, APawn* HittingPawn, const FVector VelocityOfHitter, const FVector HitNormal, const FTimeStampedPhysicsPawnState ClientBallState)
{
	return true;
}

void AFortPlayerControllerAthena::ServerAddDownloadOnDemandContent_Implementation(const FOnlineLinkId& LinkId)
{
}
bool AFortPlayerControllerAthena::ServerAddDownloadOnDemandContent_Validate(const FOnlineLinkId& LinkId)
{
	return true;
}

void AFortPlayerControllerAthena::ServerAddToCachedPurchased_Implementation(UFortItemDefinition* ItemDefinition, int32 Count)
{
}
bool AFortPlayerControllerAthena::ServerAddToCachedPurchased_Validate(UFortItemDefinition* ItemDefinition, int32 Count)
{
	return true;
}

void AFortPlayerControllerAthena::ServerAlertForceOthersOffIsland_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerAlertForceOthersOffIsland_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerBeginEndPreview_Implementation(bool bInBegin)
{
}
bool AFortPlayerControllerAthena::ServerBeginEndPreview_Validate(bool bInBegin)
{
	return true;
}

void AFortPlayerControllerAthena::ServerBroadcastDeviceButtonComponentClickedDelegate_Implementation(const UFortCreativeDeviceButtonComponent* DeviceButtonComponent)
{
}
bool AFortPlayerControllerAthena::ServerBroadcastDeviceButtonComponentClickedDelegate_Validate(const UFortCreativeDeviceButtonComponent* DeviceButtonComponent)
{
	return true;
}

void AFortPlayerControllerAthena::ServerClaimPortal_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerClaimPortal_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerClearSkydiveLeader_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerClearSkydiveLeader_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerClientIsReadyToRespawn_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerClientIsReadyToRespawn_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerCreateProfileGoCollectionForSublevels_Implementation(const FString& SublevelSearchString, int32 GridStepsX, int32 GridStepsY, int32 RotationSteps, int32 Quad)
{
}
bool AFortPlayerControllerAthena::ServerCreateProfileGoCollectionForSublevels_Validate(const FString& SublevelSearchString, int32 GridStepsX, int32 GridStepsY, int32 RotationSteps, int32 Quad)
{
	return true;
}

void AFortPlayerControllerAthena::ServerCreativeCreateNewLevelInstance_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerCreativeCreateNewLevelInstance_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerCreativeDeleteLevelInstance_Implementation(const FGuid LevelInstanceGuid)
{
}
bool AFortPlayerControllerAthena::ServerCreativeDeleteLevelInstance_Validate(const FGuid LevelInstanceGuid)
{
	return true;
}

void AFortPlayerControllerAthena::ServerCreativeRenameLevelInstance_Implementation(const FGuid LevelInstanceGuid, const FString& NewLevelName)
{
}
bool AFortPlayerControllerAthena::ServerCreativeRenameLevelInstance_Validate(const FGuid LevelInstanceGuid, const FString& NewLevelName)
{
	return true;
}

void AFortPlayerControllerAthena::ServerCreativeUnlockItemCategory_Implementation(const FString& ItemCategory, const FString& ItemSubcategory)
{
}
bool AFortPlayerControllerAthena::ServerCreativeUnlockItemCategory_Validate(const FString& ItemCategory, const FString& ItemSubcategory)
{
	return true;
}

void AFortPlayerControllerAthena::ServerDBNOReviveInterrupted_Implementation(AFortPlayerPawnAthena* DBNOPawn)
{
}
bool AFortPlayerControllerAthena::ServerDBNOReviveInterrupted_Validate(AFortPlayerPawnAthena* DBNOPawn)
{
	return true;
}

void AFortPlayerControllerAthena::ServerDownloadContentByLinkId_Implementation(const FOnlineLinkId& LinkId, const bool bStripProjectId)
{
}
bool AFortPlayerControllerAthena::ServerDownloadContentByLinkId_Validate(const FOnlineLinkId& LinkId, const bool bStripProjectId)
{
	return true;
}

void AFortPlayerControllerAthena::ServerEnableAnonymousCharacterMode_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerEnableAnonymousCharacterMode_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerEnableAnonymousMode_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerEnableAnonymousMode_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerEnableHideOtherPlayersNames_Implementation()
{
}

void AFortPlayerControllerAthena::ServerEndLoadingVolume_Implementation(AActor* VolumeToLoad)
{
}
bool AFortPlayerControllerAthena::ServerEndLoadingVolume_Validate(AActor* VolumeToLoad)
{
	return true;
}

void AFortPlayerControllerAthena::ServerEndMinigame_Implementation(bool bAbandon)
{
}
bool AFortPlayerControllerAthena::ServerEndMinigame_Validate(bool bAbandon)
{
	return true;
}

void AFortPlayerControllerAthena::ServerEndUnloadingVolume_Implementation(AActor* VolumeToUnload)
{
}
bool AFortPlayerControllerAthena::ServerEndUnloadingVolume_Validate(AActor* VolumeToUnload)
{
	return true;
}

void AFortPlayerControllerAthena::ServerEnteredCameraMode_Implementation()
{
}

void AFortPlayerControllerAthena::ServerEnteredCursorMode_Implementation()
{
}

void AFortPlayerControllerAthena::ServerFriendGameMemberAdded_Implementation(AFortPlayerStateAthena* FriendPSA, bool bIsEpicFriend)
{
}

void AFortPlayerControllerAthena::ServerGenerateMockMatchReport_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerGenerateMockMatchReport_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerGiveCreativeItem_Implementation(const FFortItemEntry& CreativeItem, const FGuid& ItemToRemoveGuid)
{
}
bool AFortPlayerControllerAthena::ServerGiveCreativeItem_Validate(const FFortItemEntry& CreativeItem, const FGuid& ItemToRemoveGuid)
{
	return true;
}

void AFortPlayerControllerAthena::ServerInsertExtraStreamingTestSkydiveStates_Implementation()
{
}

void AFortPlayerControllerAthena::ServerInvalidateRespawnOnWaitingForLevelStreamingFailed_Implementation()
{
}

void AFortPlayerControllerAthena::ServerLoadIslandCheckpoint_Implementation(AFortAthenaCreativePortal* Portal)
{
}
bool AFortPlayerControllerAthena::ServerLoadIslandCheckpoint_Validate(AFortAthenaCreativePortal* Portal)
{
	return true;
}

void AFortPlayerControllerAthena::ServerLoadPlotForPortal_Implementation(AFortAthenaCreativePortal* Portal, const FString& PlotItemId)
{
}
bool AFortPlayerControllerAthena::ServerLoadPlotForPortal_Validate(AFortAthenaCreativePortal* Portal, const FString& PlotItemId)
{
	return true;
}

void AFortPlayerControllerAthena::ServerLoadPlotForPortalFromMnemonic_Implementation(AFortAthenaCreativePortal* Portal, const FOnlineLinkId& LinkId)
{
}
bool AFortPlayerControllerAthena::ServerLoadPlotForPortalFromMnemonic_Validate(AFortAthenaCreativePortal* Portal, const FOnlineLinkId& LinkId)
{
	return true;
}

void AFortPlayerControllerAthena::ServerLookedAtFocalPoint_Implementation()
{
}

void AFortPlayerControllerAthena::ServerMarkSkydiveLocationsComplete_Implementation()
{
}

void AFortPlayerControllerAthena::ServerNotifyClientReachedMaxWaitingTimeForDeviceReplication_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerNotifyClientReachedMaxWaitingTimeForDeviceReplication_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerNotifyOstrichSelfDestruct_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerNotifyOstrichSelfDestruct_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerNotifyOstrichShieldOvercharge_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerNotifyOstrichShieldOvercharge_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerPlaySquadQuickChatMessage_Implementation(FAthenaQuickChatActiveEntry ChatEntry, FUniqueNetIdRepl SenderID)
{
}
bool AFortPlayerControllerAthena::ServerPlaySquadQuickChatMessage_Validate(FAthenaQuickChatActiveEntry ChatEntry, FUniqueNetIdRepl SenderID)
{
	return true;
}

void AFortPlayerControllerAthena::ServerReleasePortal_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerReleasePortal_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerReloadCreativePlot_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerReloadCreativePlot_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerRemoveDownloadOnDemandContent_Implementation(const FOnlineLinkId& LinkId)
{
}
bool AFortPlayerControllerAthena::ServerRemoveDownloadOnDemandContent_Validate(const FOnlineLinkId& LinkId)
{
	return true;
}

void AFortPlayerControllerAthena::ServerRequestNewSkydiveLeader_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerRequestNewSkydiveLeader_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerRequestObjectTrackingDetails_Implementation(const AFortVolume* Volume)
{
}

void AFortPlayerControllerAthena::ServerRequestVkSessionModeratorLinkCode_Implementation()
{
}

void AFortPlayerControllerAthena::ServerResetCameraPreviewToDefaultLocation_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerResetCameraPreviewToDefaultLocation_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerResetCurrentVolumeWithoutTeleport_Implementation()
{
}

void AFortPlayerControllerAthena::ServerRespondToAbandonMatch_Implementation(bool bAbandon)
{
}
bool AFortPlayerControllerAthena::ServerRespondToAbandonMatch_Validate(bool bAbandon)
{
	return true;
}

void AFortPlayerControllerAthena::ServerRestartMinigame_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerRestartMinigame_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerSaveIslandCheckpoint_Implementation(AFortAthenaCreativePortal* Portal)
{
}
bool AFortPlayerControllerAthena::ServerSaveIslandCheckpoint_Validate(AFortAthenaCreativePortal* Portal)
{
	return true;
}

void AFortPlayerControllerAthena::ServerSelectMutatorItem_Implementation(AFortGameplayMutator* Mutator, int32 ItemIndex, int32 PayloadData)
{
}
bool AFortPlayerControllerAthena::ServerSelectMutatorItem_Validate(AFortGameplayMutator* Mutator, int32 ItemIndex, int32 PayloadData)
{
	return true;
}

void AFortPlayerControllerAthena::ServerSetCosmeticAndRefresh_Implementation(const FFortAthenaLoadout& Loadout)
{
}

void AFortPlayerControllerAthena::ServerSetCosmeticLoadout_Implementation(const FFortAthenaLoadout& Loadoutbool, bool bRefreshPawn)
{
}

void AFortPlayerControllerAthena::ServerSetMinigameClassSlot_Implementation(uint8 InClassSlotIndex)
{
}

void AFortPlayerControllerAthena::ServerSetMinigameTeamAndClassSlot_Implementation(const uint8 InTeam, const uint8 InClassSlotIndex, const bool bDeferred)
{
}
bool AFortPlayerControllerAthena::ServerSetMinigameTeamAndClassSlot_Validate(const uint8 InTeam, const uint8 InClassSlotIndex, const bool bDeferred)
{
	return true;
}

void AFortPlayerControllerAthena::ServerSetModeratorTeam_Implementation(uint8 InTeam)
{
}
bool AFortPlayerControllerAthena::ServerSetModeratorTeam_Validate(uint8 InTeam)
{
	return true;
}

void AFortPlayerControllerAthena::ServerSetOnCreativePortalLoadedDelegate_Implementation(int32 PortalIndex)
{
}

void AFortPlayerControllerAthena::ServerSetPlayset_Implementation(UFortPlaysetItemDefinition* NewPlayset)
{
}
bool AFortPlayerControllerAthena::ServerSetPlayset_Validate(UFortPlaysetItemDefinition* NewPlayset)
{
	return true;
}

void AFortPlayerControllerAthena::ServerSetReceiveEmailSignups_Implementation(bool bSignUp)
{
}
bool AFortPlayerControllerAthena::ServerSetReceiveEmailSignups_Validate(bool bSignUp)
{
	return true;
}

void AFortPlayerControllerAthena::ServerSetRespawnData(FVector RespawnLoc, FRotator RespawnRot, float RespawnCameraDist)
{
}

void AFortPlayerControllerAthena::ServerSetStreamingTestStreamingLevels_Implementation(bool streaming)
{
}

void AFortPlayerControllerAthena::ServerSetTeam_Implementation(uint8 InTeam)
{
}
bool AFortPlayerControllerAthena::ServerSetTeam_Validate(uint8 InTeam)
{
	return true;
}

void AFortPlayerControllerAthena::ServerShowSeasonLevel_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerShowSeasonLevel_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerSpawnCreativeSupplyDrop_Implementation(TSubclassOf<AActor> InSupplyDropClass)
{
}
bool AFortPlayerControllerAthena::ServerSpawnCreativeSupplyDrop_Validate(TSubclassOf<AActor> InSupplyDropClass)
{
	return true;
}

void AFortPlayerControllerAthena::ServerSpawnPickup_Implementation(const FFortItemEntry& CreativeItem)
{
}
bool AFortPlayerControllerAthena::ServerSpawnPickup_Validate(const FFortItemEntry& CreativeItem)
{
	return true;
}

void AFortPlayerControllerAthena::ServerStartInteractWithIslandPortal_Implementation(AFortAthenaCreativePortal* Portal)
{
}

void AFortPlayerControllerAthena::ServerStartInteractWithPartyRiftPortal_Implementation(AFortAthenaPartyRiftPortal* Portal, const FString& Reason)
{
}

void AFortPlayerControllerAthena::ServerStartLoadingVolume_Implementation(AActor* VolumeToLoad)
{
}
bool AFortPlayerControllerAthena::ServerStartLoadingVolume_Validate(AActor* VolumeToLoad)
{
	return true;
}

void AFortPlayerControllerAthena::ServerStartMinigame_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerStartMinigame_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerStartUnloadingVolume_Implementation(AActor* VolumeToUnload)
{
}
bool AFortPlayerControllerAthena::ServerStartUnloadingVolume_Validate(AActor* VolumeToUnload)
{
	return true;
}

void AFortPlayerControllerAthena::ServerStopSavingCreativePlot_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerStopSavingCreativePlot_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerStopWaitLTMLoading_Implementation()
{
}

void AFortPlayerControllerAthena::ServerTeleportToMapMarker_Implementation()
{
}

void AFortPlayerControllerAthena::ServerTeleportToPlaygroundIslandDock_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerTeleportToPlaygroundIslandDock_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerTeleportToPlaygroundLobbyIsland_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerTeleportToPlaygroundLobbyIsland_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerTeleportViaCreativePortal_Implementation(int32 PortalIndex)
{
}

void AFortPlayerControllerAthena::ServerThankBusDriver_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerThankBusDriver_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerThankBusDriverCheck_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerThankBusDriverCheck_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerTickForDoneTeleporting_Implementation(AFortAthenaCreativePortal* Portal)
{
}

void AFortPlayerControllerAthena::ServerToggleAutoRestartMinigame_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerToggleAutoRestartMinigame_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerTryFindPlotItemForDefinition_Implementation(UFortCreativeRealEstatePlotItemDefinition* PlotDefinition)
{
}

void AFortPlayerControllerAthena::ServerUnloadDownloadedContentByLinkId_Implementation(const FOnlineLinkId& LinkId)
{
}
bool AFortPlayerControllerAthena::ServerUnloadDownloadedContentByLinkId_Validate(const FOnlineLinkId& LinkId)
{
	return true;
}

void AFortPlayerControllerAthena::ServerUpdateCreativePlotData_Implementation(AFortVolume* VolumeToPublish, FCreativeIslandInfo MyInfo)
{
}
bool AFortPlayerControllerAthena::ServerUpdateCreativePlotData_Validate(AFortVolume* VolumeToPublish, FCreativeIslandInfo MyInfo)
{
	return true;
}

void AFortPlayerControllerAthena::ServerUpdateCreativePlotName_Implementation(const FString& IslandId, const FString& Locale, const FString& Title)
{
}
bool AFortPlayerControllerAthena::ServerUpdateCreativePlotName_Validate(const FString& IslandId, const FString& Locale, const FString& Title)
{
	return true;
}

void AFortPlayerControllerAthena::ServerUpdateHeatmapBoundsForCurrentVolume_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerUpdateHeatmapBoundsForCurrentVolume_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::ServerUpdateLevelStreamingHandshakeData_Implementation(const bool bClientLevelStreamingState)
{
}
bool AFortPlayerControllerAthena::ServerUpdateLevelStreamingHandshakeData_Validate(const bool bClientLevelStreamingState)
{
	return true;
}

void AFortPlayerControllerAthena::ServerUpdatePrimaryQuickBarSlots_Implementation(const FQuickBarEquippedItemGuids& SlotItemGuids)
{
}

void AFortPlayerControllerAthena::ServerUpdateSkydiveLocation_Implementation(const FString& LocationStr, const FVector& Location)
{
}

void AFortPlayerControllerAthena::ServerUpdateUserCameraPreview_Implementation()
{
}
bool AFortPlayerControllerAthena::ServerUpdateUserCameraPreview_Validate()
{
	return true;
}

void AFortPlayerControllerAthena::SetFocalPoint(AActor* InFocalPoint, FVector InFocalPointOffset, float InFocalPointFOV, float InInterpSpeed)
{
}

void AFortPlayerControllerAthena::SetFocalPointWithDuration(AActor* InFocalPoint, FVector InFocalPointOffset, float InFocalPointFOV, float InDuration, float InInterpSpeed)
{
}

void AFortPlayerControllerAthena::SetIgnoreSpectatorViewRotation(const bool bNewValue)
{
}

void AFortPlayerControllerAthena::SetOverrideDesiredRotation(const FRotator& NewDesiredRotation)
{
}

void AFortPlayerControllerAthena::SetupClientRespawnTimerAndLocation(FVector RespawnLoc, FRotator RespawnRot, FVector OldPlayerLocation, bool bCalculateRespawnData, bool bAllowCreativeOverride)
{
}

void AFortPlayerControllerAthena::SetUseOverrideDesiredRotation(const bool bNewUseDesiredRotation, const float NewDuration)
{
}

void AFortPlayerControllerAthena::ShowHighlightSummary()
{
}

void AFortPlayerControllerAthena::StartMatchmakingByLinkCode(const FOnlineLinkId& LinkCode, bool bIsPrivateMatch)
{
}

void AFortPlayerControllerAthena::StartRespawnLoading()
{
}

void AFortPlayerControllerAthena::StopRecordingHighlights()
{
}

void AFortPlayerControllerAthena::TeleportToPlaygroundLobbyIsland()
{
}

void AFortPlayerControllerAthena::TellServer_ClientReceivedPlaysetDataForVolume_Implementation(FFortPlaysetStreamingData PlaysetData, AActor* Volume)
{
}
bool AFortPlayerControllerAthena::TellServer_ClientReceivedPlaysetDataForVolume_Validate(FFortPlaysetStreamingData PlaysetData, AActor* Volume)
{
	return true;
}

void AFortPlayerControllerAthena::UpdateCreativeIslandDescriptionTags_Implementation(const FString& IslandId, const FString& Locale, const TArray<FString>& DescriptionTags)
{
}
bool AFortPlayerControllerAthena::UpdateCreativeIslandDescriptionTags_Validate(const FString& IslandId, const FString& Locale, const TArray<FString>& DescriptionTags)
{
	return true;
}

void AFortPlayerControllerAthena::UpdateCreativePlotData(AFortVolume* VolumeToPublish, FCreativeIslandInfo MyInfo)
{
}

void AFortPlayerControllerAthena::UpdateCreativePlotName(const FString& IslandId, const FString& Locale, const FString& Title)
{
}

void AFortPlayerControllerAthena::UpdateDuel(const EDuelState DuelState, const FDuelOverlayData& DuelOverlayData)
{
}

void AFortPlayerControllerAthena::UpdateRichPresenceTimer()
{
}

void AFortPlayerControllerAthena::UpdateUGCRestrictedForVolume_Implementation(AFortVolume* Volume, bool bRestricted)
{
}
bool AFortPlayerControllerAthena::UpdateUGCRestrictedForVolume_Validate(AFortVolume* Volume, bool bRestricted)
{
	return true;
}

void AFortPlayerControllerAthena::WriteCreateBuildingAnalytics()
{
}

void AFortPlayerControllerAthena::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPlayerControllerAthena, FocalPoint);
	DOREPLIFETIME(AFortPlayerControllerAthena, FocalPointOffset);
	DOREPLIFETIME(AFortPlayerControllerAthena, FocalPointFOV);
	DOREPLIFETIME(AFortPlayerControllerAthena, SkydiveLeader);
	DOREPLIFETIME(AFortPlayerControllerAthena, LastDownedVictim);
	DOREPLIFETIME(AFortPlayerControllerAthena, LastElimVictim);
	DOREPLIFETIME(AFortPlayerControllerAthena, bNextRespawnInAir);
	DOREPLIFETIME(AFortPlayerControllerAthena, MaxPlotCount);
	DOREPLIFETIME(AFortPlayerControllerAthena, bMarkedAlive);
	DOREPLIFETIME(AFortPlayerControllerAthena, CreativeIslands);
	DOREPLIFETIME(AFortPlayerControllerAthena, bIsAllowedToPublish);
	DOREPLIFETIME(AFortPlayerControllerAthena, BroadcastRemoteClientInfo);
	DOREPLIFETIME(AFortPlayerControllerAthena, CreativePlotLinkedVolume);
	DOREPLIFETIME(AFortPlayerControllerAthena, OwnedPortal);
	DOREPLIFETIME(AFortPlayerControllerAthena, OwnedPartyRiftPortal);
	DOREPLIFETIME(AFortPlayerControllerAthena, CachedPurchasedItems);
	DOREPLIFETIME(AFortPlayerControllerAthena, PendingMinigameSpawnData);
	DOREPLIFETIME(AFortPlayerControllerAthena, CurrentPlayset);
	DOREPLIFETIME(AFortPlayerControllerAthena, CreativeUserContentManager);
	DOREPLIFETIME(AFortPlayerControllerAthena, CreativeObjectTrackingComponent);
	DOREPLIFETIME(AFortPlayerControllerAthena, CreativeEntitlementComponent);
}
