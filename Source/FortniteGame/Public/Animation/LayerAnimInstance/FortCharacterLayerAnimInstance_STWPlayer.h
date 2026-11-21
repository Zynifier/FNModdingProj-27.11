// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInputs/FortAnimInput_STWHoverboard.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortGender.h"
#include "FortCharacterLayerAnimInstance_STWPlayer.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortCharacterLayerAnimInstance_STWPlayer : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCharacterLayerAnimInstance_STWPlayer")
	FFortAnimInput_STWHoverBoard HoverBoardInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCharacterLayerAnimInstance_STWPlayer")
	float LeanAdditiveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCharacterLayerAnimInstance_STWPlayer")
	float LeanAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCharacterLayerAnimInstance_STWPlayer")
	float Speed2D;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCharacterLayerAnimInstance_STWPlayer")
	float LocalVelocityYawAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCharacterLayerAnimInstance_STWPlayer")
	TEnumAsByte<EFortCustomGender::Type> Gender;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCharacterLayerAnimInstance_STWPlayer")
	bool bIsSlopeSliding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCharacterLayerAnimInstance_STWPlayer")
	bool bIsOnGround;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCharacterLayerAnimInstance_STWPlayer")
	bool bLandingPredicted;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCharacterLayerAnimInstance_STWPlayer")
	bool bIsFalling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCharacterLayerAnimInstance_STWPlayer")
	bool bIsJumping;

};

