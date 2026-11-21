// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "FortCosmeticItemTileButton.generated.h"

class UFortCosmeticItemCard;
class UFortItem;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortCosmeticItemTileButton : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCosmeticItemTileButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCosmeticItemCard> ItemWidget;

	UPROPERTY(BlueprintReadOnly, Category="Item Tile")
	TWeakObjectPtr<UFortItem> Item;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Tile")
	float ItemCardWidth;

private:
	UPROPERTY(EditDefaultsOnly, Category="Mobile Cosmetics")
	float MobileScalingFactor;

};

