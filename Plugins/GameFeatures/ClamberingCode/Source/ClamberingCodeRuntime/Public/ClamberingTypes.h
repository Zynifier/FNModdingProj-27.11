// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/NetSerialization.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortReleaseVersion.h"
#include "ClamberingTypes.generated.h"

class AActor;
class UAnimMontage;
class UPrimitiveComponent;

UENUM()
enum class EClamberingActivationMode : uint8
{
	/** This will pull the activation mode from the client settings */
	ClientPreference = 0,
	ForceAutoClambering = 1,
	ForceManualClambering = 2,
};

UENUM()
enum class EClamberingDebugTextAlign : uint8
{
	Left = 0,
	Right = 1,
	Center = 2,
};

UENUM(BlueprintType)
enum class EClamberingFailedReason : uint8
{
	//Global Clambering failed reason

	None = 0,
	Unknown = 1,
	DebugForced = 2,
	OwnerDied = 3,
	OwnerDBNO = 4,
	OwnerLaunched = 5,
	SynchedActionNotStarted = 6,
	OwnerTeleported = 7,
	//Ledge Clambering specific states

	Ledge_PlayerTooFar = 8,
	Ledge_TargetLocationInvalid = 9,
	Ledge_TargetActorInvalid = 10,
	Ledge_TargetActorDestroyed = 11,
	Ledge_BlockerEncountered = 12,
};

UENUM(BlueprintType)
enum class EClamberingState : uint8
{
	//Global Clambering states

	Inactive = 0,
	Targeting = 1,
	//Ledge Clambering specific states

	Ledge_Moving = 2,
	Ledge_Failed = 3,
	//Window Clambering specific states -- Stubs for now, will implement in a future release

	Window_Moving = 4,
	Window_Failed = 5,
};

UENUM(BlueprintType)
enum class EClamberingType : uint8
{
	Invalid = 0,
	Ledge = 1,
	Window = 2,
};

USTRUCT()
struct FClamberingAnalytics_ClamberEvent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 MatchTime;

	UPROPERTY()
	EClamberingType ClamberType;

	UPROPERTY()
	FVector ClamberLocation;

	UPROPERTY()
	EClamberingFailedReason FailureReason;

};

USTRUCT()
struct FClamberingAnimationEntry : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ClamberingAnimationEntry")
	TObjectPtr<UAnimMontage> Montage;

	UPROPERTY(EditDefaultsOnly, Category="ClamberingAnimationEntry", meta=(ClampMin="0", UIMin="0"))
	float MinClamberHeight;

	UPROPERTY(EditDefaultsOnly, Category="ClamberingAnimationEntry")
	bool bLedgeLaunch;

};

USTRUCT(BlueprintType)
struct FClamberingInputConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingInputConfig")
	FScalableFloat ClamberActivationHorizontalRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingInputConfig")
	FScalableFloat ClamberActivationVerticalRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingInputConfig")
	FScalableFloat EnableInputDelay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingInputConfig")
	FScalableFloat QueuedInputWindow;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingInputConfig")
	FScalableFloat HeldInputDuration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingInputConfig")
	EClamberingActivationMode ActivationMode;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingInputConfig")
	FScalableFloat AutoStartMovementThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingInputConfig")
	FScalableFloat AutoStartLookAtThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingInputConfig")
	FScalableFloat AutoStartWallCheckCastRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingInputConfig")
	FScalableFloat AutoStartWallCheckHorizontalRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingInputConfig")
	FScalableFloat AutoStartWallCheckLookAtThresholdMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingInputConfig")
	FScalableFloat TargetInvalidateDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingInputConfig")
	FScalableFloat TargetAimInvalidateAngle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingInputConfig")
	FScalableFloat TargetActorMovementInvalidateDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingInputConfig", meta=(ForceUnits="deg"))
	FScalableFloat MaxDirectionalLedgeLaunchAngle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingInputConfig", meta=(ForceUnits="cm"))
	FScalableFloat PBWLedgeLaunchMaxHorizontalTranslation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingInputConfig", meta=(ForceUnits="cm"))
	FScalableFloat DefaultLedgeLaunchVerticalTranslation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingInputConfig", meta=(ForceUnits="cm"))
	FScalableFloat PBWLedgeLaunchVerticalTranslation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingInputConfig", meta=(ForceUnits="cm"))
	FScalableFloat PBWNextLedgeLaunchVerticalTranslation;

};

USTRUCT()
struct FClamberingInputConfig_CachedValues
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FClamberingMovementConfig_Ledge
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingMovementConfig_Ledge")
	FScalableFloat Duration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingMovementConfig_Ledge")
	FScalableFloat BlockCheckTickRate;

};

USTRUCT(BlueprintType)
struct FClamberingTargetingConfig_Ledge
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat ForwardCastDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat ForwardCastRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat FowardCast2D;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat VerticalSurfaceThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat HorizontalSurfaceThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat UpwardDistanceCapsuleHeightMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat UpwardStartDistanceCapsuleHeightMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat DownwardDistanceCapsuleHeightMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat MinimumLedgeHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat MinimumLedgeHeightWater;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat FallingSpeedThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat MinimumLedgeFallingHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat MinimumLedgeFallingWaterHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat ForwardSphereCastRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat DownwardSphereCastRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat AllowNonWalkableSurfaces;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat TargetValidationEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat TargetValidationCapsuleRadiusModifier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat TargetValidationCapsuleHalfHeightModifier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ClamberingTargetingConfig_Ledge")
	FScalableFloat TargetValidationCapsuleBottomVerticalOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Prototype")
	FFortReleaseVersion ContextualActionPrototypeVersion;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Prototype | LedgeLaunch")
	FScalableFloat MinimumLedgeDepth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Prototype | LedgeLaunch")
	FScalableFloat DownwardSweepOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Prototype | LedgeLaunch", meta=(ClampMin="0.000000", ForceUnits="cm", UIMin="0.000000"))
	FScalableFloat FutureLedgeLaunchMaxVerticalDetectionRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Prototype | LedgeLaunch", meta=(ClampMin="0.000000", ForceUnits="cm", UIMin="0.000000"))
	FScalableFloat FutureLedgeLaunchMaxHorizontalDetectionRange;

};

