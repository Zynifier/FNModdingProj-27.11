// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ReplicationGraph.h"
#include "ReplicationGraphTypes.h"
#include "UObject/NoExportTypes.h"
#include "FortReplicationGraph.generated.h"

class AActor;
class AFortPlayerStateAthena;
class AFortTeamHealthInfo;
class AFortTeamPrivateInfo;
class AFortVolume;
class UFortReplicationGraphNode_Custom;
class UFortReplicationGraphNode_LiveSpectator;
class UFortReplicationGraphNode_PlayerStateFrequencyLimiter;
class UObject;
class UReplicationGraphNode_ActorList;
class UReplicationGraphNode_DormancyNode;
class UReplicationGraphNode_FortVolumeGlobalRelevancyNode;
class UReplicationGraphNode_FortVolumeGrid;
class UReplicationGraphNode_GridSpatialization2D;

UENUM()
enum EClassRepNodeMapping
{
	NotRouted = 0,
	// Doesn't map to any node. Used for special case actors that handled by special case nodes (UFortReplicationGraphNode_AlwaysRelevantForTeam, UFortReplicationGraphNode_PlayerStateFrequencyLimiter)

	RelevantAllConnections = 1,
	// Routes to an AlwaysRelevantNode or AlwaysRelevantStreamingLevelNode node

	RelevantAllInsideFortVolume = 2,
	// Will always be relevant to all clients inside the given FortVolume

	Custom = 3,
	// ONLY SPATIALIZED Enums below here! See UFortReplicationGraph::IsSpatialized

	Spatialize_Static = 4,
	// Routes to GridNode: these actors don't move and don't need to be updated every frame.

	Spatialize_Dynamic = 5,
	// Routes to GridNode: these actors mode frequently and are updated once per frame.

	Spatialize_Dormancy = 6,
	// Routes to GridNode: While dormant we treat as static. When flushed/not dormant dynamic. Note this is for things that "move while not dormant". BuildingActors for example are Spatialize_Static despite using net dormancy.

	Instance_Dynamic = 7,
};

UENUM()
enum class EFortDynamicNodeType : uint8
{
	AI = 0,
	PhysicsObject = 1,
	Vehicle = 2,
	NumTypes = 3,
};

USTRUCT()
struct FRepGraphActorSettingsBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="RepGraphActorSettingsBase")
	uint8 bAddClassRepInfoToMap : 1;

	UPROPERTY()
	uint8 bUseCustomClassRepInfo : 1;

	UPROPERTY()
	uint8 bAddToExplicitCSVStatTracker : 1;

	UPROPERTY()
	uint8 bAddToImplicitCSVStatTracker : 1;

	UPROPERTY(EditAnywhere, Category="RepGraphActorSettingsBase")
	uint8 bAddToRPC_Multicast_OpenChannelForClassMap : 1;

	UPROPERTY(EditAnywhere, Category="RepGraphActorSettingsBase", meta=(EditCondition="bAddToRPC_Multicast_OpenChannelForClassMap"))
	uint8 bRPC_Multicast_OpenChannelForClass : 1;

	UPROPERTY(EditAnywhere, Category="RepGraphActorSettingsBase", meta=(EditCondition="bAddClassRepInfoToMap"))
	TEnumAsByte<EClassRepNodeMapping> ClassNodeMapping;

	UPROPERTY()
	FClassReplicationInfo ClassRepInfo;

	UPROPERTY()
	FName CSVStatNamePrefix;

};

USTRUCT()
struct FRepGraphActorClassSettings : public FRepGraphActorSettingsBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="RepGraphActorClassSettings")
	FName ActorClassName;

	UPROPERTY()
	FName MapToTemplate;

};

USTRUCT()
struct FRepGraphActorTemplateSettings : public FRepGraphActorSettingsBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName TemplateName;

};

USTRUCT()
struct FRepGraphClassTracking
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ClassName;

	UPROPERTY()
	FString CSVStatNamePrefix;

	UPROPERTY()
	bool bIncludeFastPath;

};

