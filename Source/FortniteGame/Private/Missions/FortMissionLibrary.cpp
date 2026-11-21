// Copyright Epic Games, Inc. All Rights Reserved.

#include "Missions/FortMissionLibrary.h"

void UFortMissionLibrary::AddCompletionTagsToMission(UObject* WorldContextObject, FGuid MissionGuid, FGameplayTagContainer NewCompletionTagContainer)
{
}

void UFortMissionLibrary::AddCompletionTagToMission(UObject* WorldContextObject, FGuid MissionGuid, FGameplayTag NewCompletionTag)
{
}

void UFortMissionLibrary::AdjustWaveBasedGameDifficulty(UObject* WorldContextObject, float fDifficultyAddMod)
{
}

void UFortMissionLibrary::CreateDynamicBuildingDeconstructor(UObject* WorldContextObject, FVector Origin, FVector BoxExtent, bool bIgnoreMissionActors, bool bShrinkAndDestroy)
{
}

FFortMissionEvent UFortMissionLibrary::CreateMissionEvent(UObject* WorldContextObject, FName EventType, FGuid MissionGuid, FGameplayTagContainer ObjectiveHandle, UFortMissionEventParams* Params, bool DO_NOT_USE_THIS_OR_VARIABLES_BELOW, UObject* EventFocus, UDataAsset* EventContent, AActor* EventInstigator, int32 GenericInt, float GenericFloat, FText GenericText, const FGameplayTagContainer GameplayTags)
{
	return FFortMissionEvent();
}

void UFortMissionLibrary::ExecuteMissionEvent(UObject* WorldContextObject, FName EventType, FGuid MissionGuid, FGameplayTagContainer ObjectiveHandle, UFortMissionEventParams* Params, bool DO_NOT_USE_THIS_OR_VARIABLES_BELOW, UObject* EventFocus, UDataAsset* EventContent, AActor* EventInstigator, int32 GenericInt, float GenericFloat, FText GenericText, const FGameplayTagContainer GameplayTags)
{
}

void UFortMissionLibrary::ExecuteMissionEventEx(UObject* WorldContextObject, FFortMissionEventName EventType, FGuid MissionGuid, FGameplayTagContainer ObjectiveHandle, UFortMissionEventParams* Params, bool DO_NOT_USE_THIS_OR_VARIABLES_BELOW, UObject* EventFocus, UDataAsset* EventContent, AActor* EventInstigator, int32 GenericInt, float GenericFloat, FText GenericText, const FGameplayTagContainer GameplayTags)
{
}

TArray<ABuildingActor*> UFortMissionLibrary::FindActorsWithTags(UObject* WorldContextObject, const FGameplayTagContainer& Tags)
{
	return TArray<ABuildingActor*>();
}

AFortPlacementActor* UFortMissionLibrary::FindOriginatingPlacementActor(ABuildingActor* BuildingActor)
{
	return nullptr;
}

TArray<AFortMission*> UFortMissionLibrary::GetAllLoadedMissions(UObject* WorldContextObject)
{
	return TArray<AFortMission*>();
}

int32 UFortMissionLibrary::GetAveragePlayerAccountLevel(UObject* WorldContextObject)
{
	return int32();
}

AFortBluGloManager* UFortMissionLibrary::GetBluGloManager(UObject* WorldContextObject)
{
	return nullptr;
}

bool UFortMissionLibrary::GetIronCityMinMaxPowerLevels(int32 DifficultyLevel, float& MinPowerLevel, float& MaxPowerLevel)
{
	return false;
}

float UFortMissionLibrary::GetIronCityWorldDifficulty(int32 AccountLevel)
{
	return float();
}

int32 UFortMissionLibrary::GetLocalPlayerAccountLevel(UObject* WorldContextObject)
{
	return int32();
}

int32 UFortMissionLibrary::GetLowestPlayerAccountLevel(UObject* WorldContextObject)
{
	return int32();
}

TArray<AActor*> UFortMissionLibrary::GetMissionActorsInEncounterDirection(UObject* WorldContextObject, TSubclassOf<AActor> ActorSubclass, FVector StartLocation, EFortEncounterDirection::Type DirectionToLookForActors, float Angle, float MaxDistance)
{
	return TArray<AActor*>();
}

