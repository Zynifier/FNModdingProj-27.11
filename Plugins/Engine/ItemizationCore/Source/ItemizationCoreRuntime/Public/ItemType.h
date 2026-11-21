// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemType.generated.h"

// Representative item type, such as 'resource', 'armor', etc.

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemType : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Item Type")
	FText Name;

	UPROPERTY(EditDefaultsOnly, Category="Item Type")
	FText Description;

};

