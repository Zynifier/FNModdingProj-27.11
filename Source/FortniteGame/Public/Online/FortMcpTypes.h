// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMcpTypes.generated.h"

class UFortItem;

USTRUCT(BlueprintType)
struct FFriendCode
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FriendCode")
	FString Code;

	UPROPERTY(BlueprintReadOnly, Category="FriendCode")
	FString CodeType;

};

USTRUCT(BlueprintType)
struct FPurchasedItemInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="PurchasedItemInfo")
	TObjectPtr<UFortItem> Item;

	UPROPERTY(BlueprintReadOnly, Category="PurchasedItemInfo")
	int32 Quantity;

};

