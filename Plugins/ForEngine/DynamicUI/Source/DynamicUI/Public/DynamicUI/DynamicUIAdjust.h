// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DynamicUI/DynamicUIWidgetTarget.h"
#include "DynamicUIAdjust.generated.h"

class UDynamicUIConstraintBase;
class UDynamicUISizeBase;

USTRUCT()
struct FDynamicUIAdjust
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	FDynamicUIWidgetTarget TargetWidget;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Dynamic UI|Layout")
	TObjectPtr<UDynamicUIConstraintBase> LayoutConstraint;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Dynamic UI|Layout")
	TObjectPtr<UDynamicUISizeBase> SizeModifier;

};

