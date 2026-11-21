// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAIFaunaAnimInstance.h"
#include "FortAIFaunaAnimInstance_Crow.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortAIFaunaAnimInstance_Crow : public UFortAIFaunaAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Crow|Event Graph|Native Floats")
	float WingFlapPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Crow|Event Graph|Native Booleans")
	bool bIsDescending;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Crow|Event Graph|Native Booleans")
	bool bIsGliding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Crow|Event Graph|Native Booleans")
	bool bIsFlying;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Crow|Event Graph|Native Booleans")
	bool bIsFlyingSlow;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Crow|Event Graph|Native Booleans")
	bool bIsLanding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crow|Event Graph|Magic Floats|Wing Flap Play Rate Range")
	float WingFlapPlayRateInRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crow|Event Graph|Magic Floats|Wing Flap Play Rate Range")
	float WingFlapPlayRateInRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crow|Event Graph|Magic Floats|Wing Flap Play Rate Range")
	float WingFlapPlayRateOutRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crow|Event Graph|Magic Floats|Wing Flap Play Rate Range")
	float WingFlapPlayRateOutRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crow|Event Graph|Magic Floats")
	float ZVelocityDescendingThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crow|Event Graph|Magic Floats")
	float GlidingSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crow|Event Graph|Magic Floats")
	float FlyingSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crow|Event Graph|Magic Floats")
	float FlyingSlowSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crow|Event Graph|Magic Floats")
	float LandingSpeedThreshold;

};

