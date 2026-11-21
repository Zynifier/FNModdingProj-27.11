// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/FortPawnComponent.h"
#include "DynamicCapsuleComponent.generated.h"

USTRUCT()
struct FDynamicCapsuleState
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	float CapsuleRadius;

	UPROPERTY(Transient)
	float CapsuleHalfHeight;

	UPROPERTY(Transient)
	double RelativeMeshHeight;

};

USTRUCT()
struct FDynamicCapsuleEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FGameplayTag Tag;

	UPROPERTY(Transient)
	FDynamicCapsuleState State;

};

UCLASS(Config=Game, MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UDynamicCapsuleComponent : public UFortPawnComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Dynamic Capsule")
	bool ApplyDynamicCapsule(const FGameplayTag& Tag, float CapsuleRadius, float CapsuleHalfHeight);

	UFUNCTION(BlueprintCallable, Category="Dynamic Capsule")
	bool ApplyDynamicCapsuleWithLocationAdjust(const FGameplayTag& Tag, float CapsuleRadius, float CapsuleHalfHeight, double NewRelativeMeshHeight);

	UFUNCTION(BlueprintCallable, Category="Dynamic Capsule")
	bool RemoveDynamicCapsule(const FGameplayTag& Tag);

private:
	UFUNCTION()
	void OnRep_DynamicCapsuleEntryStack();

	UFUNCTION()
	void OnRep_ReplicatedCapsuleState();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerApplyDynamicCapsule(const FGameplayTag& Tag, float CapsuleRadius, float CapsuleHalfHeight, double NewRelativeMeshHeight);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerRemoveDynamicCapsule(const FGameplayTag& Tag);

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedCapsuleState)
	TArray<FDynamicCapsuleEntry> DynamicCapsuleEntryStack;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedCapsuleState)
	FDynamicCapsuleState ReplicatedCapsuleState;

};

