// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_Conversation.generated.h"

class AActor;
class AFortAthenaAIBotController;
class AFortPlayerPawnAthena;
class UFortAthenaAIRuntimeParameters_Conversation;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_Conversation : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnPlayerPawnSpawned(AFortAthenaAIBotController* BotController, AFortPlayerPawnAthena* BotPawn);

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName IsInConversationStateName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	TArray<FName> ExecutionStatusesToCheckedToAvoidStoppingWhenNearActorNames;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	TArray<FName> ExecutionStatusesToCheckForAllowToAvoidStoppingWhenNearActorNames;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	TArray<FName> MovementStatusesToCheckedToAvoidStoppingWhenNearActorNames;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotEvaluator_Conversation")
	bool bForceStopIfNoPlayerNearby;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_Conversation> ConversationRuntimeParameters;

	UPROPERTY(Transient)
	TObjectPtr<AActor> ActorToFocus;

};

