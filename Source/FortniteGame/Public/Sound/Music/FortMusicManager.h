// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/NoExportTypes.h"
#include "FortCombatTypes.h"
#include "FortInitializationInterface.h"
#include "FortMusicManager.generated.h"

class AFortPlayerController;
class UAudioComponent;
class UFortMusicAsset;
class UFortMusicManagerBank;
class UFortMusicVoice;
enum class EFortDayPhase : uint8;

UENUM()
namespace EMusicChannel
{
	enum Type
	{
		VoiceA = 0,
		VoiceB = 1,
		Max_None = 2 UMETA(DisplayName="None"),
	};
}

UENUM(BlueprintType)
namespace EMusicFadeStyles
{
	enum Type
	{
		CrossFade = 0,
		FadeOutThenIn = 1,
		Max_None = 2 UMETA(DisplayName="None"),
	};
}

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMusicVoiceEvent, UFortMusicVoice*, Voice);

USTRUCT()
struct FQueuedMusic
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object", "Actor", "Advanced", "Navigation"))
class AFortMusicManager : public AActor, public IFortInitializationInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Music")
	UFortMusicVoice* ChangePrimaryMusic(UFortMusicAsset* NewMusicAsset, bool bPlayStinger);

	UFUNCTION(BlueprintPure, Category="Music")
	virtual float GetEventHeatPercent(EFortCombatEvents::Type CombatEvent);

	UFUNCTION(BlueprintPure, Category="Music")
	virtual float GetEventHeatPercentTotal(EFortCombatEvents::Type CombatEvent);

	UFUNCTION(BlueprintPure, Category="Music")
	const UFortMusicManagerBank* GetMusicBank() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnAudioComponentPlayed(UAudioComponent* Component);

	UFUNCTION(BlueprintImplementableEvent)
	void OnAudioComponentStopped(UAudioComponent* Component);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDayPhaseChanged(EFortDayPhase CurrentDayPhase, EFortDayPhase PreviousDayPhase, bool bAtCreation);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMusicBankChanged(UFortMusicManagerBank* NewBank);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerDowned(const FFortPlayerDeathReport& DeathReport);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerSpawned();

	UFUNCTION(BlueprintImplementableEvent)
	void OnThresholdChange(EFortCombatThresholds::Type OldThreshold, EFortCombatThresholds::Type NewThreshold);

	UFUNCTION(BlueprintCallable, Category="Music")
	UFortMusicVoice* PlayMusicVoice(UFortMusicAsset* Asset);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Music")
	void PlayStinger(UFortMusicAsset* NewMusicAsset);

	UFUNCTION(BlueprintCallable, Category="Music")
	void SetMusicBank(UFortMusicManagerBank* Bank);

	UFUNCTION(BlueprintCallable, Category="Music")
	void StopMusicVoice(UFortMusicVoice* Voice);

	UFUNCTION(BlueprintCallable, Category="Music")
	void StopPrimaryMusic(bool bPlayOutro = true);

	UPROPERTY(BlueprintReadOnly, Category="Music")
	TObjectPtr<AFortPlayerController> ControllerOwner;

protected:
	UFUNCTION(BlueprintPure, Category="Music")
	float GetPrimaryMusicVolume() const;

	UFUNCTION(BlueprintCallable, Category="Music")
	void SetPrimaryMusicVolume(float InVolumeMultiplier);

	UPROPERTY(Transient)
	uint8 bWorldReadyCalled : 1;

	UPROPERTY(EditDefaultsOnly, Category="Assets")
	TObjectPtr<UFortMusicManagerBank> MusicBank;

private:
	UFUNCTION()
	void OnVoiceFinished(UFortMusicVoice* Voice);

	UPROPERTY(Transient, Instanced, meta=(ArraySizeEnum="/Script/FortniteGame.EMusicChannel"))
	TObjectPtr<UFortMusicVoice> Voices[2];

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortMusicVoice>> VoicesToCleanUp;

};

UCLASS(BlueprintType)
class UFortMusicVoice : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnMusicVoiceEvent OnVoiceStarted;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnMusicVoiceEvent OnVoiceFinished;

};

