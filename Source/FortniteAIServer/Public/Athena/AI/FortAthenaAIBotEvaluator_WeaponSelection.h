// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_WeaponSelection.generated.h"

class UFortAthenaAIBotAimingDigestedSkillSet;
class UFortAthenaAIBotAttackingDigestedSkillSet;
class UFortAthenaAIBotRangeAttackDigestedSkillSet;

UCLASS(BlueprintType, Blueprintable)
class FORTNITEAISERVER_API UFortAthenaAIBotEvaluator_WeaponSelection : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ThrowableAttackIsReadyToThrowName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WeaponKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName TargetActorName;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotRangeAttackDigestedSkillSet> CacheRangeAttackDigestedSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotAttackingDigestedSkillSet> CacheAttackingDigestedSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotAimingDigestedSkillSet> CacheAimingDigestedSkillSet;

};

