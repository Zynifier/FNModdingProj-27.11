// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/GameStateComponents/FortGameStateComponent_BattleRoyaleGamePhaseLogic.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_GameModeBase.generated.h"

class AFortPlayerStateAthena;
class AFortSquadStart;
class UAudioComponent;
class UFortAudioEventForwarder;
class USoundCue;

USTRUCT()
struct FFortMutatorAudioStinger
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMutatorAudioStinger")
	TObjectPtr<USoundCue> SoundCue;

	UPROPERTY(EditAnywhere, Category="FortMutatorAudioStinger")
	float LoopTimeBeforeFade;

	UPROPERTY(EditAnywhere, Category="FortMutatorAudioStinger")
	float FadeTime;

};

USTRUCT()
struct FFortSquadStartSearchParamData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortSquadStartSearchParamData")
	FGameplayTagContainer FilterTags;

	UPROPERTY(EditDefaultsOnly, Category="FortSquadStartSearchParamData")
	FScalableFloat DistanceMinimum;

	UPROPERTY(EditDefaultsOnly, Category="FortSquadStartSearchParamData")
	FScalableFloat DistanceMaximum;

	UPROPERTY(EditDefaultsOnly, Category="FortSquadStartSearchParamData")
	FScalableFloat bDistance2D;

	UPROPERTY(EditDefaultsOnly, Category="FortSquadStartSearchParamData")
	FScalableFloat bShuffle;

};

UCLASS(MinimalAPI, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_GameModeBase : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API virtual const FText& GetPOINameForTag(const FGameplayTag& POITag) const;

	UFUNCTION()
	FORTNITEGAME_API void HandleEndMatchStingerWaitingOnPlacement_Local(AFortPlayerStateAthena* Sender, int32 NewPlace);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnMutatorGameplayEvent(int32 EventId, int32 EventParam1, int32 EventParam2, int32 EventParam3);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContainerTags);

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_GameModeBase")
	bool bAutomaticallyFinishInitialization;

	UPROPERTY(EditDefaultsOnly, Category="Game Message")
	FAthenaGameMessageData GameMsg_AircraftPhaseIntroMessage;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	FFortMutatorAudioStinger Stinger_MatchStart;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	FFortMutatorAudioStinger Stinger_MatchEnd;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	FFortMutatorAudioStinger Stinger_MatchEndWin;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	FFortMutatorAudioStinger Stinger_MatchEndLose;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> StingerAudioComponent;

	UPROPERTY(Transient)
	TObjectPtr<UFortAudioEventForwarder> StingerEventForwarder;

private:
	UPROPERTY()
	TArray<TObjectPtr<AFortSquadStart>> FortSquadStartActors;

};

UCLASS()
class UFortAudioEventForwarder : public UObject
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleGamePhaseChanged(const FFortGamePhaseUpdatedEvent& Event);

};

