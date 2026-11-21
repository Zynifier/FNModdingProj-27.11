// Copyright Epic Games, Inc. All Rights Reserved.

#include "Player/FortPlayerController.h"
#include "Net/UnrealNetwork.h"

void AFortPlayerController::AddDamageNumber(float Damage, AActor* DamagedActor, APawn* DamageCauser, const FGameplayEffectContextHandle& EffectContext, const FGameplayTagContainer& DamageTags, bool bIsCriticalDamage, const FVector& OverridePosition, const FVector& HitNormal, bool bShowZeroDamage)
{
}

void AFortPlayerController::AddInventoryItemWithAlterationBasedOnLootLevel(FFortItemEntry ItemDescription)
{
}

void AFortPlayerController::AddInventoryItemWithAnimation(const FFortItemEntry& ItemDescription, const FVector OverrideSpawnLocation)
{
}

void AFortPlayerController::AddItemToQuickBars(UFortItemDefinition* ItemDefinition, EFortQuickBars QuickBarType, int32 SlotIndex)
{
}

void AFortPlayerController::AddZeroDamageNumber(AActor* DamagedActor, APawn* DamageCauser, const FVector& HitLocation)
{
}

void AFortPlayerController::AlternateInteractCarryHoldStopped(FName InputActionName, bool bCompletedSuccessfully)
{
}

void AFortPlayerController::ApplyOverrideWrapToVehicle(const TSoftObjectPtr<UAthenaItemWrapDefinition>& ItemWrap)
{
}

bool AFortPlayerController::AreActionsBoundToSameKey(FName FirstActionName, FName SecondActionName, const EInputEvent InputEvent)
{
	return false;
}

bool AFortPlayerController::AreHUDElementsVisible(const FGameplayTagContainer& HUDElementTags) const
{
	return false;
}

UFortItem* AFortPlayerController::BP_FindExistingItemForDefinition(const UFortItemDefinition* ItemDefinition, FGuid ItemVariantGuid, bool bInStorageVault) const
{
	return nullptr;
}

void AFortPlayerController::BP_FindItemInstancesFromDefinition(const UFortItemDefinition* ItemDefinition, FGuid ItemVariantGuid, TArray<UFortItem*>& ItemArray)
{
}

UFortItem* AFortPlayerController::BP_GetInventoryItemWithGuid(FGuid ItemGuid) const
{
	return nullptr;
}

void AFortPlayerController::BroadcastOnPickupCreated(AFortPickup* Pickup)
{
}

bool AFortPlayerController::CanAlterHostileWalls() const
{
	return false;
}

bool AFortPlayerController::CanEnableBattleMapSpectator() const
{
	return false;
}

bool AFortPlayerController::CanPerformNativeAction(const FGameplayTag& ActionTag) const
{
	return false;
}

void AFortPlayerController::ChangeActiveVariantForCosmeticItem(FName ItemTemplateToChange, FGameplayTag VariantChannelToChange, FGameplayTag DesiredActiveVariant, AFortPlayerPawn* PreviewPawn)
{
}

void AFortPlayerController::Cheat(const FString& Msg)
{
}

void AFortPlayerController::Cheat_ClearForcedCosmeticItems_Implementation()
{
}
bool AFortPlayerController::Cheat_ClearForcedCosmeticItems_Validate()
{
	return true;
}

void AFortPlayerController::Cheat_ClearForcedCosmeticVariantChannels_Implementation()
{
}
bool AFortPlayerController::Cheat_ClearForcedCosmeticVariantChannels_Validate()
{
	return true;
}

void AFortPlayerController::Cheat_ForceAthenaCosmeticItemInSlot_Implementation(const UAthenaCosmeticItemDefinition* CosmeticItem, EAthenaCustomizationCategory Slot, int32 Index)
{
}
bool AFortPlayerController::Cheat_ForceAthenaCosmeticItemInSlot_Validate(const UAthenaCosmeticItemDefinition* CosmeticItem, EAthenaCustomizationCategory Slot, int32 Index)
{
	return true;
}

void AFortPlayerController::Cheat_ForceCosmeticVariantChannels_Implementation(const TArray<FMcpVariantChannelInfo>& CosmeticVariantChannels)
{
}
bool AFortPlayerController::Cheat_ForceCosmeticVariantChannels_Validate(const TArray<FMcpVariantChannelInfo>& CosmeticVariantChannels)
{
	return true;
}

void AFortPlayerController::Cheat_ForcePlayEmoteItem_Implementation(const UFortMontageItemDefinitionBase* EmoteAsset)
{
}
bool AFortPlayerController::Cheat_ForcePlayEmoteItem_Validate(const UFortMontageItemDefinitionBase* EmoteAsset)
{
	return true;
}

void AFortPlayerController::Cheat_ForcePlayerToAssembledMeshSchema_Implementation(const FString& AssembledMeshSchemaName)
{
}
bool AFortPlayerController::Cheat_ForcePlayerToAssembledMeshSchema_Validate(const FString& AssembledMeshSchemaName)
{
	return true;
}

void AFortPlayerController::Cheat_StopObjectiveServer_Implementation(AFortObjectiveBase* Objective, const EFortObjectiveStatus Status)
{
}
bool AFortPlayerController::Cheat_StopObjectiveServer_Validate(AFortObjectiveBase* Objective, const EFortObjectiveStatus Status)
{
	return true;
}

void AFortPlayerController::CheatAll(const FString& Msg)
{
}

bool AFortPlayerController::CheckPossessionOfAmountOfItems(EFortItemType Type, int32 AmountToCheck)
{
	return false;
}

void AFortPlayerController::ClientActivateSlot_Implementation(EFortQuickBars InQuickBar, int32 Slot, float ActivateDelay, bool bUpdatePreviousFocusedSlot, bool bForceExecution)
{
}

void AFortPlayerController::ClientAddDamageNumber_Implementation(float Damage, AActor* DamagedActor, APawn* DamageCauser, const FGameplayEffectContextHandle& EffectContext, const FGameplayTagContainer& DamageTags, bool bIsCriticalDamage, const FVector& OverridePosition, const FVector& HitNormal)
{
}

void AFortPlayerController::ClientAddScoreNumber_Implementation(int32 Score, EStatCategory ScoreCategory, const FVector_NetQuantize& ScoreLocation, bool bDisplayScoreOnPlayer)
{
}

void AFortPlayerController::ClientBotEnqueueCommand_Implementation(const FString& CommandToEnqueue)
{
}

void AFortPlayerController::ClientBotSetModuleToUse_Implementation(const FString& PilotCategory, const FString& NewModule, bool bResetNow)
{
}

void AFortPlayerController::ClientCancelCrafting_Implementation()
{
}

void AFortPlayerController::ClientConfirmTargetData_Implementation(uint16 UniqueId, bool bSuccess, const TArray<uint8>& HitReplaces)
{
}

void AFortPlayerController::ClientCreateOrJoinChatRoom_Implementation(const FString& ChatRoomId)
{
}

