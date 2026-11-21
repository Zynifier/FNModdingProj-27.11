// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_Whiff_Cape.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_Whiff_Cape : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FVector CalculateDanceGravity();

	UFUNCTION(BlueprintCallable)
	void CollectFinalWindGravity();

	UFUNCTION(BlueprintCallable)
	void CollectWindVector();

	UFUNCTION(BlueprintCallable)
	void SetCompLinearScaleForSkydiving();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Whiff_Cape")
	float SkydivingVectorForceScalingFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Whiff_Cape")
	FVector DanceYawGravityPositive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Whiff_Cape")
	FVector DanceYawGravityNegative;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Whiff_Cape")
	FVector NonSkyDivingWind;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Whiff_Cape")
	FVector SkydivingScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CustomCharacterPartAnimInstance_Whiff_Cape")
	FVector NonSkyDivingScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_Whiff_Cape")
	bool bIsInTheAir;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_Whiff_Cape")
	FVector WindVector;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_Whiff_Cape")
	FVector FinalGravity;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_Whiff_Cape")
	FVector CompLinearVelScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_Whiff_Cape")
	FVector CompLinearAccScale;

};

