// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "FortCraftingListEntry.generated.h"

class UAthenaItemIcon;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCraftingListEntry : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCraftingListItemSet();

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCraftingListEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaItemIcon> ItemIcon;

	UPROPERTY(BlueprintReadOnly, Category="FortCraftingListEntry", meta=(AllowPrivateAccess))
	bool bCanCraftItem;

};

