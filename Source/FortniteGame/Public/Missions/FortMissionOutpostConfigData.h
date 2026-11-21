// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Missions/FortMissionConfigData.h"
#include "FortMissionOutpostConfigData.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortMissionOutpostConfigData : public UFortMissionConfigData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DefenseData")
	FDataTableRowHandle DifficultyData;

};

