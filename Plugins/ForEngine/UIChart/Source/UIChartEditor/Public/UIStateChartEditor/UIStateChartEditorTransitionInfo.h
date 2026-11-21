// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UIStateChart.h"
#include "UIStateChartEditorTransitionInfo.generated.h"

UCLASS(CollapseCategories)
class UICHARTEDITOR_API UUIStateChartEditorTransitionInfo : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Transient, Category="UIStateChartEditorTransitionInfo")
	FUIStateTransitionData TransitionConfiguration;

	UPROPERTY(Transient)
	int32 TransitionIndex;

};

