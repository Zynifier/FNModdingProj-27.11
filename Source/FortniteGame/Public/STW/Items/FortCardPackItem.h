// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "McpSharedTypes.h"
#include "FortCardPackItem.generated.h"

class UFortAccountItemDefinition;
class UFortItem;

UCLASS(MinimalAPI)
class UFortCardPackItem : public UFortAccountItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="CardPack")
	bool CanStoreOpen() const;

	UFUNCTION(BlueprintPure, Category="CardPack")
	void GetChoiceItems(TArray<UFortItem*>& ChoiceAttributes) const;

	UFUNCTION(BlueprintPure, Category="CardPack")
	void GetChoices(TArray<UFortAccountItemDefinition*>& Choices) const;

	UFUNCTION(BlueprintPure, Category="CardPack")
	bool IsChoicePack() const;

	UPROPERTY()
	TArray<FMcpLootEntry> options;

	UPROPERTY(BlueprintReadOnly, Category="FortCardPackItem")
	FString pack_source;

	UPROPERTY(BlueprintReadOnly, Category="FortCardPackItem")
	bool is_loot_tier_overridden;

	UPROPERTY(BlueprintReadOnly, Category="FortCardPackItem")
	int32 override_loot_tier;

};

