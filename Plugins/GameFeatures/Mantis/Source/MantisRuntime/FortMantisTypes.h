// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "FortMantisTypes.generated.h"

class AActor;
class UAnimMontage;

UENUM()
enum class EFortMantisBranchPath : uint8
{
	Default = 0,
	Path_1 = 1,
	Path_2 = 2,
	Path_3 = 3,
	Path_4 = 4,
	Path_5 = 5,
	Blocked = 6,
};

UENUM()
enum class EFortMantisBranchRule : uint8
{
	// Disables branching to another technique.

	Off = 0,
	// Allows branching to any valid technique.

	Any = 1,
	// Allows branching only to techniques that start a sequence.

	Starter = 2,
};

UENUM()
enum class EFortMantisNotifyEvent : uint8
{
	// Invalid event.

	Invalid = 0,
	// Event that enables branching to any valid technique.

	Branch = 1,
	// Event that ends the technique.

	EndTechnique = 2,
};

UENUM()
enum class EFortMantisNotifyRotationWarpRateRule : uint8
{
	// Warp rotation toward the target such that it snaps to facing immediately.

	Snap = 0,
	// Warp rotation toward the target such that it takes the duration of the window to complete the rotation.

	WindowDurationLerp = 1,
};

UENUM()
enum class EFortMantisNotifyTranslationWarpLimitRule : uint8
{
	// No limit is applied during translation warping.

	None = 0,
	// Limit translation warping to the total translation in the animation in the range covered by the warping window

	Window = 1,
	// Limit translation warping to the total translation in the animation

	Animation = 2,
	// Limit translation warping to a custom value defined in the warping window

	Custom = 3,
};

UENUM()
enum class EFortMantisNotifyWindow : uint8
{
	// Invalid window.

	Invalid = 0,
	// Window that defines when input is accepted for the next technique.
// Note: This window is optional.  If present, it will override the input window delay set on the technique. 

	Input = 1,
	// Window that defines the section between the windup and recovery portions of the technique.

	Execution = 2,
	// Window that defines when the technique will collide and register damage.

	Damage = 3,
	// Window that defines when the technique will potentially allow for root motion warping
// Note: This window is optional. If present and calling gameplay code has a valid warping target, will attempt to warp
// root motion translation and rotation as appropriate toward the target.

	RootMotionWarp = 4,
};

UENUM()
enum class EFortMantisWarpRotationMethod : uint8
{
	None = 0,
	FaceTargetActor = 1,
	StaticRotation = 2,
};

UENUM()
enum class EFortMantisWarpTranslationMethod : uint8
{
	None = 0,
	OffsetFromTargetActor = 1,
	StaticLocation = 2,
	Reorient = 3,
	ScaledBasedOnInput = 4,
	ReorientAndScaledBasedOnInput = 5,
};

USTRUCT()
struct FFortMantisMontageData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UAnimMontage> Montage;

};

USTRUCT(BlueprintType)
struct FFortMantisReplicatedAnimInstanceInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortMantisReplicatedAnimInstanceInfo")
	bool bIsTechniqueActive;

	UPROPERTY(BlueprintReadOnly, Category="FortMantisReplicatedAnimInstanceInfo")
	FName ActiveTechniqueName;

	UPROPERTY(BlueprintReadOnly, Category="FortMantisReplicatedAnimInstanceInfo")
	int32 ActiveTechniqueIndex;

	UPROPERTY(BlueprintReadOnly, Category="FortMantisReplicatedAnimInstanceInfo")
	int32 ActiveTechniqueConsecutiveBranchesToSelf;

};

USTRUCT()
struct FFortMantisRootMotionWarpInfo
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> WarpTarget;

	UPROPERTY(Transient)
	FVector_NetQuantize LastValidWarpTargetLocation;

	UPROPERTY(Transient)
	uint8 bAllowTranslationWarp : 1;

	UPROPERTY(Transient)
	uint8 bAllowRotationWarp : 1;

	UPROPERTY(Transient)
	uint8 bSnapshotTargetLocation : 1;

	UPROPERTY(Transient)
	bool bUseAlternativeWarpingBehavior;

	UPROPERTY(Transient)
	EFortMantisWarpTranslationMethod WarpTranslationMethod;

	UPROPERTY(Transient)
	FVector_NetQuantize WarpTranslationVector;

	UPROPERTY(Transient)
	EFortMantisWarpRotationMethod WarpRotationMethod;

	UPROPERTY(Transient)
	float WarpRotationYaw;

};

