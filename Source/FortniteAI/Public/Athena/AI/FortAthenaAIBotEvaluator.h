// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIEvaluator.h"
#include "FortAthenaAIBotEvaluator.generated.h"

class AFortAthenaAIBotController;

UCLASS(Abstract, MinimalAPI)
class UFortAthenaAIBotEvaluator : public UFortAthenaAIEvaluator
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaAIBotController> CachedBotController;

};

