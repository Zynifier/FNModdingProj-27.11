// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimTypes.h"
#include "Animation/BoneReference.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "FortAnimNode_Flap.generated.h"

class UCurveFloat;

UENUM()
enum class ESourceSelectionMode : uint8
{
	// Pick max absolute difference

	MaxDifference = 0,
};

USTRUCT()
struct FSourceDriver
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Source (driver)")
	FBoneReference SourceBone;

	UPROPERTY(EditAnywhere, Category="Source (driver)")
	TEnumAsByte<EComponentType::Type> SourceComponent;

	UPROPERTY(EditAnywhere, Category="Decomposition")
	bool UseQuaternion;

	UPROPERTY(EditAnywhere, Category="Mapping")
	TObjectPtr<UCurveFloat> DrivingCurve;

	UPROPERTY(EditAnywhere, Category="Mapping")
	float Multiplier;

	UPROPERTY(EditAnywhere, Category="Mapping", meta=(DisplayName="Remap Source"))
	bool bUseRange;

	UPROPERTY(EditAnywhere, Category="Mapping", meta=(DisplayName="Source Range Min", EditCondition="bUseRange"))
	float RangeMin;

	UPROPERTY(EditAnywhere, Category="Mapping", meta=(DisplayName="Source Range Max", EditCondition="bUseRange"))
	float RangeMax;

	UPROPERTY(EditAnywhere, Category="Mapping", meta=(DisplayName="Mapped Range Min", EditCondition="bUseRange"))
	float RemappedMin;

	UPROPERTY(EditAnywhere, Category="Mapping", meta=(DisplayName="Mapped Range Max", EditCondition="bUseRange"))
	float RemappedMax;

};

USTRUCT()
struct FFortAnimNode_Flap : public FAnimNode_SkeletalControlBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Source (driver)")
	TArray<FSourceDriver> SourceDrives;

	UPROPERTY(EditAnywhere, Category="Target (driven)")
	FBoneReference TargetBone;

	UPROPERTY(EditAnywhere, Category="Target (driven)")
	TEnumAsByte<EComponentType::Type> TargetComponent;

	UPROPERTY(EditAnywhere, Category="Target (driven)")
	ESourceSelectionMode SelectionMode;

	UPROPERTY(EditAnywhere, Category="Target (driven)", meta=(DisplayName="Clamp Value"))
	bool bUseClamp;

	UPROPERTY(EditAnywhere, Category="Target (driven)", meta=(DisplayName="Target Clamp Min", EditCondition="bUseClamp"))
	float TargetClampMin;

	UPROPERTY(EditAnywhere, Category="Target (driven)", meta=(DisplayName="Target Clamp Max", EditCondition="bUseClamp"))
	float TargetClampMax;

};

