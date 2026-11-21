// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateTreeTaskBase.h"
#include "Athena/AI/FortPlayerBotUtils.h"
#include "Tasks/LWMEncounterInstance.h"
#include "LWMEncounterSetAlertLevelStateTreeTask.generated.h"

class AActor;

USTRUCT(meta=(Category="Encounter", DisplayName="LWM Encounter [Set Alert Level]"))
struct FLWMEncounterSetAlertLevelStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FLWMEncounterSetAlertLevelStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagQuery EncounterQuery;

	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bOnlyRaiseLevel;

	UPROPERTY(EditAnywhere, Category="Parameter")
	EAlertLevel AlertLevel;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="AlertLevel != EAlertLevel::Unaware", Optional))
	FLWMEncounterAlertLevelTargetInfo HasThreatTargetInfo;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="AlertLevel != EAlertLevel::Unaware", Optional))
	FLWMEncounterAlertLevelTargetInfo NoThreatTargetInfo;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> UserActor;

};

