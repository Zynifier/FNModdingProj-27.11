// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_PluginHUDContent.generated.h"

class UWidget;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_PluginHUDContent : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TMap<FGameplayTag, TSoftClassPtr<UWidget>> PluginHUDElements;

};

