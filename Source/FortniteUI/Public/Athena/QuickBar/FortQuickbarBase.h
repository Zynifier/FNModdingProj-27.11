// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "FortQuickbarBase.generated.h"

class UFortQuickBarSlotBase;

UCLASS(MinimalAPI, meta=(DisableNativeTick))
class UFortQuickbarBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, Category="Tutorial")
	UFortQuickBarSlotBase* GetSpecificSlot(int32 SlotNumber) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnShouldShowBothQuickbarsChanged(bool bShouldShowBothQuickbars);

};

