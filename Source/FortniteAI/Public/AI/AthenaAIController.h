// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "AI/FortAIController.h"
#include "AI/FortAIPerceptionComponent.h"
#include "AI/FortBehaviorTreeComponent.h"
#include "AthenaAIController.generated.h"

class AActor;
class UAthenaPathFollowingComponent;
class UFortAthenaAIRuntimeParametersComponent;
class UFortGameplayAbility;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Collision", "Rendering", "Transformation"))
class AAthenaAIController : public AFortAIController
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UFortGameplayAbility> PrimaryMeleeAttackAbilityInstance;

	UPROPERTY()
	TObjectPtr<UFortGameplayAbility> PrimaryRangedAttackAbilityInstance;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Flying")
	FVector NavWalkingSearchExtentScale;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Flying")
	float CheapFlyingNavPointHorizontalGridRatio;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Flying")
	float CheapFlyingNavNavPointVerticalGridRatio;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Flying", meta=(EditCondition="bEnableFlying"))
	FGameplayTagContainer CheapFlyingNavSmashableAbilityTag;

	UPROPERTY(EditDefaultsOnly, Category="Flying")
	uint8 bEnableCheapFlyingNavigation : 1;

	UPROPERTY(EditDefaultsOnly, Category="AthenaAIController")
	uint8 bAllowBacktrackPathfinding : 1;

	UPROPERTY(EditDefaultsOnly, Category="AthenaAIController")
	uint8 bIsGoalRequiredForBehavior : 1;

	UPROPERTY(EditDefaultsOnly, Category="AthenaAIController")
	uint8 bAutomaticallyChooseClosestTargetAsGoal : 1;

	UPROPERTY(EditDefaultsOnly, Category="AthenaAIController")
	uint8 bAutoGenerateHotspotOnPlayerBuildings : 1;

	UPROPERTY(EditDefaultsOnly, Category="AthenaAIController")
	uint8 bAutoAttackOnMovedHit : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Optimisation")
	uint8 bRegisterToAthenaAIDropper : 1;

	UPROPERTY()
	TObjectPtr<AActor> SecondaryGoalActor;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaPathFollowingComponent> AthenaPFC;

};

UCLASS(HideCategories=("Activation", "Collision"), ClassGroup=("AI"), meta=(BlueprintSpawnableComponent))
class UAthenaAIPerceptionComponent : public UFortAIPerceptionComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="AthenaAIPerceptionComponent", meta=(AllowPrivateAccess="true"))
	TWeakObjectPtr<UFortAthenaAIRuntimeParametersComponent> CachedAIRuntimeParametersComponent;

};

UCLASS(MinimalAPI, HideCategories=("Sockets", "Collision"))
class UAthenaBehaviorTreeComponent : public UFortBehaviorTreeComponent
{
	GENERATED_BODY()

};

