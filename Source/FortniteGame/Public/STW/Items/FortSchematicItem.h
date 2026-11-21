// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTypes.h"
#include "STW/Items/FortAlterableItem.h"
#include "FortSchematicItem.generated.h"

UCLASS(MinimalAPI)
class UFortSchematicItem : public UFortAlterableItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Item")
	int32 GetRequiredTeamLevelToCraft() const;

	UFUNCTION(BlueprintPure, Category="Item")
	int32 GetSchematicQuantityProduced() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FRecipe GetSchematicRecipe() const;

	UFUNCTION(BlueprintPure, Category="Item")
	bool IsBulkCraftable() const;

	UPROPERTY()
	bool refundable;

	UPROPERTY()
	bool refund_legacy_item;

	UPROPERTY()
	TArray<FString> alteration_base_rarities;

protected:
	UPROPERTY(Transient)
	bool bGrantedByAbility;

	UPROPERTY(Transient)
	int32 RequiredTeamLevel;

};

