// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Misc/Guid.h"
#include "Cosmetics/Variants/FortAppliedSwapItemAndVariantStateEnum.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "FortAnimNotifyState_SwapEquippedItem.generated.h"

UCLASS(HideCategories=("Object"), meta=(DisplayName="Swap Equipped Item"))
class UFortAnimNotifyState_SwapEquippedItem : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Swap")
	FGuid SwapId;

	UPROPERTY(EditAnywhere, Category="Swap")
	TArray<FFortSwapItemAndVariantData> SwapData;

	UPROPERTY(EditAnywhere, Category="Swap")
	EFortAppliedSwapItemAndVariantState ForcedSwapState;

};

