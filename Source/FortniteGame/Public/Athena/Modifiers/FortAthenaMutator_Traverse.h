// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Athena/Modifiers/FortAthenaMutator_GameModeBase.h"
#include "FortAthenaMutator_Traverse.generated.h"

class AActor;
class AAthenaTraversePoint;

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Traverse : public AFortAthenaMutator_GameModeBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_CurrentPointIndex();

	UPROPERTY(Replicated)
	TArray<TObjectPtr<AAthenaTraversePoint>> TraversePoints;

	UPROPERTY(ReplicatedUsing=OnRep_CurrentPointIndex)
	int32 CurrentPointIndex;

	UPROPERTY(EditAnywhere, Category="Tweakables")
	FScalableFloat RaceStartIndex;

	UPROPERTY(EditDefaultsOnly, Category="Tweakables")
	FScalableFloat NumOfCheckpoints;

	UPROPERTY(EditDefaultsOnly, Category="Tweakables")
	FScalableFloat TraversePointSpawnZ;

	UPROPERTY(EditAnywhere, Category="Tweakables")
	FScalableFloat InitialRadius;

	UPROPERTY(EditAnywhere, Category="Tweakables")
	FScalableFloat RespawnRadius;

	UPROPERTY(EditAnywhere, Category="Tweakables")
	FScalableFloat DelayBeforeFirstReveal;

	UPROPERTY(EditAnywhere, Category="Tweakables")
	FScalableFloat MinDistanceAwayFromOtherPoints;

	UPROPERTY(EditAnywhere, Category="Tweakables")
	FFortRespawnLogicData RespawnData;

	UPROPERTY(EditDefaultsOnly, Category="Classes")
	TSubclassOf<AAthenaTraversePoint> TraversePointClass;

	UPROPERTY(EditDefaultsOnly, Category="Classes")
	TSubclassOf<AActor> BoundsXYSplineClass;

};

