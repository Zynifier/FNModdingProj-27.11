// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortUIDataConfiguration.h"
#include "FortUITypes.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_ModifyUIStateWidgets.generated.h"

class UFortUIStateWidgetBase;

USTRUCT()
struct FTagStateWidgetEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="TagStateWidgetEntry")
	TSoftClassPtr<UFortUIStateWidgetBase> Class;

	UPROPERTY(EditAnywhere, Category="TagStateWidgetEntry")
	EFortNamedBundle Bundle;

};

UCLASS(MinimalAPI, meta=(DisplayName="Modify UI State Widgets"))
class UFortUIGameFeatureAction_ModifyUIStateWidgets : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="UI")
	TMap<EFortUIState, FStateWidgetEntry> StateWidgetClassOverrides;

	UPROPERTY(EditAnywhere, Category="UI")
	TMap<FGameplayTag, FTagStateWidgetEntry> StateWidgetClassesByTag;

};