void AFortPlayerController::ClientDeveloper_GetConsoleVariable_Implementation(const FString& ConsoleVariable, const FString& Value)
{
}

void AFortPlayerController::ClientEndGameKick_Implementation()
{
}

void AFortPlayerController::ClientEquipItem_Implementation(const FGuid& ItemGuid, bool bForceExecution)
{
}

void AFortPlayerController::ClientExecuteInventoryItem_Implementation(FGuid ItemGuid, float Delay, bool bForceExecute, bool bActivateSlotAfterSettingFocused)
{
}

void AFortPlayerController::ClientFailedToBeginEditingBuildingActor_Implementation(ABuildingSMActor* BuildingActorToStopEditing)
{
}

void AFortPlayerController::ClientFinishedInteractionInZone_Implementation()
{
}

void AFortPlayerController::ClientForceCancelBuildingTool_Implementation()
{
}

void AFortPlayerController::ClientForceProfileQuery_Implementation()
{
}

void AFortPlayerController::ClientForceUpdateQuickbar_Implementation(EFortQuickBars QuickbarToRefresh)
{
}

void AFortPlayerController::ClientForceWorldInventoryUpdate_Implementation()
{
}

void AFortPlayerController::ClientGivePlayerLocalAccountItem_Implementation(UFortAccountItemDefinition* ItemDefinition, int32 Count)
{
}

void AFortPlayerController::ClientHandleHitNotifyAudio_Implementation(const FGameplayTagContainer& InTags, const FGameplayEffectContextHandle& EffectContext, AFortPawn* PawnInstigator, AActor* DamageCauser, AActor* DamagedActor)
{
}

void AFortPlayerController::ClientJoinConsoleSession_Implementation(const FString& ConsoleSession)
{
}
bool AFortPlayerController::ClientJoinConsoleSession_Validate(const FString& ConsoleSession)
{
	return true;
}

void AFortPlayerController::ClientLogDebugString_Implementation(const FString& Msg)
{
}

void AFortPlayerController::ClientOnGenericPlayerInitialization_Implementation()
{
}

void AFortPlayerController::ClientOpenChoiceUI_Implementation(FChoiceData ChoiceItems)
{
}

void AFortPlayerController::ClientPingMinimap_Implementation(FVector WorldLocation, FLinearColor PingColor)
{
}

void AFortPlayerController::ClientPrecacheMediaSource_Implementation(UMediaPlayer* InMediaPlayer, UMediaSource* InMediaSource)
{
}

void AFortPlayerController::ClientReadyCheckComplete_Implementation(bool bPassed)
{
}

void AFortPlayerController::ClientReceivedAttributeSources_Implementation(FGameplayAttribute Attribute, UFortAbilitySystemComponent* AbilitySystemComponent, const TArray<FAttributeModifierInfo>& Sources)
{
}

void AFortPlayerController::ClientReceivePresetTeamChat_Implementation(const FText& ChatText, FUniqueNetIdRepl SenderID)
{
}

void AFortPlayerController::ClientRegisterWithParty_Implementation()
{
}

void AFortPlayerController::ClientReportDamagedResourceBuilding_Implementation(ABuildingSMActor* BuildingSMActor, EFortResourceType::Type PotentialResourceType, int32 PotentialResourceCount, bool bDestroyed, bool bJustHitWeakspot)
{
}

void AFortPlayerController::ClientReportGotResourceFromVehicle_Implementation(AActor* Vehicle, int32 ResourceCount)
{
}

void AFortPlayerController::ClientRequestReadyCheck_Implementation(const FText& QueryText, const FText& YesText, const FText& NoText)
{
}

void AFortPlayerController::ClientRetryLocalPlaceBuildableClass_Implementation()
{
}

void AFortPlayerController::ClientSendMessage_Implementation(const FText& Message, USoundBase* StartSound)
{
}

void AFortPlayerController::ClientSetActionMappingEnabled_Implementation(FName ActionName, bool bEnabled)
{
}

void AFortPlayerController::ClientSetInviteFlags_Implementation(const FJoinabilitySettings& Settings)
{
}

void AFortPlayerController::ClientSetSpectatorCamera_Implementation(FVector CameraLocation, FRotator CameraRotation)
{
}

void AFortPlayerController::ClientSideEditPredictionTimedOut()
{
}

void AFortPlayerController::ClientSpawnWeakSpotOnBuildingActor_Implementation(const FBuildingWeakSpotData& ReplicatedWeakSpotData)
{
}

void AFortPlayerController::ClientStopAutoRun_Implementation()
{
}

void AFortPlayerController::ClientStopUIFeedbackEvent_Implementation(FName EventName)
{
}

void AFortPlayerController::ClientSwapQuickBarFocus_Implementation(EFortQuickBars InQuickBar, int32 SlotOverride, bool bForceExecution)
{
}

void AFortPlayerController::ClientTriggerUIFeedbackEvent_Implementation(FName EventName)
{
}

void AFortPlayerController::ClientUpdateRichPresence_Implementation(ERichPresenceStateChange RichPresenceChange, bool bImportant)
{
}

void AFortPlayerController::ClientUpdateServerOnPlayerChangedBuildMode_Implementation()
{
}

int32 AFortPlayerController::CountInventoryOverflowFromAddingItem(const FFortItemEntry& ItemDescription, bool bIsClassItem, bool bFromPickup) const
{
	return int32();
}

void AFortPlayerController::DBNOCarryDrop()
{
}

void AFortPlayerController::DBNOCarryHoist()
{
}

void AFortPlayerController::DBNOCarryThrow()
{
}

bool AFortPlayerController::DBNOTryStartCarry()
{
	return false;
}

void AFortPlayerController::DeployDefender(ABuildingTrapDefender* DefenderTrap, const UFortDefenderItem* DefenderItem, const FName& DefenderSquadId, const UFortItem* WeaponItem, const int32 AmmoQuantity)
{
}

void AFortPlayerController::DisplayHUDElementVisibility() const
{
}

void AFortPlayerController::DropAllItems(const UFortItemDefinition* IgnoreItemDef, const UFortItemDefinition* AdditionalIgnoreItemDef, bool bIgnoreBuildingMaterials, bool bSpawnPickups)
{
}

void AFortPlayerController::DropItemsByCreativeTags(const TArray<FName>& DropCreativeTags, const TArray<FName>& IgnoreCreativeTags)
{
}

void AFortPlayerController::DropSpecificItem(const UFortItemDefinition* DropItemDef, bool bSpawnPickups)
{
}

void AFortPlayerController::DumpHomebaseRatingInfo() const
{
}

void AFortPlayerController::Emote(const FName& AssetName)
{
}

void AFortPlayerController::ExecuteInventoryItemDefinition(UFortItemDefinition* ItemDefinition, FGuid ItemVariantGuid, float Delay, bool bForceExecute, bool bActivateSlotAfterSettingFocused)
{
}

