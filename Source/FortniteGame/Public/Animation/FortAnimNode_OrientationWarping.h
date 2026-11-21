// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/BoneReference.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "FortAnimNode_OrientationWarping.generated.h"

USTRUCT()
struct FFortOrientationWarpingSpineBoneSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FBoneReference Bone;

};

USTRUCT(BlueprintType)
struct FFortOrientationWarpingSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	TEnumAsByte<EAxis::Type> YawRotationAxis;

	UPROPERTY(EditAnywhere, Category="Settings")
	float BodyOrientationAlpha;

	UPROPERTY(EditAnywhere, Category="Settings")
	TArray<FFortOrientationWarpingSpineBoneSettings> SpineBones;

	UPROPERTY(EditAnywhere, Category="Settings")
	FBoneReference IKFootRootBone;

	UPROPERTY(EditAnywhere, Category="Settings")
	TArray<FBoneReference> IKFootBones;

};

USTRUCT()
struct FFortOrientationWarpingSpineBoneData
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType, meta=(BlueprintInternalUseOnly="true"))
struct FFortAnimNode_OrientationWarping : public FAnimNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings", meta=(PinShownByDefault))
	float LocomotionAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings", meta=(PinHiddenByDefault))
	FFortOrientationWarpingSettings Settings;

	UPROPERTY(Transient)
	TArray<FFortOrientationWarpingSpineBoneData> SpineBoneDataArray;

	UPROPERTY(Transient)
	float CachedDeltaTime;

};

