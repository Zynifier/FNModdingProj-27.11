// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAIFaunaAnimInstance.h"
#include "FortAIFaunaAnimInstance_Labrador.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortAIFaunaAnimInstance_Labrador : public UFortAIFaunaAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Labrador Transient Properties")
	bool bHighVelocity;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Labrador Transient Properties")
	bool bIsInterruptible;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Labrador Transient Properties")
	bool bLocoToIdle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Labrador Transient Properties")
	bool bIdleToLoco;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Labrador Transient Properties")
	bool bJumpStartToJumpLoop;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Labrador Transient Properties")
	bool bJumpLandToMovement;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Labrador Transient Properties")
	bool bIsRunning;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Labrador Transient Properties")
	bool bIdleToFalling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Labrador Transient Properties")
	bool bToppledOnGround;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Labrador Transient Properties")
	bool bTransitionToLand;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Labrador Transient Properties")
	float TargetDistance;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Labrador Transient Properties")
	bool bTargetIsClose;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Labrador Transient Properties")
	bool bIsToppled;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Labrador Transient Properties")
	bool bIsLeaking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Labrador Configuration Properties")
	float MinHighVelocityMagnitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Labrador Configuration Properties")
	float MaxInterruptibleCurveValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Labrador Configuration Properties")
	float LocoIdleTransitionThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Labrador Configuration Properties")
	float RunSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Labrador Configuration Properties")
	float JumpLandToMovementInterruptibleThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Labrador Configuration Properties")
	float MinTargetIsCloseDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Labrador Curve Names")
	FName CurveName_Interruptible;

};

