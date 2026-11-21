// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorial.h"
#include "FortContextualTutorial_GameplayEvent.generated.h"

class AFortPlayerControllerZone;

UCLASS(MinimalAPI)
class UFortContextualTutorial_GameplayEvent : public UFortContextualTutorial
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	FORTNITEGAME_API void HandleBindActivationTrigger(AFortPlayerControllerZone* FortPCZone);

	UFUNCTION()
	FORTNITEGAME_API void HandleBindCompletionTrigger(AFortPlayerControllerZone* FortPCZone);

};

