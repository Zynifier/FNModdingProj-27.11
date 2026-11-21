// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "Context/FortStoreContext.h"
#include "ItemManagement/FortItemManagementMulchPanel.h"
#include "FortStoreSummary_Legacy.generated.h"

class UCommonTileView;
class UFortMulchConfirmationModalWidget;
class UStoreCardObject;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortStoreSummary_Legacy : public UCommonActivatablePanelLegacy, public IFortItemManagementMulchPanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void CloseSummaryScreen();

	UFUNCTION(BlueprintCallable)
	void FinalizeFavoriteStatus();

	UFUNCTION(BlueprintPure)
	bool GetIsInChoiceSelectionMode() const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Context Menu Open Changed"))
	void HandleContextMenuOpenChangedBP(bool bIsOpen);

	UFUNCTION(BlueprintCallable)
	virtual void HideMulchConfirmationModal();

	UFUNCTION(BlueprintCallable)
	void MarkDefaultItemsForMulch();

	UFUNCTION(BlueprintCallable)
	void SetCards(const TArray<FCard>& Cards);

	UFUNCTION(BlueprintCallable)
	void SetIsInChoiceSelectionMode(bool InIsInChoiceSelectionMode);

	UFUNCTION(BlueprintCallable)
	virtual void ShowMulchConfirmationModal();

	UPROPERTY(BlueprintReadOnly, Category="FortStoreSummary_Legacy")
	TArray<TObjectPtr<UStoreCardObject>> StoreCardObjects;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortStoreSummary_Legacy", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTileView> TileView;

protected:
	UFUNCTION(BlueprintCallable)
	virtual void NotifyPanelActivated();

	UFUNCTION(BlueprintCallable)
	virtual void NotifyPanelDeactivated();

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Store Summary")
	TSubclassOf<UFortMulchConfirmationModalWidget> MulchConfirmationModalClass;

private:
	UFUNCTION()
	void HandleContextMenuOpenChanged(bool bIsOpen);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortMulchConfirmationModalWidget> MulchConfirmationModal;

};

