// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorial.h"
#include "FortContextualTutorial_BattleBus.generated.h"

UCLASS()
class UFortContextualTutorial_BattleBus : public UFortContextualTutorial
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleStartSkydiving();

};

