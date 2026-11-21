// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Tasks/TargetingFilterTask_BasicFilterTemplate.h"
#include "TargetingFilterTask_GameplayTagQuery.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UTargetingFilterTask_GameplayTagQuery : public UTargetingFilterTask_BasicFilterTemplate
{
	GENERATED_BODY()

public:
	UTargetingFilterTask_GameplayTagQuery(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, Category="Targeting Filter | Tags")
	FGameplayTagQuery GameplayTagQuery;

};

