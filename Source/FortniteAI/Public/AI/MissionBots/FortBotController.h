// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortAIController.h"
#include "FortBotController.generated.h"

class UFortBotMissionLogic;

UCLASS(MinimalAPI, HideCategories=("Collision", "Rendering", "Transformation"))
class AFortBotController : public AFortAIController
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<UFortBotMissionLogic> CurrentMissionLogic;

};

