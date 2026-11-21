// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimationBlueprintLibrary.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_Buffet_F.generated.h"

USTRUCT(BlueprintType)
struct FBuffetGravityOverrideInput
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Gravity Offset")
	float TimeOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Gravity Offset")
	float PerlinScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Gravity Offset")
	FVector Frequency;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Gravity Offset")
	FVector Amplitude;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Gravity Offset")
	FVector Offset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Gravity Offset")
	FName ReorientationJoint;

};

USTRUCT(BlueprintType)
struct FBuffetPoseSpaceDeformerInput
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet|PoseSpace Deformation")
	float DeformationValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|PoseSpace Deformation")
	FName TargetBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|PoseSpace Deformation")
	FName BaseBoneName;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_Buffet_F : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet|AnimGraph|Sim Space")
	FRotator sim_space_rotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet|AnimGraph|Sim Space")
	bool LockedOnSimSpace;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet|AnimGraph|Sim Space")
	bool InComponentSpace;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet|AnimGraph|Sim Space")
	bool InComponentSpaceLastFrame;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet|AnimGraph|Sim Space")
	float InterpSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Buffet|AnimGraph|Crouching")
	float crouchingAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Buffet|AnimGraph|Gravity")
	FVector gravityOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Buffet|Inputs|PoseSpace Deformation")
	FPoseDeformationQuery_Arms Arms;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Inputs|PoseSpace Deformation")
	FBuffetPoseSpaceDeformerInput ElbowRotR;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Inputs|PoseSpace Deformation")
	FBuffetPoseSpaceDeformerInput ElbowRotL;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Inputs|PoseSpace Deformation")
	FBuffetPoseSpaceDeformerInput ThighRotR;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Inputs|PoseSpace Deformation")
	FBuffetPoseSpaceDeformerInput ThighRotL;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Inputs|PoseSpace Deformation")
	FBuffetPoseSpaceDeformerInput KneeRotR;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Inputs|PoseSpace Deformation")
	FBuffetPoseSpaceDeformerInput KneeRotL;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Inputs|Gravity Override")
	float GravityStrength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Buffet|Inputs|Gravity Override")
	FBuffetGravityOverrideInput GravityOverrideInput;

};