USTRUCT()
struct FClamberingTargetingConfig_Ledge_CachedContextualValues
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FClamberingTargetingData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ClamberingTargetingData")
	EClamberingType Type;

	UPROPERTY(BlueprintReadOnly, Category="ClamberingTargetingData")
	uint8 bValid : 1;

	UPROPERTY(BlueprintReadOnly, Category="ClamberingTargetingData")
	uint8 bCanStandOnLedge : 1;

	UPROPERTY(BlueprintReadOnly, Category="ClamberingTargetingData")
	TObjectPtr<AActor> SourceActor;

	UPROPERTY(BlueprintReadOnly, Category="ClamberingTargetingData")
	FVector SourceLocation;

	UPROPERTY(BlueprintReadOnly, Category="ClamberingTargetingData")
	FVector SourceAim;

	UPROPERTY(BlueprintReadOnly, Category="ClamberingTargetingData")
	FVector WallLocation;

	UPROPERTY(BlueprintReadOnly, Category="ClamberingTargetingData")
	FVector WallNormal;

	UPROPERTY(BlueprintReadOnly, Category="ClamberingTargetingData")
	FVector TargetLocation;

	UPROPERTY(BlueprintReadOnly, Category="ClamberingTargetingData")
	FVector TargetNormal;

	UPROPERTY(BlueprintReadOnly, Category="ClamberingTargetingData")
	TObjectPtr<AActor> TargetActor;

	UPROPERTY(BlueprintReadOnly, Export, Category="ClamberingTargetingData", meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> TargetActorComponent;

	UPROPERTY(BlueprintReadOnly, Category="ClamberingTargetingData")
	FVector TargetActorComponentLocation;

	UPROPERTY(BlueprintReadOnly, Category="ClamberingTargetingData")
	FName TargetActorBoneName;

	UPROPERTY(BlueprintReadOnly, Category="ClamberingTargetingData")
	bool bHasNextLedgeLaunchTarget;

	UPROPERTY(BlueprintReadOnly, Category="ClamberingTargetingData")
	FVector NextLedgeLaunchWarpPoint;

};

USTRUCT()
struct FClamberingTargetingDebugData
{
	GENERATED_BODY()

};

USTRUCT()
struct FClamberingTargetingDebugData_Ledge : public FClamberingTargetingDebugData
{
	GENERATED_BODY()

};

USTRUCT()
struct FClamberingTargetingDebugDrawData
{
	GENERATED_BODY()

};

USTRUCT()
struct FClamberingTargetingDebugDrawData_Capsule : public FClamberingTargetingDebugDrawData
{
	GENERATED_BODY()

};

USTRUCT()
struct FClamberingTargetingDebugDrawData_CapsuleCast : public FClamberingTargetingDebugDrawData_Capsule
{
	GENERATED_BODY()

};

USTRUCT()
struct FClamberingTargetingDebugDrawData_DirectionalArrow : public FClamberingTargetingDebugDrawData
{
	GENERATED_BODY()

};

USTRUCT()
struct FClamberingTargetingDebugDrawData_Line : public FClamberingTargetingDebugDrawData
{
	GENERATED_BODY()

};

USTRUCT()
struct FClamberingTargetingDebugDrawData_Sphere : public FClamberingTargetingDebugDrawData
{
	GENERATED_BODY()

};

USTRUCT()
struct FClamberingTargetingDebugDrawData_SphereCast : public FClamberingTargetingDebugDrawData_Sphere
{
	GENERATED_BODY()

};

USTRUCT()
struct FReplicatedClamberingTargetingData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EClamberingType Type;

	UPROPERTY()
	FVector_NetQuantize10 SourceLocation;

	UPROPERTY()
	FVector_NetQuantize100 WallLocation;

	UPROPERTY()
	uint16 WallNormalYawQuantized;

	UPROPERTY()
	uint16 WallNormalPitchQuantized;

	UPROPERTY()
	FVector_NetQuantize100 TargetLocation;

	UPROPERTY()
	uint16 TargetNormalYawQuantized;

	UPROPERTY()
	uint16 TargetNormalPitchQuantized;

	UPROPERTY()
	TObjectPtr<AActor> TargetActor;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> TargetActorComponent;

	UPROPERTY()
	FName TargetActorBoneName;

	UPROPERTY()
	int8 AnimationIndex;

};

USTRUCT()
struct FReplicatedClamberingTargetingData_SimClient
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EClamberingType Type;

	UPROPERTY()
	uint16 WallNormalYawQuantized;

	UPROPERTY()
	FVector_NetQuantize100 TargetLocation;

	UPROPERTY()
	TObjectPtr<AActor> TargetActor;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> TargetActorComponent;

	UPROPERTY()
	FName TargetActorBoneName;

	UPROPERTY()
	int8 AnimationIndex;

};