TArray<AActor*> UFortMissionLibrary::GetMissionActorsInVectorDirection(UObject* WorldContextObject, TSubclassOf<AActor> ActorSubclass, FVector StartLocation, FVector DirectionToLookForActors, float Angle, float MaxDistance)
{
	return TArray<AActor*>();
}

AFortMission* UFortMissionLibrary::GetMissionFromGuid(UObject* WorldContextObject, const FGuid& MissionGuid)
{
	return nullptr;
}

float UFortMissionLibrary::GetMissionHUDTextLineHeightEstimate(FText Text)
{
	return float();
}

AFortMission* UFortMissionLibrary::GetPrimaryMission(UObject* WorldContextObject)
{
	return nullptr;
}

void UFortMissionLibrary::GetTieredWaveBaseNumKillPoints(UObject* WorldContextObject, FName BaseNumOfKillPointsRowName, float OverrideDifficulty, float& OutBaseNumKillPoints)
{
}

void UFortMissionLibrary::GetTieredWaveBaseNumKills(UObject* WorldContextObject, FName BaseNumOfKillsRowName, float OverrideDifficulty, float& OutBaseNumKills)
{
}

void UFortMissionLibrary::GetTieredWaveBaseRiftKills(UObject* WorldContextObject, FName BaseNumOfRiftKillsRowName, float OverrideDifficulty, int32& OutBaseRiftKills)
{
}

void UFortMissionLibrary::GetTieredWaveBaseWaveLength(UObject* WorldContextObject, FName BaseWaveLengthRowName, float OverrideDifficulty, float& OutBaseWaveLength)
{
}

void UFortMissionLibrary::GetTieredWaveSet(FName TieredWaveCollectionName, int32 Tier, FTieredWaveSetCollectionData& WaveCollectionInfo, TArray<FTieredWaveSetData>& OutWaveData)
{
}

void UFortMissionLibrary::GiveMissionRewardsToPlayer(UObject* WorldContextObject, FGuid EventGuid, AFortPlayerController* PlayerController, FText TitleText, FText DescriptionText, FName LootTierGroup, int32 LootTier, float RewardDisplayTime)
{
}

void UFortMissionLibrary::GiveMissionRewardsToPlayerAsPickups(UObject* WorldContextObject, FGuid MissionGUID, AFortPlayerController* PlayerController, FVector StartPosition, float Radius, FName LootTierGroup, int32 LootTier)
{
}

bool UFortMissionLibrary::GiveMissionSchematicItemDirectlyToPlayer(UObject* WorldContextObject, AFortPlayerController* TargetPlayer, FGuid MissionGuid, UFortSchematicItemDefinition* SchematicDefinition)
{
	return false;
}

bool UFortMissionLibrary::HasTags(const FGameplayTagContainer& ContainerToCheck, const FGameplayTagContainer& TagsToCheck, bool bRequireAll, bool bCountEmptyAsMatch)
{
	return false;
}

bool UFortMissionLibrary::IsUsingNewMissionGeneration(UObject* WorldContextObject)
{
	return false;
}

void UFortMissionLibrary::LoadMission(UObject* WorldContextObject, UFortMissionInfo* MissionInfo)
{
}

int32 UFortMissionLibrary::NumBluGloFromPlayerPawn(AFortPlayerPawn* PlayerPawn)
{
	return int32();
}

int32 UFortMissionLibrary::NumBluGloFromPlayerState(AFortPlayerStateZone* PlayerState)
{
	return int32();
}

void UFortMissionLibrary::PingMinimap(UObject* WorldContextObject, FVector WorldLocation, FLinearColor PingColor, EFortTeam::Type RequiredTeam)
{
}

int32 UFortMissionLibrary::PollActorsInVolume(UObject* WorldContextObject, UBoxComponent* VolumeBoxComponent, EPollActorsInVolumeTypes::Type PollBuildingTypes, TSubclassOf<AActor> ActorClassToPoll)
{
	return int32();
}

bool UFortMissionLibrary::RegisterForMissionEvents(AActor* ActorToRegister, FGuid MissionGuid)
{
	return false;
}

