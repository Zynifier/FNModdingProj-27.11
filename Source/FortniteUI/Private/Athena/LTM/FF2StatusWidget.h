// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "FF2StatusWidget.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFF2StatusWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetHealth(float CurrentHealth, float MaxHealth);

};

