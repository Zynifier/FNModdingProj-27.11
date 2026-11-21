// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPlayerSurveyQuestion.generated.h"

UENUM(BlueprintType)
enum class EFortPlayerSurveyQuestionType : uint8
{
	SingleChoice = 0,
	MultipleChoice = 1,
	Rating = 2,
};

