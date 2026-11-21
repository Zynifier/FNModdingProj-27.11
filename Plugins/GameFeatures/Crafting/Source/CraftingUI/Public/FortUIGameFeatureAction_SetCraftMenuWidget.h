// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_SetCraftMenuWidget.generated.h"

class ACraftingObjectBGA;
class UUserWidget;

UCLASS(MinimalAPI, meta=(DisplayName="Set Craft Menu Widget"))
class UFortUIGameFeatureAction_SetCraftMenuWidget : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortUIGameFeatureAction_SetCraftMenuWidget")
	TSubclassOf<ACraftingObjectBGA> CraftingObject;

	UPROPERTY(EditAnywhere, Category="FortUIGameFeatureAction_SetCraftMenuWidget")
	TSoftClassPtr<UUserWidget> CraftingMenuWidget;

};

