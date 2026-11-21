// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Animation/FortAnimNotify_CycleCharacterVariants.h"
#include "FortAnimNotifyState_CycleCharacterVariants.generated.h"

UCLASS(HideCategories=("Object"), meta=(DisplayName="Swap Active Character Variant (Complex)"))
class UFortAnimNotifyState_CycleCharacterVariants : public UAnimNotifyState
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Variant Swapping", meta=(TitleProperty="ItemToManage"))
	TArray<FFortCosmeticVariantSwapData> TransitionData;

};

