// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_Fill.generated.h"

class AAthenaFillFloor;

UCLASS(MinimalAPI, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Fill : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	AAthenaFillFloor* GetLavaFloor() const;

	UFUNCTION(BlueprintPure)
	float GetLavaSupportLevel() const;

protected:
	UFUNCTION()
	void OnMutatorGameplayEvent(int32 EventId, int32 EventParam1, int32 EventParam2, int32 EventParam3);

	UFUNCTION()
	void OnPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContainerTags);

	UPROPERTY(EditAnywhere, Category="Lava Floor")
	TSubclassOf<AAthenaFillFloor> FloorActorClass;

	UPROPERTY(EditAnywhere, Category="Lava Floor")
	FScalableFloat SpawnHeight;

	UPROPERTY(EditAnywhere, Category="Lava Floor")
	FScalableFloat ZKillOffset;

	UPROPERTY(EditAnywhere, Category="Lava Floor")
	FScalableFloat ZMovementToleranceOffset;

	UPROPERTY(EditAnywhere, Category="Lava Floor")
	FScalableFloat BuildableOffset;

	UPROPERTY(EditAnywhere, Category="Lava Floor")
	FScalableFloat CanBuildOnLava;

	UPROPERTY(Replicated)
	TObjectPtr<AAthenaFillFloor> LavaFloor;

	UPROPERTY(EditDefaultsOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_LavaMoving;

};

