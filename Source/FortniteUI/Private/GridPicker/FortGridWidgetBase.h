// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ContentWidget.h"
#include "Layout/Margin.h"
#include "Styling/SlateBrush.h"
#include "GridPicker/FortGridPickerTile.h"
#include "GridPicker/FortGridSorting.h"
#include "FortGridWidgetBase.generated.h"

class UFortGridPickerTile;
class UObject;

UCLASS(Abstract)
class UFortGridWidgetBase : public UContentWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Tile|Getters")
	virtual UFortGridPickerTile* GetTileForObject(const UObject* Object);

	UFUNCTION(BlueprintPure, Category="Tile|Getters")
	virtual TArray<UFortGridPickerTile*> GetTiles();

	UFUNCTION(BlueprintCallable, Category="Tile|Setters")
	void SetClearWidgetType(TSubclassOf<UFortGridPickerTile> InClearWidgetType);

	UFUNCTION(BlueprintCallable, Category="Grid Picker")
	void SetDataProvider(const TArray<UObject*>& Data);

	UFUNCTION(BlueprintCallable, Category="Tile|Setters")
	void SetPeekOverflowTilePercentage(float Percent);

	UFUNCTION(BlueprintCallable, Category="Tile|Setters")
	void SetTileHeight(float Height);

	UFUNCTION(BlueprintCallable, Category="Tile|Setters")
	void SetTilePadding(FMargin Padding);

	UFUNCTION(BlueprintCallable, Category="Tile|Setters")
	void SetTilesAcross(int32 Across);

	UFUNCTION(BlueprintCallable, Category="Tile|Setters")
	void SetTilesDown(int32 Down);

	UFUNCTION(BlueprintCallable, Category="Tile|Setters")
	void SetTileWidth(float Width);

	UPROPERTY(BlueprintAssignable, Category="Grid Picker|Event")
	FGridPickerTileEvent OnTileGenerated;

	UPROPERTY(BlueprintAssignable, Category="Grid Picker|Event")
	FGridPickerTileEvent OnTileClicked;

	UPROPERTY(BlueprintAssignable, Category="Grid Picker|Event")
	FGridPickerTileEvent OnMouseEnterTile;

	UPROPERTY(BlueprintAssignable, Category="Grid Picker|Event")
	FGridPickerTileEvent OnMouseLeaveTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tile settings")
	TSubclassOf<UFortGridPickerTile> TileWidgetType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sorting")
	EGridSortKind SortKind;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sorting")
	bool bReversed;

	UPROPERTY(EditAnywhere, Category="Sorting", meta=(IsBindableEvent="True"))
	FGetSortKeyFor GetSortKeyFor;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tile settings")
	TSubclassOf<UFortGridPickerTile> ClearWidgetType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tile settings")
	float TileWidth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tile settings")
	float TileHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tile settings")
	int32 TilesAcross;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tile settings")
	int32 TilesDown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tile settings")
	bool bShrinkToFit;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tile settings")
	float PeekOverflowTilePercentage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tile settings")
	FMargin TilePadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FSlateBrush GridBackground;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FMargin GridBackgroundPadding;

	UPROPERTY(BlueprintReadOnly, Category="FortGridWidgetBase")
	TArray<TObjectPtr<UObject>> DataProvider;

};

