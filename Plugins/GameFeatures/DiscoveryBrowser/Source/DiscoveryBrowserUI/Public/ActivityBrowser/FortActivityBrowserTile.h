// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActivityBrowser/FortActivityBrowserTileBase.h"
#include "FortActivityBrowserTile.generated.h"

class UFortActivityTileDetailsDisplay;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortActivityBrowserTile : public UFortActivityBrowserTileBase
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleActivitySelected();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityBrowserTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityTileDetailsDisplay> Display_TileDetails;

};

