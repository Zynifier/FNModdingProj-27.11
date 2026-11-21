// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIEvaluator.h"
#include "FortAthenaAIEvaluator_FleeEnvDanger.generated.h"

class AAIController;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIEvaluator_FleeEnvDanger : public UFortAthenaAIEvaluator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Environmental Danger", meta=(AllowPrivateAccess="true"))
	float MaximumCheckDistance;

	UPROPERTY(EditAnywhere, Category="Environmental Danger", meta=(AllowPrivateAccess="true"))
	float AdditionalFleeDistance;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName EnvironmentalDangerExecutionStatusName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName EnvironmentalDangerFleeDirectionFromKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName EnvironmentalDangerFleeDirectionToKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName EnvironmentalDangerFleeDistanceKeyName;

	UPROPERTY(Transient)
	TObjectPtr<AAIController> CachedController;

};

