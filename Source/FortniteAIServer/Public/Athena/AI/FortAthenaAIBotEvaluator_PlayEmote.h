// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_PlayEmote.generated.h"

class AActor;

UCLASS()
class UFortAthenaAIBotEvaluator_PlayEmote : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName PlayEmoteExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName PlayEmoteDestinationKeyName;

	UPROPERTY(Transient)
	AActor* ExcludeReachingTarget;

};

