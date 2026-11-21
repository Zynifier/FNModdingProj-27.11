// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "FortPlayerSurveyTokenItem.generated.h"

UCLASS(MinimalAPI)
class UFortPlayerSurveyTokenItem : public UFortAccountItem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortPlayerSurveyTokenItem")
	FString survey_id;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerSurveyTokenItem")
	int32 token_type;

};

