// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAnimInput_WeaponAdditiveAnimAsset.generated.h"

class UAnimSequence;

USTRUCT(BlueprintType)
struct FFortAnimInput_WeaponAdditiveAnimAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> TargetingAdditivePoseOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> NonTargetedAdditivePoseOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> RelaxedAdditivePoseOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> RelaxedWhileSprintingAdditiveAnim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	TObjectPtr<UAnimSequence> RelaxedWhileCrouchSprintingAdditiveAnim;

};

