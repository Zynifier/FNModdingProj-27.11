// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_ReloadWeapon.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_ReloadWeapon : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WeaponKeyName;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_ReloadWeapon")
	bool bCanReloadWeaponsInInventory;

};