bool AFortPlayerController::FindItem(const UFortItem* Item, EFortQuickBars& OutQuickBar, int32& OutSlot) const
{
	return false;
}

void AFortPlayerController::FixupInteractionWidgetsOnUnzoom()
{
}

void AFortPlayerController::ForceCancelBuildingTool()
{
}

void AFortPlayerController::ForceExitBuildMode()
{
}

void AFortPlayerController::ForcePickerClose()
{
}

void AFortPlayerController::FortClientPlaySound_Implementation(USoundBase* Sound, float VolumeMultiplier, float PitchMultiplier)
{
}

void AFortPlayerController::FortClientPlaySoundAtLocation_Implementation(USoundBase* Sound, FVector Location, float VolumeMultiplier, float PitchMultiplier)
{
}

void AFortPlayerController::ForwardActiveVariantChangeRequest_Implementation(FName ItemTemplateToChange, FGameplayTag VariantChannelToChange, FGameplayTag DesiredActiveVariant, AFortPlayerPawn* PreviewPawn)
{
}
bool AFortPlayerController::ForwardActiveVariantChangeRequest_Validate(FName ItemTemplateToChange, FGameplayTag VariantChannelToChange, FGameplayTag DesiredActiveVariant, AFortPlayerPawn* PreviewPawn)
{
	return true;
}

UFortAccountItem* AFortPlayerController::GetAccountItem(const FString& Id) const
{
	return nullptr;
}

int32 AFortPlayerController::GetAccountLevel() const
{
	return int32();
}

AActor* AFortPlayerController::GetActorUnderReticle() const
{
	return nullptr;
}

AFortAIDirectorDataManager* AFortPlayerController::GetAIDirectorDataManager()
{
	return nullptr;
}

UFortControllerComponent_Aircraft* AFortPlayerController::GetAircraftComponent() const
{
	return nullptr;
}

bool AFortPlayerController::GetAtNameHomeBaseScreen()
{
	return false;
}

ABuildingPlayerPrimitivePreview* AFortPlayerController::GetBuildPreviewMarker() const
{
	return nullptr;
}

UFortCollectionBookManager* AFortPlayerController::GetCollectionBookManager() const
{
	return nullptr;
}

UFortControllerComponent_InputContextTracker* AFortPlayerController::GetContextTrackerComponent() const
{
	return nullptr;
}

UWidget* AFortPlayerController::GetCurrentlyBoundEntryFromActions(const TArray<FName>& InBoundActionsToCheck)
{
	return nullptr;
}

AFortVolume* AFortPlayerController::GetCurrentVolume() const
{
	return nullptr;
}

int32 AFortPlayerController::GetFocusedSlot(const EFortQuickBars InQuickbar) const
{
	return int32();
}

const AActor* AFortPlayerController::GetFocusTarget() const
{
	return nullptr;
}

bool AFortPlayerController::GetForceAllowCameraMode() const
{
	return false;
}

int32 AFortPlayerController::GetFPSForHUD()
{
	return int32();
}

FUniqueNetIdRepl AFortPlayerController::GetGameAccountId() const
{
	return FUniqueNetIdRepl();
}

FText AFortPlayerController::GetGliderDisplayName() const
{
	return FText();
}

bool AFortPlayerController::GetIgnoreSignifanceBasedCustomDepthRendering()
{
	return false;
}

bool AFortPlayerController::GetItemDefinitionOwnershipState(const UFortItemDefinition* ItemDefinition, bool& bIsOwned) const
{
	return false;
}

UFortItem* AFortPlayerController::GetItemInQuickbarSlot(EFortQuickBars QuickBarType, int32 SlotIndex)
{
	return nullptr;
}

int32 AFortPlayerController::GetItemNumInStackByGuid(FGuid ItemGuid)
{
	return int32();
}

const UFortMontageItemDefinitionBase* AFortPlayerController::GetLastEmotePlayed() const
{
	return nullptr;
}

const FRotator& AFortPlayerController::GetLastInputRotation() const
{
	static FRotator Dummy;
	return Dummy;
}

FVector AFortPlayerController::GetLocationUnderReticle() const
{
	return FVector();
}

ELockOnState AFortPlayerController::GetLockOnState() const
{
	return ELockOnState();
}

UAthenaMarkerComponent* AFortPlayerController::GetMarkerComponent() const
{
	return nullptr;
}

UFortMcpProfileAthena* AFortPlayerController::GetMcpAthenaProfile() const
{
	return nullptr;
}

UFortMcpProfileCampaign* AFortPlayerController::GetMcpCampaignProfile() const
{
	return nullptr;
}

UFortMinigameManager* AFortPlayerController::GetMinigameManager(ESubGame SubGame) const
{
	return nullptr;
}

UFortControllerComponent_Minimap* AFortPlayerController::GetMiniMapComponent() const
{
	return nullptr;
}

int32 AFortPlayerController::GetNumQuickbarSlots(EFortQuickBars QuickBarType)
{
	return int32();
}

UFortControllerComponent_PinQuest* AFortPlayerController::GetPinQuestComponent() const
{
	return nullptr;
}

AFortPlayerPawn* AFortPlayerController::GetPlayerPawn() const
{
	return nullptr;
}

AFortPlayerPawn* AFortPlayerController::GetPlayerPawnOrVehicleDriver() const
{
	return nullptr;
}

UFortQuestManager* AFortPlayerController::GetQuestManager(ESubGame SubGame) const
{
	return nullptr;
}

UFortControllerComponent_QuickEdit* AFortPlayerController::GetQuickEditComponent() const
{
	return nullptr;
}

UAthenaCharacterItemDefinition* AFortPlayerController::GetRandomDefaultAthenaCharacterDefinition(UFortMcpProfileAthena* McpAthenaProfile)
{
	return nullptr;
}

UFortRegisteredPlayerInfo* AFortPlayerController::GetRegisteredPlayerInfo() const
{
	return nullptr;
}

bool AFortPlayerController::GetRevertPlayerListenerChangeFlag() const
{
	return false;
}

bool AFortPlayerController::GetRotatePawnToCamera() const
{
	return false;
}

int32 AFortPlayerController::GetStatValue(FName StatName, EStatRecordingPeriod Period) const
{
	return int32();
}

UFortControllerComponent_SurvivorTiers* AFortPlayerController::GetSurvivorTiersComponent() const
{
	return nullptr;
}

ABuildingActor* AFortPlayerController::GetTargetedBuilding() const
{
	return nullptr;
}

int32 AFortPlayerController::GetTeamPerkProgressiveActivationLevel() const
{
	return int32();
}

float AFortPlayerController::GetTimeRemainingForRespawnBP() const
{
	return float();
}

bool AFortPlayerController::GetUseHoldToSwapPickupSetting() const
{
	return false;
}

const FVoiceChatDistanceAttenuationSettings& AFortPlayerController::GetVoiceChatDistanceAttenuationSettings() const
{
	static FVoiceChatDistanceAttenuationSettings Dummy;
	return Dummy;
}

