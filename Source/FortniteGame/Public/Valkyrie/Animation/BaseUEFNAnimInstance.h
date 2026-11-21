// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Math/MathFwd.h"
#include "BaseUEFNAnimInstance.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UBaseUEFNAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Pawn")
	FVector PawnVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Pawn")
	float PawnSpeedXY;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Pawn")
	float PawnVelocityZ;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Pawn")
	FVector PawnLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Pawn")
	FRotator PawnRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Pawn")
	FVector PawnForwardVector;

};

