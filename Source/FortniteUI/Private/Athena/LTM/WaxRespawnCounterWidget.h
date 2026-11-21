// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "WaxRespawnCounterWidget.generated.h"

UCLASS()
class UWaxRespawnCounterWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetCount(int32 NewCount);

};

