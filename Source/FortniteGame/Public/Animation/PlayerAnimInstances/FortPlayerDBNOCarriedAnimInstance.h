// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInputs/FortAnimInput_DBNOCarried.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortPlayerDBNOCarriedAnimInstance.generated.h"

UCLASS(MinimalAPI, HideCategories=("AnimInstance"))
class UFortPlayerDBNOCarriedAnimInstance : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DBNOCarried")
	FFortAnimInput_DBNOCarried DBNOCarriedInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="IK")
	float RightHandIKAlpha;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="DBNO")
	uint8 bIsBeingInterrogated : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Gender")
	uint8 bIsFemale : 1;

};

