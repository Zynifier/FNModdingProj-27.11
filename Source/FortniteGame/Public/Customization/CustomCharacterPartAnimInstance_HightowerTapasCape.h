// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_HightowerTapasCape.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_HightowerTapasCape : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector PelvisLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector ThighLeftLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector ThighRightLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector CalfLeftLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector CalfRightLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector BodyRootLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector Spine05Location;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector ClavicleRightLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector ClavicleLeftLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector UpperarmLeftLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector UpperarmRightLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector LowerarmLeftLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector LowerarmRightLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector Spine01Location;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector Spine02Location;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector Spine03Location;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector Spine04Location;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector FinalGravity;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector CompLinearAccelarationScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FVector CompLinearVelocityScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FRotator PelvisRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FRotator ThighLeftRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FRotator ThighRightRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FRotator CalfLeftRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FRotator CalfRightRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FRotator BodyRootRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FRotator Spine05Rotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FRotator ClavicleRightRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FRotator ClavicleLeftRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FRotator UpperarmLeftRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FRotator UpperarmRightRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FRotator LowerarmLeftRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FRotator LowerarmRightRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FRotator Spine01Rotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FRotator Spine02Rotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FRotator Spine03Rotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	FRotator Spine04Rotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_HightowerTapasCape")
	float RigidBodyAlpha;

};

