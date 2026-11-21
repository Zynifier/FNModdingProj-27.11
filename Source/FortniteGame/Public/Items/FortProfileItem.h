// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortPersistableItem.h"
#include "FortProfileItem.generated.h"

UCLASS(NotBlueprintable)
class UFortProfileItem : public UFortPersistableItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Item")
	void MarkItemAsSeen();

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortProfileItem")
	uint8 item_seen : 1;

	UPROPERTY(BlueprintReadOnly, Category="FortProfileItem")
	uint8 favorite : 1;

};

