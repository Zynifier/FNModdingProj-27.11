// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Components/FortPawnComponent.h"
#include "JumpSlideComponent.generated.h"

class ACharacter;

UCLASS(Config=Game, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UJumpSlideComponent : public UFortPawnComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Slide")
	void OnJumpSlideEnd();

	UFUNCTION(BlueprintImplementableEvent, Category="Slide")
	void OnJumpSlideStart();

private:
	UFUNCTION()
	void OnMovementModeChange(ACharacter* Character, EMovementMode PrevMovementMode, uint8 PreviousCustomMode);

};

