// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "UIStateChartContext.h"
#include "UIStateComponent.h"
#include "UIState.generated.h"

class UUIState;
class UUIStateChartRegion;
class UUIStateChartTransition;
class UUIStateComponent;
class UUIStateComponentConfiguration;
class UUIStateConfiguration;

UENUM()
enum class EUIStateAutomationType : uint8
{
	// The State Automation Rules will be used to choose the appropriate Child State when this State is activated during a transition that targets a parent state.

	Initial = 0,
	// While this State is active it will monitor the Context and automatically transition to the appropriate Child State (according to State Automation Rules) when relevant data changes.

	Continual = 1,
};

USTRUCT()
struct UICHART_API FUIStateConfigurationChildReference
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="UIStateConfigurationChildReference")
	int32 ChildStateId;

};

USTRUCT()
struct UICHART_API FUIStateAutomationRule
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="UIStateAutomationRule")
	TArray<FUIStateChartContextCondition> ContextConditions;

	UPROPERTY(EditAnywhere, Category="UIStateAutomationRule")
	FUIStateConfigurationChildReference ChildStateReference;

};

UCLASS(DefaultToInstanced, EditInlineNew)
class UICHART_API UUIState : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<UUIState*> Children;

	UPROPERTY(Transient)
	TArray<UUIStateChartRegion*> ParallelRegions;

	UPROPERTY(Transient)
	TArray<UUIStateComponent*> Components;

protected:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	UUIStateConfiguration* Configuration;

	UPROPERTY(Transient)
	TArray<UUIStateChartTransition*> OutgoingTransitions;

	UPROPERTY(Transient)
	float SecondsUntilTimeout;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIState> Parent;

	UPROPERTY(Transient)
	TObjectPtr<UUIStateChartRegion> StateChartRegion;

	UPROPERTY(Transient)
	EStateComponentStatus Status;

	UPROPERTY(Transient)
	TSet<FGameplayTag> ContinualAutomationContextKeys;

};

UCLASS(DefaultToInstanced, EditInlineNew, CollapseCategories)
class UICHART_API UUIStateConfiguration : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="UIStateChartEditor")
	FString Name;

	UPROPERTY(EditAnywhere, Category="UIStateChartEditor", meta=(Categories="UI.Chart.StateTag"))
	FGameplayTagContainer StateTags;

	UPROPERTY(EditAnywhere, Category="UIStateConfiguration")
	int32 Id;

	UPROPERTY(EditAnywhere, Instanced, Category="UIStateConfiguration")
	TArray<UUIStateConfiguration*> Children;

	UPROPERTY(EditAnywhere, Instanced, Category="UIStateConfiguration")
	TArray<UUIStateConfiguration*> ParallelRegions;

	UPROPERTY(EditAnywhere, Instanced, Category="UIStateChartEditor")
	TArray<UUIStateComponentConfiguration*> Components;

	UPROPERTY(EditAnywhere, Category="UIStateChartEditor")
	float MinimumUnloadTime;

	UPROPERTY(EditAnywhere, Category="UIStateChartEditor")
	EUIStateAutomationType AutomationType;

	UPROPERTY(EditAnywhere, Category="UIStateChartEditor")
	TArray<FUIStateAutomationRule> AutomationRules;

	UPROPERTY(EditAnywhere, Category="UIStateChartEditor")
	bool bSupportsBacktracking;

	UPROPERTY(EditAnywhere, Category="UIStateChartEditor")
	bool bOverrideIncomingBacktracks;

};

