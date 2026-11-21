// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortStoreSummaryItemButton_Legacy.generated.h"

class UFortInventoryContext;
class UMenuAnchor;
class UStoreCardObject;
class UUserWidget;

UCLASS()
class UFortStoreSummaryItemButton_Legacy : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnContextMenuOpenChangedEvent, bool, bIsOpen);

public:
	UFUNCTION(BlueprintPure)
	UStoreCardObject* GetStoreCardObject() const;

	UFUNCTION(BlueprintImplementableEvent)
	void HandleItemMulchStateChanged();

	UFUNCTION(BlueprintCallable)
	void SetStoreCardObject(UStoreCardObject* CardObject);

	UFUNCTION(BlueprintCallable)
	void UpdateMulchListWithItem(bool bAddingItem);

	UPROPERTY(BlueprintReadOnly, Category="FortStoreSummaryItemButton_Legacy")
	bool HasAnItemMarkedForMulching;

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortStoreSummaryItemButton_Legacy", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UMenuAnchor> PopupMenuAnchor;

private:
	UFUNCTION()
	UUserWidget* GetPopupMenu();

	UFUNCTION()
	void HandleMenuOpenChanged(bool bIsOpen);

	UPROPERTY()
	TObjectPtr<UStoreCardObject> StoreCardObject;

	UPROPERTY(Transient)
	TObjectPtr<UFortInventoryContext> InventoryContext;

};

