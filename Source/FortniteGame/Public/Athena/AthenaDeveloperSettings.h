// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "FortItemAndCount.h"
#include "AthenaDeveloperSettings.generated.h"

class UAthenaSeasonItemDefinition;
class UFortGameplayModifierItemDefinition;
class UFortMissionGenerator;
class UFortPlaylistAthena;

UENUM(BlueprintType)
enum class EAthenaPIEStartupMode : uint8
{
	// Use a PIE start location instead of anything gamemode specific

	UseDefaults = 0,
	// Start in the warmup phase (bus depot) - this is the default mode for the actual game

	Warmup = 1,
	// Start in the warmup phase (bus depot), but paused (you can use the cheat UNPAUSEWARMUP to resume)

	WarmupPaused = 2,
	// Start in the aircraft phase

	Aircraft = 3,
	// Start in the aircraft phase, but paused (you can use the cheat UNPAUSEAIRCRAFT to resume)

	AircraftPaused = 4,
	// Start in the gameplay phase

	Gameplay = 5,
};

UCLASS(Config=EditorPerProjectUserSettings, MinimalAPI, meta=(DisplayName="Battle Royale Settings"))
class UAthenaDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="AthenaDeveloperSettings")
	TSoftClassPtr<UFortMissionGenerator> DefaultMissionGen;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="AthenaDeveloperSettings")
	TArray<FString> CheatsToRunOnPlayerPawnPossession;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="AthenaDeveloperSettings")
	TArray<FItemAndCount> InventoryItemsToGrant;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="BattleRoyale")
	TSoftObjectPtr<UFortPlaylistAthena> Playlist;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="BattleRoyale")
	TMap<FString, FString> PlaylistOptions;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale")
	TArray<FString> PlaylistConditionalFlags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale")
	bool bOverrideAthenaMaxPlayerCount;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale", meta=(ClampMax="101", ClampMin="1", EditCondition="bOverrideAthenaMaxPlayerCount"))
	int32 AthenaMaxPlayerCount;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale")
	bool bOverrideAthenaMaxTeamSize;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale", meta=(ClampMax="101", ClampMin="1", EditCondition="bOverrideAthenaMaxTeamSize"))
	int32 AthenaMaxTeamSize;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale")
	bool bOverrideAthenaTeamSpread;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale", meta=(ClampMax="101", ClampMin="1", EditCondition="bOverrideAthenaTeamSpread"))
	int32 AthenaTeamSpread;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale")
	bool bOverrideAthenaSquadSizes;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale", meta=(ClampMax="101", ClampMin="1", EditCondition="bOverrideAthenaSquadSizes"))
	int32 AthenaSquadSizes;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale")
	EAthenaPIEStartupMode AthenaStartupPhase;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale")
	bool bOverrideWarmupRequiredPlayerCount;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale", meta=(ClampMax="100", ClampMin="0", EditCondition="bOverrideWarmupRequiredPlayerCount", UIMax="100", UIMin="0"))
	int32 AthenaWarmupRequiredPlayerCount;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale")
	bool bOverrideWarmupEarlyRequiredPlayerPercent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale", meta=(ClampMax="1.000000", ClampMin="0.000000", EditCondition="bOverrideWarmupEarlyRequiredPlayerPercent", UIMax="1.000000", UIMin="0.000000"))
	float AthenaWarmupEarlyRequiredPlayerPercent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale")
	bool bOverrideWarmupCountdownDuration;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale", meta=(ClampMax="600.000000", ClampMin="0.100000", EditCondition="bOverrideWarmupCountdownDuration", UIMax="600.000000", UIMin="0.100000"))
	float AthenaWarmupCountdownDuration;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale")
	bool bOverrideWarmupEarlyCountdownDuration;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale", meta=(ClampMax="600.000000", ClampMin="0.100000", EditCondition="bOverrideWarmupEarlyCountdownDuration", UIMax="600.000000", UIMin="0.100000"))
	float AthenaWarmupEarlyCountdownDuration;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale")
	bool bAllowEndGamePhase;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale")
	bool bAllowAthenaRespawning;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale")
	bool bForceDBNO;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="AIs", meta=(DisplayName="Spawn Bots in Bots Playlist"))
	bool bBotsEnabled;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="AIs")
	bool bBotsCustomizationEnabled;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="AIs")
	int32 NumberOfBotsToSpawn;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="AIs")
	int32 BotsElo;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="AIs")
	bool bLivingWorldEnabled;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="AIs")
	bool bAIPreloadingEnabled;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="AIs")
	float OverrideAIBudgetManagerBudgetInMB;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Config, Category="BattleRoyale")
	TSet<int32> SpectatorControllerIndices;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="BattleRoyale")
	TArray<TObjectPtr<UFortGameplayModifierItemDefinition>> DeveloperGameplayModifiers;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Front End")
	TObjectPtr<UAthenaSeasonItemDefinition> FrontEndSeasonOverride;
#endif

};

