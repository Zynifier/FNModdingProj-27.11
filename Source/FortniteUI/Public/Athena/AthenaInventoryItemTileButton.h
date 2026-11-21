// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "AthenaInventoryItemTileButton.generated.h"

class UAthenaItemIcon;
class UFortItem;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaInventoryItemTileButton : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	UFortItem* GetItemToRepresent() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemChanged(const UFortItem* Item);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryItemTileButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaItemIcon> ItemIcon;

};

