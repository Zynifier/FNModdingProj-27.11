// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimationBlueprintLibrary.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CCP_AnimInstance_Dark_Minion.generated.h"

UCLASS(MinimalAPI, HideCategories=("AnimInstance"))
class UCCP_AnimInstance_Dark_Minion : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnGravityOverrideUpdate();

	UPROPERTY(BlueprintReadOnly, Transient, Category="DarkMinion|Event Graph|Native Properties|float")
	float CrouchFloat;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DarkMinion|Event Graph|Native Properties|float")
	float LegOutR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DarkMinion|Event Graph|Native Properties|float")
	float LegUpL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DarkMinion|Event Graph|Native Properties|float")
	float LegUpStrapL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DarkMinion|Event Graph|Native Properties|float")
	float LegUpStrapR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DarkMinion|Event Graph|Native Properties|float")
	float SubLegL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DarkMinion|Event Graph|Native Properties|float")
	float LegUpClothL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DarkMinion|Event Graph|Native Properties|float")
	float LegOutClothL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DarkMinion|Event Graph|Native Properties|float")
	float SubLegHighL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DarkMinion|Event Graph|Native Properties|float")
	float LegUpClothR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DarkMinion|Event Graph|Native Properties|bool")
	bool bIsWearingJumpBoots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="DarkMinion|Settings|FGameplayTag")
	FGameplayTag JumpBootsTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FName ThighLBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FName ThighRBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FName PelvisBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	TEnumAsByte<EAlphaFromDeltaTypes::Type> LegUpL_DeltaComponentType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector2D LegUpL_InputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector2D LegUpL_OutputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector LegUpL_TwistAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	TEnumAsByte<EAlphaFromDeltaTypes::Type> LegUpStrapL_DeltaComponentType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector2D LegUpStrapL_InputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector2D LegUpStrapL_OutputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector LegUpStrapL_TwistAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	TEnumAsByte<EAlphaFromDeltaTypes::Type> LegUpClothL_DeltaComponentType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector2D LegUpClothL_InputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector2D LegUpClothL_OutputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector LegUpClothL_TwistAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	TEnumAsByte<EAlphaFromDeltaTypes::Type> LegOutClothL_DeltaComponentType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector2D LegOutClothL_InputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector2D LegOutClothL_OutputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector LegOutClothL_TwistAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	TEnumAsByte<EAlphaFromDeltaTypes::Type> LegUpClothR_DeltaComponentType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector2D LegUpClothR_InputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector2D LegUpClothR_OutputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector LegUpClothR_TwistAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	TEnumAsByte<EAlphaFromDeltaTypes::Type> LegUpStrapR_DeltaComponentType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector2D LegUpStrapR_InputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector2D LegUpStrapR_OutputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector LegUpStrapR_TwistAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	TEnumAsByte<EAlphaFromDeltaTypes::Type> LegOutR_DeltaComponentType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector2D LegOutR_InputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector2D LegOutR_OutputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector LegOutR_TwistAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	float LegUpStrapL_IsJumpingTargetMult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	float LegUpStrapL_IsJumpingInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	TEnumAsByte<EAlphaFromDeltaTypes::Type> SubLegL_DeltaComponentType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector2D SubLegL_InputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector2D SubLegL_OutputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector SubLegL_TwistAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	TEnumAsByte<EAlphaFromDeltaTypes::Type> SubLegHighL_DeltaComponentType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector2D SubLegHighL_InputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector2D SubLegHighL_OutputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	FVector SubLegHighL_TwistAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	float LegUpL_Crouching;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DarkMinion|Event Graph|Settings|MagicalNumber")
	float SubLegL_NotCrouching;

};

