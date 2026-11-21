// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_DBNO.generated.h"

class AFortPawn;
class AFortPlayerPawnAthena;
class UFortAthenaAIBotDBNODigestedSkillSet;
class UFortAthenaAICoverComponent;
class UFortAthenaAIRuntimeParameters_DBNOBehavior;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_DBNO : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnAllyPawnDBNOStateChanged(AFortPawn* InPlayer, bool bInIsDBNO);

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName DBNODestinationKeyName;

	UPROPERTY(EditAnywhere, Category="Revive", meta=(AllowPrivateAccess="true"))
	uint8 bAllowReachSquadmates : 1;

	UPROPERTY(EditAnywhere, Category="Revive", meta=(AllowPrivateAccess="true"))
	uint8 bAllowReachSameFactionNPCs : 1;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerPawnAthena>> AllyPawns;

	UPROPERTY(Transient)
	FVector CachedCurrentDestination;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotDBNODigestedSkillSet> DBNOSkillSet;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaAICoverComponent> CachedCoverComponent;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_DBNOBehavior> DBNOBehaviorRuntimeParameters;

};

