// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HarmonixMidi/MidiSongPos.h"
#include "FabricTimelineSyncComponent.generated.h"

class UFabricMetaSoundManagerComponent;
class UMusicClockComponent;
enum class EMusicClockState : uint8;

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Harmonix"), meta=(BlueprintSpawnableComponent))
class FABRICRUNTIME_API UFabricTimelineSyncComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_ServerCurrentSongPos();

	UFUNCTION()
	void OnTimelinePlayingChanged(EMusicClockState State);

	UFUNCTION(BlueprintCallable)
	void SetFabricMetaSoundManager(UFabricMetaSoundManagerComponent* MusicManagerComponent);

protected:
	UPROPERTY(EditDefaultsOnly, Category="Timeline Net Sync|Config")
	float ThresholdForSeekMS;

	UPROPERTY(EditDefaultsOnly, Category="Timeline Net Sync|Config")
	float ThresholdForStartSpeedAdjustMS;

	UPROPERTY(EditDefaultsOnly, Category="Timeline Net Sync|Config")
	float ThresholdForEndOfSpeedAdjustMS;

	UPROPERTY(EditDefaultsOnly, Category="Timeline Net Sync|Config")
	float SpeedAdjustFactor;

	UPROPERTY(EditDefaultsOnly, Category="Timeline Net Sync|Debug")
	bool bPrintToScreen;

	UPROPERTY(EditDefaultsOnly, Category="Timeline Net Sync|Config")
	float SpeedSyncTimeoutLength;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	UFabricMetaSoundManagerComponent* MetaSoundManager;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	UMusicClockComponent* MusicClock;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerCurrentSongPos)
	FMidiSongPos ServerCurrentSongRenderPos;

};

