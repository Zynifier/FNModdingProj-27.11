// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UIStateComponent.generated.h"

class UUIState;
class UUIStateChartRegion;
class UUIStateComponentConfiguration;

UENUM()
enum class EStateChartResourceScope : int32
{
	StateChart = 0,
	Player = 1,
	Global = 2,
};

UENUM()
enum class EStateComponentStatus : int32
{
	Inactive = 0,
	PreparingForLoad = 1,
	Loading = 2,
	DoneLoading = 3,
	Operational = 4,
	PreparingForUnload = 5,
	Unloading = 6,
	DoneUnloading = 7,
};

UCLASS(Abstract)
class UICHART_API UUIStateComponent : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	EStateComponentStatus Status;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIStateComponentConfiguration> ComponentConfiguration;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIState> OwningState;

private:
	UPROPERTY(Transient)
	TObjectPtr<UUIStateChartRegion> StateChartRegion;

};

UCLASS(Abstract, DefaultToInstanced, EditInlineNew, CollapseCategories)
class UICHART_API UUIStateComponentConfiguration : public UObject
{
	GENERATED_BODY()

};

