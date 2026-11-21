// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_Skull_Brite_FaceAcc.generated.h"

class AFortPlayerPawn;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_Skull_Brite_FaceAcc : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Skull_Brite_FaceAcc")
	float JumpStrapAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Skull_Brite_FaceAcc")
	float PawnSpeed;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Skull_Brite_FaceAcc")
	float StrapRotAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Skull_Brite_FaceAcc")
	float StrapsStandingAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Skull_Brite_FaceAcc")
	float StrapsStandRot;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Skull_Brite_FaceAcc")
	bool bIsStandingStill;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Skull_Brite_FaceAcc")
	bool bIsMovingBackward;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Skull_Brite_FaceAcc")
	FVector JumpVector;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Skull_Brite_FaceAcc")
	FVector StrapsVector;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Skull_Brite_FaceAcc")
	FVector HairVector;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Skull_Brite_FaceAcc")
	FVector StrapsForceVector;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Skull_Brite_FaceAcc")
	TObjectPtr<AFortPlayerPawn> PlayerPawn;

};

