// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "FortAthenaAIBotHarvestSkillSet.generated.h"

UCLASS()
class UFortAthenaAIBotHarvestDigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	float DelayBetweenHarvest;

	UPROPERTY(Transient)
	float DeviationTimeBetweenHarvest;

	UPROPERTY(Transient)
	float HarvestingMaxDistanceSquared;

	UPROPERTY(Transient)
	float WeakSpotHitProbability;

};

UCLASS()
class UFortAthenaAIBotHarvestSkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Harvest", meta=(AllowPrivateAccess="true", ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	FScalableFloat DelayBetweenHarvest;

	UPROPERTY(EditDefaultsOnly, Category="Harvest", meta=(AllowPrivateAccess="true", ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	FScalableFloat DeviationTimeBetweenHarvest;

	UPROPERTY(EditDefaultsOnly, Category="Harvest", meta=(AllowPrivateAccess="true", ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	FScalableFloat HarvestingMaxDistance;

	UPROPERTY(EditDefaultsOnly, Category="Harvest", meta=(AllowPrivateAccess="true", ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	FScalableFloat WeakSpotHitProbability;

};

