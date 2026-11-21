// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemAttribute.h"
#include "ItemComponentBase.h"
#include "ItemComponent_Core.generated.h"

class UItemRarityTable;
class UItemType;

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemAttribute_Rarity : public UItemAttribute_Int
{
	GENERATED_BODY()

};

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemAttribute_WasLoadedFromSave : public UItemAttribute_Bool
{
	GENERATED_BODY()

};

UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemComponent_Core : public UItemComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Core Component")
	UItemRarityTable* GetItemRarityTable() const;

	UFUNCTION(BlueprintPure, Category="Core Component")
	UItemType* GetItemType() const;

private:
	UPROPERTY(EditDefaultsOnly, Category="Core Component")
	TObjectPtr<UItemType> ItemType;

	UPROPERTY(EditDefaultsOnly, Category="Core Component")
	TObjectPtr<UItemRarityTable> ItemRarityTable;

	UPROPERTY(EditDefaultsOnly, Category="Item Component", meta=(ClampMin="0"))
	int64 DefaultRarityIndex;

};

