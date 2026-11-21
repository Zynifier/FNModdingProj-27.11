// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortNearbyActorsPerceptionComponent.h"
#include "FortAthenaAIBotEvaluator_ReactToVerb.generated.h"

class AFortPawn;
class UDataTable;
class UFortAthenaAIBotReactToVerbDigestedSkillSet;
class UFortItemDefinition;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_ReactToVerb : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandlePawnStartedEmote(const UFortItemDefinition* MontageItemDef, AFortPawn* PawnEmoting);

	UFUNCTION()
	void HandlePawnStoppedEmote(const UFortItemDefinition* MontageItemDef, AFortPawn* PawnEmoting);

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotReactToVerbDigestedSkillSet> CacheReactToVerbDigestedSkillSet;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotEvaluator_ReactToVerb", meta=(RowType="/Script/FortniteGame.FortNPCVerbReactionTableRow"))
	TObjectPtr<UDataTable> VerbReactions;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotEvaluator_ReactToVerb", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinDistanceFromPlayerToReact;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotEvaluator_ReactToVerb", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxReactionEmoteDuration;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotEvaluator_ReactToVerb", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxReactionWaitTime;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotEvaluator_ReactToVerb", meta=(AllowPrivateAccess="true"))
	FFortNearbyActorsPerceptionConfiguration PerceptionConfiguration;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotEvaluator_ReactToVerb", meta=(AllowPrivateAccess="true"))
	bool bIsHighPriorityEvaluator;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotEvaluator_ReactToVerb", meta=(AllowPrivateAccess="true"))
	FScalableFloat ReactToEmotes;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ReactToVerbTargetActorKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ReactToVerbShouldMoveKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName GameplayEffectReactionKeyName;

};

