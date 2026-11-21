// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "FortEncounterDirectionEnum.h"
#include "FortEncounterEnvironmentQueryInfo.h"
#include "FortEncounterSettings.h"
#include "FortEventName.h"
#include "FortTeamEnum.h"
#include "Missions/MissionTypes.h"
#include "STW/GameDataSTW.h"
#include "STW/TieredWaveSet.h"
#include "FortMissionLibrary.generated.h"

class AActor;
class ABuildingActor;
class AFortBluGloManager;
class AFortMission;
class AFortPawn;
class AFortPickup;
class AFortPlacementActor;
class AFortPlayerController;
class AFortPlayerPawn;
class AFortPlayerStateZone;
class UBoxComponent;
class UDataAsset;
class UFortAIEncounterInfo;
class UFortMissionEventParams;
class UFortMissionInfo;
class UFortMissionItemDefinition;
class UFortSchematicItemDefinition;
class UFortWorldItemDefinition;
class UObject;
enum class EFortObjectiveStatus : uint8;

UENUM()
namespace EMissionReplyTypes
{
	enum Type
	{
		Handled = 0,
		NotHandled = 1,
	};
}

UENUM()
namespace EPollActorsInVolumeTypes
{
	enum Type
	{
		DesignerPlacedOnly = 0,
		PlayerBuiltOnly = 1,
		All = 2,
	};
}

