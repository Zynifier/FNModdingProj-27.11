// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonTextBlock.h"
#include "FortItemDisplayNameText.generated.h"

class UFortItem;

UCLASS(BlueprintType, PrioritizeCategories=("Content"))
class UFortItemDisplayNameText : public UCommonTextBlock
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Item Display Name Text")
	void SetItemToRepresent(UFortItem* ItemToRepresent);

	UPROPERTY(BlueprintReadOnly, Category="Item Display Name Text", meta=(ExposeOnSpawn))
	TWeakObjectPtr<UFortItem> ItemToRepresent;

};

