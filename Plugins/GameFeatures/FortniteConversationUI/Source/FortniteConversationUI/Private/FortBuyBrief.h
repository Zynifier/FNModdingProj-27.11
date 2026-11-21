// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortItemTransactionBrief.h"
#include "FortBuyBrief.generated.h"

enum class ECannotBuyReason : uint8;

UENUM(BlueprintType)
enum class ECannotBuyReason : uint8
{
	CannotAfford = 0,
	OutOfStock = 1,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortBuyBrief : public UFortItemTransactionBrief
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnDisplayUnavailability(ECannotBuyReason CannotBuyReason);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnPurchaseDataReceived(int32 StackSize, int32 RemainingForSale);

};

