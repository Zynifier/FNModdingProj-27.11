// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_ObjectiveGate.generated.h"

UCLASS(meta=(Hidden))
class UFortGameplayAbility_ObjectiveGate : public UFortGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="GateControl")
	bool BlueprintCanGateClose(const FName ObjectiveBackendName) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="GateControl")
	bool BlueprintCanGateOpen(const FName ObjectiveBackendName) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="GateControl")
	void CloseGates() const;

	UFUNCTION(BlueprintImplementableEvent, Category="GateControl")
	void GateStateChangedEvent(const bool bGateIsOpen, const FName ObjectiveBackendName) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="GateControl")
	void OpenGates() const;

};

