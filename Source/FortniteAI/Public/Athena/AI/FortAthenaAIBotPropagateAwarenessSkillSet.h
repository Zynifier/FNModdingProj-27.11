// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "FortAthenaAIBotPropagateAwarenessSkillSet.generated.h"

UCLASS(MinimalAPI)
class UFortAthenaAIBotPropagateAwarenessDigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	float PropagationMaxDistanceSQ;

	UPROPERTY(Transient)
	float CosineFOV;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotPropagateAwarenessSkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Propagation", meta=(AllowPrivateAccess="true"))
	FScalableFloat PropagationMaxDistance;

	UPROPERTY(EditDefaultsOnly, Category="Propagation", meta=(AllowPrivateAccess="true", ClampMax="180", ClampMin="0", UIMax="180", UIMin="0"))
	FScalableFloat FOV;

};

