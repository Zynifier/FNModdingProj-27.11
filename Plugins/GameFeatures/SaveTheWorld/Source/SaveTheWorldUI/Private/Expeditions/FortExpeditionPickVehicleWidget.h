// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortExpeditionPickVehicleWidget.generated.h"

class UFortExpeditionItem;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortExpeditionPickVehicleWidget : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="ObjectListItem")
	void SetData(UFortExpeditionItem* InItem);

protected:
	UPROPERTY(BlueprintReadOnly, Category="Item Management|Tile")
	TWeakObjectPtr<UFortExpeditionItem> Item;

};

