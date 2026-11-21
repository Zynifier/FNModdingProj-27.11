// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_TeamPlacement.generated.h"

class AFortTeamInfoAthena;

USTRUCT()
struct FTeamPlacementData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 TeamId;

	UPROPERTY()
	int32 TeamPlacement;

	UPROPERTY()
	int32 TeamScore;

	UPROPERTY(NotReplicated)
	TObjectPtr<AFortTeamInfoAthena> TeamInfoAthena;

};

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_TeamPlacement : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void OnRep_TeamsInfo();

	UPROPERTY(ReplicatedUsing=OnRep_TeamsInfo)
	TArray<FTeamPlacementData> TeamsInfo;

};

