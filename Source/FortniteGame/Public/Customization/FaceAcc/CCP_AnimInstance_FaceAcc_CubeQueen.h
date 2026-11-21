// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CCP_AnimInstance_FaceAcc_CubeQueen.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCCP_AnimInstance_FaceAcc_CubeQueen : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Cube Queen|Native Booleans")
	bool bSnapBack;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cube Queen|Native Booleans")
	bool bWearingBackbling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cube Queen|Native Booleans")
	bool bBackblingGlider;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cube Queen|Native Floats")
	float IsTargeting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cube Queen|Native Floats")
	float BackblingAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cube Queen|Native Floats")
	float IsWearingCape;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cube Queen|Native Floats")
	float CapeAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Magic Tags")
	FGameplayTagContainer BackpackGliderTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Magic Floats")
	float LongBackblingThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Magic Floats")
	float CapeAlphaScaler;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Magic Floats")
	float IsTargetingValue_True;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Magic Floats")
	float IsTargetingValue_False;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Magic Floats")
	float BackblingAlpha_True;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cube Queen|Magic Floats")
	float BackblingAlpha_False;

};

