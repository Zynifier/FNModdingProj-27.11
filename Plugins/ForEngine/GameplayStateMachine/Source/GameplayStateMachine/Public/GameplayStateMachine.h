// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayState.h"
#include "GameplayStateMachine.generated.h"

class UGameplayState;

USTRUCT(BlueprintType)
struct GAMEPLAYSTATEMACHINE_API FActiveGameplayStateData
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<UGameplayState> GameplayState;

	UPROPERTY(Transient)
	FGameplayTag PreviousStateId;

	UPROPERTY(Transient)
	float BeginStateDelay;

	UPROPERTY(Transient)
	float InitializationTime;

};

USTRUCT(BlueprintType)
struct GAMEPLAYSTATEMACHINE_API FGameplayStateTransition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="GameplayStateMachine")
	FGameplayTagContainer TransitionConditionTags;

	UPROPERTY(EditDefaultsOnly, Category="GameplayStateMachine")
	FGameplayTag TransitionStateTag;

	UPROPERTY(EditDefaultsOnly, Category="GameplayStateMachine")
	float BeginStateDelay;

};

USTRUCT(BlueprintType)
struct GAMEPLAYSTATEMACHINE_API FGameplayStateSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="GameplayStateMachine")
	TSubclassOf<UGameplayState> StateClass;

	UPROPERTY(EditDefaultsOnly, Category="GameplayStateMachine")
	FGameplayTag StateId;

	UPROPERTY(EditDefaultsOnly, Category="GameplayStateMachine")
	TArray<FGameplayStateTransition> StateTransitions;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class GAMEPLAYSTATEMACHINE_API UGameplayStateMachine : public UGameplayState
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="GameplayStateMachine")
	FGameplayTag GetActiveStateId() const;

	UFUNCTION(BlueprintPure, Category="GameplayStateMachine")
	UGameplayState* GetActiveStateObject() const;

	UFUNCTION(BlueprintPure, Category="GameplayStateMachine", meta=(BlueprintGetter))
	FGameplayTag GetStateMachineId() const;

	UFUNCTION(BlueprintCallable, Category="GameplayStateMachine")
	void SetState(const FGameplayTag& InStateId, float InBeginStateDelay);

protected:
	UFUNCTION(BlueprintNativeEvent, Category="GameplayStateMachine")
	void EvaluateStateTransition();

	UPROPERTY(EditAnywhere, BlueprintGetter=GetStateMachineId, Replicated, Category="GameplayStateMachine")
	FGameplayTag StateMachineId;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ActiveGameplayStateData)
	FActiveGameplayStateData ActiveGameplayStateData;

	UPROPERTY(EditDefaultsOnly, Category="GameplayStateMachine")
	TArray<FGameplayStateSettings> GameplayStateSettings;

	UPROPERTY(EditDefaultsOnly, Category="GameplayStateMachine")
	FGameplayTag InitialGameplayStateId;

private:
	UFUNCTION()
	void OnRep_ActiveGameplayStateData();

};

