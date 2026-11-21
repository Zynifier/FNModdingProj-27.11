// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "AI/Perks/FortAIPerkBase.h"
#include "Athena/AI/FortAthenaAIBotEvasiveManeuversSkillSet.h"
#include "FortAthenaAIPerk_EvasiveManeuvers.generated.h"

USTRUCT()
struct FFortAIRuntimePerkInfo_EvasiveManeuvers : public FFortAIRuntimePerkInfo
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	float DistanceMinSquared;

	UPROPERTY(Transient)
	float DistanceMaxSquared;

};

UCLASS(MinimalAPI)
class UFortAthenaAIPerk_EvasiveManeuvers : public UFortAIPerkBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIPerk_EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FEvasiveManeuverSkillSettings EvasiveManeuverSkillSettings;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIPerk_EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat DistanceMin;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIPerk_EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FScalableFloat DistanceMax;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIPerk_EvasiveManeuvers", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery WeaponTagQuery;

};

