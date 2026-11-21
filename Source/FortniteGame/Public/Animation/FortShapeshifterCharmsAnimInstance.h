// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "FortShapeshifterCharmsAnimInstance.generated.h"

class AFortPlayerPawn;
class USkeletalMeshComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortShapeshifterCharmsAnimInstance : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortShapeshifterCharmsAnimInstance")
	uint8 bTransition_IdleAdditive_to_SwimJumpStart : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortShapeshifterCharmsAnimInstance")
	float SwimmingSprintYawDeltaRatePerSecondSmooth;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortShapeshifterCharmsAnimInstance")
	float SwimmingVelocityAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortShapeshifterCharmsAnimInstance")
	float SwimmingSpeedRelativeToFlow;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortShapeshifterCharmsAnimInstance")
	float SwimmingDivePitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortShapeshifterCharmsAnimInstance")
	float SwimmingYawDeltaRatePerSecond;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortShapeshifterCharmsAnimInstance")
	float SwimmingDivePitchDeltaRatePerSec;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortShapeshifterCharmsAnimInstance")
	float Speed2D;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortShapeshifterCharmsAnimInstance")
	uint8 bIsDiveJumping : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortShapeshifterCharmsAnimInstance")
	uint8 bTransition_SwimSprint_to_SwimSprintSlow : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortShapeshifterCharmsAnimInstance")
	uint8 bTransition_SwimSprintSlow_to_SwimSprint : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortShapeshifterCharmsAnimInstance")
	uint8 bTransition_SwimSprintSlow_to_SwimSprintStart : 1;

private:
	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerPawn> FortPlayerPawn;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> PawnSkeletalMesh;

};

