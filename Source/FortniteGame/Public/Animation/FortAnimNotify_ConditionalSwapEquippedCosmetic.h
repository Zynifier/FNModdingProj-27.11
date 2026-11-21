// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Cosmetics/Variants/FortCosmeticLoadoutTagDrivenVariant.h"
#include "FortAnimNotify_ConditionalSwapEquippedCosmetic.generated.h"

UCLASS(HideCategories=("Object"), meta=(DisplayName="Conditional Swap Equipped Cosmetic"))
class UFortAnimNotifyState_ConditionalSwapEquippedCosmetic : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_ConditionalSwapEquippedCosmetic")
	bool bCheckBaseLoadout;

	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_ConditionalSwapEquippedCosmetic")
	TArray<FFortCosmeticDependentSwapData> Swaps;

};

UCLASS(HideCategories=("Object"), meta=(DisplayName="Conditional Swap Equipped Cosmetic"))
class UFortAnimNotify_ConditionalSwapEquippedCosmetic : public UAnimNotify
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAnimNotify_ConditionalSwapEquippedCosmetic")
	bool bCheckBaseLoadout;

	UPROPERTY(EditAnywhere, Category="FortAnimNotify_ConditionalSwapEquippedCosmetic")
	TArray<FFortCosmeticDependentSwapData> Swaps;

};

