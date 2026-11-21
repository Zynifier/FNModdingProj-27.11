// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/Color.h"
#include "ItemRarityTable.generated.h"

USTRUCT()
struct FVkRarityEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Rarity")
	FText Name;

	UPROPERTY(EditDefaultsOnly, Category="Rarity")
	FText Description;

	UPROPERTY(EditDefaultsOnly, Category="Rarity")
	FLinearColor Color;

};

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemRarityTable : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Rarity Table")
	FText RarityTableName;

	UPROPERTY(EditDefaultsOnly, Category="Rarity Table")
	FText RarityTableDescription;

	UPROPERTY(EditDefaultsOnly, Category="Rarity Table")
	TArray<FVkRarityEntry> RarityList;

};

