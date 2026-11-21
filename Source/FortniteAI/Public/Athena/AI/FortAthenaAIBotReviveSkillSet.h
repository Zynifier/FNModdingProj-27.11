// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "FortAthenaAIBotReviveSkillSet.generated.h"

UCLASS(MinimalAPI)
class UFortAthenaAIBotReviveDigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	float AllyEvaluationTime;

	UPROPERTY(Transient)
	float AllyEvaluationTimeDeviation;

	UPROPERTY(Transient)
	float CooldownOnCancel;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotReviveSkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Revive", meta=(ClampMin="0.0", UIMin="0.0"))
	FScalableFloat AllyEvaluationTime;

	UPROPERTY(EditDefaultsOnly, Category="Revive", meta=(ClampMin="0.0", UIMin="0.0"))
	FScalableFloat AllyEvaluationTimeDeviation;

	UPROPERTY(EditDefaultsOnly, Category="Revive", meta=(ClampMin="0.0", UIMin="0.0"))
	FScalableFloat CooldownOnCancel;

};

