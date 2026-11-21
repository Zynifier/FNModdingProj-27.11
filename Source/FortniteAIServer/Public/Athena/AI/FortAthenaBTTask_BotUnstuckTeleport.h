// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "FortAthenaBTTask_BotUnstuckTeleport.generated.h"

class UFortAthenaAIBotUnstuckDigestedSkillSet;

UCLASS()
class UFortAthenaBTTask_BotUnstuckTeleport : public UBTTaskNode
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="EQS", meta=(AllowPrivateAccess="true"))
	FEQSParametrizedQueryExecutionRequest EQSRequest;

	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName CanReachDestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Teleport", meta=(AllowPrivateAccess="true"))
	FName TeleportExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LastPartialPathTimeKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LastPartialPathCountKeyName;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotUnstuckDigestedSkillSet> UnstuckSkillSet;

};