UCLASS()
class UFortReplicationGraph : public UReplicationGraph
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnGameStatePlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UFUNCTION()
	void OnHighFrequencyPawnDestroyed(AActor* Pawn);

	UFUNCTION()
	void OnVehicleDestroyed(AActor* DestroyedVehicle);

	UPROPERTY()
	TObjectPtr<UReplicationGraphNode_GridSpatialization2D> RootGridNode;

	UPROPERTY()
	TObjectPtr<UReplicationGraphNode_ActorList> AlwaysRelevantNode;

	UPROPERTY()
	TObjectPtr<UFortReplicationGraphNode_LiveSpectator> LiveSpectatorRelevancyNode;

	UPROPERTY()
	TObjectPtr<UFortReplicationGraphNode_PlayerStateFrequencyLimiter> PlayerStateLimiterNode;

	UPROPERTY()
	TObjectPtr<UFortReplicationGraphNode_PlayerStateFrequencyLimiter> ReplayPlayerStateLimiterNode;

private:
	UPROPERTY()
	TArray<TObjectPtr<UReplicationGraphNode_FortVolumeGrid>> FortVolumeGrids;

	UPROPERTY()
	TMap<TSubclassOf<UObject>, TObjectPtr<UFortReplicationGraphNode_Custom>> ClassToNodetoRouteTo;

	UPROPERTY(Config)
	TArray<FString> UncapDSFBandwidthForPlaylists;

	UPROPERTY(Config)
	TArray<FString> UncapDSFBandwidthForFleets;

};

UCLASS()
class UFortReplicationGraphConnection : public UNetReplicationGraphConnection
{
	GENERATED_BODY()

};

UCLASS()
class UFortReplicationGraphNode_AlwaysRelevantForSquad : public UReplicationGraphNode
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerStateAthena>> PlayerStates;

	UPROPERTY()
	TArray<TObjectPtr<AActor>> AlwaysRelevantActors;

};

UCLASS()
class UFortReplicationGraphNode_AlwaysRelevantForTeam : public UReplicationGraphNode
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<AFortTeamPrivateInfo> FortTeamPrivateInfo;

};

UCLASS()
class UFortReplicationGraphNode_AlwaysRelevantHealthForTeam : public UReplicationGraphNode
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TWeakObjectPtr<AFortTeamHealthInfo> FortTeamHealthInfo;

};

UCLASS()
class UFortReplicationGraphNode_AlwaysRelevant_ForConnection : public UReplicationGraphNode
{
	GENERATED_BODY()

};

UCLASS()
class UFortReplicationGraphNode_DynamicSpatialFrequency : public UReplicationGraphNode_DynamicSpatialFrequency
{
	GENERATED_BODY()

};

UCLASS()
class UFortReplicationGraphNode_LiveSpectator : public UReplicationGraphNode_ActorList
{
	GENERATED_BODY()

};

UCLASS()
class UFortReplicationGraphNode_PlayerStateFrequencyLimiter : public UReplicationGraphNode
{
	GENERATED_BODY()

};

UCLASS(Config=Engine)
class UGlobalRepGraphActorClassSettings : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	TArray<FRepGraphActorClassSettings> ClassSettings;

	UPROPERTY(Config)
	TArray<FRepGraphClassTracking> ExplicitCSVTracking;

	UPROPERTY(Config)
	TArray<FRepGraphClassTracking> MinimalExplicitCSVTracking;

	UPROPERTY(Config)
	TArray<FRepGraphClassTracking> ImplicitCSVTracking;

private:
	UPROPERTY(Config)
	TArray<FRepGraphActorTemplateSettings> TemplateSettings;

};

UCLASS()
class UReplicationGraphNode_FortVolumeGlobalRelevancyNode : public UReplicationGraphNode
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UReplicationGraphNode_ActorList> NeverDormantOrAwakeList;

	UPROPERTY()
	TObjectPtr<UReplicationGraphNode_DormancyNode> DormantNode;

};

UCLASS()
class UReplicationGraphNode_FortVolumeGrid : public UReplicationGraphNode
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleStreamedLevelHidden();

	UFUNCTION()
	void HandleStreamedLevelLoaded();

	UFUNCTION()
	void HandleStreamedLevelShown();

	UFUNCTION()
	void HandleStreamedLevelUnloaded();

	UPROPERTY()
	TWeakObjectPtr<AFortVolume> FortVolume;

	UPROPERTY()
	TObjectPtr<UReplicationGraphNode_GridSpatialization2D> FortVolumeGrid2D;

	UPROPERTY()
	TObjectPtr<UReplicationGraphNode_FortVolumeGlobalRelevancyNode> FortVolumeGlobalRelevancyNode;

};

