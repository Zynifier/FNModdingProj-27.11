// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortCollectionsTasks.generated.h"

UCLASS(Config=Game)
class UFortCollectionsTaskManager : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	float DefaultTimeoutSeconds;

	UPROPERTY(Config)
	float StatsRequestThrottleSeconds;

};

