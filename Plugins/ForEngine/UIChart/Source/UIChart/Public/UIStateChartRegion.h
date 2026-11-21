// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "UIStateChartContext.h"
#include "UIStateChartRegion.generated.h"

class UUIState;
class UUIStateBacktrackStep;
class UUIStateChartManagerEntry;
class UUIStateChartRegion;
class UUIStateChartTransitionOperation;

UENUM()
enum class EUIChartRegionTransitionScope : uint8
{
	ThisRegionOnly = 0,
	ThisRegionOrChildRegions = 1,
};

UCLASS()
class UICHART_API UUIStateBacktrackStep : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTag TransitionTag;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIState> ReturnState;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIState> AvailableState;

	UPROPERTY()
	FUIStateChartContextChangeSet ReverseContextChanges;

	UPROPERTY()
	TArray<UUIStateBacktrackStep*> AvailablePaths;

};

UCLASS()
class UICHART_API UUIStateChartRegion : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<UUIStateChartManagerEntry> ManagerEntry;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIState> RootState;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIState> ParentState;

	UPROPERTY(Transient)
	TArray<UUIStateChartRegion*> ParallelRegions;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<FGameplayTag, UUIState*> TaggedStates;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIState> ActiveLeafState;

	UPROPERTY(Transient)
	TObjectPtr<UUIStateChartTransitionOperation> ActiveTransitionOperation;

	UPROPERTY(Transient)
	TObjectPtr<UUIStateChartTransitionOperation> QueuedTransitionOperation;

	UPROPERTY(Transient)
	TArray<UUIStateBacktrackStep*> AvailableBacktrackPaths;

	UPROPERTY(Transient)
	TObjectPtr<UUIStateBacktrackStep> ActiveTransitionBacktrackStep;

	UPROPERTY()
	FString ChartName;

};

