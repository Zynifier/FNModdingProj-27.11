// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_Repair.generated.h"

UENUM(BlueprintType)
enum class EFortRepairIncrementType : uint8
{
	// Increment by 1

	Single = 0,
	// Increment By amount of Repairing Done

	RepairAmount = 1,
	// Increment by percentage of repairing that was done in this event (0 - 100) 

	PercentRepaired = 2,
};

USTRUCT(meta=(DisplayName="Repair"))
struct FFortObjectiveFilter_Repair : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Repair")
	FObjectiveSubjectTags RepairType;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Repair")
	FObjectiveSubjectTags ActorRepaired;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Repair", meta=(DisplayPriority="-1"))
	EFortRepairIncrementType IncrementBy;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Repair")
	uint8 bFullyRepaired : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Repair", meta=(InlineEditConditionToggle))
	uint8 bUseAmountRepaired : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Repair", meta=(InlineEditConditionToggle))
	uint8 bUsePercentRepaired : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Repair", meta=(EditCondition="bUseAmountRepaired", UIMin="0"))
	FFloatRange AmountRepaired;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Repair", meta=(EditCondition="bUsePercentRepaired", UIMax="100", UIMin="0"))
	FFloatRange PercentRepaired;

};

UCLASS()
class UFortObjectiveProcessor_Repair : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

