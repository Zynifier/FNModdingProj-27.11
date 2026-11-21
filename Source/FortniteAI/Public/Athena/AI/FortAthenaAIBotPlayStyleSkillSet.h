// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "Athena/AI/FortPlayerBotUtils.h"
#include "FortAthenaAIBotPlayStyleSkillSet.generated.h"

USTRUCT()
struct FPlaystyleSwitchToAggressiveData
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Behavior", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery TagQueryToMatch;

	UPROPERTY(EditDefaultsOnly, Category="Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat TurnToAggressiveMinimumDistance;

	UPROPERTY(EditDefaultsOnly, Category="Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat TurnToAggressiveTime;

	UPROPERTY(EditDefaultsOnly, Category="Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat SwitchBackToDefensivePreventionTime;

	UPROPERTY(EditDefaultsOnly, Category="Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat DamageThresholdToSwitchToAggressive;

};

USTRUCT()
struct FPlaystyleSwitchToAggressiveDataDigested
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FGameplayTagQuery TagQueryToMatch;

	UPROPERTY(Transient)
	float TurnToAggressiveMinimumDistanceSquared;

	UPROPERTY(Transient)
	float TurnToAggressiveTime;

	UPROPERTY(Transient)
	float DamageThresholdToSwitchToAggressive;

	UPROPERTY(Transient)
	float SwitchBackToDefensivePreventionTime;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotPlayStyleDigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	FScalableFloat AggressiveTowardsThreatWeight;

	UPROPERTY(Transient)
	FScalableFloat DefensiveTowardsThreatWeight;

	UPROPERTY(Transient)
	EDBNOPlayStyle DBNOPlayStyle;

	UPROPERTY(Transient)
	TArray<FPlaystyleSwitchToAggressiveDataDigested> ChangeToAggressiveData;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotPlayStyleSkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat AggressiveTowardsThreatWeight;

	UPROPERTY(EditDefaultsOnly, Category="Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat DefensiveTowardsThreatWeight;

	UPROPERTY(EditDefaultsOnly, Category="Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat PassiveDBNOPlayStyle;

	UPROPERTY(EditDefaultsOnly, Category="Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat ThirstyDBNOPlayStyle;

	UPROPERTY(EditDefaultsOnly, Category="Behavior", meta=(AllowPrivateAccess="true"))
	FScalableFloat PassiveOnHumansDBNOPlayStyle;

	UPROPERTY(EditDefaultsOnly, Category="Behavior", meta=(AllowPrivateAccess="true"))
	TArray<FPlaystyleSwitchToAggressiveData> ChangeToAggressiveData;

};

