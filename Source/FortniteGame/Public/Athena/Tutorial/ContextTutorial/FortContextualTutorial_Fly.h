// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Athena/Tutorial/ContextTutorial/FortContextualTutorial.h"
#include "FortContextualTutorial_Fly.generated.h"

class ACharacter;

UCLASS()
class UFortContextualTutorial_Fly : public UFortContextualTutorial
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandlePawnLanded(const FHitResult& Hit);

	UFUNCTION()
	void HandleStartSkydivingForActivation();

	UFUNCTION()
	void OnMovementModeChange(ACharacter* Character, EMovementMode PrevMovementMode, uint8 PreviousCustomMode);

};

