// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortGameStateComponent.h"
#include "FortGameStateComponent_MidMatchObjectiveParent.generated.h"

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_MidMatchObjectiveParent : public UFortGameStateComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	MIDMATCHOBJECTIVESGAMEPLAYRUNTIME_API void SetObjectiveCompletedStat(const uint8 SquadId);

	UPROPERTY(EditDefaultsOnly, Category="Stats")
	FName ObjectiveCompletedStatName;

};

