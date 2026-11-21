// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/PlayerAnimInstances/FortPlayerAnimInstanceProxy.h"
#include "FortPlayerAnimInstance_OctopusDriver.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPlayerAnimInstance_OctopusDriver : public UFortPlayerAnimInstanceProxy
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="OctopusDriver")
	FFortAnimInput_VelocityImpact VelocityImpact;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	FVector SeatLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	FRotator HandRotationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tunables")
	FRotator FootRotationOffset;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	FRotator SeatRotationPose;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	FVector HandAttachmentLocLeft;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	FRotator HandAttachmentRotLeft;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	FVector HandAttachmentLocRight;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	FRotator HandAttachmentRotRight;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	FVector FootAttachmentLocLeft;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	FRotator FootAttachmentRotLeft;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	FVector FootAttachmentLocRight;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	FRotator FootAttachmentRotRight;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	EFortCardinalDirection PivotDir;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	float LowerVelocityTime;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	float LowerVelocityDuration;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	float FwdBwd;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	float LeftRight;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	float SeatSteerYaw;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	float SeatSteerPitch;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	float SeatSteerStrength;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	uint8 bIsLowerVelocity : 1;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	uint8 bWasLowerVelocity : 1;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	uint8 bShouldPlayGrappleFire : 1;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	uint8 bShouldApplyLeanAdditive : 1;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	uint8 bShouldPlayPivotTransition : 1;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	uint8 bHasDriver : 1;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	uint8 bIsBoosting : 1;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	uint8 bWantsEastWestPivot : 1;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	uint8 bWantsNorthSouthPivot : 1;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	uint8 bIsVehicleInAir : 1;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	uint8 bIsTowhookHolstered : 1;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	uint8 bIsTowhookExtending : 1;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	uint8 bIsTowhookAttached : 1;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerAnimInstance_OctopusDriver")
	uint8 bEnterMovingInPlace : 1;

};

