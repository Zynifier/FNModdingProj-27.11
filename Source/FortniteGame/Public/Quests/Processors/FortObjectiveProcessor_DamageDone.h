// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_DamageDone.generated.h"

USTRUCT(meta=(DisplayName="Damage Done"))
struct FFortObjectiveFilter_DamageDone : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageDone", meta=(InlineEditConditionToggle))
	uint8 bUseDistance : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageDone")
	uint8 bAllowSelfInflictedDamage : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageDone")
	uint8 bRequireCriticalHit : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageDone", meta=(DisplayPriority="-2", EditCondition="!bIncrementByUncappedDamage"))
	uint8 bIncrementByDamageAmount : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageDone", meta=(InlineEditConditionToggle))
	uint8 bUseDamageAmount : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageDone", meta=(DisplayPriority="-1", EditCondition="!bIncrementByDamageAmount"))
	uint8 bIncrementByUncappedDamage : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageDone", meta=(InlineEditConditionToggle))
	uint8 bUseUncappedDamage : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageDone", meta=(EditCondition="bUseDistance", ForceUnits="Meters", UIMin="0"))
	FDoubleRange Distance;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageDone")
	FObjectiveSubjectTags DamageSource;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageDone")
	FObjectiveSubjectTags_Progressible DamagedActor;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageDone")
	FObjectiveSubjectTags DamageType;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageDone", meta=(EditCondition="bUseDamageAmount", UIMin="0"))
	FInt32Range DamageAmount;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageDone", meta=(EditCondition="bUseUncappedDamage", UIMin="0"))
	FInt32Range UncappedDamageAmount;

};

UCLASS()
class UFortObjectiveProcessor_DamageDone : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

