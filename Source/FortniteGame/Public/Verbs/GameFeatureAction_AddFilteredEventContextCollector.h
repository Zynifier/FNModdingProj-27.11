// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameFeatureAction_AddFilteredEventContextCollector.generated.h"

class UFilteredEventContextCollectorBase;

UCLASS(MinimalAPI, meta=(DisplayName="Add Context Collectors"))
class UGameFeatureAction_AddFilteredEventContextCollector : public UGameFeatureAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Collectors")
	TArray<TSoftClassPtr<UFilteredEventContextCollectorBase>> CollectorList;

};

