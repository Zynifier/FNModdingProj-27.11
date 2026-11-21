// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortFirstPersonProceduralAnimInstance.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortFirstPersonProceduralAnimInstance : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FirstPerson")
	FName RightHandName;

	UPROPERTY(EditDefaultsOnly, Category="FirstPerson")
	FName LeftHandName;

	UPROPERTY(EditDefaultsOnly, Category="FirstPerson")
	FName RightShoulderName;

	UPROPERTY(EditDefaultsOnly, Category="FirstPerson")
	FName LeftShoulderName;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	FVector FPLeftShoulderTarget;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	FRotator FPLeftShoulderRotator;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	FVector FPRightShoulderTarget;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	FRotator FPRightShoulderRotator;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	FVector FPLeftElbowTarget;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	FRotator FPLeftElbowRotator;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	FVector FPRightElbowTarget;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	FRotator FPRightElbowRotator;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	FTransform PreUpdateLeftHand;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	FTransform PreUpdateRightHand;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	FTransform PreUpdateLeftElbow;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	FTransform PreUpdateRightElbow;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	FTransform PreUpdateLeftShoulder;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	FTransform PreUpdateRightShoulder;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	FTransform PreUpdateHead;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	FTransform PreUpdateWeaponRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	FTransform PreUpdateSpine;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	float FPHandIKWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	FRotator FPBodyLean;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	FVector FPBodyOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FirstPerson")
	float FPBodyLeanWeight;

};