USoundEffectSourcePresetChain* AFortPlayerController::GetVoiceInputEffectChain() const
{
	return nullptr;
}

void AFortPlayerController::GivePlayerAmmo(int32 AmmoCount)
{
}

void AFortPlayerController::HandleBattleMapSpectatorEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason)
{
}

void AFortPlayerController::HandleDifferentHeroLoadoutActivated(const UFortMcpProfileCampaign* Profile)
{
}

void AFortPlayerController::HandleNonZeroRollSetOnCamera()
{
}

void AFortPlayerController::HandleOutpostInventoryLocalUpdate()
{
}

void AFortPlayerController::HandleViewTargetInventoryLocalUpdate()
{
}

void AFortPlayerController::HandleWinnerAnnounced(const FString& WinnerPlayerName)
{
}

void AFortPlayerController::HandleWorldInventoryLocalUpdate()
{
}

bool AFortPlayerController::HasLockOnTarget() const
{
	return false;
}

bool AFortPlayerController::HasPermissionToEditWorld(const ABuildingActor* Building, const FVector& Location, const FRotator& Rotation) const
{
	return false;
}

void AFortPlayerController::InitializeZeroingCameraRoll()
{
}

bool AFortPlayerController::IsActionInputIgnored() const
{
	return false;
}

bool AFortPlayerController::IsAnyPlayerOwnerOfCurrentExperience(const UObject* WorldContextObject)
{
	return false;
}

bool AFortPlayerController::IsAutoChangeMaterialOn()
{
	return false;
}

bool AFortPlayerController::IsBuildToolOverridden() const
{
	return false;
}

bool AFortPlayerController::IsClientBot() const
{
	return false;
}

bool AFortPlayerController::IsClientTimingOut() const
{
	return false;
}

bool AFortPlayerController::IsHiddenControllerOnly(AActor* TargetActor) const
{
	return false;
}

bool AFortPlayerController::IsInAircraft() const
{
	return false;
}

bool AFortPlayerController::IsInBuildMode() const
{
	return false;
}

bool AFortPlayerController::IsInRespawnCountdown() const
{
	return false;
}

bool AFortPlayerController::IsInSplitscreen() const
{
	return false;
}

bool AFortPlayerController::IsNearActiveEncounters() const
{
	return false;
}

bool AFortPlayerController::IsPartyLeader() const
{
	return false;
}

bool AFortPlayerController::IsPersonalVehicleActive() const
{
	return false;
}

bool AFortPlayerController::IsPersonalVehicleAvailable() const
{
	return false;
}

bool AFortPlayerController::IsPlayerInAnExperienceTheyOwn() const
{
	return false;
}

bool AFortPlayerController::IsPlayingEmote() const
{
	return false;
}

bool AFortPlayerController::IsRequirementsMet(const FFortRequirementsInfo& InRequirements, bool bUsePhoenixStats) const
{
	return false;
}

void AFortPlayerController::IsUsingCosmeticsOwnedByStWHero(bool& bIsUsingOutfitOwnedByHero, bool& bIsUsingBackblingOwnedByHero) const
{
}

bool AFortPlayerController::IsUsingFirstPersonCamera() const
{
	return false;
}

bool AFortPlayerController::IsUsingGamepad() const
{
	return false;
}

bool AFortPlayerController::IsUsingHarvestingTool() const
{
	return false;
}

bool AFortPlayerController::IsUsingTouch() const
{
	return false;
}

void AFortPlayerController::LocalOnBlueprintEdit(ABuildingSMActor* EditedActor)
{
}

void AFortPlayerController::LocalOnUiChoiceCompleted(int32 ChosenItem, int32 MenuIdentifier)
{
}

void AFortPlayerController::LocalOverrideBuildMode(bool bVisible, TSubclassOf<ABuildingSMActor> InBuildingClass, FVector3f BuildingOverrideDistance, UMaterialInterface* PreviewMaterial, FVector NewScale, FRotator NewRotation)
{
}

void AFortPlayerController::LocalPlayForceFeedback(UForceFeedbackEffect* ForceFeedbackEffect, bool bLooping, FName Tag)
{
}

void AFortPlayerController::LocalStopForceFeedback(UForceFeedbackEffect* ForceFeedbackEffect, FName Tag)
{
}

void AFortPlayerController::MarkCollectionItemSeen_Implementation(const FString& CollectionType, const FString& Category, const FString& Variant)
{
}

void AFortPlayerController::ModifyStat(FName StatName, int32 Amount, EStatMod ModType, bool bForceStatSave)
{
}

void AFortPlayerController::MulticastClearWeakSpotData_Implementation(UObject* ParentBuilding)
{
}

void AFortPlayerController::MutePlayer(const FUniqueNetIdRepl& UniqueNetId)
{
}

void AFortPlayerController::NotifyMeshNetPlayer(FName Tag)
{
}

void AFortPlayerController::OnMinigameSpatialLoadingStateChanged(ESpatialLoadingState NewState, AFortVolume* Volume)
{
}

void AFortPlayerController::OnRep_bHasServerFinishedLoading()
{
}

void AFortPlayerController::OnRep_CheatMovement()
{
}

void AFortPlayerController::OnRep_DelayedQuickBarActions()
{
}

void AFortPlayerController::OnRep_HoldingObject()
{
}

void AFortPlayerController::OnRep_IntensityGraphInfo()
{
}

void AFortPlayerController::OnRep_LatestRewardReport()
{
}

void AFortPlayerController::OnRep_MeshParentIds()
{
}

void AFortPlayerController::OnRep_PIDContributionsGraphInfo()
{
}

void AFortPlayerController::OnRep_PIDValuesGraphInfo()
{
}

void AFortPlayerController::OnRep_UpdatedObjectiveStats()
{
}

void AFortPlayerController::OnRep_UpdatedUnsavedPrimaryMissionProgress()
{
}

void AFortPlayerController::OpenChoiceUI(FChoiceData ChoiceData)
{
}

void AFortPlayerController::OpenInventory(const FName InventoryTabId)
{
}

void AFortPlayerController::OpenVoteDialog()
{
}

bool AFortPlayerController::OwnsCurrentIslandVolume() const
{
	return false;
}

bool AFortPlayerController::OwnsIslandVolume(AFortVolume* Volume) const
{
	return false;
}

void AFortPlayerController::PlayEmoteItem(const UFortMontageItemDefinitionBase* EmoteAsset, EFortEmotePlayMode PlayMode)
{
}

void AFortPlayerController::PlayerRequestClearIslandData()
{
}

void AFortPlayerController::PlaySpatialSound(USoundBase* Sound, FVector Location)
{
}

void AFortPlayerController::PostHeroStatCollectionBookProgressMade(int32 LevelReached)
{
}

void AFortPlayerController::PostHeroStatMissionCompleted(int32 DifficultyRating)
{
}

void AFortPlayerController::PostHeroStatSkillPointsEarned(int32 NumSkillPoints)
{
}

void AFortPlayerController::PrintDebugInfo()
{
}

