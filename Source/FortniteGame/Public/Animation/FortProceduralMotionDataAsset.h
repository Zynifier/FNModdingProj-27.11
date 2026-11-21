// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/MathFwd.h"
#include "FortProceduralMotionDataAsset.generated.h"

class UCurveFloat;
class UCurveVector;

USTRUCT(BlueprintType)
struct FFortProceduralMotionDataSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortProceduralMotionDataSet")
	TObjectPtr<UCurveVector> TranslationRemapCurve;

	UPROPERTY(BlueprintReadOnly, Category="FortProceduralMotionDataSet")
	TObjectPtr<UCurveFloat> RotationRemapCurve;

	UPROPERTY(BlueprintReadOnly, Category="FortProceduralMotionDataSet")
	float ProceduralAlpha;

	UPROPERTY(BlueprintReadOnly, Category="FortProceduralMotionDataSet")
	float Delay;

	UPROPERTY(BlueprintReadOnly, Category="FortProceduralMotionDataSet")
	FVector TranslationScale;

	UPROPERTY(BlueprintReadOnly, Category="FortProceduralMotionDataSet")
	FRotator TranslationRotationalOffset;

	UPROPERTY(BlueprintReadOnly, Category="FortProceduralMotionDataSet")
	FRotator RotationOffset;

	UPROPERTY(BlueprintReadOnly, Category="FortProceduralMotionDataSet")
	FVector RotationPivot;

	UPROPERTY(BlueprintReadOnly, Category="FortProceduralMotionDataSet")
	float RotationScale;

	UPROPERTY(BlueprintReadOnly, Category="FortProceduralMotionDataSet")
	FVector IKHandGunTranslationOffset;

	UPROPERTY(BlueprintReadOnly, Category="FortProceduralMotionDataSet")
	FRotator IKHandGunRotationOffset;

	UPROPERTY(BlueprintReadOnly, Category="FortProceduralMotionDataSet")
	float IKHandGunInHandSpaceAlpha;

	UPROPERTY(BlueprintReadOnly, Category="FortProceduralMotionDataSet")
	FVector IKHandGunInHandSpaceTranslationWeight;

	UPROPERTY(BlueprintReadOnly, Category="FortProceduralMotionDataSet")
	float IKHandGunInHandSpaceRotationWeight;

	UPROPERTY(BlueprintReadOnly, Category="FortProceduralMotionDataSet")
	float RightElbowTwistScale;

	UPROPERTY(BlueprintReadOnly, Category="FortProceduralMotionDataSet")
	float RightElbowTwistOffset;

	UPROPERTY(BlueprintReadOnly, Category="FortProceduralMotionDataSet")
	float LeftElbowTwistScale;

	UPROPERTY(BlueprintReadOnly, Category="FortProceduralMotionDataSet")
	float LeftElbowTwistOffset;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortProceduralMotionDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(BlueprintThreadSafe))
	void ApplyTo(FFortProceduralMotionDataSet& DataAsset) const;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="FortProceduralMotionDataAsset")
	TObjectPtr<UCurveVector> TranslationRemapCurve;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="FortProceduralMotionDataAsset")
	TObjectPtr<UCurveFloat> RotationRemapCurve;

	UPROPERTY(EditAnywhere, Category="FortProceduralMotionDataAsset", meta=(UIMax="1", UIMin="0"))
	float ProceduralAlpha;

	UPROPERTY(EditAnywhere, Category="FortProceduralMotionDataAsset")
	float Delay;

	UPROPERTY(EditAnywhere, Category="FortProceduralMotionDataAsset", meta=(UIMax="1", UIMin="0"))
	FVector TranslationScale;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="FortProceduralMotionDataAsset")
	FRotator TranslationRotationalOffset;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="FortProceduralMotionDataAsset")
	FRotator RotationOffset;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="FortProceduralMotionDataAsset")
	FVector RotationPivot;

	UPROPERTY(EditAnywhere, Category="FortProceduralMotionDataAsset", meta=(UIMax="1", UIMin="0"))
	float RotationScale;

	UPROPERTY(EditAnywhere, Category="FortProceduralMotionDataAsset")
	FVector IKHandGunTranslationOffset;

	UPROPERTY(EditAnywhere, Category="FortProceduralMotionDataAsset")
	FRotator IKHandGunRotationOffset;

	UPROPERTY(EditAnywhere, Category="FortProceduralMotionDataAsset", meta=(UIMax="1", UIMin="0"))
	float IKHandGunInHandSpaceAlpha;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="FortProceduralMotionDataAsset", meta=(AllowPreserveRatio, UIMax="1", UIMin="0"))
	FVector IKHandGunInHandSpaceTranslationWeight;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="FortProceduralMotionDataAsset", meta=(UIMax="1", UIMin="0"))
	float IKHandGunInHandSpaceRotationWeight;

	UPROPERTY(EditAnywhere, Category="FortProceduralMotionDataAsset")
	float RightElbowTwistScale;

	UPROPERTY(EditAnywhere, Category="FortProceduralMotionDataAsset")
	float RightElbowTwistOffset;

	UPROPERTY(EditAnywhere, Category="FortProceduralMotionDataAsset")
	float LeftElbowTwistScale;

	UPROPERTY(EditAnywhere, Category="FortProceduralMotionDataAsset")
	float LeftElbowTwistOffset;

};

