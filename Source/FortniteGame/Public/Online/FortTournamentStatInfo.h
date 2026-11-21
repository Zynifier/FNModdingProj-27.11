// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTournamentStatInfo.generated.h"

USTRUCT()
struct FFortTournamentStatInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString StatName;

	UPROPERTY()
	FName StatDisplayName;

	UPROPERTY()
	bool bIsDeltaCount;

	UPROPERTY()
	int32 StatValue;

};

