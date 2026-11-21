// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CatalogTypes.h"
#include "McpCatalogItemPrice.h"
#include "FortGiftingSocialUserTypes.generated.h"

USTRUCT()
struct FFortGiftingRecipientState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FCatalogItemPrice Price;

	UPROPERTY()
	TArray<FItemQuantity> Items;

};

