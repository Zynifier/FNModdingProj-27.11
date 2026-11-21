// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "FortAthenaAIBotDBNOSkillSet.generated.h"

UCLASS(MinimalAPI)
class UFortAthenaAIBotDBNODigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	float MaxDBNOCrawlingResponseTime;

	UPROPERTY(Transient)
	float MaxDBNOCrawlingResponseTimeDeviation;

	UPROPERTY(Transient)
	float AllyEvaluationTime;

	UPROPERTY(Transient)
	float AllyEvaluationTimeDeviation;

	UPROPERTY(Transient)
	float AllyEvaluationMaxDistance;

	UPROPERTY(Transient)
	float OddsToLookForCover;

	UPROPERTY(Transient)
	float CoverEvaluationTime;

	UPROPERTY(Transient)
	float CoverEvaluationTimeDeviation;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotDBNOSkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="DBNO", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxDBNOCrawlingResponseTime;

	UPROPERTY(EditDefaultsOnly, Category="DBNO", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxDBNOCrawlingResponseTimeDeviation;

	UPROPERTY(EditDefaultsOnly, Category="DBNO", meta=(AllowPrivateAccess="true"))
	FScalableFloat AllyEvaluationTime;

	UPROPERTY(EditDefaultsOnly, Category="DBNO", meta=(AllowPrivateAccess="true"))
	FScalableFloat AllyEvaluationTimeDeviation;

	UPROPERTY(EditDefaultsOnly, Category="DBNO", meta=(AllowPrivateAccess="true"))
	FScalableFloat AllyEvaluationMaxDistance;

	UPROPERTY(EditDefaultsOnly, Category="DBNO", meta=(AllowPrivateAccess="true"))
	FScalableFloat OddsToLookForCover;

	UPROPERTY(EditDefaultsOnly, Category="DBNO", meta=(AllowPrivateAccess="true"))
	FScalableFloat CoverEvaluationTime;

	UPROPERTY(EditDefaultsOnly, Category="DBNO", meta=(AllowPrivateAccess="true"))
	FScalableFloat CoverEvaluationTimeDeviation;

};

