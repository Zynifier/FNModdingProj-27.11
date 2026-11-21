// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimationBlueprintLibrary.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CCP_AnimInstance_Backpack_GarageBand.generated.h"

class USkeletalMeshComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCCP_AnimInstance_Backpack_GarageBand : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="Garage Band|Event Graph|Native Properties|Components", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> SkelMesh;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Garage Band|Event Graph|Native Properties|Rotators")
	FRotator BackpackRotator;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Garage Band|Event Graph|Native Properties|Floats")
	float SwingRotationAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Garage Band|Event Graph|Native Properties|Floats")
	float BackpackRotationAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Names")
	FName BackpackRotationAlpha_DeltaFromRefPose_BoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Names")
	FName BackpackRotationAlpha_DeltaFromRefPose_BaseName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Floats")
	float BackpackRotationAlpha_ClampMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Floats")
	float BackpackRotationAlpha_ClampMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Map Range Clamped|Floats")
	float BackpackRotationAlpha_InRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Map Range Clamped|Floats")
	float BackpackRotationAlpha_InRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Map Range Clamped|Floats")
	float BackpackRotationAlpha_OutRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Map Range Clamped|Floats")
	float BackpackRotationAlpha_OutRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Positive Input|Names")
	FName Positive_AlphaFromTransformDelta_BoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Positive Input|Names")
	FName Positive_AlphaFromTransformDelta_BaseName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Positive Input|Enums")
	TEnumAsByte<EAlphaFromDeltaTypes::Type> Positive_DeltaComponentType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Positive Input|Vectors")
	FVector2D Positive_InputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Positive Input|Vectors")
	FVector2D Positive_OutputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Positive Input|Vectors")
	FVector Positive_TwistAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Negative Input|Names")
	FName Negative_AlphaFromTransformDelta_BoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Negative Input|Names")
	FName Negative_AlphaFromTransformDelta_BaseName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Negative Input|Enums")
	TEnumAsByte<EAlphaFromDeltaTypes::Type> Negative_DeltaComponentType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Negative Input|Vectors")
	FVector2D Negative_InputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Negative Input|Vectors")
	FVector2D Negative_OutputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotation Alpha|Negative Input|Vectors")
	FVector Negative_TwistAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotator|Names")
	FName BackpackRotator_DeltaFromRefPose_BoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotator|Names")
	FName BackpackRotator_DeltaFromRefPose_BaseName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotator|Map Range Clamped|Floats")
	float BackpackRotator_InRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotator|Map Range Clamped|Floats")
	float BackpackRotator_InRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotator|Map Range Clamped|Floats")
	float BackpackRotator_OutRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotator|Map Range Clamped|Floats")
	float BackpackRotator_OutRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotator|Names")
	FName SwingRotationAlpha_DeltaFromRefPose_BoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotator|Names")
	FName SwingRotationAlpha_DeltaFromRefPose_BaseName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotator|Map Range Clamped|Floats")
	float SwingRotationAlpha_InRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotator|Map Range Clamped|Floats")
	float SwingRotationAlpha_InRangeB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotator|Map Range Clamped|Floats")
	float SwingRotationAlpha_OutRangeA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Event Graph|Settings|Backpack Rotator|Map Range Clamped|Floats")
	float SwingRotationAlpha_OutRangeB;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Garage Band|Anim Graph|Native Properties|Vectors")
	FVector BackpackTranslation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Anim Graph|Settings|Backpack Translation|Floats")
	float PawnSpeedMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Anim Graph|Settings|Backpack Translation|Floats")
	float PawnSpeedAdditive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Anim Graph|Settings|Backpack Translation|Floats")
	float AimPitchMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Anim Graph|Settings|Backpack Translation|Floats")
	float Translation_AxisX_Modifier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Garage Band|Anim Graph|Settings|Backpack Translation|Floats")
	float Translation_AxisZ_Modifier;

};

