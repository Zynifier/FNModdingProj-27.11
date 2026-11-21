// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimationBlueprintLibrary.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CCP_AnimInstance_FaceAcc_CritterCuddle.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCCP_AnimInstance_FaceAcc_CritterCuddle : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Critter Cuddle|Native Floats")
	float EyeForward;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Critter Cuddle|Native Floats")
	float EyeBackward;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Critter Cuddle|Native Floats")
	float BodyRotationLeft;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Critter Cuddle|Native Floats")
	float BodyRotationRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Critter Cuddle|Native Booleans")
	bool bIsMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Critter Cuddle|Native Booleans")
	bool bIsNotTargeting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Critter Cuddle|Delay Timer")
	float CurrentEyeDartTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Critter Cuddle|Delay Timer")
	float CurrentEyeDartDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Names")
	FName LeftRotationSourceBone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Names")
	FName LeftRotationBaseBone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Names")
	FName RightRotationSourceBone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Names")
	FName RightRotationBaseBone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Enums")
	TEnumAsByte<EAlphaFromDeltaTypes::Type> LeftRotationDeltaComponentType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Enums")
	TEnumAsByte<EAlphaFromDeltaTypes::Type> RightRotationDeltaComponentType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Structs")
	FVector2D LeftRotationInputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Structs")
	FVector2D LeftRotationOutputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Structs")
	FVector2D RightRotationInputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Structs")
	FVector2D RightRotationOutputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Vectors")
	FVector LeftRotationTwistAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Vectors")
	FVector RightRotationTwistAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Floats")
	float EyeDelayMaximum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Floats")
	float EyeDelayMinimum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Floats")
	float EyeMoveMaximum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Critter Cuddle|Magic Floats")
	float EyeMoveMinimum;

};

