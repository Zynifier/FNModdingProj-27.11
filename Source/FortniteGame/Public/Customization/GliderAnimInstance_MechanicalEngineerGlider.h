// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/PoseSnapshot.h"
#include "Math/MathFwd.h"
#include "Animation/FortGliderAnimInstance.h"
#include "GliderAnimInstance_MechanicalEngineerGlider.generated.h"

class UBlendSpace;
class USkeletalMesh;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UGliderAnimInstance_MechanicalEngineerGlider : public UFortGliderAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GliderAnimInstance_MechanicalEngineerGlider")
	TSoftObjectPtr<USkeletalMesh> BackpackSkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	TObjectPtr<UBlendSpace> FlapBS;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	FPoseSnapshot BackpackSnapshotPose;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	FVector AttachLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	FRotator AttachRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	FVector Weapon_Attach_Location;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	FRotator Weapon_Attrach_Rotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	FVector Wrench_Offset_Loc;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	FRotator Wrench_Offset_Rot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	FVector BackpackOwlSnapshotLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	FRotator BackpackOwlSnapshotRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	float FlapPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	float FeatherSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	float DeployAnimAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	float WingPoseAdditiveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	float BackPackPoseCurveValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	float BackpackCurveValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bBackpacksMatch : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bIsCosmeticPreview : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bUseClosedFromPack : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bHideBackpackOwl : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bSkydiveFreefall : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bTransition_Closed_To_OpenIntoGliderItem : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bTransition_Closed_To_OpenIntoGeyserVent : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bTransition_Closed_To_OpenInto : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bTransition_IdleOpen_To_Flap : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bTransition_To_Closed : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bTransition_OpenInto_To_Flap : 1;

	UPROPERTY(Transient)
	uint8 bFlapGateIsAccelerating : 1;

	UPROPERTY(Transient)
	uint8 bFlapGateIsNotAccelerating : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bGateFlapEnable : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bGateLookoff : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bGateBlinkOff : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bCanFlap : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bIsFlapping : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bCanFlapTransition : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bCanLook : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bCanCaw : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="GliderAnimInstance_MechanicalEngineerGlider")
	uint8 bCanBlink : 1;

};

