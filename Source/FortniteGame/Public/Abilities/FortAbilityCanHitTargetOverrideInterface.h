// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAbilityCanHitTargetOverrideInterface.generated.h"

class AActor;
class AFortPawn;
class UFortGameplayAbility;

UINTERFACE(BlueprintType, Blueprintable)
class UFortAbilityCanHitTargetOverrideInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortAbilityCanHitTargetOverrideInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="AbilityCanHit")
	bool ShouldAcceptCanHitForTarget(const AFortPawn* Source, const AActor* Target, const UFortGameplayAbility* Ability);

};

