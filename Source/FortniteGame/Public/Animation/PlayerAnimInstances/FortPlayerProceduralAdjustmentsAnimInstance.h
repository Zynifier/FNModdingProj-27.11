// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/AnimInputs/FortAnimInput_PlayerGliderAnimAsset.h"
#include "Animation/AnimInputs/FortAnimInput_SpringGlider.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortPlayerProceduralAdjustmentsAnimInstance.generated.h"

USTRUCT(BlueprintType)
struct FFeetSettleAnimInput
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FeetSettleAnimInput")
	FVector PreviousLeftFootPosition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FeetSettleAnimInput")
	FRotator PreviousLeftFootRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FeetSettleAnimInput")
	FVector PreviousRightFootPosition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FeetSettleAnimInput")
	FRotator PreviousRightFootRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FeetSettleAnimInput")
	float LockLeftFootAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FeetSettleAnimInput")
	float LockRightFootAlpha;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPlayerProceduralAdjustmentsAnimInstance : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="Skydiving")
	FRotator FreeFall_PelvisModRot;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Glider")
	FFortAnimInput_SpringGlider SpringGlider;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AnimSets")
	FFortAnimInput_PlayerGliderAnimAsset CurrentGliderAnimSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Transient, Category="FortPlayerPawn")
	EFortPlayerAnimBodyType AnimBodyType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="Skydiving")
	bool bFreeFall_UseDiveAngleMod;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="DBNO")
	uint8 bIsBeingInterrogated : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="IK")
	float RightHandIKAlpha;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="Skydiving")
	FFortAnimInput_Skydiving Skydiving;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Gender")
	uint8 bIsFemale : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsInCannon : 1;

	UPROPERTY(BlueprintReadOnly, Category="JackalVehicle")
	FFortAnimInput_JackalVehicle JackalVehicleInput;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	float UpperBodyNoAdditivesMaskWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SlopeWarping")
	float SlopeWarpingAlpha;

	UPROPERTY(BlueprintReadOnly, Category="TurnInPlace")
	FFortAnimInput_TurnInPlace TurnInPlaceInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TurnInPlace")
	FRotator TurnPelvisRotationOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SlopeWarping")
	FVector SlopeWarpingFloorOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SlopeWarping")
	uint8 bUseCustomFloorOffset : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SlopeWarping")
	uint8 bUseFloorOffsetInterpolator : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TurnInPlace")
	FVector TurnPelvisTranslationOffset;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Emotes")
	uint8 bIsPlayingEmote : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Emote")
	float EmoteForcedRootYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Prediction")
	FVector WholeAnimOffset;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Transient, Category="Idle")
	float IdlePelvisOffsetAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="IK")
	float LegIKAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SlopeWarping")
	float RootSlopeRotationAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SlopeWarping")
	FRotator RootSlopeRotationOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerProceduralAdjustmentsAnimInstance")
	uint8 bHideWeaponForEmptyHands : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="IK")
	float LeftHandIKAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BowWeapon")
	FFortAnimInput_BowWeapon BowWeaponInput;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HandIK")
	FFortAnimInput_HandIK HandIKInput;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PelvisAdjustment")
	FFortAnimInput_PelvisAdjustment PelvisAdjustmentInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Pelvis")
	float PelvisAdjustmentCrouchAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="IK")
	float SnapWeapon_LHandAlphaSwitch;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="Skydiving")
	float FreeFall_DiveAngleInterpSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	float ProceduralAdjustmentsAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Emote")
	FVector EmoteAnimOffset;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsCrouching : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsCrouchMoving : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsCrouchSprinting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerProceduralAdjustmentsAnimInstance")
	uint8 bIsRiding : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerProceduralAdjustmentsAnimInstance")
	FFeetSettleAnimInput FeetSettleAnimInput;

};

