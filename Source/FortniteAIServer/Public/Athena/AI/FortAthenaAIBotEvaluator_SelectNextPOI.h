// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_SelectNextPOI.generated.h"

class AFortPoiVolume;
class AFortTeamInfoAthena;
class UFortAthenaAIBotLootingDigestedSkillSet;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_SelectNextPOI : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName NextPOIKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName MarkerLocationKeyName;

	UPROPERTY(Transient)
	TObjectPtr<AFortPoiVolume> StartingGroundPOI;

	UPROPERTY(Transient)
	bool bCheckForStartingGroundPOI;

	UPROPERTY(Transient)
	float CurrentPOICompletionTime;

	UPROPERTY(Transient)
	float DurationInsideCurrentPOI;

	UPROPERTY(Transient)
	TObjectPtr<AFortTeamInfoAthena> CachedTeamInfo;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotLootingDigestedSkillSet> CachedLootingSkillSet;

};

