// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUserWidget.h"
#include "FortGridPickerTile.generated.h"

class UFortGridPickerTile;
class UFortGridWidgetBase;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGridPickerTileEvent, UObject*, Data, UFortGridPickerTile*, Tile);

UCLASS()
class UFortGridPickerTile : public UFortUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="Grid Picker")
	void ForwardClicked();

	UFUNCTION(BlueprintImplementableEvent, Category="Grid Picker", meta=(BlueprintProtected="true"))
	void OnClicked();

	UFUNCTION(BlueprintImplementableEvent, Category="Grid Picker", meta=(BlueprintProtected="true"))
	void SetData(UObject* InData);

private:
	UPROPERTY()
	TObjectPtr<UObject> Data;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortGridWidgetBase> Owner;

};

