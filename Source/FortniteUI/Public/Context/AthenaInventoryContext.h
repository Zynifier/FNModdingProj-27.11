// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintContextBase.h"
#include "AthenaInventoryContext.generated.h"

class UFortItem;

UCLASS(MinimalAPI)
class UAthenaInventoryContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAthenaInventoryItemSelected, UFortItem*, Item);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAthenaInventorySwapComplete);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAthenaInventorySwapStarted, int32, SlotIndex);

public:
	UFUNCTION(BlueprintCallable)
	void CancelSwap();

	UFUNCTION(BlueprintPure)
	UFortItem* GetSelectedInventoryItem() const;

	UFUNCTION(BlueprintPure)
	bool IsSwapping() const;

	UFUNCTION(BlueprintCallable)
	void SetSelectedInventoryItem(UFortItem* Item);

	UFUNCTION(BlueprintCallable)
	void StartOrFinishSwap(const int32 SlotIndex);

	UPROPERTY(BlueprintAssignable)
	FOnAthenaInventoryItemSelected OnInventoryItemSelected;

	UPROPERTY(BlueprintAssignable)
	FOnAthenaInventorySwapStarted OnInventorySwapStarted;

	UPROPERTY(BlueprintAssignable)
	FOnAthenaInventorySwapComplete OnInventorySwapComplete;

};

