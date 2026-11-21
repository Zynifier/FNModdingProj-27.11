// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AI/FortAthenaAIRuntimeParametersComponent.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent.h"
#include "FortAthenaAISpawnerDataComponent_PerceptionBase.generated.h"

UCLASS()
class UFortAthenaAIRuntimeParameters_Hearing : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	bool bOverrideHearingRange;

	UPROPERTY(Transient)
	FGameplayTagContainer OverrideHearingRangeConditionTag;

	UPROPERTY(Transient)
	float HearingRadius;

	UPROPERTY(Transient)
	bool bRestrictOverrideToUnaware;

};

UCLASS()
class UFortAthenaAIRuntimeParameters_Sight : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	bool bOverrideVisibilityRange;

	UPROPERTY(Transient)
	FGameplayTagContainer OverrideVisibilityRangeConditionTag;

	UPROPERTY(Transient)
	float SightRadius;

	UPROPERTY(Transient)
	float LoseSightRadius;

	UPROPERTY(Transient)
	bool bRestrictOverrideToUnaware;

};

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_PerceptionBase : public UFortAthenaAISpawnerDataComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetVisibilityRange(const float InSightRadius, const float LoseSightRadius, const bool bInRestrictOverrideToUnaware = true);

	UPROPERTY(EditDefaultsOnly, Category="Visibility", meta=(AllowPrivateAccess="true"))
	bool bOverrideVisibilityRange;

	UPROPERTY(EditDefaultsOnly, Category="Visibility", meta=(AllowPrivateAccess="true", EditCondition="bOverrideVisibilityRange"))
	FGameplayTagContainer OverrideVisibilityRangeConditionTag;

	UPROPERTY(EditDefaultsOnly, Category="Visibility", meta=(AllowPrivateAccess="true", EditCondition="bOverrideVisibilityRange"))
	float SightRadius;

	UPROPERTY(EditDefaultsOnly, Category="Visibility", meta=(AllowPrivateAccess="true", EditCondition="bOverrideVisibilityRange"))
	float LoseSightRadius;

	UPROPERTY(EditDefaultsOnly, Category="Visibility", meta=(AllowPrivateAccess="true", EditCondition="bOverrideVisibilityRange"))
	bool bRestrictSightOverrideToUnaware;

	UPROPERTY(EditDefaultsOnly, Category="Hearing", meta=(AllowPrivateAccess="true"))
	bool bOverrideHearingRange;

	UPROPERTY(EditDefaultsOnly, Category="Hearing", meta=(AllowPrivateAccess="true", EditCondition="bOverrideHearingRange"))
	FGameplayTagContainer OverrideHearingRangeConditionTag;

	UPROPERTY(EditDefaultsOnly, Category="Hearing", meta=(AllowPrivateAccess="true", EditCondition="bOverrideHearingRange"))
	float HearingRadius;

	UPROPERTY(EditDefaultsOnly, Category="Hearing", meta=(AllowPrivateAccess="true", EditCondition="bOverrideHearingRange"))
	bool bRestrictHearingOverrideToUnaware;

};

