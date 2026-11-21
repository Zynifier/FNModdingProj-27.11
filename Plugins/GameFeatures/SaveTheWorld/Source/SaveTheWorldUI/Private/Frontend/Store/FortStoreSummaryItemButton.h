// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortStoreSummaryItemButton.generated.h"

class UFortInventoryContext;
class UMenuAnchor;
class UStoreCardObject;
class UUserWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnContextMenuOpenChangedEvent, bool, bIsOpen);

UCLASS()
class UFortStoreSummaryItemButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UStoreCardObject* GetStoreCardObject() const;

	UFUNCTION(BlueprintImplementableEvent)
	void HandleItemMulchStateChanged();

	UFUNCTION(BlueprintCallable)
	void SetStoreCardObject(UStoreCardObject* CardObject);

	UFUNCTION(BlueprintCallable)
	void UpdateMulchListWithItem(bool bAddingItem);

	UPROPERTY(BlueprintReadOnly, Category="FortStoreSummaryItemButton")
	bool HasAnItemMarkedForMulching;

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortStoreSummaryItemButton", meta=(BindWidget, EditInline="true"))
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

