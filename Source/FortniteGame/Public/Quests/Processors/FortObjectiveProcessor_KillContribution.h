// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_KillContribution.generated.h"

UENUM()
enum class EFinalBlowAllowance : int32
{
	WhenPassingFilter = 0,
	Always = 1,
	Never = 2,
};

USTRUCT(meta=(DisplayName="Kill Contribution"))
struct FFortObjectiveFilter_KillContribution : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_KillContribution", meta=(DisplayAfter="Author"))
	FObjectiveSubjectTags_Progressible KilledActor;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_KillContribution", meta=(DisplayAfter="KilledActor"))
	FObjectiveSubjectTags KillerTags;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_KillContribution", meta=(DisplayAfter="KillerTags"))
	EFinalBlowAllowance FinalBlowGivesCredit;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_KillContribution", meta=(InlineEditConditionToggle))
	uint8 bUseDamageContributed : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_KillContribution", meta=(InlineEditConditionToggle))
	uint8 bUseDamageContributedPercent : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_KillContribution", meta=(InlineEditConditionToggle))
	uint8 bUseDistanceFromEliminatedPawn : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_KillContribution", meta=(EditCondition="bUseDamageContributed"))
	FInt32Range DamageContributed;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_KillContribution", meta=(ClampMax="100", ClampMin="0", EditCondition="bUseDamageContributedPercent"))
	FInt32Range PercentageOfDamageContributed;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_KillContribution", meta=(EditCondition="bUseDistanceFromEliminatedPawn", ForceUnits="Meters"))
	FDoubleRange DistanceFromEliminatedPawn;

};

UCLASS()
class UFortObjectiveProcessor_KillContribution : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

