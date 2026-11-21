// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "FortExpeditionListItemWidget.generated.h"

class UFortExpeditionItem;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortExpeditionListItemWidget : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Expedition")
	void OnItemChanged();

	UPROPERTY(BlueprintReadOnly, Category="Expedition|Item")
	TWeakObjectPtr<UFortExpeditionItem> Item;

};

