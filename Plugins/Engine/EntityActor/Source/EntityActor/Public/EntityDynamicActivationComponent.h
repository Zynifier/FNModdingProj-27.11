// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EntityEnableableComponent.h"
#include "EntityDynamicActivationComponent.generated.h"

class UEntityComponent;

UCLASS(meta=(DisplayName="Dynamic Activation Component"))
class ENTITYACTOR_API UEntityDynamicActivationComponent : public UEntityEnableableComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnEnabledChanged(bool bIsEnabled);

private:
	UFUNCTION()
	void OnRep_TransitionTarget();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_TransitionTarget)
	float TransitionTargetTime;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_TransitionTarget)
	bool bTargetState;

	UPROPERTY(Transient, Replicated)
	TArray<TObjectPtr<UEntityComponent>> LinkedComponents;

};

