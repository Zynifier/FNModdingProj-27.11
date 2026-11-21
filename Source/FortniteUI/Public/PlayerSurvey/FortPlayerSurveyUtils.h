// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPlayerSurveyUtils.generated.h"

USTRUCT()
struct FFortPlayerSurveyLocalizableText
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TextID;

	UPROPERTY()
	FString LocalizedText;

};

