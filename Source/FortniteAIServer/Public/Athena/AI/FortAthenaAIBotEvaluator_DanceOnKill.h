// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_DanceOnKill.generated.h"

class UFortAthenaAIBotEmoteDigestedSkillSet;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_DanceOnKill : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LastKillPositionKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LastKillTimeKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LastKillWasABotKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName PlayEmoteExecutionStatusKeyName;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotEmoteDigestedSkillSet> CacheEmoteDigestedSkillSet;

};

