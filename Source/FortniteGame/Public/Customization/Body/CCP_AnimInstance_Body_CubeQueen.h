// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CCP_AnimInstance_Body_CubeQueen.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCCP_AnimInstance_Body_CubeQueen : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Cube Queen|Event Graph|Native Booleans")
	bool bIsCrouchMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cube Queen|Event Graph|Native Booleans")
	bool bIsCrouchIdling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cube Queen|Event Graph|Native Floats")
	float ClavL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cube Queen|Event Graph|Native Floats")
	float ClavR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cube Queen|Event Graph|Native Floats")
	float CrouchMovingAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cube Queen|Event Graph|Native Floats")
	float CrouchSprintingAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cube Queen|Event Graph|Native Floats")
	float RigidBodyEnabledAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Event Graph|Magic Floats")
	float CrouchMovingAlphaTrue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Event Graph|Magic Floats")
	float CrouchMovingAlphaFalse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Event Graph|Magic Floats")
	float CrouchMovingAlphaInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Event Graph|Magic Floats")
	float CrouchSprintingAlphaTrue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Event Graph|Magic Floats")
	float CrouchSprintingAlphaFalse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Event Graph|Magic Floats")
	float RigidBodyEnabledAlphaTrue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Event Graph|Magic Floats")
	float RigidBodyEnabledAlphaFalse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Event Graph|Magic Floats|ClavR Map Range")
	float ClavRInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Event Graph|Magic Floats|ClavR Map Range")
	float ClavRInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Event Graph|Magic Floats|ClavR Map Range")
	float ClavROutRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Event Graph|Magic Floats|ClavR Map Range")
	float ClavROutRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Event Graph|Magic Floats|ClavL Map Range")
	float ClavLInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Event Graph|Magic Floats|ClavL Map Range")
	float ClavLInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Event Graph|Magic Floats|ClavL Map Range")
	float ClavLOutRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Event Graph|Magic Floats|ClavL Map Range")
	float ClavLOutRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Event Graph|Magic Names")
	FName ClavRSourceBone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Event Graph|Magic Names")
	FName ClavRBaseBone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Event Graph|Magic Names")
	FName ClavLSourceBone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Event Graph|Magic Names")
	FName ClavLBaseBone;

};

