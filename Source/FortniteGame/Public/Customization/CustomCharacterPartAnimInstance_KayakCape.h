// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_KayakCape.generated.h"

class USkeletalMeshComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_KayakCape : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Export, Category="CustomCharacterPartAnimInstance_KayakCape", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> HeadMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_KayakCape")
	FVector CapeTrailFakeVelocityLowLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_KayakCape")
	FVector CapeTrailFakeVelocityMidLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_KayakCape")
	FVector CapeTrailFakeVelocityMidRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_KayakCape")
	FVector CapeTrailFakeVelocityLowRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_KayakCape")
	FVector CapeGravityOverride;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_KayakCape")
	FVector HoodGravityOverride;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_KayakCape")
	FRotator HeadRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_KayakCape")
	float CapeTrailRelaxSpeedScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_KayakCape")
	float PlayerForwardAcceleration;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_KayakCape")
	float UpperArmRightAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_KayakCape")
	float UpperArmLeftAlpha;

};

