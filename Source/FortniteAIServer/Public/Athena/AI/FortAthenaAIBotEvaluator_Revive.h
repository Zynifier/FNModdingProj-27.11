// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_Revive.generated.h"

class AFortPlayerPawn;
class AFortPlayerPawnAthena;
class UFortAthenaAIBotReviveDigestedSkillSet;
class UFortAthenaAIRuntimeParameters_ReviveBehavior;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_Revive : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnCurrentTargetRevived(AFortPlayerPawn* RevivedPawn);

	UPROPERTY(EditAnywhere, Category="Revive", meta=(AllowPrivateAccess="true", UIMin="0.0"))
	FScalableFloat LastReviveTargetExpiration;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ReviveTargetKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ReviveLastTargetKeyName;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_ReviveBehavior> ReviveBehaviorRuntimeParameters;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerPawnAthena> CurrentReviveTarget;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerPawnAthena>> DBNOAllyPawns;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotReviveDigestedSkillSet> ReviveSkillSet;

};

