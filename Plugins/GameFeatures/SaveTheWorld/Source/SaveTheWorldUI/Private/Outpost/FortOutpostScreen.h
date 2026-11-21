// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortOutpostScreen.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortOutpostScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetInputReflectorBoxVisibility(bool bShow);

};

