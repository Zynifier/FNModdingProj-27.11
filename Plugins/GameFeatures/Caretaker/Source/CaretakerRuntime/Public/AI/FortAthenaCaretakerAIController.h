// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "AI/AthenaAIController.h"
#include "FortAthenaCaretakerAIController.generated.h"

class ACharacter;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Collision", "Rendering", "Transformation"))
class AFortAthenaCaretakerAIController : public AAthenaAIController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Caretaker Controller")
	void DebugUpdate(float UpdateInterval);

	UFUNCTION()
	void OnMovementModeChanged(ACharacter* CharacterOwner, EMovementMode PreviousMovementMode, uint8 PreviousCustomMode);

};