bool UFortMissionLibrary::RegisterMissionInfoUIActor(AActor* AttachmentActor, FGuid MissionGuid, FVector AttachementOffset, float MaxVisibleDistance)
{
	return false;
}

void UFortMissionLibrary::SetOnlinePresenceDoNotDisturb(UObject* WorldContextObject, bool bDoNotDisturb, AFortPlayerController* SpecificPlayer)
{
}

void UFortMissionLibrary::SetWorldSavingEnabled(UObject* WorldContextObject, bool bEnabled)
{
}

bool UFortMissionLibrary::ShouldUseAlternateAIDirectorBalance()
{
	return false;
}

void UFortMissionLibrary::SpawnAndCollectPlayerPickups(UObject* WorldContextObject, AFortPlayerController* PlayerController, FVector StartPosition, FName LootTierGroup, int32 LootTier)
{
}

TArray<AActor*> UFortMissionLibrary::SpawnAtPlacementActorsHelper(UObject* WorldContextObject, UClass* Entries, bool& bSucceeded)
{
	return TArray<AActor*>();
}

ABuildingActor* UFortMissionLibrary::SpawnBuildingActorAtTransform(UObject* WorldContextObject, FGuid MissionGuid, TSubclassOf<ABuildingActor> BuildingClass, const FTransform& Transform)
{
	return nullptr;
}

AFortPickup* UFortMissionLibrary::SpawnMissionItemPickup(UObject* WorldContextObject, FGuid MissionGuid, UFortMissionItemDefinition* MissionItemDefinition, FVector StartPosition, AFortPawn* TargetPawn)
{
	return nullptr;
}

AFortPickup* UFortMissionLibrary::SpawnMissionItemPickupInWorld(UObject* WorldContextObject, FGuid MissionGuid, UFortWorldItemDefinition* ItemDefinition, int32 NumberToSpawn, FVector Position, FVector Direction, int32 OverrideMaxStackCount)
{
	return nullptr;
}

bool UFortMissionLibrary::SpawnPlacementMissionActor(UObject* WorldContextObject, const TSubclassOf<AActor>& ActorToSpawn, const FVector& SpawnLocation, const FRotator& SpawnRotation, AActor* PlacementLocationActor, AActor*& OutSpawnedActor)
{
	return false;
}

UFortAIEncounterInfo* UFortMissionLibrary::StartAIEncounter(UObject* WorldContextObject, FString& AssociatedMissionName, TSubclassOf<UFortAIEncounterInfo> EncounterTemplate, AActor* TargetActor, FGameplayTagContainer InjectedTags, FFortEncounterSettings EncounterSettings, int32 ActivationDelay)
{
	return nullptr;
}

UFortAIEncounterInfo* UFortMissionLibrary::StartAIEncounterWithEnvironmentQuery(UObject* WorldContextObject, FString& AssociatedMissionName, TSubclassOf<UFortAIEncounterInfo> EncounterTemplate, AActor* TargetActor, FEncounterEnvironmentQueryInfo EnvironmentQueryInfo, AActor* QueryActor, FGameplayTagContainer InjectedTags, FFortEncounterSettings EncounterSettings, int32 ActivationDelay)
{
	return nullptr;
}

void UFortMissionLibrary::StartPlayingMission(UObject* WorldContextObject, const FGuid& MissionGuid)
{
}

void UFortMissionLibrary::StopAIEncounter(UObject* WorldContextObject, UFortAIEncounterInfo* ActiveEncounter, EFortObjectiveStatus ObjectiveStatus)
{
}

void UFortMissionLibrary::StopAIEncounterAgainstActor(UObject* WorldContextObject, AActor* TargetActor)
{
}

void UFortMissionLibrary::TeleportPawnNearLocation(const UObject* WorldContextObject, AFortPawn* Pawn, FVector DestLocation)
{
}

bool UFortMissionLibrary::TeleportPlayerPawn(const UObject* WorldContextObject, AFortPlayerPawn* PlayerPawn, FVector DestLocation, FRotator DestRotation, bool bIgnoreCollision, bool bIgnoreSupplementalKillVolumeSweep)
{
	return false;
}

bool UFortMissionLibrary::UnregisterForMissionEvents(AActor* ActorToUnregister, FGuid MissionGuid)
{
	return false;
}
