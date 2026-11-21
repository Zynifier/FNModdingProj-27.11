// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayspaceComponent.h"
#include "PlayspaceComponent_GlobalCurrencyOverride.generated.h"

class AActor;
class UFortWorldItemDefinition;
class UPlayspaceComponent_GlobalCurrencyOverride;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UPlayspaceComponent_GlobalCurrencyOverride : public UPlayspaceComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Playspace")
	static UPlayspaceComponent_GlobalCurrencyOverride* GetPlayspaceGlobalCurrencyOverrideForActor(const AActor* Actor);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlayspaceComponent_GlobalCurrencyOverride")
	TObjectPtr<UFortWorldItemDefinition> OverrideGlobalCurrency;

};

