// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaBTService_Jump.h"
#include "FortAthenaBTService_JetpackStrafe.generated.h"

class UFortAthenaAIBotEvasiveManeuversDigestedSkillSet;

UCLASS()
class UFortAthenaBTService_JetpackStrafe : public UFortAthenaBTService_Jump
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName JetpackStrafeExecutionStatusName;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotEvasiveManeuversDigestedSkillSet> CacheEMDigestedSkillSet;

};

