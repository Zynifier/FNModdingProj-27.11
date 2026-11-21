// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "ControllerStateComponent.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStateChanged, FString&, State, bool, Active);

/**
 * ControllerStateComponent interacts with actor controllers and replicates state from the server to the host where the player controller
 * is being driven from
 */
UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class VGAMEPLAYRST_API UControllerStateComponent : public UControllerComponent
{
	GENERATED_BODY()

public:
	UControllerStateComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	// Called when state changes as a result of replication

	UFUNCTION()
	void OnRep_ActiveStates();

	// Replicated list of active states

	UPROPERTY(ReplicatedUsing=OnRep_ActiveStates)
	TArray<FString> ActiveStates;

};

