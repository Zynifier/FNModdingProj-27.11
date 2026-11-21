// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInputs/FortAnimInput_PlayerGliderAnimAsset.h"
#include "Animation/AnimInputs/FortAnimInput_PlayerSkydiveAnimAsset.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortGender.h"
#include "FortSkydivingAnimInstance.generated.h"

class UFortPlayerSkydiveAnimSet;

UCLASS(MinimalAPI, HideCategories=("AnimInstance"))
class UFortSkydivingAnimInstance : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="Skydiving")
	FFortAnimInput_Skydiving Skydiving;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="Skydiving")
	float FreeFall_AimPitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AnimSets")
	FFortAnimInput_PlayerGliderAnimAsset CurrentGliderAnimSet;

	UPROPERTY(EditDefaultsOnly, Category="Default")
	TObjectPtr<UFortPlayerSkydiveAnimSet> DefaultSkydiveAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AnimSets")
	FFortAnimInput_PlayerSkydiveAnimAsset CurrentSkydiveAnimSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Transient, Category="FortPlayerPawn")
	EFortPlayerAnimBodyType AnimBodyType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Transient, Category="FortPlayerPawn")
	TEnumAsByte<EFortCustomGender::Type> Gender;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="Weapon")
	float AimPitch;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	uint8 bIsAccelerating2D : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSkydivingAnimInstance")
	float ParaGliderTurnAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSkydivingAnimInstance")
	float ParaGliderAddAlpha;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Transient, Category="FortSkydivingAnimInstance")
	float Glider_BaseBS_Y_Axis;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Transient, Category="FortSkydivingAnimInstance")
	float Glider_BaseBS_PlayRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Transient, Category="FortSkydivingAnimInstance")
	float Glider_IntoBS_PlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSkydivingAnimInstance")
	uint8 bParaGlideSurferHipsAreLow : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSkydivingAnimInstance")
	int32 PlayerGliderLOD;

};

