// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BuildingClassData.generated.h"

class ABuildingActor;

USTRUCT()
struct FBuildingClassData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TSubclassOf<ABuildingActor> BuildingClass;

	UPROPERTY(Transient)
	int32 PreviousBuildingLevel;

	UPROPERTY(Transient)
	uint8 UpgradeLevel;

};

