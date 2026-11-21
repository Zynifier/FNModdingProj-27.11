// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_BallerRace.generated.h"

UCLASS(MinimalAPI, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_BallerRace : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnMutatorGameplayEvent(int32 EventId, int32 EventParam1, int32 EventParam2, int32 EventParam3);

	UFUNCTION()
	void OnRep_ServerWorldTimeToStartRace();

	UPROPERTY(ReplicatedUsing=OnRep_ServerWorldTimeToStartRace)
	float ServerWorldTimeToStartRace;

	UPROPERTY(EditDefaultsOnly, Category="Messages")
	FScalableFloat DelayBeforeRace;

	UPROPERTY(EditDefaultsOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_IntroMessage;

};

