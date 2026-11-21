// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorial.h"
#include "FortContextualTutorial_MultipleAugmentsQueued.generated.h"

class AFortPlayerControllerZone;

UCLASS(MinimalAPI)
class UFortContextualTutorial_MultipleAugmentsQueued : public UFortContextualTutorial
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void ActivationEventCallback(int8 NumPendingAugmentsToGrant);

	UFUNCTION()
	void CompletionEventCallback(const bool bIsOpened, const bool bViewingAugmentInventory);

	UFUNCTION()
	void HandleBindActivationTrigger(AFortPlayerControllerZone* FortPCZone);

	UFUNCTION()
	void HandleBindCompletionTrigger(AFortPlayerControllerZone* FortPCZone);

};

