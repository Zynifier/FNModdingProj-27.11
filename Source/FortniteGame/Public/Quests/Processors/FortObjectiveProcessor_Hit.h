// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_Hit.generated.h"

USTRUCT(meta=(DisplayName="Hit"))
struct FFortObjectiveFilter_Hit : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Hit", meta=(InlineEditConditionToggle))
	uint8 bUseDistance : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Hit")
	uint8 bAllowSelfInflictedDamage : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Hit")
	uint8 bRequireCriticalHit : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Hit", meta=(EditCondition="bUseDistance", ForceUnits="Meters", UIMin="0"))
	FDoubleRange Distance;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Hit")
	FObjectiveSubjectTags DamageSource;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Hit")
	FObjectiveSubjectTags_Progressible DamagedActor;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Hit")
	FObjectiveSubjectTags DamageType;

};

UCLASS()
class UFortObjectiveProcessor_Hit : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

