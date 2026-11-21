// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DynamicUI/DynamicUITypes.h"
#include "DynamicUI/DynamicUIWidgetTarget.h"
#include "DynamicUIUnallow.generated.h"

UENUM()
enum class EDynamicUIUnallowLayerComparison : uint8
{
	Equal = 0,
	NotEqual = 1,
	Less = 2,
	LessOrEqual = 3,
	Greater = 4,
	GreaterOrEqual = 5,
};

UCLASS(Abstract, EditInlineNew, CollapseCategories)
class UDynamicUIUnallowBase : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	EDynamicUIUnallowedBehavior Behavior;

};

UCLASS(meta=(DisplayName="Layer"))
class UDynamicUIUnallowLayer : public UDynamicUIUnallowBase
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI", meta=(GetOptions="DynamicUI.DynamicUIScene.GetLayerNames"))
	FString Layer;
#endif

	UPROPERTY()
	uint8 LayerID;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	EDynamicUIUnallowLayerComparison Comparison;

};

UCLASS(meta=(DisplayName="Widget"))
class UDynamicUIUnallowWidget : public UDynamicUIUnallowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	FDynamicUIWidgetTarget Widget;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	uint8 bTargetAll : 1;

};

