// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorldConditionBase.h"
#include "WorldConditionTypes.h"
#include "FortWorldConditionInSafeZone.generated.h"

USTRUCT(meta=(DisplayName="(Fortnite) Is in Safe Zone"))
struct FFortWorldConditionInSafeZone : public FWorldConditionCommonActorBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortWorldConditionInSafeZone", meta=(BaseClass="/Script/Engine.Actor"))
	FWorldConditionContextDataRef ActorRef;

};

