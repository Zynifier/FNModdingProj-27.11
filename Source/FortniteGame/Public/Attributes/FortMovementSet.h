// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "FortMovementSet.generated.h"

UCLASS(BlueprintType)
class UFortMovementSet : public UFortAttributeSet
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_SpeedMultiplier(const FFortGameplayAttributeData& OldValue);

private:
	UPROPERTY(BlueprintReadOnly, Replicated, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WalkSpeed;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData RunSpeed;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData SprintSpeed;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData FlySpeed;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData CrouchedRunSpeed;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData CrouchedSprintSpeed;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData BackwardSpeedMultiplier;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData JumpHeight;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData GravityZScale;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData VehicleGravityZScale;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_SpeedMultiplier, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData SpeedMultiplier;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData LandSpeedMultiplier;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData SwimSpeedMultiplier;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData LandSpeedWhileBlobMultiplier;

	UPROPERTY(BlueprintReadOnly, Category="Movement", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData FootstepStimRangeMultiplier;

};

