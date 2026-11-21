// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortTowhookModel.generated.h"

class UPrimitiveComponent;

UENUM()
enum class FTowhookExtensionState : uint8
{
	Hold = 0,
	Extend = 1,
	Contract = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTowhookYankDelegate, const FVector&, YankForce, UPrimitiveComponent*, YankedComponent);

USTRUCT()
struct FFortTowhookModel
{
	GENERATED_BODY()

};

USTRUCT()
struct FNetTowhookAttachState
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> Component;

	UPROPERTY()
	FVector_NetQuantize100 LocalLocation;

	UPROPERTY()
	FVector_NetQuantize100 LocalNormal;

};

USTRUCT()
struct FTowhookAttachState
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FTowhookParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	float MaxCableLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	float MinCableLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	bool bUseSpring;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	bool bUseRope;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	bool bUseAsTractorBeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	float SpringStiffness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	float SpringDamping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	float SpringMaxStiffnessForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	float SpringMaxStiffnessVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	float SpringDeformationRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	float RopeGive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	float RopeBreakForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	float RopeBreakLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	float RopeYankForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	float ExtendSpeedKmh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	float ContractSpeedKmh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	bool bApplySpringToSelf;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	bool bApplySpringToOther;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	bool bTakeUpSlack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	bool bEnableParentDominates;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams")
	bool bAttachToOwnersVehicle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams", meta=(EditCondition="bUseAsTractorBeam"))
	float TractorBeamRestLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams", meta=(EditCondition="bUseAsTractorBeam"))
	float TractorBeamUpSpringStiffness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams", meta=(EditCondition="bUseAsTractorBeam"))
	float TractorBeamSideSpringStiffness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams", meta=(EditCondition="bUseAsTractorBeam"))
	float TractorBeamUpSpringDamping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams", meta=(EditCondition="bUseAsTractorBeam"))
	float TractorBeamSideSpringDamping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams", meta=(EditCondition="bUseAsTractorBeam"))
	float TractorBeamMaxStiffnessTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams", meta=(EditCondition="bUseAsTractorBeam"))
	FScalableFloat TractorBeamHeightModifierLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams", meta=(EditCondition="bUseAsTractorBeam"))
	FScalableFloat TractorBeamHeightModifierStartPositionExtraDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowhookParams", meta=(EditCondition="bUseAsTractorBeam"))
	FScalableFloat TractorBeamHeightScalingForceMagnitude;

};

