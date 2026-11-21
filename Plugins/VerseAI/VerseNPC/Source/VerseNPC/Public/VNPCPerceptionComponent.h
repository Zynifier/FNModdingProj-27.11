// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIPerceptionComponentBase.h"
#include "VNPCPerceptionComponent.generated.h"

class AFortAthenaAIBotController;
enum class EAlertLevel : uint8;

UCLASS(ClassGroup=("Fortnite"))
class VERSENPC_API UNPCPerceptionComponentBase : public UAIPerceptionComponentBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnBotControllerAlertLevelChanged(AFortAthenaAIBotController* BotController, EAlertLevel OldAlertLevel, EAlertLevel NewAlertLevel);

};

