// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAnimTypes.h"
#include "FortAnimInput_PlayerGliderAnimAsset.generated.h"

class UAnimSequence;
class UBlendSpace;

USTRUCT(BlueprintType)
struct FPelvisMod_BankAngleInput_Spring
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Bank Angle Input + Spring")
	float BankLeanStrafeA;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Bank Angle Input + Spring")
	float BankLeanStrafeB;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Bank Angle Input + Spring")
	float BankTurnA;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Bank Angle Input + Spring")
	float BankTurnB;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Bank Angle Input + Spring")
	float BankStiffness;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Bank Angle Input + Spring")
	float BankDampening;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Bank Angle Input + Spring")
	float BankMass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Bank Angle Input + Spring")
	float BankClampMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Bank Angle Input + Spring")
	float BankClampMax;

};

USTRUCT(BlueprintType)
struct FPelvisMod_LateralInput_Spring
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Lateral Input + Spring")
	float LateralLeanStrafeA;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Lateral Input + Spring")
	float LateralLeanStrafeB;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Lateral Input + Spring")
	float LateralTurnA;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Lateral Input + Spring")
	float LateralTurnB;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Lateral Input + Spring")
	float LateralStiffness;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Lateral Input + Spring")
	float LateralDamping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Lateral Input + Spring")
	float LateralMass;

};

USTRUCT(BlueprintType)
struct FPelvisMod_VerticalInput_Spring
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Vertical Input + Spring")
	float VerticalLeanForwardA;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Vertical Input + Spring")
	float VerticalLeanForwardB;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Vertical Input + Spring")
	float VerticalLeanForwardStiffness;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Vertical Input + Spring")
	float VerticalLeanForwardDamping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pelvis Mod - Vertical Input + Spring")
	float VerticalLeanForwardMass;

};

USTRUCT(BlueprintType)
struct FThighMod_LeftLegDrag
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Thigh Mod - Left Leg Drag")
	float LeftLegBankSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Thigh Mod - Left Leg Drag")
	float LeftLegPitchSpeed;

};

USTRUCT(BlueprintType)
struct FThighMod_LegAngleInput
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Thigh Mod - Leg Angle Input", meta=(DisplayName="Leg Bank/Pitch Forward A"))
	float LegBankPitchForwardA;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Thigh Mod - Leg Angle Input", meta=(DisplayName="Leg Bank/Pitch Forward B"))
	float LegBankPitchForwardB;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Thigh Mod - Leg Angle Input", meta=(DisplayName="Leg Bank/Pitch Lean Strafe A"))
	float LegBankPitchLeanStrafeA;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Thigh Mod - Leg Angle Input", meta=(DisplayName="Leg Bank/Pitch Lean Strafe B"))
	float LegBankPitchLeanStrafeB;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Thigh Mod - Leg Angle Input", meta=(DisplayName="Leg Bank/Pitch Turn A"))
	float LegBankPitchTurnA;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Thigh Mod - Leg Angle Input", meta=(DisplayName="Leg Bank/Pitch Turn B"))
	float LegBankPitchTurnB;

};

USTRUCT(BlueprintType)
struct FThighMod_LegBankSpring
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Thigh Mod - Leg Bank(side to side) Spring")
	float LegBankStiffness;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Thigh Mod - Leg Bank(side to side) Spring")
	float LegBankDampening;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Thigh Mod - Leg Bank(side to side) Spring")
	float LegBankMass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Thigh Mod - Leg Bank(side to side) Spring")
	float LegBankClampMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Thigh Mod - Leg Bank(side to side) Spring")
	float LegBankClampMax;

};

