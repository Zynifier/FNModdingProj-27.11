// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimationBlueprintLibrary.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CCP_AnimInstance_Body_FemaleCavern.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCCP_AnimInstance_Body_FemaleCavern : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Cavern")
	float LookUp_L;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Cavern")
	float LookUp_R;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Cavern")
	float LegRot_R;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Cavern")
	FVector SlopeRootTrans;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Female Cavern")
	FRotator SlopeFootRot;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Female Cavern")
	FRotator SimSpaceRot;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Female Cavern|Settings")
	FName UpperArmLBoneName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Female Cavern|Settings")
	FName UpperArmRBoneName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Female Cavern|Settings")
	FName ClavicleLBoneName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Female Cavern|Settings")
	FName ClavicleRBoneName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Female Cavern|Settings")
	FName ThighRBoneName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Female Cavern|Settings")
	FName PelvisBoneName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Female Cavern|Settings")
	FMapRangeClamped_Ranges LookUpLRanges;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Female Cavern|Settings")
	FMapRangeClamped_Ranges LookUpRRanges;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Female Cavern|Settings")
	TEnumAsByte<EAlphaFromDeltaTypes::Type> LegRotRReferenceTransform_DeltaComponentType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Female Cavern|Settings")
	FVector2D LegRotRReferenceTransform_InputRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Female Cavern|Settings")
	FVector2D LegRotRReferenceTransform_OutputRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Female Cavern|Settings")
	FVector LegRotRReferenceTransform_TwistAxis;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Female Cavern|Settings")
	float ComplexSimSpace_InterSpeedMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Female Cavern|Settings")
	float ComplexSimSpace_PawnSpeedMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Female Cavern|Settings")
	float ComplexSimSpace_RInterpErrorTolerance;

};

