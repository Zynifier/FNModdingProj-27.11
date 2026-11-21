// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Animation/FortAnimInstance.h"
#include "FortAnimNotify_SetRelaxedState.generated.h"

UCLASS(HideCategories=("Object", "Object"), meta=(DisplayName="Set Relaxed State"))
class UFortAnimNotify_SetRelaxedState : public UAnimNotify
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAnimNotify_SetRelaxedState")
	EAnimRelaxedState NewRelaxedState;

};

