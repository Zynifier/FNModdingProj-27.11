// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMatchmakingPublicConfig.generated.h"

USTRUCT(BlueprintType)
struct FFortMatchmakingPublicConfig
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 MaxPlayers;

	UPROPERTY()
	int32 MaxTeamCount;

	UPROPERTY()
	int32 MaxTeamSize;

	UPROPERTY()
	int32 MaxSocialPartySize;

	UPROPERTY()
	bool AllowJoinInProgress;

	UPROPERTY()
	bool AllowSquadFillOption;

};

