// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "WorldConditionBase.h"
#include "WorldConditionTypes.h"
#include "FortAthenaLivingWorldCondition_TrackedPlayerPresence.generated.h"

USTRUCT(meta=(DisplayName="LW Tracked Players presence"))
struct FFortAthenaLivingWorldCondition_TrackedPlayerPresence : public FWorldConditionCommonActorBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldCondition_TrackedPlayerPresence", meta=(BaseClass="/Script/Engine.Actor"))
	FWorldConditionContextDataRef ActorRef;

	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldCondition_TrackedPlayerPresence")
	FScalableFloat MinDistanceToPlayer;

	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldCondition_TrackedPlayerPresence")
	FScalableFloat MaxDistanceToPlayer;

};

