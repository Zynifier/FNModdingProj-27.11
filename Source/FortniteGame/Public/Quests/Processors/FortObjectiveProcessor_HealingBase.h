// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "FortObjectiveProcessor_HealingBase.generated.h"

UENUM(BlueprintType)
enum class EFortHealingIncrementType : uint8
{
	Single = 0,
	//amount of health gained from this event

	HealingAmount = 1,
	//amount of healing wasted (healed above full health)

	HealthOverHealing = 2,
	//percentage of health that was healed in this event (0 - 100)

	PercentHealed = 3,
	//combined healing and overhealing done durign this event

	TotalHealingDone = 4,
};

UENUM(BlueprintType)
enum class EFortSelfHealingHandling : uint8
{
	// Self healing is allowed, but not required

	Allowed = 0,
	// Self healing is required

	Required = 1,
	// self healing is not allowed

	Prohibited = 2,
};

USTRUCT(meta=(Hidden))
struct FFortObjectiveFilter_HealingBase : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_HealingBase")
	FObjectiveSubjectTags HealingType;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_HealingBase", meta=(DisplayPriority="-1"))
	EFortHealingIncrementType IncrementBy;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_HealingBase")
	uint8 bRequireHealedToFull : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_HealingBase", meta=(InlineEditConditionToggle))
	uint8 bUseHealingAmount : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_HealingBase", meta=(InlineEditConditionToggle))
	uint8 bUseOverHealing : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_HealingBase", meta=(InlineEditConditionToggle))
	uint8 bUsePercentHealed : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_HealingBase")
	EFortSelfHealingHandling SelfHealingBehavior;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_HealingBase", meta=(EditCondition="bUseHealingAmount", UIMin="0"))
	FFloatRange HealingAmount;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_HealingBase", meta=(EditCondition="bUseOverHealing", UIMin="0"))
	FFloatRange HealthOverHealed;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_HealingBase", meta=(EditCondition="bUsePercentHealed", UIMin="0"))
	FFloatRange PercentHealed;

};

