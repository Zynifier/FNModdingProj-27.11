// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortActorIndicatorWidget.h"
#include "NevadaTargetIndicator.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UNevadaTargetIndicator : public UFortActorIndicatorWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnTractorBeamActivated(const bool bActivated);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTractorBeamAttached(const bool bAttached);

};

