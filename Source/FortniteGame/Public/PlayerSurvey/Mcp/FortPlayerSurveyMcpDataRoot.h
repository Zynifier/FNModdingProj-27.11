// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerSurvey/Mcp/FortPlayerSurveyMcpDataSurveyMetadata.h"
#include "FortPlayerSurveyMcpDataRoot.generated.h"

USTRUCT()
struct FFortPlayerSurveyMcpDataRoot
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortPlayerSurveyMcpDataSurveyMetadata AllSurveysMetadata;

	UPROPERTY()
	TMap<FString, FFortPlayerSurveyMcpDataSurveyMetadata> Metadata;

};

