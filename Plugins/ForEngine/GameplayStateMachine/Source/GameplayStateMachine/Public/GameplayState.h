// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "GameplayState.generated.h"

class AActor;
class UGameplayState;
class UGameplayStateMachine;
class UGameplayStateMachineManager;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameplayStateInitialize, const FGameplayTag&, StateId);

UCLASS(Abstract, BlueprintType, Blueprintable)
class GAMEPLAYSTATEMACHINE_API UGameplayState : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddStateRuntimeTag(const FGameplayTag& AddedTag);

	UFUNCTION(BlueprintPure)
	UGameplayStateMachine* GetGameplayStateMachine() const;

	UFUNCTION(BlueprintPure)
	AActor* GetOwningActor() const;

	UFUNCTION(BlueprintPure, Category="GameplayState", meta=(BlueprintGetter))
	FGameplayTag GetStateId() const;

	UFUNCTION(BlueprintPure, Category="GameplayState")
	const FGameplayTagContainer& GetStateRuntimeTags() const;

	UFUNCTION(BlueprintPure)
	bool HasAuthority() const;

	UFUNCTION(BlueprintCallable)
	bool HasStateRuntimeTag(const FGameplayTag& QueryTag);

	UFUNCTION(BlueprintCallable)
	void MarkStateToEvaluateTransitions();

	UFUNCTION(BlueprintCallable)
	void RemoveStateRuntimeTag(const FGameplayTag& RemovedTag);

	UPROPERTY(Transient)
	TObjectPtr<UGameplayState> Hack_StateToDelayProcess;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="GameplayStateMachine", meta=(DisplayName="BeginState"))
	void BeginStateEvent(const FGameplayTag& PrevStateId);

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayStateMachine", meta=(DisplayName="BeginState Client"))
	void BeginStateEventClient(const FGameplayTag& PrevStateId);

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayStateMachine", meta=(DisplayName="BeginState Server"))
	void BeginStateEventServer(const FGameplayTag& PrevStateId);

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayStateMachine", meta=(DisplayName="EndState"))
	void EndStateEvent(const FGameplayTag& NextStateId);

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayStateMachine", meta=(DisplayName="EndState Client"))
	void EndStateEventClient(const FGameplayTag& NextStateId);

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayStateMachine", meta=(DisplayName="EndState Server"))
	void EndStateEventServer(const FGameplayTag& NextStateId);

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayStateMachine", meta=(DisplayName="InitializeState"))
	void InitializeStateEvent(const FGameplayTag& PrevStateId);

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayStateMachine", meta=(DisplayName="InitializeState Client"))
	void InitializeStateEventClient(const FGameplayTag& PrevStateId);

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayStateMachine", meta=(DisplayName="InitializeState Server"))
	void InitializeStateEventServer(const FGameplayTag& PrevStateId);

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayStateMachine", meta=(DisplayName="UpdateState"))
	void UpdateStateEvent(const float DeltaTime);

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayStateMachine", meta=(DisplayName="UpdateState Client"))
	void UpdateStateEventClient(const float DeltaTime);

	UFUNCTION(BlueprintImplementableEvent, Category="GameplayStateMachine", meta=(DisplayName="UpdateState Server"))
	void UpdateStateEventServer(const float DeltaTime);

	UPROPERTY(EditDefaultsOnly, BlueprintGetter=GetStateId, Replicated, Category="GameplayState")
	FGameplayTag StateId;

	UPROPERTY(Transient)
	FGameplayTagContainer StateRuntimeTags;

	UPROPERTY(Transient)
	bool bEvaluateTransition;

	UPROPERTY(EditDefaultsOnly, Category="GameplayState")
	bool bReplicates;

	UPROPERTY(Transient)
	bool bStateBegun;

	UPROPERTY(Transient)
	bool bStateEnded;

	UPROPERTY(Transient)
	float InitializationServerTime;

	UPROPERTY(Transient)
	float BeginStateDelay;

	UPROPERTY(Transient)
	TObjectPtr<UGameplayStateMachine> CachedGameplayStateMachine;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UGameplayStateMachineManager> CachedStateMachineManager;

};

