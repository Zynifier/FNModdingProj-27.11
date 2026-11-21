// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UIStateComponent.h"
#include "UIStateTransitionUrgency.h"
#include "SplitScreenUIStateComponentBase.generated.h"

class ULocalPlayer;
class USplitScreenUIStateComponentBaseConfiguration;
class UUIStateChart;

UCLASS(Abstract)
class UICHART_API USplitScreenUIStateComponentBase : public UUIStateComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	USplitScreenUIStateComponentBaseConfiguration* BaseConfiguration;

protected:
	UPROPERTY(Transient)
	TMap<ULocalPlayer*, int32> ChildStateCharts;

	UPROPERTY(Transient)
	TArray<int32> DeactivatingStateCharts;

};

UCLASS(Abstract)
class UICHART_API USplitScreenUIStateComponentBaseConfiguration : public UUIStateComponentConfiguration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SplitScreenUIStateComponentBaseConfiguration")
	TObjectPtr<UUIStateChart> PlayerStateChart;

	UPROPERTY(EditAnywhere, Category="SplitScreenUIStateComponentBaseConfiguration")
	bool bIgnoreTransitionParametersOnActivation;

	UPROPERTY(EditAnywhere, Category="SplitScreenUIStateComponentBaseConfiguration")
	EUIStateTransitionUrgency UrgencyOnPlayerAdd;

	UPROPERTY(EditAnywhere, Category="SplitScreenUIStateComponentBaseConfiguration")
	FGameplayTagContainer AnimationHintsOnPlayerAdd;

	UPROPERTY(EditAnywhere, Category="SplitScreenUIStateComponentBaseConfiguration")
	bool bIgnoreTransitionParametersOnDeactivation;

	UPROPERTY(EditAnywhere, Category="SplitScreenUIStateComponentBaseConfiguration")
	EUIStateTransitionUrgency UrgencyOnPlayerRemove;

	UPROPERTY(EditAnywhere, Category="SplitScreenUIStateComponentBaseConfiguration")
	FGameplayTagContainer AnimationHintsOnPlayerRemove;

};

