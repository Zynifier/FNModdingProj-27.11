// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "FortAdvancedMovementSet.generated.h"

UCLASS(BlueprintType)
class UFortAdvancedMovementSet : public UFortAttributeSet
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_BrakingDecelerationFalling(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_BrakingDecelerationFlying(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_BrakingDecelerationWalking(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_BrakingFrictionFactor(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_GroundFriction(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_JumpZVelocity(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxAcceleration(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxAccelerationFlying(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MinAnalogWalkSpeed(const FFortGameplayAttributeData& OldValue);

private:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_GroundFriction, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData GroundFriction;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_BrakingDecelerationWalking, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData BrakingDecelerationWalking;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_BrakingDecelerationFalling, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData BrakingDecelerationFalling;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_BrakingDecelerationFlying, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData BrakingDecelerationFlying;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxAcceleration, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData MaxAcceleration;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxAccelerationFlying, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData MaxAccelerationFlying;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_BrakingFrictionFactor, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData BrakingFrictionFactor;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_JumpZVelocity, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData JumpZVelocity;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData JumpHorizontalAccelerationOverride;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData JumpHorizontalVelocityOverride;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MinAnalogWalkSpeed, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData MinAnalogWalkSpeed;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData AirControlMultiplier;

};

