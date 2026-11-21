// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "GameplayTagContainer.h"
#include "FortAthenaBTService_ApplyGameplayTags.generated.h"

UCLASS()
class UFortAthenaBTService_ApplyGameplayTags : public UBTService
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortAthenaBTService_ApplyGameplayTags")
	FGameplayTagContainer GameplayTagsToApply;

};

