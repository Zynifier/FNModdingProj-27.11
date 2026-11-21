// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "FortItemQuantityPair.h"
#include "Items/FortPersistableItem.h"
#include "FortAccountItem.generated.h"

UCLASS(MinimalAPI, NotBlueprintable)
class UFortAccountItem : public UFortPersistableItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Item")
	virtual FDateTime GetCreationTime() const;

	UFUNCTION(BlueprintPure, Category="Sacrifice")
	TArray<FFortItemQuantityPair> GetRecyclingRefunds() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual TArray<FFortItemQuantityPair> GetRefundResults() const;

	UFUNCTION(BlueprintPure, Category="Item")
	bool HasBeenSeenLocally() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual bool IsArchived() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual bool IsFavorite() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual bool IsRefundable() const;

	UFUNCTION(BlueprintCallable, Category="Item")
	void MarkItemAsSeenBP();

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortAccountItem")
	int32 level;

	UPROPERTY(BlueprintReadOnly, Category="FortAccountItem")
	int32 xp;

	UPROPERTY(BlueprintReadOnly, Category="FortAccountItem")
	int32 item_seen;

	UPROPERTY(BlueprintReadOnly, Category="FortAccountItem")
	int32 favorite;

	UPROPERTY(BlueprintReadOnly, Category="FortAccountItem")
	int32 archived;

	UPROPERTY(BlueprintReadOnly, Category="FortAccountItem")
	int32 max_level_bonus;

	UPROPERTY()
	FString inventory_overflow_date;

	UPROPERTY()
	FDateTime creation_time;

	UPROPERTY()
	bool bIsPendingBeingMarkedAsSeen;

	UPROPERTY()
	bool bNeedsResolveMarkedAsSeen;

};

