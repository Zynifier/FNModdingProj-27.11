// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_JumpOffBus.generated.h"

class AFortGameStateAthena;
class AFortPoiVolume;
class UFortAthenaAIBotMovementDigestedSkillSet;

UCLASS()
class UFortAthenaAIBotEvaluator_JumpOffBus : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName JumpOffBusDestinationName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName JumpOffBusDestinationVolumeKeyName;

	UPROPERTY(Transient)
	TObjectPtr<AFortPoiVolume> BusDroppingVolume;

	UPROPERTY(Transient)
	TObjectPtr<AFortGameStateAthena> CachedAthenaGameState;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotMovementDigestedSkillSet> CacheMovementDigestedSkillSet;

};

