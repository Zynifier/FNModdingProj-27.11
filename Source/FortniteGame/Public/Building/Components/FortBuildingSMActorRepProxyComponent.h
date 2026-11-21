// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "GameplayCueInterface.h"
#include "FortBuildingSMActorRepProxyComponent.generated.h"

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortBuildingSMActorRepProxyComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UFortBuildingSMActorRepProxyComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UFUNCTION()
	void HandleBuildingAbilitySystemComponentInitialized();

	UPROPERTY(Replicated)
	FMinimalGameplayCueReplicationProxy SimulatedProxyActiveGameplayCues;

};

