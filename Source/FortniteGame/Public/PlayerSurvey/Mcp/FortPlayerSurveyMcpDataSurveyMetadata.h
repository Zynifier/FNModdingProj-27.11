// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "FortPlayerSurveyMcpDataSurveyMetadata.generated.h"

USTRUCT()
struct FFortPlayerSurveyMcpDataSurveyMetadata
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 NumTimesCompleted;

	UPROPERTY()
	FDateTime LastTimeCompleted;

};

