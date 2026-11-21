// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_JerkyUniverseBody.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_JerkyUniverseBody : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_JerkyUniverseBody")
	FVector WindVector;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_JerkyUniverseBody")
	float SkydiveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_JerkyUniverseBody")
	FRotator RotCoat0;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_JerkyUniverseBody")
	FRotator RotCoat1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_JerkyUniverseBody")
	FRotator RotCoat2;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_JerkyUniverseBody")
	FRotator RotCoat3;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_JerkyUniverseBody")
	FRotator RotCoat4;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_JerkyUniverseBody")
	FRotator RotCoat5;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_JerkyUniverseBody")
	FRotator RotCoat6;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_JerkyUniverseBody")
	bool bDisableRigidBodies;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_JerkyUniverseBody")
	float LOD2MovingAndCrouchAlpha;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CustomCharacterPartAnimInstance_JerkyUniverseBody")
	float SkydivingVectorForceMultiplier;

};

