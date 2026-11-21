// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Animation/PoseSnapshot.h"
#include "Math/MathFwd.h"
#include "Animation/AnimInputs/FortAnimInput_AimScrambleDataHelper.h"
#include "Animation/FortAnimInputs.h"
#include "LayerAnimInstance_MechanicalEngineerPet.generated.h"

class UFortPlayerGliderAnimSet;
class USkeletalMesh;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class ULayerAnimInstance_MechanicalEngineerPet : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="LayerAnimInstance_MechanicalEngineerPet")
	TSoftObjectPtr<USkeletalMesh> GliderSkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	TSoftObjectPtr<UFortPlayerGliderAnimSet> GliderPlayerAnimSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	TSoftObjectPtr<UFortPlayerGliderAnimSet> UmbrellaAnimSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	TSoftObjectPtr<UFortPlayerGliderAnimSet> HangGliderAnimSet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Default")
	FFortAnimInput_Skydiving SkydivingState;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	FPoseSnapshot GliderSnapshotPose;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	FVector AttachLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	FRotator AttachRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	FVector OwlLocationOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	FRotator OwlRotationOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	FVector GliderOwlSnapshotLocation;

	UPROPERTY(Transient)
	FVector GliderOwlSnapshotLocationStatic;

	UPROPERTY(Transient)
	FVector PlayerRootSnapshotLocationStatic;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	FRotator GliderOwlSnapshotRotation;

	UPROPERTY(Transient)
	float FrontendLocAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	float OwlFrameAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	float OwlPoseAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	FVector PlayerRootLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	FRotator PlayerRootRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	FVector GliderOwlFrameLandingStart;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	FVector Owl_GLBase_Location;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	FRotator Owl_GLBase_Rotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	FFortAnimInput_AimScrambleDataHelper AimSmooth;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	float SkydiveForward;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	float ClosedAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	float AdditiveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	float Closed_NewCurveValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	float GliderCurveValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	float WingCorrectiveAdditiveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	float LocalVelocityRight;

	UPROPERTY(Transient)
	uint8 bSwitchInterpSpeed : 1;

	UPROPERTY(Transient)
	uint8 bGateCanPlayLanding : 1;

	UPROPERTY(Transient)
	uint8 bGateWrenchTransition : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	uint8 bOwlIsOnPack : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	uint8 BlockAnimRule : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	uint8 bHideOwl : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	uint8 bDetachFromWrenchTransition : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	uint8 bSkydiveFreefall : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	uint8 bIsInLandingPhase : 1;

	UPROPERTY(BlueprintReadWrite, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	uint8 bCanPlayLandingAnim : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	uint8 bIsFrontEndContrails : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	uint8 bUseLayer : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	uint8 bUsingHangGliderSet : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	uint8 bUsingUmbrellaGliderSet : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	uint8 bTransition_ToSkydive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	uint8 bTransition_ToClosed : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	uint8 bTransition_Detach_To_Dive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LayerAnimInstance_MechanicalEngineerPet")
	uint8 bTransition_Detach_To_Glide : 1;

};

