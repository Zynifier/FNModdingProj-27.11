// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_ConstructionBase.h"
#include "FortAthenaAISpawnerDataComponent_AIBotConstruction.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_AIBotConstruction : public UFortAthenaAISpawnerDataComponent_ConstructionBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Building Actor", meta=(AllowPrivateAccess="true"))
	FConstructionBuildingList ConstructionBuildingInfoList;

};

