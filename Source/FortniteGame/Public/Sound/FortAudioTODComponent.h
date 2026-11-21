// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortGameStateComponent.h"
#include "FortAudioTODComponent.generated.h"

enum class EFortDayPhase : uint8;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortAudioTODComponent : public UFortGameStateComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnDayPhaseChanged(EFortDayPhase CurrentDayPhase, EFortDayPhase PreviousDayPhase, bool bAtCreation);

};

