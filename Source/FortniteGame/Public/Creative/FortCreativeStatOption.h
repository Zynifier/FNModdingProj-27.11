// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/FortQuestObjectiveType.h"
#include "FortCreativeStatOption.generated.h"

USTRUCT(BlueprintType)
struct FCreativeStatOption
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeStatOption")
	FStatEventFilter StatEventFilter;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeStatOption")
	FText DisplayName;

};

