// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_TimedRespawnHelper.generated.h"

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_TimedRespawnHelper : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void OnMutatorGameplayEvent(int32 EventId, int32 EventParam1, int32 EventParam2, int32 EventParam3);

	UFUNCTION()
	void OnRep_ServerTimeRespawnIsDisallowed();

	UPROPERTY(EditDefaultsOnly, Category="Game Message")
	FAthenaGameMessageData GameMsg_NoMoreRespawn;

	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_TimedRespawnHelper")
	FScalableFloat RespawnAllowedTime;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_TimedRespawnHelper")
	FFortRespawnLogicData RespawnLogicData;

	UPROPERTY(ReplicatedUsing=OnRep_ServerTimeRespawnIsDisallowed)
	float ServerTimeRespawnIsDisallowed;

};

