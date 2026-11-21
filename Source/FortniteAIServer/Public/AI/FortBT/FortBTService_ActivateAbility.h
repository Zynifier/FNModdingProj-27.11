// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "GameplayTagContainer.h"
#include "AI/FortAITypes.h"
#include "FortBTService_ActivateAbility.generated.h"

UCLASS(MinimalAPI)
class UFortBTService_ActivateAbility : public UBTService
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortBTService_ActivateAbility")
	FGameplayTagContainer AbilityTags;

	UPROPERTY(EditAnywhere, Category="FortBTService_ActivateAbility")
	bool bRequireCanHitTargetWithAbility;

	UPROPERTY(EditAnywhere, Category="FortBTService_ActivateAbility")
	bool bPawnTargetsOnly;

	UPROPERTY(EditAnywhere, Category="FortBTService_ActivateAbility")
	FGameplayTagContainer ProhibitedTargetTags;

	UPROPERTY(EditAnywhere, Category="FortBTService_ActivateAbility")
	bool bCanActivateWhenMoving;

	UPROPERTY(EditAnywhere, Category="FortBTService_ActivateAbility")
	TArray<FDistanceToTargetComparison> DistanceChecks;

};

