// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "FortUITypes.h"
#include "ItemTiles/FortItemListViewInterface.h"
#include "FortItemTileButton.generated.h"

class IFortItemViewContextInterface;
class UFortItem;
class UFortMultiSizeItemCard;
enum class EFortItemCardSize : uint8;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortItemTileButton : public UCommonButtonLegacy, public IUserObjectListEntry, public IFortItemListEntryWidgetInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Item Tile")
	FORTNITEUI_API void OnTileSizeOverrideCheck(EFortItemCardSize SizeIn, EFortItemCardSize& SizeOut) const;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemTileButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMultiSizeItemCard> ItemWidget;

	UPROPERTY(BlueprintReadOnly, Category="Item Tile")
	TWeakObjectPtr<UFortItem> Item;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Tile")
	EFortItemCardSize ItemCardSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Tile")
	bool IsRewardCard;

	UPROPERTY()
	TScriptInterface<IFortItemViewContextInterface> ItemViewContext;

};

