// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortPetOffsets.generated.h"

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortPetOffsets
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortPetOffsets")
	FVector DefaultIdle;

	UPROPERTY(EditAnywhere, Category="FortPetOffsets")
	FVector DefaultDownsights;

	UPROPERTY(EditAnywhere, Category="FortPetOffsets")
	FVector CrouchIdle;

	UPROPERTY(EditAnywhere, Category="FortPetOffsets")
	FVector CrouchDownsights;

	UPROPERTY(EditAnywhere, Category="FortPetOffsets")
	FVector DBNOIdle;

	UPROPERTY(EditAnywhere, Category="FortPetOffsets")
	FVector MeleePlaying;

	UPROPERTY(EditAnywhere, Category="FortPetOffsets")
	FVector EmotePlaying;

	UPROPERTY(EditAnywhere, Category="FortPetOffsets")
	FVector DefaultSkydive;

	UPROPERTY(EditAnywhere, Category="FortPetOffsets")
	FVector SurfaceSwimmingIdle;

	UPROPERTY(EditAnywhere, Category="FortPetOffsets")
	FVector SurfaceSwimmingDownsights;

	UPROPERTY(EditAnywhere, Category="FortPetOffsets")
	FVector SurfaceSwimmingMeleePlaying;

	UPROPERTY(EditAnywhere, Category="FortPetOffsets")
	FVector DiveJumping;

	UPROPERTY(EditAnywhere, Category="FortPetOffsets")
	FVector CrouchTurning;

	UPROPERTY(EditAnywhere, Category="FortPetOffsets")
	FVector DivingSkydive;

};

