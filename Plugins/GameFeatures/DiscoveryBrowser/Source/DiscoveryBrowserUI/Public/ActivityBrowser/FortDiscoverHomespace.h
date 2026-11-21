// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/ScrollableActivatableWidget.h"
#include "FortDiscoverHomespace.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortDiscoverHomespace : public UScrollableActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPeekPushPercentMobileCVarChanged(float PeekPushPercent);

};

