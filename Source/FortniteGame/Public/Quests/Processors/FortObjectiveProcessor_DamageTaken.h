// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_DamageTaken.generated.h"

USTRUCT(meta=(DisplayName="Damage Taken"))
struct FFortObjectiveFilter_DamageTaken : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageTaken", meta=(EditCondition="bUseDistance", ForceUnits="Meters", UIMin="0"))
	FDoubleRange Distance;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageTaken")
	FObjectiveSubjectTags DamageSource;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageTaken")
	FObjectiveSubjectTags DamageType;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageTaken", meta=(InlineEditConditionToggle))
	uint8 bUseDistance : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageTaken")
	uint8 bAllowSelfInflictedDamage : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageTaken", meta=(DisplayPriority="-1"))
	uint8 bIncrementByDamageAmount : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageTaken", meta=(InlineEditConditionToggle))
	uint8 bUseDamageAmount : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DamageTaken", meta=(EditCondition="bUseDamageAmount", UIMin="0"))
	FInt32Range DamageAmount;

};

UCLASS()
class UFortObjectiveProcessor_DamageTaken : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

