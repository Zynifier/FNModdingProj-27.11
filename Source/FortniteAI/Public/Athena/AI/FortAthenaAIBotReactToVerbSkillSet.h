// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "FortAthenaAIBotReactToVerbSkillSet.generated.h"

UCLASS(MinimalAPI)
class UFortAthenaAIBotReactToVerbDigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	float OverriddenReactionDistance;

	UPROPERTY(Transient)
	float OverriddenHighPriorityReactionDistance;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotReactToVerbSkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="ReactToVerb", meta=(AllowPrivateAccess="true", ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	FScalableFloat OverriddenReactionDistance;

	UPROPERTY(EditDefaultsOnly, Category="ReactToVerb", meta=(AllowPrivateAccess="true", ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	FScalableFloat OverriddenHighPriorityReactionDistance;

};

