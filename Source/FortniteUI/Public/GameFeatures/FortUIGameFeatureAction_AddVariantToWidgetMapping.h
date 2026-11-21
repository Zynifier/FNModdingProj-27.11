// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_AddVariantToWidgetMapping.generated.h"

class UObject;
class UUserWidget;

UCLASS(MinimalAPI, meta=(DisplayName="Add Variant To Widget Mapping"))
class UFortUIGameFeatureAction_AddVariantToWidgetMapping : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="UI")
	TMap<TSubclassOf<UObject>, TSoftClassPtr<UUserWidget>> AddVariantToWidgetMapping;

};

