// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_Shapeshifter_Medusa.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActivateTargetingDelegate, bool, bIsTargeting);

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_Shapeshifter_Medusa : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FActivateTargetingDelegate ActivateTargeting;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Shapeshifter_Medusa")
	FVector GravityOverride;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_Shapeshifter_Medusa")
	FVector HairBandScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_Shapeshifter_Medusa")
	FVector HairScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_Shapeshifter_Medusa")
	FVector HairScaleInterp;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_Shapeshifter_Medusa")
	FVector SnakeBandScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_Shapeshifter_Medusa")
	FVector SnakeHairScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_Shapeshifter_Medusa")
	FVector SnakeHairScaleInterp;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Shapeshifter_Medusa")
	float BackBlingAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_Shapeshifter_Medusa")
	float HairRbanAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_Shapeshifter_Medusa")
	float HairRbanAlphaInterp;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_Shapeshifter_Medusa")
	float PawnMovementDirectionAzimuth2;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_Shapeshifter_Medusa")
	float RigidsAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_Shapeshifter_Medusa")
	float ScaleAnimExplicitTime;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Shapeshifter_Medusa")
	bool bDisableSnakes;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Shapeshifter_Medusa")
	bool bIsReactivePreviewSnakesFromAds;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_Shapeshifter_Medusa")
	bool bIsMedusaTargeting;

};

