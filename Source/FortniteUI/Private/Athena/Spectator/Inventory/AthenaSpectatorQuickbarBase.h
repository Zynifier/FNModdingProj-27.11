// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaSpectatorQuickbarBase.generated.h"

class UAthenaSpectatorInventorySlotBase;
enum class EFortQuickBars : uint8;

UCLASS(Abstract)
class UAthenaSpectatorQuickbarBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Export, Category="AthenaSpectatorQuickbarBase", meta=(EditInline="true"))
	TArray<TObjectPtr<UAthenaSpectatorInventorySlotBase>> ItemSlots;

private:
	UFUNCTION()
	void OnQuickbarContentsChanged(EFortQuickBars QuickbarIndex, const TArray<int32>& ChangedSlots);

	UFUNCTION()
	void OnQuickbarSlotFocusChanged(EFortQuickBars QuickbarIndex, int32 FocusedSlotIdx);

};

