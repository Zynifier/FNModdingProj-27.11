// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaSpectatorInventorySlotBase.generated.h"

class UFortItem;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaSpectatorInventorySlotBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	UFortItem* GetItem() const;

	UFUNCTION(BlueprintImplementableEvent)
	void SetIsSelected(bool bIsSelected);

	UFUNCTION(BlueprintImplementableEvent)
	void SetItem(const UFortItem* Item);

};

