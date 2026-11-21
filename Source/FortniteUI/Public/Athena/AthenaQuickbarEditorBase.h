// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Items/FortQuickBars.h"
#include "AthenaQuickbarEditorBase.generated.h"

class UAthenaQuickBarSlotButtonBase;
class UCommonButtonGroupBase;
class UWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaQuickbarEditorBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UWidget* GetFirstEquipSlotButton() const;

	UFUNCTION(BlueprintCallable)
	void SelectNextQuickBarSlot(const bool bSetFocus = true);

	UFUNCTION(BlueprintCallable)
	void SelectPreviousQuickBarSlot(const bool bSetFocus = true);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnQuickBarSlotButtonCreated(UAthenaQuickBarSlotButtonBase* QuickBarSlotButton);

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaQuickbarEditorBase")
	TObjectPtr<UCommonButtonGroupBase> EquipButtonGroup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AthenaQuickbarEditorBase")
	bool bCheckVisibilityBasedOffInventoryCapacity;

private:
	UPROPERTY(EditAnywhere, Category="AthenaQuickbarEditorBase")
	EFortQuickBars QuickBarIndex;

	UPROPERTY(EditAnywhere, Category="AthenaQuickbarEditorBase")
	TSubclassOf<UAthenaQuickBarSlotButtonBase> QuickBarSlotButtonClass;

	UPROPERTY(EditAnywhere, Category="AthenaQuickbarEditorBase", meta=(ClampMin="0"))
	int32 FirstQuickBarSlotIndex;

	UPROPERTY(EditAnywhere, Category="AthenaQuickbarEditorBase", meta=(ClampMin="1"))
	int32 NumQuickBarSlots;

};

