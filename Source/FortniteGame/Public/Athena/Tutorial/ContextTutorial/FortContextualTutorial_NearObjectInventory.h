// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayCueInterface.h"
#include "GameplayEffectTypes.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorial.h"
#include "FortContextualTutorial_NearObjectInventory.generated.h"

UCLASS()
class UFortContextualTutorial_NearObjectInventory : public UFortContextualTutorial, public IGameplayCueInterface
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void GameplayCue_Wumba_Upgraded(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters);

	UFUNCTION()
	void HandleStartSkydivingForActivation();

};

