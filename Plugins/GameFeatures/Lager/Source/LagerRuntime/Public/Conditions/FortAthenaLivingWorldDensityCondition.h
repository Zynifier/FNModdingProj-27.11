// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "WorldConditionBase.h"
#include "WorldConditionTypes.h"
#include "FortAthenaLivingWorldDensityCondition.generated.h"

USTRUCT(meta=(DisplayName="LWM Density"))
struct FFortAthenaLivingWorldDensityCondition : public FWorldConditionCommonActorBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldDensityCondition", meta=(BaseClass="/Script/Engine.Actor"))
	FWorldConditionContextDataRef ActorRef;

	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldDensityCondition", meta=(Categories="Athena.AI.Lager.TagDensity"))
	FGameplayTag Tag;

	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldDensityCondition")
	FScalableFloat Distance;

	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldDensityCondition")
	FScalableFloat MaxDensity;

	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldDensityCondition")
	FScalableFloat MinDensity;

};

