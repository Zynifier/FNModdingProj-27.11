// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DynamicUITransitionableWidgetInterface.generated.h"

UINTERFACE(MinimalAPI, NotBlueprintable)
class UDynamicUITransitionableWidgetInterface : public UInterface
{
	GENERATED_BODY()
};

class IDynamicUITransitionableWidgetInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="Dynamic UI")
	virtual void BroadcastTransitionCompleted();

};

