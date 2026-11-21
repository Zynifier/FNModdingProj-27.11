// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemManagement/FortItemManagementMulchPanel.h"
#include "ItemPicker/FortItemPicker.h"
#include "FortCollectionBookPicker.generated.h"

class UFortAccountItem;
class UFortItem;
class UFortMulchConfirmationModalWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(Category="Collection Book"))
class UFortCollectionBookPicker : public UFortItemPickerBase, public IFortItemManagementMulchPanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Item Picker")
	void ShowMulchDialogForItem(UFortItem* ItemToMulch);

protected:
	UFUNCTION(BlueprintCallable)
	virtual void HideMulchConfirmationModal();

	UFUNCTION(BlueprintCallable)
	virtual void NotifyPanelActivated();

	UFUNCTION(BlueprintCallable)
	virtual void NotifyPanelDeactivated();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Picker")
	void OnCollectComplete();

	UFUNCTION(BlueprintCallable)
	virtual void ShowMulchConfirmationModal();

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Item Picker")
	TSubclassOf<UFortMulchConfirmationModalWidget> MulchConfirmationModalClass;

private:
	UPROPERTY()
	TObjectPtr<UFortAccountItem> CurrentSlottedItem;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortMulchConfirmationModalWidget> MulchConfirmationModal;

};

