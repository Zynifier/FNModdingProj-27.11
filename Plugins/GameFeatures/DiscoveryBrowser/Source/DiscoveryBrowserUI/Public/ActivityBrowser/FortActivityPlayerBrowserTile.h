// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActivityBrowser/FortActivityTileViewTileBase.h"
#include "FortActivityPlayerBrowserTile.generated.h"

class UCommonTextBlock;
class UFortActivityTileDetailsDisplay;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortActivityPlayerBrowserTile : public UFortActivityTileViewTileBase
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleActivitySelected();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityPlayerBrowserTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityTileDetailsDisplay> Display_TileDetails;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_LastPlayedDate;

};

