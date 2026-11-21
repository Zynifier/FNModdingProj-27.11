// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "Engine/DataTable.h"
#include "Items/FortPersistableItemDefinition.h"
#include "UObject/PrimaryAssetId.h"
#include "FortAccountItemDefinition.generated.h"

UCLASS(NotBlueprintable)
class FORTNITEGAME_API UFortAccountItemDefinition : public UFortPersistableItemDefinition
{
	GENERATED_BODY()

public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;

private:
	FPrimaryAssetId CachedPrimaryAssetId;

protected:
	UPROPERTY(EditAnywhere, Category="AccountItem")
	FCurveTableRowHandle LevelToXpHandle;

	UPROPERTY(EditAnywhere, Category="Sacrifice")
	FCurveTableRowHandle LevelToSacrificeXpHandle;

	UPROPERTY(EditAnywhere, Category="Sacrifice")
	FDataTableRowHandle SacrificeRecipe;

	UPROPERTY(EditAnywhere, Category="Sacrifice")
	FDataTableRowHandle TransmogSacrificeRow;

	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category="Conversion")
	TArray<FDataTableRowHandle> ConversionRecipes;

	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category="Conversion")
	FDataTableRowHandle UpgradeRarityRecipeHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Level")
	int32 MinLevel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Level")
	int32 MaxLevel;

	UPROPERTY()
	FString GrantToProfileType;

};

