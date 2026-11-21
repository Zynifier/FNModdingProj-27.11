// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent.h"
#include "Athena/AI/FortPlayerBotUtils.h"
#include "FortAthenaAISpawnerDataComponent_ConstructionBase.generated.h"

USTRUCT(BlueprintType)
struct FConstructionBuildingList
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ConstructionBuildingList", meta=(ArraySizeEnum="/Script/FortniteAI.EConstructionBuildingType"))
	FConstructionBuildingInfo BuildingList[6];

};

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_ConstructionBase : public UFortAthenaAISpawnerDataComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	bool GetConstructionBuildingInfo(FConstructionBuildingList& OutConstructionInfoList) const;

};

