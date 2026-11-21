// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortGameFeatureAction_AddGameplayModifiers.h"
#include "FortGameFeatureAction_AddConditionalGameplayModifiers.generated.h"

class AFortMinigameSettingsBuilding;
class UActorComponent;
class UWorld;

UCLASS(MinimalAPI, meta=(DisplayName="Add Conditional Gameplay Modifiers"))
class UFortGameFeatureAction_AddConditionalGameplayModifiers : public UFortGameFeatureAction_AddGameplayModifiers
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Override")
	uint8 bOverrideConditions : 1;

	UPROPERTY(EditAnywhere, Category="Override")
	uint8 bReplaceConditionsWith : 1;

	UPROPERTY(EditAnywhere, Category="Conditions", meta=(AllowAbstract="True"))
	TSoftClassPtr<AFortMinigameSettingsBuilding> ActorClass;

	UPROPERTY(EditAnywhere, Category="Conditions")
	TSoftClassPtr<UActorComponent> ComponentClass;

	UPROPERTY(EditAnywhere, Category="Conditions")
	FName BooleanPropertyName;

	UPROPERTY(EditAnywhere, Category="Conditions")
	uint8 bCheckValue : 1;

private:
	UPROPERTY(Transient)
	TMap<UWorld*, bool> AffectedWorlds;

};