void AFortPlayerController::PrintEventInfo()
{
}

void AFortPlayerController::ProcessMcpProfileUpdate_Implementation(const FProfileUpdate& Update)
{
}

void AFortPlayerController::RefreshHUDElementVisibilitiesToSettings()
{
}

void AFortPlayerController::RemoveItemFromQuickBars(UFortItemDefinition* ItemDefinition)
{
}

void AFortPlayerController::RemoveItemsByCreativeTags(const TArray<FName>& RemoveCreativeTags, const TArray<FName>& IgnoreCreativeTags)
{
}

void AFortPlayerController::ReportVideoStreamingError(UMediaPlayer* MediaPlayer, bool bLocalContentFallback, const FString& LastError) const
{
}

void AFortPlayerController::ResetForcedInputRotationSpeed()
{
}

void AFortPlayerController::ResetHUDElementVisibilityToSettings(const FGameplayTagContainer& HUDElementTags)
{
}

void AFortPlayerController::ResetInputRotationScale()
{
}

void AFortPlayerController::ReturnToAthenaItemShop()
{
}

void AFortPlayerController::ReturnToMainMenu()
{
}

void AFortPlayerController::SendMessage(const FText& Message)
{
}

void AFortPlayerController::SendStreamingAnalytics(UMediaPlayer* MediaPlayer) const
{
}

void AFortPlayerController::ServerAcknowledgeDelayedQuickBarAction_Implementation(const TArray<uint32>& ProcessedActionIds)
{
}

void AFortPlayerController::ServerAddPawnMovementInput_Implementation(AFortPawn* InChar, FVector WorldDirection, float ScaleValue, bool bForce)
{
}
bool AFortPlayerController::ServerAddPawnMovementInput_Validate(AFortPawn* InChar, FVector WorldDirection, float ScaleValue, bool bForce)
{
	return true;
}

void AFortPlayerController::ServerAnnouncementStoppedOnClient_Implementation(FGuid AnnouncementID)
{
}

void AFortPlayerController::ServerApplyOverrideWrapToItem_Implementation(const FGuid& GUID, const TSoftObjectPtr<UAthenaItemWrapDefinition>& ItemWrap)
{
}
bool AFortPlayerController::ServerApplyOverrideWrapToItem_Validate(const FGuid& GUID, const TSoftObjectPtr<UAthenaItemWrapDefinition>& ItemWrap)
{
	return true;
}

void AFortPlayerController::ServerApplyOverrideWrapToVehicle_Implementation(const TSoftObjectPtr<UAthenaItemWrapDefinition>& ItemWrap)
{
}

void AFortPlayerController::ServerAttemptInventoryDrop_Implementation(FGuid ItemGuid, int32 Count, bool bTrash)
{
}

void AFortPlayerController::ServerBeginEditingBuildingActor_Implementation(ABuildingSMActor* BuildingActorToEdit)
{
}
bool AFortPlayerController::ServerBeginEditingBuildingActor_Validate(ABuildingSMActor* BuildingActorToEdit)
{
	return true;
}

void AFortPlayerController::ServerBroadcastPlayerChangedBuildMode_Implementation(bool bIsInBuildMode)
{
}

void AFortPlayerController::ServerBroadcastUIFeedbackEvent_Implementation(FName EventName)
{
}

void AFortPlayerController::ServerCheat_Implementation(const FString& Msg)
{
}

void AFortPlayerController::ServerCheatAll_Implementation(const FString& Msg)
{
}

void AFortPlayerController::ServerClearItemList_Implementation(UFortMinigameItemContainerComponent* ItemContainerComponent)
{
}
bool AFortPlayerController::ServerClearItemList_Validate(UFortMinigameItemContainerComponent* ItemContainerComponent)
{
	return true;
}

void AFortPlayerController::ServerClientPawnLoaded_Implementation(bool bIsPawnLoaded)
{
}

void AFortPlayerController::ServerCombineInventoryItems_Implementation(FGuid TargetItemGuid, FGuid SourceItemGuid)
{
}

void AFortPlayerController::ServerConvertToDirectBinding_Implementation(AFortMinigameSettingsBuilding* Target)
{
}
bool AFortPlayerController::ServerConvertToDirectBinding_Validate(AFortMinigameSettingsBuilding* Target)
{
	return true;
}

void AFortPlayerController::ServerCraftSchematic_Implementation(const FString& ItemId, int32 PostCraftSlot, int32 CraftAmount, EFortItemTier RequestedTier, bool bIsQuickCrafted)
{
}

void AFortPlayerController::ServerCreateBuildingActor_Implementation(FCreateBuildingActorData CreateBuildingData)
{
}
bool AFortPlayerController::ServerCreateBuildingActor_Validate(FCreateBuildingActorData CreateBuildingData)
{
	return true;
}

void AFortPlayerController::ServerDeployDefender_Implementation(ABuildingTrapDefender* DefenderTrap, const FString& SelectedItemInstanceId, const FName& DefenderSquadId, const FGuid WeaponToGiveGuid, const int32 AmmoQuantity)
{
}
bool AFortPlayerController::ServerDeployDefender_Validate(ABuildingTrapDefender* DefenderTrap, const FString& SelectedItemInstanceId, const FName& DefenderSquadId, const FGuid WeaponToGiveGuid, const int32 AmmoQuantity)
{
	return true;
}

void AFortPlayerController::ServerDeveloper_GetConsoleVariable_Implementation(const FString& ConsoleVariable)
{
}

void AFortPlayerController::ServerDisassembleInventoryItems_Implementation(const TArray<FGuid>& ItemGuids, const TArray<int32>& ItemCounts)
{
}
bool AFortPlayerController::ServerDisassembleInventoryItems_Validate(const TArray<FGuid>& ItemGuids, const TArray<int32>& ItemCounts)
{
	return true;
}

void AFortPlayerController::ServerDropAllItems_Implementation(const UFortItemDefinition* IgnoreItemDef)
{
}
bool AFortPlayerController::ServerDropAllItems_Validate(const UFortItemDefinition* IgnoreItemDef)
{
	return true;
}

void AFortPlayerController::ServerDropCarriedObject_Implementation()
{
}

void AFortPlayerController::ServerEditBuildingActor_Implementation(ABuildingSMActor* BuildingActorToEdit, TSubclassOf<ABuildingSMActor> NewBuildingClass, uint8 RotationIterations, bool bMirrored)
{
}
bool AFortPlayerController::ServerEditBuildingActor_Validate(ABuildingSMActor* BuildingActorToEdit, TSubclassOf<ABuildingSMActor> NewBuildingClass, uint8 RotationIterations, bool bMirrored)
{
	return true;
}

void AFortPlayerController::ServerEmote_Implementation(const FName& AssetName)
{
}

void AFortPlayerController::ServerEndEditingBuildingActor_Implementation(ABuildingSMActor* BuildingActorToStopEditing)
{
}
bool AFortPlayerController::ServerEndEditingBuildingActor_Validate(ABuildingSMActor* BuildingActorToStopEditing)
{
	return true;
}

