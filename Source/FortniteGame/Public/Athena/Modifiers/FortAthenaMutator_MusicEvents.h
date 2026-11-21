// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "Athena/AthenaGamePhaseEnum.h"
#include "Athena/FortGameStateAthenaEnums.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_MusicEvents.generated.h"

class AFortPlayerStateAthena;
class UAudioComponent;
class USoundBase;

USTRUCT()
struct FFortMutatorMusicEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMutatorMusicEvent")
	TObjectPtr<USoundBase> Sound;

	UPROPERTY(EditAnywhere, Category="FortMutatorMusicEvent")
	float LoopTime;

	UPROPERTY(EditAnywhere, Category="FortMutatorMusicEvent")
	float FadeTime;

};

USTRUCT()
struct FFortMutatorGamePhaseMusicEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMutatorGamePhaseMusicEvent")
	EAthenaGamePhase Phase;

	UPROPERTY(EditAnywhere, Category="FortMutatorGamePhaseMusicEvent")
	FFortMutatorMusicEvent Event;

};

USTRUCT()
struct FFortMutatorGamePhaseStepMusicEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMutatorGamePhaseStepMusicEvent")
	EAthenaGamePhaseStep Step;

	UPROPERTY(EditAnywhere, Category="FortMutatorGamePhaseStepMusicEvent")
	FFortMutatorMusicEvent Event;

};

USTRUCT()
struct FFortMutatorMusicEventPlayInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Export, Category="FortMutatorMusicEventPlayInstance", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> AudioComponent;

	UPROPERTY(EditAnywhere, Category="FortMutatorMusicEventPlayInstance")
	FTimerHandle LoopTimerHandle;

};

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_MusicEvents : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleWaitingOnPlacement_Local(AFortPlayerStateAthena* Sender, int32 NewPlace);

	UFUNCTION()
	void HandleWaitingOnPlacement_Spectate();

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TArray<FFortMutatorGamePhaseMusicEvent> GamePhaseEvents;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TArray<FFortMutatorGamePhaseStepMusicEvent> GamePhaseStepEvents;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	FFortMutatorMusicEvent MatchEndWinEvent;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	FFortMutatorMusicEvent MatchEndLoseEvent;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	FFortMutatorMusicEvent MatchEndNeutralEvent;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	float CrossfadeTime;

};

