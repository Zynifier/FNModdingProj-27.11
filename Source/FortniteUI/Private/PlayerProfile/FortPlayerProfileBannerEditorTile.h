// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "FortPlayerProfileBannerEditorTile.generated.h"

class UFortItem;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortPlayerProfileBannerEditorTile : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="Item Tile")
	TWeakObjectPtr<UFortItem> Item;

};