void AFortPlayerController::ServerExecuteInventoryItem_Implementation(FGuid ItemGuid)
{
}

void AFortPlayerController::ServerExecutePresetTeamChat_Implementation(const FText& ChatText, FUniqueNetIdRepl SenderID)
{
}
bool AFortPlayerController::ServerExecutePresetTeamChat_Validate(const FText& ChatText, FUniqueNetIdRepl SenderID)
{
	return true;
}

void AFortPlayerController::ServerFinishedLevelStreaming_Implementation(UFortLevelStreamComponent* ComponentStreamingFinishedFor)
{
}
bool AFortPlayerController::ServerFinishedLevelStreaming_Validate(UFortLevelStreamComponent* ComponentStreamingFinishedFor)
{
	return true;
}

void AFortPlayerController::ServerHandleMissionEvent_StartLeavingZone_Implementation()
{
}

void AFortPlayerController::ServerHandleMissionEvent_ToggledCursorMode_Implementation(bool bOpened)
{
}

void AFortPlayerController::ServerHandleMissionEvent_ToggledEditMode_Implementation(ABuildingSMActor* EditableActor, bool bOpened)
{
}
bool AFortPlayerController::ServerHandleMissionEvent_ToggledEditMode_Validate(ABuildingSMActor* EditableActor, bool bOpened)
{
	return true;
}

void AFortPlayerController::ServerItemWillBeDestroyed_Implementation(FGuid DestroyedItemGuid, int32 Count)
{
}

void AFortPlayerController::ServerKickPlayer_Implementation(const FUniqueNetIdRepl& PlayerToKick, const FText& Reason)
{
}

void AFortPlayerController::ServerKillAllAIPawnsAroundPlayer_Implementation()
{
}

void AFortPlayerController::ServerLoadingScreenDropped_Implementation()
{
}

void AFortPlayerController::ServerModifyStat_Implementation(FName StatName, int32 Amount, EStatMod ModType, bool bForceStatSave)
{
}

void AFortPlayerController::ServerNotifyMeshNetPlayer_Implementation(FName Tag)
{
}

void AFortPlayerController::ServerOnMaterialSelection_Implementation(EFortResourceType::Type NewResourceType, EFortResourceLevel::Type NewResourceLevel)
{
}

void AFortPlayerController::ServerPingMinimap_Implementation(FVector WorldLocation, FLinearColor PingColor, uint8 RequiredTeam)
{
}

void AFortPlayerController::ServerPlayEmoteItem_Implementation(const UFortMontageItemDefinitionBase* EmoteAsset, float EmoteRandomNumber)
{
}
bool AFortPlayerController::ServerPlayEmoteItem_Validate(const UFortMontageItemDefinitionBase* EmoteAsset, float EmoteRandomNumber)
{
	return true;
}

void AFortPlayerController::ServerPlayerRequestClearIslandData_Implementation()
{
}

void AFortPlayerController::ServerReadyToStartMatch_Implementation()
{
}

void AFortPlayerController::ServerReAimAllReplaySpotLights_Implementation(FVector NewLocation, FRotator NewRotation)
{
}

void AFortPlayerController::ServerReAimCurrentReplaySpotLight_Implementation(FVector NewLocation, FRotator NewRotation)
{
}

void AFortPlayerController::ServerReleaseInventoryItemKey_Implementation(FGuid ItemGuid)
{
}

void AFortPlayerController::ServerRemoveDefender_Implementation(ABuildingTrapDefender* DefenderTrap)
{
}
bool AFortPlayerController::ServerRemoveDefender_Validate(ABuildingTrapDefender* DefenderTrap)
{
	return true;
}

void AFortPlayerController::ServerRemoveInventoryItem_Implementation(FGuid ItemGuid, int32 Count, bool bForceRemoval, bool bForcePersistWhenEmpty)
{
}

void AFortPlayerController::ServerRemoveInventoryStateValue_Implementation(FGuid ItemGuid, EFortItemEntryState::Type StateValueType)
{
}

void AFortPlayerController::ServerRepairBuildingActor_Implementation(ABuildingSMActor* BuildingActorToRepair)
{
}
bool AFortPlayerController::ServerRepairBuildingActor_Validate(ABuildingSMActor* BuildingActorToRepair)
{
	return true;
}

void AFortPlayerController::ServerReplyToReadyCheck_Implementation(bool bReady)
{
}

void AFortPlayerController::ServerRequestAIDebug_Implementation()
{
}

void AFortPlayerController::ServerRequestAttributeSources_Implementation(FGameplayAttribute Attribute, UFortAbilitySystemComponent* AbilitySystemComponent)
{
}
bool AFortPlayerController::ServerRequestAttributeSources_Validate(FGameplayAttribute Attribute, UFortAbilitySystemComponent* AbilitySystemComponent)
{
	return true;
}

void AFortPlayerController::ServerRequestGameplayAction_Implementation(EFortRequestedGameplayAction::Type RequestedAction)
{
}

void AFortPlayerController::ServerRequestPresetCosmeticSwap_Implementation(const UAthenaCosmeticItemDefinition* ItemDef, int32 SwapIndex)
{
}

void AFortPlayerController::ServerRetryLocalPlaceBuildableClass_Implementation()
{
}

void AFortPlayerController::ServerReturnToMainMenu_Implementation()
{
}

void AFortPlayerController::ServerSendClientProgressUpdate_Implementation(const TArray<uint8>& ClientProgressUpdate)
{
}

void AFortPlayerController::ServerSendCustomStatEventWithTags_Implementation(EFortQuestObjectiveStatEvent Type, FGameplayTagContainer AdditionalSourceTags, FGameplayTagContainer TargetTags, int32 Count)
{
}

void AFortPlayerController::ServerSetAntiAddictionPlayTimeMultiplier_Implementation(float NewPlayTimeRewardRate)
{
}

void AFortPlayerController::ServerSetAutoEquipBetterItems_Implementation(bool bAutoEquip)
{
}

void AFortPlayerController::ServerSetClientHasFinishedLoading_Implementation(bool bInHasFinishedLoading)
{
}

void AFortPlayerController::ServerSetCurrentReplaySpotLight_Implementation(AFortReplayMovableSpotLight* NewReplaySpotLight)
{
}

void AFortPlayerController::ServerSetCurrentReplaySpotLightColor_Implementation(int32 R, int32 G, int32 B)
{
}

void AFortPlayerController::ServerSetCurrentReplaySpotLightDebugDraw_Implementation(bool bEnabled)
{
}

void AFortPlayerController::ServerSetInventoryStateValue_Implementation(FGuid ItemGuid, FFortItemEntryStateValue StateValue)
{
}

void AFortPlayerController::ServerSetMarkText_Implementation(AFortMarkActor* MarkActor, const FString& MarkText)
{
}

void AFortPlayerController::ServerSetPartyOwner_Implementation(const FUniqueNetIdRepl& PartyOwnerUniqueId)
{
}

