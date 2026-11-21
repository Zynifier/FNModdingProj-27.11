// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingGameplayActorLockOnConsumable.h"
#include "BuildingGameplayActorBlade.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActorBlade : public ABuildingGameplayActorLockOnConsumable
{
	GENERATED_BODY()

public:
	UFUNCTION(NetMulticast, Reliable, BlueprintCallable)
	void BroadcastOnPullAborted();

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable)
	void BroadcastOnPullStart();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPullAborted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPullStart();

};

