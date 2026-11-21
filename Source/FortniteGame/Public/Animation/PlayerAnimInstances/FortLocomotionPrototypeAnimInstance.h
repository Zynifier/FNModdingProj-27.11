// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/PlayerAnimInstances/FortPlayerAnimInstanceProxy.h"
#include "FortLocomotionPrototypeAnimInstance.generated.h"

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FFortLocomotionStateMachineChildInput
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineChildInput")
	float TurnWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineChildInput")
	float MovementWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineChildInput")
	float StartWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineChildInput")
	float PivotWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineChildInput")
	float StopWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineChildInput")
	float TurnExplicitTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineChildInput")
	float MovementExplicitTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineChildInput")
	float StartExplicitTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineChildInput")
	float PivotExplicitTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionStateMachineChildInput")
	float StopExplicitTime;

};

UCLASS(HideCategories=("AnimInstance"))
class FORTNITEGAME_API UFortLocomotionPrototypeAnimInstance : public UFortPlayerAnimInstanceProxy
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	FFortLocomotionStateMachineChildInput LocomotionStateMachineChildInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLocomotionPrototypeAnimInstance")
	float OrientationWarpingYawAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	bool bEnableDistanceMatching;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Config")
	bool bUseAltLayerSetup;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	bool bUseEightDirectionLocomotion;

};

