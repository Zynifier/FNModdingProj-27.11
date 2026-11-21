// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAnimInput_PlayerSkydiveAnimAsset.generated.h"

class UAnimSequence;
class UBlendSpace;

USTRUCT(BlueprintType)
struct FFortAnimInput_PlayerSkydiveAnimAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Diving")
	TObjectPtr<UBlendSpace> Dive_BS_Female;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Diving")
	TObjectPtr<UBlendSpace> Dive_BS_Male;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Diving")
	TObjectPtr<UBlendSpace> Dive_ToGlide_BS_Female;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Diving")
	TObjectPtr<UBlendSpace> Dive_ToGlide_BS_Male;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Diving")
	TObjectPtr<UBlendSpace> Dive_Lean_Additive_BS_Female;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Diving")
	TObjectPtr<UBlendSpace> Dive_Lean_Additive_BS_Male;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Diving")
	TObjectPtr<UAnimSequence> Dive_Lean_Center_Pose;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Diving")
	TObjectPtr<UBlendSpace> Dive_Turn_Additive_BS_Female;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Diving")
	TObjectPtr<UBlendSpace> Dive_Turn_Additive_BS_Male;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Diving")
	TObjectPtr<UBlendSpace> Dive_DriftA_Additive_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Diving")
	TObjectPtr<UBlendSpace> Dive_DriftB_Additive_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Diving")
	TObjectPtr<UBlendSpace> Dive_DriftC_Additive_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Diving")
	TObjectPtr<UBlendSpace> Dive_FidgetA_Additive_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Diving")
	TObjectPtr<UBlendSpace> Dive_FidgetB_Additive_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Diving")
	TObjectPtr<UBlendSpace> Dive_FidgetC_Additive_BS;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gliding")
	TObjectPtr<UBlendSpace> Glide_BS_Female;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gliding")
	TObjectPtr<UBlendSpace> Glide_BS_Male;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gliding")
	TObjectPtr<UBlendSpace> Glide_ToDive_BS_Female;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gliding")
	TObjectPtr<UBlendSpace> Glide_ToDive_BS_Male;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gliding")
	TObjectPtr<UBlendSpace> Glide_Lean_Additive_BS_Female;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gliding")
	TObjectPtr<UBlendSpace> Glide_Lean_Additive_BS_Male;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gliding")
	TObjectPtr<UBlendSpace> Glide_Turn_Additive_BS_Female;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gliding")
	TObjectPtr<UBlendSpace> Glide_Turn_Additive_BS_Male;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gliding")
	TObjectPtr<UAnimSequence> Glide_DriftA_Additive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gliding")
	TObjectPtr<UAnimSequence> Glide_DriftB_Additive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gliding")
	TObjectPtr<UAnimSequence> Glide_DriftC_Additive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gliding")
	TObjectPtr<UAnimSequence> Glide_DriftZero_Additive;

};

