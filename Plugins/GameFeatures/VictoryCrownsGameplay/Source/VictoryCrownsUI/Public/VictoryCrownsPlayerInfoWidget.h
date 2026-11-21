// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaPlayerInfoBaseWidgetInterface.h"
#include "FortHUDElementWidget.h"
#include "VictoryCrownsPlayerInfoWidget.generated.h"

class AFortPlayerStateAthena;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UVictoryCrownsPlayerInfoWidget : public UFortHUDElementWidget, public IAthenaPlayerInfoBaseWidgetInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleCrownBearerListChanged(const TArray<AFortPlayerStateAthena*>& CrownBearerList);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerVictoryCrownStatusChanged(const bool bHasCrown);

};

