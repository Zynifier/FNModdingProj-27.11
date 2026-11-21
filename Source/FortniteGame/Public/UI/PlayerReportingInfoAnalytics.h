// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerReportingInfoAnalytics.generated.h"

USTRUCT()
struct FCachedPlayerReportingMatchInfoAnalytics
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString GameSessionId;

	UPROPERTY()
	FName PlaylistName;

	UPROPERTY()
	FString TournamentId;

	UPROPERTY()
	FString EventWindowId;

};

