// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "McpCatalogItemsForRandomPlayer.generated.h"

UCLASS(Config=Game)
class GAMESUBCATALOG_API UMcpCatalogItemsForRandomPlayer : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	uint32 Percentage;

	UPROPERTY(Config)
	FString Salt;

	UPROPERTY(Config)
	TArray<FString> CatalogItems;

};

