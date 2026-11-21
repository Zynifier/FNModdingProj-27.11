// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaPlayerInfoBaseWidgetInterface.h"
#include "FortHUDElementWidget.h"
#include "TacOvershieldPlayerInfoWidget.generated.h"

class AFortPlayerStateAthena;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UTacOvershieldPlayerInfoWidget : public UFortHUDElementWidget, public IAthenaPlayerInfoBaseWidgetInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnOvershieldStateChanged(float Overshield, float OvershieldMax);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerStateSet(AFortPlayerStateAthena* InPlayerState);

};