USTRUCT(BlueprintType)
struct FThighMod_LegPitchSpring
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Thigh Mod - Leg Pitch(fwd/back) Spring")
	float LegPitchStiffness;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Thigh Mod - Leg Pitch(fwd/back) Spring")
	float LegPitchDampening;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Thigh Mod - Leg Pitch(fwd/back) Spring")
	float LegPitchMass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Thigh Mod - Leg Pitch(fwd/back) Spring")
	float LegPitchClampMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Thigh Mod - Leg Pitch(fwd/back) Spring")
	float LegPitchClampMax;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_PlayerGliderAnimAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
	TObjectPtr<UBlendSpace> Default_Base_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DefaultAdditive")
	TObjectPtr<UBlendSpace> Default_BodyAdditive_MaleMedium_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DefaultAdditive")
	TObjectPtr<UBlendSpace> Default_BodyAdditive_MaleLarge_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DefaultAdditive")
	TObjectPtr<UBlendSpace> Default_BodyAdditive_FemaleSmall_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DefaultAdditive")
	TObjectPtr<UBlendSpace> Default_BodyAdditive_FemaleMedium_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DefaultAdditive")
	TObjectPtr<UBlendSpace> Default_BodyAdditive_FemaleLarge_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DefaultTurnAdditive")
	TObjectPtr<UBlendSpace> Default_TurnAdditive_MaleMedium_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DefaultTurnAdditive")
	TObjectPtr<UBlendSpace> Default_TurnAdditive_MaleLarge_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DefaultTurnAdditive")
	TObjectPtr<UBlendSpace> Default_TurnAdditive_FemaleSmall_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DefaultTurnAdditive")
	TObjectPtr<UBlendSpace> Default_TurnAdditive_FemaleMedium_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DefaultTurnAdditive")
	TObjectPtr<UBlendSpace> Default_TurnAdditive_FemaleLarge_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Into")
	TObjectPtr<UBlendSpace> Into_Base_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Into")
	TObjectPtr<UBlendSpace> Into_Base_MaleMedium_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntoAdditive")
	TObjectPtr<UBlendSpace> Into_BodyAdditive_MaleMedium_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntoAdditive")
	TObjectPtr<UBlendSpace> Into_BodyAdditive_MaleLarge_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntoAdditive")
	TObjectPtr<UBlendSpace> Into_BodyAdditive_FemaleSmall_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntoAdditive")
	TObjectPtr<UBlendSpace> Into_BodyAdditive_FemaleMedium_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntoAdditive")
	TObjectPtr<UBlendSpace> Into_BodyAdditive_FemaleLarge_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntoTurnAdditive")
	TObjectPtr<UBlendSpace> Into_TurnAdditive_MaleMedium_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntoTurnAdditive")
	TObjectPtr<UBlendSpace> Into_TurnAdditive_MaleLarge_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntoTurnAdditive")
	TObjectPtr<UBlendSpace> Into_TurnAdditive_FemaleSmall_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntoTurnAdditive")
	TObjectPtr<UBlendSpace> Into_TurnAdditive_FemaleMedium_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IntoTurnAdditive")
	TObjectPtr<UBlendSpace> Into_TurnAdditive_FemaleLarge_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Lean")
	TObjectPtr<UBlendSpace> Lean_MaleMedium_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Lean")
	TObjectPtr<UBlendSpace> Lean_MaleLarge_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Lean")
	TObjectPtr<UBlendSpace> Lean_FemaleSmall_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Lean")
	TObjectPtr<UBlendSpace> Lean_FemaleMedium_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Lean")
	TObjectPtr<UBlendSpace> Lean_FemaleLarge_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LeanAdditive")
	TObjectPtr<UAnimSequence> LeanAdditive_Center_MaleMedium_Pose;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LeanAdditive")
	TObjectPtr<UAnimSequence> LeanAdditive_Center_MaleLarge_Pose;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LeanAdditive")
	TObjectPtr<UAnimSequence> LeanAdditive_Center_FemaleSmall_Pose;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LeanAdditive")
	TObjectPtr<UAnimSequence> LeanAdditive_Center_FemaleMedium_Pose;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LeanAdditive")
	TObjectPtr<UAnimSequence> LeanAdditive_Center_FemaleLarge_Pose;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LeanInto")
	TObjectPtr<UBlendSpace> LeanAdditive_Into_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LeanInto")
	TObjectPtr<UAnimSequence> LeanAdditive_ForwardInto_Anim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LeanInto")
	TObjectPtr<UAnimSequence> LeanAdditive_ForwardInto_FromDeploy_Anim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LeanInto")
	TObjectPtr<UAnimSequence> LeanAdditive_BackInto_Anim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LeanInto")
	TObjectPtr<UAnimSequence> LeanAdditive_LeftInto_Anim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LeanInto")
	TObjectPtr<UAnimSequence> LeanAdditive_RightInto_Anim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LeanOut")
	TObjectPtr<UAnimSequence> LeanAdditive_ForwardOut_Anim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LeanOut")
	TObjectPtr<UAnimSequence> LeanAdditive_BackOut_Anim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LeanOut")
	TObjectPtr<UAnimSequence> LeanAdditive_LeftOut_Anim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LeanOut")
	TObjectPtr<UAnimSequence> LeanAdditive_RightOut_Anim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Outro")
	TObjectPtr<UBlendSpace> ToGlide_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Outro")
	TObjectPtr<UBlendSpace> ToGlide_Lean_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Outro")
	TObjectPtr<UBlendSpace> ToDive_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Outro")
	TObjectPtr<UBlendSpace> ToDive_Lean_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WeaponR")
	TObjectPtr<UBlendSpace> Dive_WeaponR_Additive_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WeaponR")
	TObjectPtr<UAnimSequence> Glide_WeaponR_Additive_Anim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic")
	TObjectPtr<UBlendSpace> GenericAdditive_Male_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic")
	TObjectPtr<UBlendSpace> GenericAdditive_Female_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RootMod", meta=(EditCondition="bAllowPlayerDeployRootMod"))
	float RootModPitchMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RootMod", meta=(EditCondition="bAllowPlayerDeployRootMod"))
	float RootModPitchMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RootMod", meta=(EditCondition="bAllowPlayerDeployRootMod"))
	float RootModYOffsetMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RootMod", meta=(EditCondition="bAllowPlayerDeployRootMod"))
	float RootModYOffsetMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spring", meta=(DisplayName="Pelvis Mod - Vertical Input + Spring"))
	FPelvisMod_VerticalInput_Spring PelvisModVertical;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spring", meta=(DisplayName="Pelvis Mod -  Lateral Input + Spring"))
	FPelvisMod_LateralInput_Spring PelvisModLateral;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spring", meta=(DisplayName="Pelvis Mod - Bank Angle Input + Spring"))
	FPelvisMod_BankAngleInput_Spring PelvisModBankAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spring", meta=(DisplayName="Thigh Mod - Leg Angle Input"))
	FThighMod_LegAngleInput ThighModLegAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spring", meta=(DisplayName="Thigh Mod - Leg Pitch(fwd/back) Spring"))
	FThighMod_LegPitchSpring ThighModLegPitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spring", meta=(DisplayName="Thigh Mod - Leg Bank(side to side) Spring"))
	FThighMod_LegBankSpring ThighModLegBank;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spring", meta=(DisplayName="Thigh Mod - Left Leg Drag"))
	FThighMod_LeftLegDrag ThighModLeftLegDrag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GliderMode")
	EGliderType PlayerGliderType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spring")
	bool bEnableSpringMods;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RootMod")
	bool bAllowPlayerDeployRootMod;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GliderMode")
	bool bUseSurfStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GliderMode")
	bool bUseLeanPlayRateAdjust;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GliderMode")
	bool bUseForwardAs_Y_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GliderMode")
	bool bUseDeployCurveForIntoPlayRateAdjust;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GliderMode")
	float LeanForwardValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GliderMode")
	float IdleValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GliderMode")
	float LeanBackValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GliderMode")
	float IdleInterpToSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GliderMode")
	float LeanForwardInterpToSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GliderMode")
	float LeanBackInterpToSpeed;

};

