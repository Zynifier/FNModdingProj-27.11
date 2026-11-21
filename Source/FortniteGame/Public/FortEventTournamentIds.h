// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortEventTournamentIds.generated.h"

USTRUCT()
struct FEventTournamentIds
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString EventId;

	UPROPERTY()
	FString WindowId;

	UPROPERTY()
	FString GroupId;

	UPROPERTY()
	FString SubGroupId;

};