void AFortPlayerController::ServerSetReadyToContinue_Implementation(bool bReady, EFortGameplayState::Type RequestedState, bool bTryStartTimer)
{
}

void AFortPlayerController::ServerSetRebootEligiblePartyFriendsList_Implementation(const TArray<FFortRebootEligiblePartyFriendInfo>& NewRebootEligiblePartyFriends)
{
}

void AFortPlayerController::ServerSetReplaySpotLightGroupMoveLocked_Implementation(uint32 Number, bool bLocked)
{
}

void AFortPlayerController::ServerSetShouldUseBotManager_Implementation(bool InValue)
{
}

void AFortPlayerController::ServerSetShouldUsePilotComponent_Implementation(bool InValue)
{
}

void AFortPlayerController::ServerSetWeaponAutoPickups_Implementation(bool bEnablePickups)
{
}
bool AFortPlayerController::ServerSetWeaponAutoPickups_Validate(bool bEnablePickups)
{
	return true;
}

void AFortPlayerController::ServerSpawnMark_Implementation(AActor* ActorToAttachTo, FVector AttachOffset, const FText& PreapprovedText)
{
}
bool AFortPlayerController::ServerSpawnMark_Validate(AActor* ActorToAttachTo, FVector AttachOffset, const FText& PreapprovedText)
{
	return true;
}

void AFortPlayerController::ServerSpotActor_Implementation(AActor* NewlySpottedActor)
{
}
bool AFortPlayerController::ServerSpotActor_Validate(AActor* NewlySpottedActor)
{
	return true;
}

void AFortPlayerController::ServerStartIntensityGraphing_Implementation()
{
}

void AFortPlayerController::ServerStartPIDContributionsGraphing_Implementation()
{
}

void AFortPlayerController::ServerStartPIDValueGraphing_Implementation()
{
}

void AFortPlayerController::ServerSuicide_Implementation()
{
}

void AFortPlayerController::ServerTeamChatRoomReady_Implementation(const FString& ChatRoomId)
{
}

void AFortPlayerController::ServerTeleportToReticle_Implementation(FVector TeleportLocation)
{
}

void AFortPlayerController::ServerTouchActiveTime_Implementation()
{
}

void AFortPlayerController::ServerTriggerGenericObjectiveEvent_Implementation(AFortObjectiveBase* Objective)
{
}
bool AFortPlayerController::ServerTriggerGenericObjectiveEvent_Validate(AFortObjectiveBase* Objective)
{
	return true;
}

void AFortPlayerController::ServerUIChoiceCompleted_Implementation(int32 ChosenItem, int32 MenuIdentifier)
{
}

void AFortPlayerController::ServerUpdateActorOptions_Implementation(AActor* OptionsTarget, const TArray<FString>& OptionsKeys, const TArray<FString>& OptionsValues, const TArray<FFortGameplayEventContainer_Named>& AddedSubscriptions, const TArray<FFortGameplayEventContainer_Named>& RemovedSubscriptions)
{
}
bool AFortPlayerController::ServerUpdateActorOptions_Validate(AActor* OptionsTarget, const TArray<FString>& OptionsKeys, const TArray<FString>& OptionsValues, const TArray<FFortGameplayEventContainer_Named>& AddedSubscriptions, const TArray<FFortGameplayEventContainer_Named>& RemovedSubscriptions)
{
	return true;
}

void AFortPlayerController::ServerUpdateGameDescriptionData_Implementation(AActor* DataTarget, const FText& GameName, const TArray<FText>& GameDescriptionText)
{
}
bool AFortPlayerController::ServerUpdateGameDescriptionData_Validate(AActor* DataTarget, const FText& GameName, const TArray<FText>& GameDescriptionText)
{
	return true;
}

void AFortPlayerController::ServerUpdateGameplayOptions_Implementation(const TArray<FString>& UserOptionsKeys, const TArray<FString>& UserOptionsValues)
{
}
bool AFortPlayerController::ServerUpdateGameplayOptions_Validate(const TArray<FString>& UserOptionsKeys, const TArray<FString>& UserOptionsValues)
{
	return true;
}

void AFortPlayerController::ServerUpdateItemListOptions_Implementation(UFortMinigameItemContainerComponent* ItemContainerComponent, int32 ItemIndex, const TArray<FString>& OptionsKeys, const TArray<FString>& OptionsValues)
{
}
bool AFortPlayerController::ServerUpdateItemListOptions_Validate(UFortMinigameItemContainerComponent* ItemContainerComponent, int32 ItemIndex, const TArray<FString>& OptionsKeys, const TArray<FString>& OptionsValues)
{
	return true;
}

void AFortPlayerController::ServerUpdateMessageComponents_Implementation(const TArray<UFortGameplayMessageComponentBase*>& ModifiedComponents, const TArray<FGameplayTagContainer>& NewChannelIds)
{
}
bool AFortPlayerController::ServerUpdateMessageComponents_Validate(const TArray<UFortGameplayMessageComponentBase*>& ModifiedComponents, const TArray<FGameplayTagContainer>& NewChannelIds)
{
	return true;
}

void AFortPlayerController::ServerUpdateSprintToggleable_Implementation(const bool bShouldBeToggleable)
{
}

void AFortPlayerController::ServerUpgradeBuildingActor_Implementation(ABuildingActor* BuildingActorToUpgrade, int32 NewUpgradeLevel)
{
}
bool AFortPlayerController::ServerUpgradeBuildingActor_Validate(ABuildingActor* BuildingActorToUpgrade, int32 NewUpgradeLevel)
{
	return true;
}

bool AFortPlayerController::SetActorHiddenControllerOnly(AActor* TargetActor, const bool bNewHidden)
{
	return false;
}

void AFortPlayerController::SetAtNameHomeBaseScreen(bool AtScreen)
{
}

void AFortPlayerController::SetAttemptReloadOnEquip(bool bAttemptReloadOnEquip)
{
}

void AFortPlayerController::SetBoundEntryToActions(const TArray<FName>& InBoundActions, UWidget* EntryToBind)
{
}

void AFortPlayerController::SetBuildingHighlight(const TArray<ABuildingActor*>& TargetedBuildings, EBuildingHighlightType::Type HighlightType, bool bValidHighlight)
{
}

void AFortPlayerController::SetCinematicModeWithWeapon(bool bInCinematicMode, bool bHidePlayer, bool bHideWeapon, bool bAffectsHUD, bool bAffectsMovement, bool bAffectsTurning)
{
}

void AFortPlayerController::SetCinematicOverrideClass(TSubclassOf<UFortCinematicCamera> OverrideCameraClass)
{
}

void AFortPlayerController::SetClientPawnNewRotation(const FRotator& NewRotation)
{
}

bool AFortPlayerController::SetCompHiddenControllerOnly(USceneComponent* SceneComp, const bool bNewHiddenGame, const bool bPropagateToChildren)
{
	return false;
}

