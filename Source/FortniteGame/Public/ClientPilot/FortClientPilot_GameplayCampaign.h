// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ClientPilot/FortClientPilot_GameplayBase.h"
#include "FortClientPilot_GameplayCampaign.generated.h"

class ABuildingActor;

UCLASS()
class UFortClientPilot_GameplayCampaign : public UFortClientPilot_GameplayBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<ABuildingActor> MissionTarget;

	UPROPERTY()
	TObjectPtr<ABuildingActor> PrimaryMissionTarget;

	UPROPERTY()
	TArray<TObjectPtr<ABuildingActor>> AllMissionTargets;

	UPROPERTY()
	TArray<TObjectPtr<ABuildingActor>> ActiveMissionTargets;

};

