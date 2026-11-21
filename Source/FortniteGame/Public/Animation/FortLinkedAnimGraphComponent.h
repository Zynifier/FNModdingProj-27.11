// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Animation/FortLinkedAnimGraphsData.h"
#include "FortLinkedAnimGraphComponent.generated.h"

class UAnimInstance;
class UAnimLayerInterface;

UCLASS(BlueprintType, Blueprintable, HideCategories=("ComponentTick", "ComponentReplication", "Replication", "Events", "Activation", "Cooking", "AssetUserData", "Collision", "Sockets", "Tags"))
class UFortLinkedAnimGraphComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRep_WindAnimLayer(const TSubclassOf<UAnimInstance> AnimLayer);

	UPROPERTY(EditDefaultsOnly, Category="Animation")
	FFortLinkedAnimGraphsData LinkedGraphsData;

	UPROPERTY(EditDefaultsOnly, Category="Animation")
	TSubclassOf<UAnimLayerInterface> MovementModeInterface;

	UPROPERTY(EditDefaultsOnly, Category="Debug")
	TSubclassOf<UAnimInstance> DebugGraphClass;

	UPROPERTY(EditDefaultsOnly, Category="Animation")
	float FullBodyAdditiveDeactivationTime;

	UPROPERTY(Transient)
	TSubclassOf<UAnimInstance> CurrentFullBodyAdditiveClass;

	UPROPERTY(Transient)
	TSubclassOf<UAnimInstance> CurrentFullBodyStateClass;

	UPROPERTY(Transient)
	TArray<TSubclassOf<UAnimInstance>> MovementModeLayerStack;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_WindAnimLayer)
	TSubclassOf<UAnimInstance> WindAnimLayer;

};

