// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortBaseAnimInstance.h"
#include "FortBaseAnimInstance_CageSaddle.generated.h"

class AFortSphericalVehicle;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortBaseAnimInstance_CageSaddle : public UFortBaseAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Cage Saddle")
	TObjectPtr<AFortSphericalVehicle> AsFortSphericalVehicle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cage Saddle")
	bool bIsOnGround;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cage Saddle")
	float RemappedPitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cage Saddle")
	float CurrentRoll;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cage Saddle")
	float LockedRoll;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cage Saddle")
	bool bHeadShouldBend;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cage Saddle")
	bool bFootShouldBend;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cage Saddle|Settings")
	FVector BodyGroundOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cage Saddle|Settings")
	FVector2D MinClampPitchInRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cage Saddle|Settings")
	FVector2D MinClampPitchOutRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cage Saddle|Settings")
	FVector2D MaxClampPitchInRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cage Saddle|Settings")
	FVector2D MaxClampPitchOutRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cage Saddle|Settings")
	float HeadAlphaInterpSpeed;

};

