// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NavRelevantComponent.h"
#include "FortNavObstacleComponent.generated.h"

class UNavArea;

UCLASS()
class UFortNavObstacleComponent : public UNavRelevantComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SmartLink")
	TSubclassOf<UNavArea> ObstacleAreaClass;

};

