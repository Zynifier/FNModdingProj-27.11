// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_AddWidgetAlias.generated.h"

class UUserWidget;

UCLASS(MinimalAPI, meta=(DisplayName="Add Widget Alias"))
class UFortUIGameFeatureAction_AddWidgetAlias : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="UI")
	TMap<FGameplayTag, TSoftClassPtr<UUserWidget>> WidgetAliases;

};

