// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MovementMode.h"
#include "CommonLegacyMovementSettings.generated.h"

/**
 * CommonLegacyMovementSettings: collection of settings that are shared between several of the legacy movement modes
 */
UCLASS(BlueprintType)
class MOVER_API UCommonLegacyMovementSettings : public UObject, public IMovementSettingsInterface
{
	GENERATED_BODY()

public:
	// What movement mode to use when on the ground.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="General")
	FName GroundMovementModeName;

	// What movement mode to use when airborne.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="General")
	FName AirMovementModeName;

	/** Walkable slope angle, represented as cosine(max slope angle) for performance reasons. Ex: for max slope angle of 30 degrees, value is cosine(30 deg) = 0.866 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ground Movement")
	float MaxWalkSlopeCosine;

	/** Max distance to scan for floor surfaces under a Mover actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ground Movement", meta=(ClampMin="0", ForceUnits="cm", UIMin="0"))
	float FloorSweepDistance;

	/** Mover actors will be able to step up onto or over obstacles shorter than this */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ground Movement", meta=(ClampMin="0", ForceUnits="cm", UIMin="0"))
	float MaxStepHeight;

	/** Maximum speed in the movement plane */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="General", meta=(ClampMin="0", ForceUnits="cm/s", UIMin="0"))
	float MaxSpeed;

	/** Default max linear rate of deceleration when there is no controlled input */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="General", meta=(ClampMin="0", ForceUnits="cm/s^2", UIMin="0"))
	float Deceleration;

	/** Default max linear rate of acceleration for controlled input. May be scaled based on magnitude of input. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="General", meta=(ClampMin="0", ForceUnits="cm/s^2", UIMin="0"))
	float Acceleration;

	/** Maximum rate of turning rotation (degrees per second). Negative numbers indicate instant rotation and should cause rotation to snap instantly to desired direction. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="General", meta=(ClampMin="-1", ForceUnits="degrees/s", UIMin="0"))
	float TurningRate;

	/** Speeds velocity direction changes while turning, to reduce sliding */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="General", meta=(ClampMin="0", ForceUnits="Multiplier", UIMin="0"))
	float TurningBoost;

	/** Instantaneous speed induced in an actor upon jumping */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Jumping", meta=(ClampMin="0", ForceUnits="cm/s", UIMin="0"))
	float JumpUpwardsSpeed;

	/** Depth at which the pawn starts swimming */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swimming", meta=(Units="cm"))
	float SwimmingStartImmersionDepth;

	/** Depth at which the pawn will float when in water */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swimming", meta=(Units="cm"))
	float SwimmingIdealImmersionDepth;

	/** Depth at which the pawn stops swimming */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swimming", meta=(Units="cm"))
	float SwimmingStopImmersionDepth;

};

