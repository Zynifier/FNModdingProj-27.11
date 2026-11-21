// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ClientPilot/FortClientPilot_FrontendBase.h"
#include "FortClientPilot_FrontendCampaign.generated.h"

UCLASS()
class UFortClientPilot_FrontendCampaign : public UFortClientPilot_FrontendBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bShouldPickRandomMap;

	UPROPERTY()
	int32 iSelectedTheater;

	UPROPERTY()
	TArray<int32> SelectedTheaterList;

	UPROPERTY()
	int32 iSelectedTile;

	UPROPERTY()
	TArray<int32> SelectedTileList;

	UPROPERTY()
	float RandomZoneDifficultyMinimum;

	UPROPERTY()
	float RandomZoneDifficultyMaximum;

};