bool AFortPlayerController::SetCompHiddenOtherLocalControllersOnly(USceneComponent* SceneComp, const bool bNewHiddenGame, const bool bPropagateToChildren)
{
	return false;
}

void AFortPlayerController::SetDisableNativeDamageNumbers(const bool bNewDisableNativeDamageNumbers)
{
}

void AFortPlayerController::SetDisableNativeHitMarker(const bool bNewDisableNativeHitMarker)
{
}

void AFortPlayerController::SetFirstPersonCamera(bool bNewUseFirstPersonCamera)
{
}

void AFortPlayerController::SetForcedInputRotationSpeed(float InForcedInputRotationSpeed)
{
}

void AFortPlayerController::SetHUDElementVisibility(const FGameplayTagContainer& HUDElementTags, const bool bHideElements, const FName ReasonName, const FString& LogContext)
{
}

void AFortPlayerController::SetIgnoreSignifanceBasedCustomDepthRendering(bool bValue, UObject* ModifyingObject)
{
}

void AFortPlayerController::SetInputPitchScale(float InInputPitchScale)
{
}

void AFortPlayerController::SetInputYawScale(float InInputYawScale)
{
}

void AFortPlayerController::SetLockOnTargetStickCoords(const FVector2D& Coords)
{
}

void AFortPlayerController::SetPickerEnabled(bool bEnabled)
{
}

void AFortPlayerController::SetRotatePawnToCamera(bool bNewRotatePawnToCamera)
{
}

void AFortPlayerController::SetSprintBehaviorIsOverridden(bool bNewSprintBehaviorIsOverridden, bool bNewSprintByDefaultWhenSprintIsOverridden)
{
}

void AFortPlayerController::SetVoiceChatDistance(const FUniqueNetIdRepl& UniqueNetId, float Distance)
{
}

void AFortPlayerController::SetVoiceChatDistanceAttenuationEnabled(bool bInEnabled)
{
}

void AFortPlayerController::SetVoiceChatDistanceAttenuationSettings(const FVoiceChatDistanceAttenuationSettings& InSettings)
{
}

void AFortPlayerController::SetVoiceInputEffectChain(USoundEffectSourcePresetChain* InSourceEffectPresetChain)
{
}

bool AFortPlayerController::ShouldShowInfoIndicator(const AActor* TestActor) const
{
	return false;
}

ABattleMapPawnLive* AFortPlayerController::SpawnBattleMapSpectator()
{
	return nullptr;
}

AActor* AFortPlayerController::SpawnToyInstance(TSubclassOf<AActor> ToyClass, FTransform SpawnPosition)
{
	return nullptr;
}

bool AFortPlayerController::StartReadyCheck(FText QueryText, FText YesText, FText NoText, float PercentageToPass)
{
	return false;
}

void AFortPlayerController::StartZeroingCameraRoll()
{
}

bool AFortPlayerController::StopBattleMapSpectator()
{
	return false;
}

void AFortPlayerController::Suicide()
{
}

void AFortPlayerController::SuppressEventNotifications(bool bSuppress)
{
}

void AFortPlayerController::TestStreamedVideo(const FString& URLInQuotes)
{
}

void AFortPlayerController::ToggleBattleMapSpectator()
{
}

void AFortPlayerController::ToggleClientBot()
{
}

void AFortPlayerController::ToggleCursorMode(FName ActionName)
{
}

void AFortPlayerController::ToggleInventory()
{
}

void AFortPlayerController::TogglePersonalVehicle_Implementation(bool bOn)
{
}

void AFortPlayerController::TossSpecificItem(const UFortItemDefinition* DropItemDef, const FFortPickupTossOverrideData& TossOverrideData)
{
}

void AFortPlayerController::TryActivatePrimaryQuickbarFocusedWeapon()
{
}

void AFortPlayerController::UnMutePlayer(const FUniqueNetIdRepl& UniqueNetId)
{
}

void AFortPlayerController::UpdateClientCollection_Implementation(const FString& CollectionType, const FString& Category, const FFortMcpCollectedItemProperties& Properties, EFortCollectedVariantClientUpdate UpdateKind)
{
}

bool AFortPlayerController::WantsToDBNOCarry()
{
	return false;
}

bool AFortPlayerController::WantsToSecondaryInteract()
{
	return false;
}

void AFortPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPlayerController, bFailedToRespawn);
	DOREPLIFETIME(AFortPlayerController, bHasInitiallySpawned);
	DOREPLIFETIME(AFortPlayerController, bHasServerFinishedLoading);
	DOREPLIFETIME(AFortPlayerController, bHoldingObject);
	DOREPLIFETIME(AFortPlayerController, IntensityGraphInfo);
	DOREPLIFETIME(AFortPlayerController, PIDValuesGraphInfo);
	DOREPLIFETIME(AFortPlayerController, PIDContributionsGraphInfo);
	DOREPLIFETIME(AFortPlayerController, bBuildFree);
	DOREPLIFETIME(AFortPlayerController, bCraftFree);
	DOREPLIFETIME(AFortPlayerController, DelayedQuickBarActions);
	DOREPLIFETIME(AFortPlayerController, bAutoEquipBetterItems);
	DOREPLIFETIME(AFortPlayerController, WorldInventory);
	DOREPLIFETIME(AFortPlayerController, OutpostInventory);
	DOREPLIFETIME(AFortPlayerController, ViewTargetInventory);
	DOREPLIFETIME(AFortPlayerController, LatestRewardReport);
	DOREPLIFETIME(AFortPlayerController, UpdatedObjectiveStats);
	DOREPLIFETIME(AFortPlayerController, bHasUnsavedPrimaryMissionProgress);
	DOREPLIFETIME(AFortPlayerController, TutorialCompletedState);
	DOREPLIFETIME(AFortPlayerController, bInfiniteAmmo);
	DOREPLIFETIME(AFortPlayerController, bInfiniteConsumables);
	DOREPLIFETIME(AFortPlayerController, bNoCoolDown);
	DOREPLIFETIME(AFortPlayerController, bInfiniteDurability);
	DOREPLIFETIME(AFortPlayerController, bCheatGhost);
	DOREPLIFETIME(AFortPlayerController, bCheatFly);
	DOREPLIFETIME(AFortPlayerController, bEnableShotLogging);
	DOREPLIFETIME(AFortPlayerController, bIsNearActiveEncounters);
	DOREPLIFETIME(AFortPlayerController, OverriddenBackpackSize);
	DOREPLIFETIME(AFortPlayerController, CurrentReplaySpotLight);
	DOREPLIFETIME(AFortPlayerController, AimHelpMode);
	DOREPLIFETIME(AFortPlayerController, JumpStaminaCost);
	DOREPLIFETIME(AFortPlayerController, CameraPrototypeName);
	DOREPLIFETIME(AFortPlayerController, FocusTarget);
	DOREPLIFETIME(AFortPlayerController, bFinalXPUpdateFailed);
	DOREPLIFETIME(AFortPlayerController, MeshParentIds);
}
