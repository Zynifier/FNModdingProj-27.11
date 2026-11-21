// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "AI/FortAITypes.h"
#include "FortQueryTest_IsGoalForAssignment.generated.h"

UCLASS(meta=(DisplayName="Goal: Is Part of Assignment"))
class UFortQueryTest_IsGoalForAssignment : public UEnvQueryTest
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Assignment")
	bool bRetrieveRootAssignmentFromOwner;

	UPROPERTY(EditAnywhere, Category="Assignment")
	FFortAIAssignmentIdentifier RootAssignmentID;

};

