// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimationBlueprintLibrary.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CCP_AnimInstance_Body_MaleAlienTrooper.generated.h"

class UAnimMontage;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCCP_AnimInstance_Body_MaleAlienTrooper : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Alien Trooper")
	bool bIsRifleOut;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Alien Trooper")
	bool bIsPistolOut;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Alien Trooper")
	float PistolAimUpAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Alien Trooper")
	float PistolAimDownAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Alien Trooper")
	float PistolAimMidAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Alien Trooper")
	float RifleAimUpAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Alien Trooper")
	float RifleAimDownAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Male Alien Trooper")
	float IsCustomEmotePlayingAlpha;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Male Alien Trooper")
	FVector GravityOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Male Alien Trooper|Settings|Ranges")
	FMapRangeClamped_Ranges PistolAimUp_Ranges;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Male Alien Trooper|Settings|Ranges")
	FMapRangeClamped_Ranges PistolAimDown_Ranges;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Male Alien Trooper|Settings|Ranges")
	FMapRangeClamped_Ranges PistolAimMidLowBound_Ranges;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Male Alien Trooper|Settings|Ranges")
	FMapRangeClamped_Ranges PistolAimMidHighBound_Ranges;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Male Alien Trooper|Settings|Ranges")
	FMapRangeClamped_Ranges RifleAimUp_Ranges;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Male Alien Trooper|Settings|Ranges")
	FMapRangeClamped_Ranges RifleAimDown_Ranges;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Male Alien Trooper|Settings")
	TArray<TSoftObjectPtr<UAnimMontage>> CustomEmoteMontageList;

};

