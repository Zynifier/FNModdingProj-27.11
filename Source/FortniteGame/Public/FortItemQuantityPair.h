// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/PrimaryAssetId.h"
#include "FortInventoryType.h"
#include "FortItemQuantityPair.generated.h"

class UFortItem;
class UFortItemDefinition;

USTRUCT(BlueprintType)
struct FFortHiddenRewardQuantityPair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	int32 Quantity;

protected:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Data")
	TSoftObjectPtr<UFortItemDefinition> EditorOnlyItemDefinition;
#endif

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	FName TemplateId;

};

USTRUCT(BlueprintType)
struct FFortItemInstanceQuantityPair
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortItemInstanceQuantityPair")
	TObjectPtr<UFortItem> Item;

	UPROPERTY(BlueprintReadOnly, Category="FortItemInstanceQuantityPair")
	TEnumAsByte<EFortInventoryType::Type> InventoryType;

	UPROPERTY(BlueprintReadOnly, Category="FortItemInstanceQuantityPair")
	int32 Quantity;

};

USTRUCT(BlueprintType)
struct FFortItemQuantityPair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="Data")
	int32 Quantity;

private:
	UPROPERTY(EditAnywhere, SaveGame, Category="Data")
	FPrimaryAssetId ItemPrimaryAssetId;

};

