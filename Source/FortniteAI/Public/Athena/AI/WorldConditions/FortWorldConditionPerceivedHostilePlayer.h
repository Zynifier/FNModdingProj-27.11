// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorldConditionBase.h"
#include "WorldConditionTypes.h"
#include "FortWorldConditionPerceivedHostilePlayer.generated.h"

USTRUCT(meta=(DisplayName="Perceive hostile player"))
struct FFortWorldConditionPerceivedHostilePlayer : public FWorldConditionCommonActorBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortWorldConditionPerceivedHostilePlayer", meta=(BaseClass="/Script/Engine.Actor"))
	FWorldConditionContextDataRef ActorRef;

};

