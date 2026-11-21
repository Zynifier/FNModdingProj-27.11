// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InventoryRestriction.generated.h"

class UItemType;

UCLASS()
class ITEMIZATIONCORERUNTIME_API UInventoryRestriction : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Inventory Restriction")
	FText RestrictionName;

	//TODO: Make a TSet? There's no reason for this to not be as it also stops redundant entries.

	UPROPERTY(EditDefaultsOnly, Category="Inventory Restriction")
	TArray<TObjectPtr<UItemType>> ItemTypes;

};

