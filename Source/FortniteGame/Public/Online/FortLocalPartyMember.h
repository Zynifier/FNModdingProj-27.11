// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Online/FortPartyMember.h"
#include "FortLocalPartyMember.generated.h"

UCLASS(Config=Game, MinimalAPI)
class UFortLocalPartyMember : public UFortPartyMember
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleMcpProfilesInitialized();

	UFUNCTION()
	void HandleNumAthenaPlayersLeftChanged(int32 NumPlayersLeft);

	UFUNCTION()
	void HandlePlayerControllerSet();

	UPROPERTY(Config)
	uint8 NumAthenaPlayersLeftDeltaThreshold;

	UPROPERTY(Config)
	float AthenaPlayersLeftUpdateDelay;

};

