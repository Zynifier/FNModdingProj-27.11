// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "FortAbilityTask_CommitAccountCosts.generated.h"

class UFortAbilityTask_CommitAccountCosts;
class UGameplayAbility;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCommitAccountCostsDelegate);

UCLASS()
class UFortAbilityTask_CommitAccountCosts : public UAbilityTask
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta=(BlueprintInternalUseOnly="TRUE", DefaultToSelf="OwningAbility", DisplayName="Commit Account Costs", HidePin="OwningAbility"))
	static UFortAbilityTask_CommitAccountCosts* CommitAccountCosts(UGameplayAbility* OwningAbility);

	UPROPERTY(BlueprintAssignable)
	FCommitAccountCostsDelegate OnCommitted;

	UPROPERTY(BlueprintAssignable)
	FCommitAccountCostsDelegate OnFailed;

private:
	UPROPERTY(Transient)
	bool bWasCancellable;

	UPROPERTY(Transient)
	bool bRequestPending;

	UPROPERTY(Transient)
	bool bCommittedLocally;

	UPROPERTY(Transient)
	FString PlayerName;

	UPROPERTY(Transient)
	FString AbilityName;

};

