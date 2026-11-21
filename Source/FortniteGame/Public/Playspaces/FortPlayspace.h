// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "Athena/FortMutatorContext.h"
#include "Building/FortSpatialGameplayInterface.h"
#include "GameplayEventRouterOwnerInterface.h"
#include "Playspace.h"
#include "FortPlayspace.generated.h"

class AFortPlayspace;
class AFortPlayspaceReplicatedState;
class UGameplayEventRouterComponent;
enum class EMeshNetworkNodeType : uint8;

UENUM(BlueprintType)
enum class EFortPlayspaceMatchmakingRules : uint8
{
	/** All Playlists will accept users to this Playspace unless the current Playlist is in the ExcludedPlaylists list */
	AllPlaylists = 0,
	/** The only Playlists that will accept users to this Playspace are those listed in the "SpecificPlaylists" list */
	SpecificPlaylists = 1,
};

UENUM(BlueprintType)
enum class EFortPlayspaceUserAcceptanceType : uint8
{
	/** Built-in logic from source code or script */
	CustomLogic = 0,
	/** Matchmaking service */
	Matchmaking = 1,
	/** Character entering a GameplayVolume */
	VolumeBased = 2,
};

USTRUCT(BlueprintType)
struct FFortPlayspaceInitializedEventPayload
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortPlayspaceInitializedEventPayload")
	TObjectPtr<AFortPlayspace> EventOwner;

};

USTRUCT(BlueprintType)
struct FFortPlayspaceMatchmakingSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortPlayspaceMatchmakingSettings")
	EFortPlayspaceMatchmakingRules MatchmakingRule;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayspaceMatchmakingSettings", meta=(EditCondition="MatchmakingRule == EFortPlayspaceMatchmakingRules::SpecificPlaylists"))
	TArray<FName> SpecificPlaylists;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayspaceMatchmakingSettings", meta=(EditCondition="MatchmakingRule == EFortPlayspaceMatchmakingRules::AllPlaylists"))
	TArray<FName> ExcludedPlaylists;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortPlayspace : public APlayspace, public IFortMutatorOwner, public IFortSpatialGameplayInterface, public IGameplayEventRouterOwnerInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void Blueprint_HandleMatchStarted();

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API AFortPlayspaceReplicatedState* GetReplicatedState();

	UFUNCTION()
	FORTNITEGAME_API virtual void HandleMatchStarted();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnMeshNetworkEventBurst(const FName& EventName, const EMeshNetworkNodeType NodeType, const FString& EventParameters);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnMeshNetworkEventChange(const FName& EventName, const FDateTime& EventStartTime, const EMeshNetworkNodeType NodeType, const FString& EventParameters);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnMeshNetworkEventEnd(const FName& EventName, const EMeshNetworkNodeType NodeType);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnMeshNetworkEventStart(const FName& EventName, const FDateTime& EventStartTime, const EMeshNetworkNodeType NodeType, const FString& EventParameters);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnMeshNetworkReady(EMeshNetworkNodeType NodeType);

	UFUNCTION()
	FORTNITEGAME_API void OnRep_ShouldCreateEventRouter();

	UFUNCTION()
	FORTNITEGAME_API virtual void PostHandleMatchStarted();

	UPROPERTY(EditDefaultsOnly, Category="FortPlayspace")
	bool bSubscribeToMeshNetwork;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayspace")
	EFortPlayspaceUserAcceptanceType UserAcceptanceType;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayspace", meta=(EditCondition="UserAcceptanceType == EFortPlayspaceUserAcceptanceType::Matchmaking"))
	FFortPlayspaceMatchmakingSettings MatchmakingSettings;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayspace")
	TSubclassOf<AFortPlayspaceReplicatedState> ReplicatedStateClass;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<AFortPlayspaceReplicatedState> ReplicatedState;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UGameplayEventRouterComponent> EventRouter;

	UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_ShouldCreateEventRouter, Category="Gameplay Event Router")
	bool bShouldCreateEventRouter;

private:
	UFUNCTION()
	FORTNITEGAME_API void HandleMatchStarted_Internal();

};

