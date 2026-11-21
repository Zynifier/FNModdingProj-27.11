// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_TagQuery.h"
#include "FortAthenaAIBotEvaluator_DangerDetection.generated.h"

class UAthenaAIServiceZoneManager;
class UFortAthenaAIBotMovementDigestedSkillSet;
class UFortNavArea;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Nav"))
class UFortAthenaAIBotEvaluator_DangerDetection : public UFortAthenaAIBotEvaluator_TagQuery
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard")
	FName DangerZoneDetectedExecutionStatusName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName DangerZoneDetectedSafeLocationKeyName;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotMovementDigestedSkillSet> CachedMovementSkillSet;

	UPROPERTY(Transient)
	UAthenaAIServiceZoneManager* CacheZoneManager;

private:
	UPROPERTY(EditAnywhere, Category="Danger Detection", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortNavArea> DangerNavAreaClass;

	UPROPERTY(EditAnywhere, Category="Danger Detection", meta=(AllowPrivateAccess="true"))
	float TimeToCheckForDangerAfterValidQuery;

	UPROPERTY(EditAnywhere, Category="Danger Avoidance", meta=(AllowPrivateAccess="true"))
	float MaxRadiusToSearchForSafePlace;

};

