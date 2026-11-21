// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/MinigameWidgetBase.h"
#include "MinigameObjectiveTrackerWidget.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UMinigameObjectiveTrackerWidget : public UMinigameWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnLocalPlayerChangedTeams();

};

