// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_HolsterWeapon.generated.h"

class UFortAthenaAIRuntimeParameters_AIBotConvert;
class UFortAthenaAIRuntimeParameters_NPCBehavior;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_HolsterWeapon : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	TArray<FName> ExecutionStatusesToCheckedNames;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_NPCBehavior> CachedNPCBehaviorParameters;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_AIBotConvert> CachedConvertParameters;

};

