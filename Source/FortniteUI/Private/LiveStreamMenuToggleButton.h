// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "LiveStreamMenuToggleButton.generated.h"

UCLASS(meta=(DisableNativeTick))
class ULiveStreamMenuToggleButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void RefreshButton(bool IsLiveStreamEnabled);

};

