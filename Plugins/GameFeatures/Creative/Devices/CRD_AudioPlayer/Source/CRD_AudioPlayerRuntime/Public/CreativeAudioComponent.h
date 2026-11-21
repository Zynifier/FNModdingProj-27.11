// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/Attenuation.h"
#include "GameFramework/OnlineReplStructs.h"
#include "UObject/SoftObjectPath.h"
#include "CreativeAudioComponent.generated.h"

class AController;
class ACreativeAudioPlayerReplicationProxy;
class ACreativePlayerReplicationProxy;
class AFortMinigame;
class AFortPlayerState;
class APawn;
class UAudioComponent;
class UCreativeProxyManagerComponent;
class UCreativeRegisteredPlayersManagerComponent;
class UFortMinigameProgressComponent;
class USoundBase;
enum class EFortMinigameState : uint8;

UENUM(BlueprintType, meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class EAutoplayOptions : uint8
{
	None = 0 UMETA(Hidden),
	/** Will play automatically while Creating. */
	Create = 1,
	/** Will play automatically during the pregame lobby. */
	WaitingForPlayer = 2,
	/** Will play automatically during the Game Countdown */
	Countdown = 4,
	/** Will play automatically while the game is in progress. */
	Gameplay = 8,
	/** Will play automatically at the end of each round. */
	RoundEnd = 16,
	/** Will play automatically at the end of each game. */
	GameEnd = 32,
};

UENUM(BlueprintType, meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class ECreativeAudioPlayerTargetListener : uint8
{
	None = 0 UMETA(Hidden),
	Instigator = 1,
	RegisteredPlayers = 2,
	NonRegisteredPlayers = 4,
	Everyone = 6 UMETA(Hidden),
};

UENUM(BlueprintType, meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class ECreativeAudioPlayerTargetLocation : uint8
{
	None = 0 UMETA(Hidden),
	Device = 1,
	LocalPlayer = 2,
	RegisteredPlayers = 4,
	InstigatingPlayer = 8,
	All = 15 UMETA(Hidden),
};

USTRUCT()
struct FCreativeAudioPlayerData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl NetId;

	UPROPERTY()
	TObjectPtr<APawn> Pawn;

	UPROPERTY()
	float ServerAudioStartTime;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAudioLoaded, const FCreativeAudioPlayerData&, InstigatorData);

UCLASS(Config=Creative, MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Minigame"), meta=(BlueprintSpawnableComponent))
class UCreativeAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="CreativeAudio")
	void OnEnabledStateChanged(bool bIsEnabled);

	UFUNCTION(BlueprintCallable, Category="CreativeAudio")
	void PlayAudio(AController* Player);

	UFUNCTION(BlueprintCallable, Category="CreativeAudio")
	void ResetDevice();

	UFUNCTION(BlueprintCallable, Category="CreativeAudio")
	void SetProperties(const TSoftObjectPtr<USoundBase>& Audio, const float Volume, const float PlaybackSpeed, const float NewFadeInDuration, const float NewFadeOutDuration, const bool bEnableVolumeAttenuation, const bool bEnableSpatialization, const float StereoSpread, const EAttenuationDistanceModel DistanceModel, const float AttenuationMinDistance, const float AttenuationFalloffDistance, const bool bNewSyncPlayerAudio, const bool bNewRestartAudioOnPlay, const int32 NewCanBeHeardBy, const int32 NewPlayLocation, const int32 NewAutoplayOptions);

	UFUNCTION(BlueprintCallable, Category="CreativeAudio")
	void StopAudio(AController* Player);

	UPROPERTY(EditAnywhere, Category="CreativeAudio")
	float StereoSpreadScaleFactor;

private:
	UFUNCTION()
	void OnAllPlayersUnregistered();

	UFUNCTION()
	void OnAudioLoadComplete(FSoftObjectPath Audio);

	UFUNCTION()
	void OnMinigameEnded();

	UFUNCTION()
	void OnMinigameStarted();

	UFUNCTION()
	void OnMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState NewMinigameState);

	UFUNCTION()
	void OnPlayerAdded(FUniqueNetIdRepl NetId, bool bIsLocalPlayer);

	UFUNCTION()
	void OnPlayerRegistered(const AFortPlayerState* PlayerState);

	UFUNCTION()
	void OnPlayerRemoved(FUniqueNetIdRepl NetId, bool bIsLocalPlayer);

	UFUNCTION()
	void OnPlayerUnregistered(const AFortPlayerState* PlayerState);

	UFUNCTION()
	void OnProxyDataChanged(ACreativePlayerReplicationProxy* ProxyData);

	UFUNCTION()
	void OnRep_RegisteredPlayerIds();

	UFUNCTION()
	void OnRep_ServerInstigatorData();

	UFUNCTION()
	void RetryClientPlayAudio(const FCreativeAudioPlayerData& InstigatorData);

	UFUNCTION()
	void RetryUpdateAutoplayStatusOnMinigameAdd(AFortMinigame* Minigame);

	UPROPERTY(Transient)
	float FadeInDuration;

	UPROPERTY(Transient)
	float FadeOutDuration;

	UPROPERTY(Transient)
	bool bSyncPlayerAudio;

	UPROPERTY(Transient)
	bool bRestartAudioOnPlay;

	UPROPERTY(Transient)
	ECreativeAudioPlayerTargetListener CanBeHeardBy;

	UPROPERTY(Transient)
	ECreativeAudioPlayerTargetLocation PlayLocation;

	UPROPERTY(Transient)
	EAutoplayOptions AutoplayOptions;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortMinigameProgressComponent> FortMinigameProgressComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCreativeProxyManagerComponent> CreativeProxyManager;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCreativeRegisteredPlayersManagerComponent> CreativeRegisteredPlayersManagerComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> AudioComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<FUniqueNetIdRepl, TObjectPtr<UAudioComponent>> PlayerAudioComponents;

	UPROPERTY(Transient)
	TObjectPtr<ACreativeAudioPlayerReplicationProxy> ClientCachedProxy;

	UPROPERTY(Transient)
	TObjectPtr<USoundBase> LastSoundPlayed;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerInstigatorData)
	FCreativeAudioPlayerData ServerInstigatorData;

	UPROPERTY(Transient)
	bool bEnabled;

	UPROPERTY(Transient)
	bool bAudioLoaded;

	UPROPERTY(Transient)
	FCreativeAudioPlayerData CachedInstigatorData;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_RegisteredPlayerIds)
	TArray<FUniqueNetIdRepl> RegisteredPlayerIds;

	UPROPERTY(Transient)
	TArray<FUniqueNetIdRepl> NonRegisteredPlayerIds;

	UPROPERTY(Transient)
	EAutoplayOptions CurrentAutoplayState;

};

