// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_TagQuery.h"
#include "FortAthenaAIBotEvaluator_SandTunnel.generated.h"

class AFortAthenaAIBotController;
class UFortAthenaAIBotMovementDigestedSkillSet;
enum class EAlertLevel : uint8;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_SandTunnel : public UFortAthenaAIBotEvaluator_TagQuery
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void Jump();

private:
	UFUNCTION()
	void OnBotControllerAlertLevelChanged(AFortAthenaAIBotController* BotController, EAlertLevel OldAlertLevel, EAlertLevel NewAlertLevel);

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName JumpExecutionStatusName;

	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LootInteractionExecutionStatusName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WeaponTriggerMeleeName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WeaponFireName;

	UPROPERTY(EditAnywhere, Category="Tag Query", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery BuriedTagQuery;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotMovementDigestedSkillSet> CacheMovementDigestedSkillSet;

};

