// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortLocomotionAnimSet.generated.h"

class UAnimSequenceBase;
class UBlendSpace;

USTRUCT(BlueprintType)
struct FFortLocomotionAnimSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	bool EnableAdditiveLeans;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	bool UseMovementAdditiveForOneHandedTransitions;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	bool PlayMovementTransitions;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UBlendSpace* MovementBlendSpaceTargeting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UBlendSpace* MovementBlendSpaceTargetingRightFootForward;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UBlendSpace* MovementBlendSpace;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UBlendSpace* MovementBlendSpaceNo45s;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* Start_N;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* Start_S;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* Start_E;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* Start_W;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* Stop_N;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* Stop_S;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* Stop_E;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* Stop_W;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* Pivot_N;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* Pivot_S;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* Pivot_E;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* Pivot_W;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UBlendSpace* CrouchAdditiveLean;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UBlendSpace* AdditiveLean;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* AdditiveStart_N;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* AdditiveStart_S;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* AdditiveStart_E;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* AdditiveStart_W;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* AdditiveStop_N;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* AdditiveStop_S;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* AdditiveStop_E;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* AdditiveStop_W;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* AdditivePivot_N;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* AdditivePivot_S;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* AdditivePivot_E;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionAnimSet")
	UAnimSequenceBase* AdditivePivot_W;

};

