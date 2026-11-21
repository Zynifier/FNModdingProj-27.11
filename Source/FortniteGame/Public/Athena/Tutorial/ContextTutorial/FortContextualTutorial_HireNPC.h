// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorial.h"
#include "FortContextualTutorial_HireNPC.generated.h"

class AFortPawn;
class AFortPlayerControllerZone;

UCLASS(MinimalAPI)
class UFortContextualTutorial_HireNPC : public UFortContextualTutorial
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void ActivationEventCallback(AFortPawn* ConvertedFortPawn);

	UFUNCTION()
	void HandleBindActivationTrigger(AFortPlayerControllerZone* FortPCZone);

	UFUNCTION()
	void HandleBindCompletionTrigger(AFortPlayerControllerZone* FortPCZone);

};

