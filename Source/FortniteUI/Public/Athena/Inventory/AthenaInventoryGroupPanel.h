// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaInventoryGroupPanel.generated.h"

class UAthenaInventoryGroupBase;
class UVerticalBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class FORTNITEUI_API UAthenaInventoryGroupPanel : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void GetOrCreateInventoryGroups(TArray<UAthenaInventoryGroupBase*>& OutInventoryGroups);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Inventory", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UVerticalBox> ExtensionRowHolder;

};

