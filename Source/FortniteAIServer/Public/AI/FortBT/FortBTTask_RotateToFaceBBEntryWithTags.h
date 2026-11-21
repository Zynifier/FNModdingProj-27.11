// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_RotateToFaceBBEntry.h"
#include "GameplayTagContainer.h"
#include "FortBTTask_RotateToFaceBBEntryWithTags.generated.h"

UCLASS()
class UFortBTTask_RotateToFaceBBEntryWithTags : public UBTTask_RotateToFaceBBEntry
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Config, Category="Node")
	FGameplayTagContainer TagsToApply;

};

