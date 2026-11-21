// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortProgressiveSetList.generated.h"

class UAthenaScrollBox;
class UCommonButtonGroupBase;
class UFortProgressiveSetTile;
class UFortSwipePanel;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortProgressiveSetList : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	UFortProgressiveSetTile* AddSetTile();

	UFUNCTION(BlueprintImplementableEvent)
	void ClearSetTiles();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaScrollBox> ScrollBox_SetList;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSwipePanel> SwipePanel_Navigation;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupBase> ButtonGroup_SetTiles;

	UPROPERTY(EditDefaultsOnly, Category="FortProgressiveSetList")
	int32 NumTilesPerPage;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortProgressiveSetTile>> SetTiles;

};

