// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_StrawberryPilotFace.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_StrawberryPilotFace : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_StrawberryPilotFace")
	float HeadSwingDeltaValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_StrawberryPilotFace")
	float ArmSwingDeltaLValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_StrawberryPilotFace")
	float ArmSwingDeltaRValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_StrawberryPilotFace")
	float HeadTwistLValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_StrawberryPilotFace")
	float HeadTwistRValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_StrawberryPilotFace")
	float HeadSwingDeltaTargetLValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_StrawberryPilotFace")
	float HeadSwingDeltaTargetRValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	FVector2D ArmSwingDeltaLInRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	FVector2D ArmSwingDeltaLOutRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	FVector2D ArmSwingDeltaRInRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	FVector2D ArmSwingDeltaROutRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	FVector2D HeadSwingDeltaInRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	FVector2D HeadSwingDeltaOutRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	FVector2D HeadTwistRInRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	FVector2D HeadTwistROutRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	FVector2D HeadTwistLInRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	FVector2D HeadTwistLOutRange;

};