UCLASS(MinimalAPI)
class UFortMissionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void AddCompletionTagsToMission(UObject* WorldContextObject, FGuid MissionGuid, FGameplayTagContainer NewCompletionTagContainer);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void AddCompletionTagToMission(UObject* WorldContextObject, FGuid MissionGuid, FGameplayTag NewCompletionTag);

	UFUNCTION(BlueprintCallable, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void AdjustWaveBasedGameDifficulty(UObject* WorldContextObject, float fDifficultyAddMod);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(WorldContext="WorldContextObject"))
	static void CreateDynamicBuildingDeconstructor(UObject* WorldContextObject, FVector Origin, FVector BoxExtent, bool bIgnoreMissionActors = true, bool bShrinkAndDestroy = false);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="MissionManager", meta=(DeprecatedFunction, EventType="Undefined", GenericFloat="0", GenericInt="0", WorldContext="WorldContextObject"))
	static FFortMissionEvent CreateMissionEvent(UObject* WorldContextObject, FName EventType, FGuid MissionGuid, FGameplayTagContainer ObjectiveHandle, UFortMissionEventParams* Params, bool DO_NOT_USE_THIS_OR_VARIABLES_BELOW, UObject* EventFocus, UDataAsset* EventContent, AActor* EventInstigator, int32 GenericInt, float GenericFloat, FText GenericText, const FGameplayTagContainer GameplayTags);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionManager", meta=(DisplayName="ExecuteMissionEvent_Old", EventType="Undefined", GenericFloat="0", GenericInt="0", WorldContext="WorldContextObject"))
	static void ExecuteMissionEvent(UObject* WorldContextObject, FName EventType, FGuid MissionGuid, FGameplayTagContainer ObjectiveHandle, UFortMissionEventParams* Params, bool DO_NOT_USE_THIS_OR_VARIABLES_BELOW, UObject* EventFocus, UDataAsset* EventContent, AActor* EventInstigator, int32 GenericInt, float GenericFloat, FText GenericText, const FGameplayTagContainer GameplayTags);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionManager", meta=(BlueprintInternalUseOnly="true", DisplayName="ExecuteMissionEventEx_Old", GenericFloat="0", GenericInt="0", WorldContext="WorldContextObject"))
	static void ExecuteMissionEventEx(UObject* WorldContextObject, FFortMissionEventName EventType, FGuid MissionGuid, FGameplayTagContainer ObjectiveHandle, UFortMissionEventParams* Params, bool DO_NOT_USE_THIS_OR_VARIABLES_BELOW, UObject* EventFocus, UDataAsset* EventContent, AActor* EventInstigator, int32 GenericInt, float GenericFloat, FText GenericText, const FGameplayTagContainer GameplayTags);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(WorldContext="WorldContextObject"))
	static TArray<ABuildingActor*> FindActorsWithTags(UObject* WorldContextObject, const FGameplayTagContainer& Tags);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers")
	static AFortPlacementActor* FindOriginatingPlacementActor(ABuildingActor* BuildingActor);

	UFUNCTION(BlueprintCallable, Category="MissionManager", meta=(WorldContext="WorldContextObject"))
	static TArray<AFortMission*> GetAllLoadedMissions(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static int32 GetAveragePlayerAccountLevel(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="MissionManager", meta=(WorldContext="WorldContextObject"))
	static AFortBluGloManager* GetBluGloManager(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool GetIronCityMinMaxPowerLevels(int32 DifficultyLevel, float& MinPowerLevel, float& MaxPowerLevel);

	UFUNCTION(BlueprintCallable, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static float GetIronCityWorldDifficulty(int32 AccountLevel);

	UFUNCTION(BlueprintCallable, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static int32 GetLocalPlayerAccountLevel(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static int32 GetLowestPlayerAccountLevel(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static TArray<AActor*> GetMissionActorsInEncounterDirection(UObject* WorldContextObject, TSubclassOf<AActor> ActorSubclass, FVector StartLocation, EFortEncounterDirection::Type DirectionToLookForActors, float Angle = 45.000000f, float MaxDistance = 0.000000f);

	UFUNCTION(BlueprintPure, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static TArray<AActor*> GetMissionActorsInVectorDirection(UObject* WorldContextObject, TSubclassOf<AActor> ActorSubclass, FVector StartLocation, FVector DirectionToLookForActors, float Angle = 45.000000f, float MaxDistance = 0.000000f);

	UFUNCTION(BlueprintCallable, Category="MissionManager", meta=(WorldContext="WorldContextObject"))
	static AFortMission* GetMissionFromGuid(UObject* WorldContextObject, const FGuid& MissionGuid);

	UFUNCTION(BlueprintCallable, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static float GetMissionHUDTextLineHeightEstimate(FText Text);

	UFUNCTION(BlueprintCallable, Category="MissionManager", meta=(WorldContext="WorldContextObject"))
	static AFortMission* GetPrimaryMission(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void GetTieredWaveBaseNumKillPoints(UObject* WorldContextObject, FName BaseNumOfKillPointsRowName, float OverrideDifficulty, float& OutBaseNumKillPoints);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void GetTieredWaveBaseNumKills(UObject* WorldContextObject, FName BaseNumOfKillsRowName, float OverrideDifficulty, float& OutBaseNumKills);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void GetTieredWaveBaseRiftKills(UObject* WorldContextObject, FName BaseNumOfRiftKillsRowName, float OverrideDifficulty, int32& OutBaseRiftKills);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void GetTieredWaveBaseWaveLength(UObject* WorldContextObject, FName BaseWaveLengthRowName, float OverrideDifficulty, float& OutBaseWaveLength);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers")
	static void GetTieredWaveSet(FName TieredWaveCollectionName, int32 Tier, FTieredWaveSetCollectionData& WaveCollectionInfo, TArray<FTieredWaveSetData>& OutWaveData);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(WorldContext="WorldContextObject"))
	static void GiveMissionRewardsToPlayer(UObject* WorldContextObject, FGuid EventGuid, AFortPlayerController* PlayerController, FText TitleText, FText DescriptionText, FName LootTierGroup, int32 LootTier = -1, float RewardDisplayTime = -1.000000f);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(WorldContext="WorldContextObject"))
	static void GiveMissionRewardsToPlayerAsPickups(UObject* WorldContextObject, FGuid MissionGUID, AFortPlayerController* PlayerController, FVector StartPosition, float Radius, FName LootTierGroup, int32 LootTier = -1);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(WorldContext="WorldContextObject"))
	static bool GiveMissionSchematicItemDirectlyToPlayer(UObject* WorldContextObject, AFortPlayerController* TargetPlayer, FGuid MissionGuid, UFortSchematicItemDefinition* SchematicDefinition);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers")
	static bool HasTags(const FGameplayTagContainer& ContainerToCheck, const FGameplayTagContainer& TagsToCheck, bool bRequireAll = true, bool bCountEmptyAsMatch = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool IsUsingNewMissionGeneration(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionManager", meta=(WorldContext="WorldContextObject"))
	static void LoadMission(UObject* WorldContextObject, UFortMissionInfo* MissionInfo);

	UFUNCTION(BlueprintCallable, Category="MissionHelpers")
	static int32 NumBluGloFromPlayerPawn(AFortPlayerPawn* PlayerPawn);

	UFUNCTION(BlueprintCallable, Category="MissionHelpers")
	static int32 NumBluGloFromPlayerState(AFortPlayerStateZone* PlayerState);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(WorldContext="WorldContextObject"))
	static void PingMinimap(UObject* WorldContextObject, FVector WorldLocation, FLinearColor PingColor = FLinearColor(1.000000, 1.000000, 0.000000, 1.000000), EFortTeam::Type RequiredTeam = EFortTeam::HumanCampaign);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(ActorClassToPoll="/Script/Engine.Actor", BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static int32 PollActorsInVolume(UObject* WorldContextObject, UBoxComponent* VolumeBoxComponent, EPollActorsInVolumeTypes::Type PollBuildingTypes, TSubclassOf<AActor> ActorClassToPoll);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(DefaultToSelf="ActorToRegister"))
	static bool RegisterForMissionEvents(AActor* ActorToRegister, FGuid MissionGuid);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions")
	static bool RegisterMissionInfoUIActor(AActor* AttachmentActor, FGuid MissionGuid, FVector AttachementOffset, float MaxVisibleDistance = 4096.000000f);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void SetOnlinePresenceDoNotDisturb(UObject* WorldContextObject, bool bDoNotDisturb, AFortPlayerController* SpecificPlayer);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(WorldContext="WorldContextObject"))
	static void SetWorldSavingEnabled(UObject* WorldContextObject, bool bEnabled);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool ShouldUseAlternateAIDirectorBalance();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(WorldContext="WorldContextObject"))
	static void SpawnAndCollectPlayerPickups(UObject* WorldContextObject, AFortPlayerController* PlayerController, FVector StartPosition, FName LootTierGroup, int32 LootTier = -1);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static TArray<AActor*> SpawnAtPlacementActorsHelper(UObject* WorldContextObject, UClass* Entries, bool& bSucceeded);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", WorldContext="WorldContextObject"))
	static ABuildingActor* SpawnBuildingActorAtTransform(UObject* WorldContextObject, FGuid MissionGuid, TSubclassOf<ABuildingActor> BuildingClass, const FTransform& Transform);

	UFUNCTION(Category="MissionHelpers", meta=(WorldContext="WorldContextObject"))
	static AFortPickup* SpawnMissionItemPickup(UObject* WorldContextObject, FGuid MissionGuid, UFortMissionItemDefinition* MissionItemDefinition, FVector StartPosition, AFortPawn* TargetPawn);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(WorldContext="WorldContextObject"))
	static AFortPickup* SpawnMissionItemPickupInWorld(UObject* WorldContextObject, FGuid MissionGuid, UFortWorldItemDefinition* ItemDefinition, int32 NumberToSpawn, FVector Position, FVector Direction = FVector(0.000000, 0.000000, 1.000000), int32 OverrideMaxStackCount = 0);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", WorldContext="WorldContextObject"))
	static bool SpawnPlacementMissionActor(UObject* WorldContextObject, const TSubclassOf<AActor>& ActorToSpawn, const FVector& SpawnLocation, const FRotator& SpawnRotation, AActor* PlacementLocationActor, AActor*& OutSpawnedActor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(WorldContext="WorldContextObject"))
	static UFortAIEncounterInfo* StartAIEncounter(UObject* WorldContextObject, FString& AssociatedMissionName, TSubclassOf<UFortAIEncounterInfo> EncounterTemplate, AActor* TargetActor, FGameplayTagContainer InjectedTags, FFortEncounterSettings EncounterSettings, int32 ActivationDelay = 0);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(WorldContext="WorldContextObject"))
	static UFortAIEncounterInfo* StartAIEncounterWithEnvironmentQuery(UObject* WorldContextObject, FString& AssociatedMissionName, TSubclassOf<UFortAIEncounterInfo> EncounterTemplate, AActor* TargetActor, FEncounterEnvironmentQueryInfo EnvironmentQueryInfo, AActor* QueryActor, FGameplayTagContainer InjectedTags, FFortEncounterSettings EncounterSettings, int32 ActivationDelay = 0);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionManager", meta=(WorldContext="WorldContextObject"))
	static void StartPlayingMission(UObject* WorldContextObject, const FGuid& MissionGuid);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(WorldContext="WorldContextObject"))
	static void StopAIEncounter(UObject* WorldContextObject, UFortAIEncounterInfo* ActiveEncounter, EFortObjectiveStatus ObjectiveStatus = EFortObjectiveStatus::Max_None);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(WorldContext="WorldContextObject"))
	static void StopAIEncounterAgainstActor(UObject* WorldContextObject, AActor* TargetActor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Transform|Actor", meta=(WorldContext="WorldContextObject"))
	static void TeleportPawnNearLocation(const UObject* WorldContextObject, AFortPawn* Pawn, FVector DestLocation);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Transform|Actor", meta=(WorldContext="WorldContextObject"))
	static bool TeleportPlayerPawn(const UObject* WorldContextObject, AFortPlayerPawn* PlayerPawn, FVector DestLocation, FRotator DestRotation, bool bIgnoreCollision = false, bool bIgnoreSupplementalKillVolumeSweep = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(DefaultToSelf="ActorToRegister"))
	static bool UnregisterForMissionEvents(AActor* ActorToUnregister, FGuid MissionGuid);

};

