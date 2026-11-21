// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_GainShields.generated.h"

UENUM(BlueprintType)
enum class EFortShieldGainIncrementType : uint8
{
	Single = 0,
	//amount of shields gained from this event

	ShieldGainAmount = 1,
	//amount of shield gain wasted (gain above full shields)

	ShieldGainedOverFull = 2,
	//percentage of shields that were gained in this event (0 - 100)

	ShieldGainPercent = 3,
	//combined shield gain and overhealing done during this event

	TotalShieldGained = 4,
};

USTRUCT(meta=(DisplayName="Gain Shields"))
struct FFortObjectiveFilter_GainShields : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_GainShields", meta=(DisplayPriority="-1"))
	EFortShieldGainIncrementType IncrementBy;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_GainShields")
	uint8 bRequireFullShields : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_GainShields")
	uint8 bRequireShieldGainedFromTeammate : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_GainShields")
	uint8 bRequireAuthorIsTheShieldGainSource : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_GainShields", meta=(InlineEditConditionToggle))
	uint8 bUseShieldAmountGained : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_GainShields", meta=(InlineEditConditionToggle))
	uint8 bUseOverFullShields : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_GainShields", meta=(InlineEditConditionToggle))
	uint8 bUseShieldGainedPercent : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_GainShields", meta=(InlineEditConditionToggle))
	uint8 bUseTotalShieldsGained : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_GainShields")
	FObjectiveSubjectTags_Progressible ShieldGainSource;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_GainShields")
	FObjectiveSubjectTags ShieldGainType;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_GainShields", meta=(EditCondition="bUseShieldAmountGained", UIMin="0"))
	FFloatRange AmountOfShieldsGained;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_GainShields", meta=(EditCondition="bUseOverFullShields", UIMin="0"))
	FFloatRange ShieldsGainedOverFullAmount;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_GainShields", meta=(EditCondition="bUseShieldGainedPercent", UIMin="0"))
	FFloatRange ShieldsPercentGained;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_GainShields", meta=(EditCondition="bUseTotalShieldsGained", UIMin="0"))
	FFloatRange TotalShieldGain;

};

UCLASS()
class UFortObjectiveProcessor_GainShields : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

