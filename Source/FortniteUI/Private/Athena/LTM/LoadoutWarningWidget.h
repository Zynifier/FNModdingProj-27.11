// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "LoadoutWarningWidget.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class ULoadoutWarningWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnLoadoutWarning(float TimeToSwap);

	UFUNCTION(BlueprintImplementableEvent)
	void StartWarning(float TimeToSwap);

};

