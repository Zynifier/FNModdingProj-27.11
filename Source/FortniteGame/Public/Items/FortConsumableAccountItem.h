// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "FortConsumableAccountItem.generated.h"

UCLASS(MinimalAPI)
class UFortConsumableAccountItem : public UFortAccountItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="HomebaseInventory")
	bool CanActivateOnOthers();

	UFUNCTION(BlueprintCallable, Category="HomebaseInventory")
	bool CanActivateOnSelf();

};

