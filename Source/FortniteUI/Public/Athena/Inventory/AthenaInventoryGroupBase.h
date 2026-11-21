// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortInventoryFilterEnum.h"
#include "Items/FortItemTypeEnum.h"
#include "AthenaInventoryGroupBase.generated.h"

class UAthenaInventoryPanel;
class UFortItemTileView;

UCLASS(Abstract, meta=(DisableNativeTick))
class FORTNITEUI_API UAthenaInventoryGroupBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryGroupBase")
	TWeakObjectPtr<UAthenaInventoryPanel> ParentInventoryPanel;

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryGroupBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortItemTileView> ItemTileView;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryGroupBase")
	TArray<EFortItemType> FilteredItemTypes;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryGroupBase")
	int32 DefaultNumEntries;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryGroupBase")
	EInventoryContentSortType InventoryContentSortType;

};

