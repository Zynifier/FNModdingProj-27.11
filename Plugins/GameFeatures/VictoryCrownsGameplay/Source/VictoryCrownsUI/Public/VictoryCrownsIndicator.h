// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortActorIndicatorWidget.h"
#include "VictoryCrownsIndicator.generated.h"

class AFortPlayerStateAthena;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UVictoryCrownsIndicator : public UFortActorIndicatorWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const AFortPlayerStateAthena* GetIndicatedPlayerStateAthena() const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDistanceChanged(int32 Distance);

	UFUNCTION(BlueprintImplementableEvent)
	void OnScreenClampChanged(bool bIsClamped);

};

