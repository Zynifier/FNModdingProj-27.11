// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortReleaseVersion.h"
#include "Pawns/FortPawnTypes.h"
#include "HurdleType.generated.h"

class AActor;
class UPrimitiveComponent;

UENUM(BlueprintType)
enum class EHurdleState : uint8
{
	//Global Vaulting states

	Inactive = 0,
	Targeting = 1,
	// Active Vaulting State

	HurdleOver = 2,
	HurdleOn = 3,
};

UENUM(BlueprintType)
enum class EHurdleType : uint8
{
	Invalid = 0,
	HurdleOver = 1,
	HurdleOnTop = 2,
};

USTRUCT(BlueprintType)
struct FHurdleInputConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat CastRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat MaxAllowedFallDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat ForwardCastIndicatorDistance_Phase1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat ForwardCastDistance_Phase1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat ForwardCastDistance_Phase1_HurdleFromJog;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat ForwardCastDistance_Phase1_ManualHurdle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat Phase1_WallAngleToleranceFlat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat Phase1_SweepGroundBufferHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat Phase1_SweepGroundMaxHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat Phase1_Floor_WallOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat Phase1_Floor_MinHeightForHurlde;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat Phase2_UpAngleTolerance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat Phase2_Floor_MaxHeightForHurlde;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat Phase3_CapsuleOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat Phase3_ClearanceCapsuleSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat Phase3_ForwardCastDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat Phase3_MinTopClearanceForHurdleOn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat Phase4_MaxDownDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat Phase4_UpAngleTolerance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat Phase4_HurdleOnZTolerance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat Phase5_CapsuleOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat Phase5_ClearanceCapsuleSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat FinalResult_GroundAimOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FScalableFloat SlideBufferTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Prototype", meta=(ClampMin="0.000000", ForceUnits="cm/s", UIMin="0.000000"))
	FScalableFloat MinimumSpeedToHurdle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Prototype", meta=(ClampMax="1.000000", ClampMin="0.000000", ForceUnits="cm/s", UIMax="1.000000", UIMin="0.000000"))
	FScalableFloat MinimumForwardStickDeflection;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Prototype", meta=(ClampMin="0.000000", ForceUnits="cm", UIMin="0.000000"))
	FScalableFloat RangeToIgnoreMinimumSpeedThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Prototype", meta=(ClampMin="0.000000", ForceUnits="cm", UIMin="0.000000"))
	FScalableFloat MaximumCapsuleRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Prototype", meta=(ClampMin="0.000000", ForceUnits="cm", UIMin="0.000000"))
	FScalableFloat MaximumCapsuleHalfHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Prototype", meta=(ClampMin="0.000000", ForceUnits="cm", UIMin="0.000000"))
	FScalableFloat Phase0_HorizontalSweepBreadth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Prototype", meta=(ClampMin="0.000000", ForceUnits="cm", UIMin="0.000000"))
	FScalableFloat Phase0_HorizontalSweepHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Prototype")
	FFortReleaseVersion ContextualActionPrototypeVersion;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfig")
	FFortReleaseVersion MovementModeExtensionVersion;

};

