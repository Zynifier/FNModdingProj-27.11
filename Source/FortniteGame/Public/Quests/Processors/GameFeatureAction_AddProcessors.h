// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameFeatureAction_AddProcessors.generated.h"

class UObjectiveProcessorBase;

UCLASS(MinimalAPI, meta=(DisplayName="Add Processors"))
class UGameFeatureAction_AddProcessors : public UGameFeatureAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Processors")
	TArray<TSoftClassPtr<UObjectiveProcessorBase>> ProcessorList;

};

