// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "FortControllerComponent_QuestGates.generated.h"

class UFortGameplayAbility_ObjectiveGate;

USTRUCT()
struct FGateRegistry
{
	GENERATED_BODY()

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_QuestGates : public UControllerComponent
{
	GENERATED_BODY()

public:
	UFortControllerComponent_QuestGates(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY()
	TMap<TSubclassOf<UFortGameplayAbility_ObjectiveGate>, FGateRegistry> GateRegistry;

};

