// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAnimationBlueprintLibrary.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CCP_AnimInstance_FaceAcc_JourneyMentor.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCCP_AnimInstance_FaceAcc_JourneyMentor : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Journey Mentor")
	bool bIsWearingBackpack;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Journey Mentor")
	bool bIsWearingBackpackAndNotPlayingEmote;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Journey Mentor")
	float HeadAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Journey Mentor")
	float UpperArmLRotUpAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Journey Mentor")
	float TransformBackBraidAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Journey Mentor")
	float IsCrouchMovingAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Journey Mentor")
	float IsSkyDivingAlpha;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Journey Mentor|Settings")
	FMapRangeClamped_Ranges HeadAlphaRanges;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Journey Mentor|Settings")
	FMapRangeClamped_Ranges UpperArmLRotUpAlphaRanges;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Journey Mentor|Settings")
	FName HeadAlphaBoneName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Journey Mentor|Settings")
	FName HeadAlphaBaseName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Journey Mentor|Settings")
	FName UpperArmLRotUpAlphaBoneName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Journey Mentor|Settings")
	FName UpperArmLRotUpAlphaBaseName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Journey Mentor|Settings")
	float TransformBackBraidAlphaSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Journey Mentor|Settings")
	float LongBackblingThreshold;

};