USTRUCT(BlueprintType)
struct FHurdleInputConfigCache
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float CastRadius;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float MaxAllowedFallDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HurdleInputConfigCache")
	float ForwardCastIndicatorDistance_Phase1;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float ForwardCastDistance_Phase1;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float ForwardCastDistance_Phase1_HurdleFromJog;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float ForwardCastDistance_Phase1_ManualHurdle;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase1_WallAngleToleranceFlat;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase1_SweepGroundBufferHeight;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase1_SweepGroundMaxHeight;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase1_Floor_WallOffset;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase1_Floor_MinHeightForHurlde;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase1_Floor_MaxFloorSearchHeight;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase2_UpAngleTolerance;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase2_Floor_MaxHeightForHurlde;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase2_Floor_HeightCorrectionMinFloorAngle;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase3_CapsuleOffset;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase3_ClearanceCapsuleSize;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase3_ForwardCastDistance;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase3_MinTopClearanceForHurdleOn;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase4_MaxDownDistance;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase4_UpAngleTolerance;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase4_HurdleOnZTolerance;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase5_CapsuleOffset;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase5_ClearanceCapsuleSize;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float FinalResult_GroundAimOffset;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float SlideBufferTime;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float MinimumSpeedToHurdle;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float MinimumForwardStickDeflection;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float RangeToIgnoreMinimumSpeedThreshold;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float MaximumCapsuleRadius;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float MaximumCapsuleHalfHeight;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase0_HorizontalSweepBreadth;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	float Phase0_HorizontalSweepHeight;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	FFortReleaseVersion ContextualActionPrototypeVersion;

	UPROPERTY(BlueprintReadOnly, Category="HurdleInputConfigCache")
	FFortReleaseVersion MovementModeExtensionVersion;

};

USTRUCT(BlueprintType)
struct FHurdleTargetingData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="HurdleTargetingData")
	EHurdleType Type;

	UPROPERTY(BlueprintReadOnly, Category="HurdleTargetingData")
	EFortSynchedActionEndMovementMode EndMovementMode;

	UPROPERTY(BlueprintReadOnly, Category="HurdleTargetingData")
	uint8 bValid : 1;

	UPROPERTY(BlueprintReadOnly, Category="HurdleTargetingData")
	uint8 bInRange : 1;

	UPROPERTY(BlueprintReadOnly, Category="HurdleTargetingData")
	uint8 bIsNarrowOpening : 1;

	UPROPERTY(BlueprintReadOnly, Category="HurdleTargetingData")
	FVector FacingCornerLocation;

	UPROPERTY(BlueprintReadOnly, Category="HurdleTargetingData")
	FVector FacingCornerNormal;

	UPROPERTY(BlueprintReadOnly, Category="HurdleTargetingData")
	FVector BackCornerLocation;

	UPROPERTY(BlueprintReadOnly, Category="HurdleTargetingData")
	FVector FinalLandingPosition;

	UPROPERTY(BlueprintReadOnly, Category="HurdleTargetingData")
	AActor* SourceActor;

	UPROPERTY(BlueprintReadOnly, Category="HurdleTargetingData")
	FVector SourceLocation;

	UPROPERTY(BlueprintReadOnly, Category="HurdleTargetingData")
	FVector SourceAim;

	UPROPERTY(BlueprintReadOnly, Category="HurdleTargetingData")
	FVector WallLocation;

	UPROPERTY(BlueprintReadOnly, Category="HurdleTargetingData")
	FVector WallNormal;

	UPROPERTY(BlueprintReadOnly, Category="HurdleTargetingData")
	FVector TargetLocation;

	UPROPERTY(BlueprintReadOnly, Category="HurdleTargetingData")
	FVector TargetNormal;

	UPROPERTY(BlueprintReadOnly, Category="HurdleTargetingData")
	TWeakObjectPtr<AActor> TargetActor;

	UPROPERTY(BlueprintReadOnly, Export, Category="HurdleTargetingData")
	TWeakObjectPtr<UPrimitiveComponent> TargetActorComponent;

	UPROPERTY(BlueprintReadOnly, Category="HurdleTargetingData")
	FVector TargetActorComponentLocation;

	UPROPERTY(BlueprintReadOnly, Category="HurdleTargetingData")
	FName TargetActorBoneName;

};

USTRUCT()
struct FReplicatedHurdleTargetingData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EHurdleType Type;

	UPROPERTY()
	EFortSynchedActionEndMovementMode EndMovementMode;

	UPROPERTY()
	FVector_NetQuantize10 FacingCornerLocation;

	UPROPERTY()
	FVector_NetQuantize10 FacingCornerNormal;

	UPROPERTY()
	FVector_NetQuantize10 BackCornerLocation;

	UPROPERTY()
	FVector_NetQuantize10 FinalLandingPosition;

	UPROPERTY()
	bool bValid;

};

