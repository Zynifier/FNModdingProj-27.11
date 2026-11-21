// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaZebulonDroneWidgetBase.generated.h"

class AFortGameState;
enum class EAthenaGamePhaseStep : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaZebulonDroneWidgetBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnGamePhaseStepChanged(EAthenaGamePhaseStep GamePhaseStep);

	UFUNCTION()
	void OnGameStateSet(AFortGameState* InGameState);

};

