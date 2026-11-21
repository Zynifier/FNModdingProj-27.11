// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortCombatTypes.h"
#include "FortControllerComponent_QuickbarRestore.generated.h"

USTRUCT()
struct FQuickbarRestoreMutatorData
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_QuickbarRestore : public UFortControllerComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnPlayerPawnDied(const FFortPlayerDeathReport& DeathReport);

};

