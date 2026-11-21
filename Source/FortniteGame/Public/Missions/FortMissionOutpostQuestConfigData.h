// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Missions/FortMissionConfigData.h"
#include "FortMissionOutpostQuestConfigData.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortMissionOutpostQuestConfigData : public UFortMissionConfigData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMissionOutpostQuestConfigData")
	FGameplayTagContainer LegTagContainer;

};

