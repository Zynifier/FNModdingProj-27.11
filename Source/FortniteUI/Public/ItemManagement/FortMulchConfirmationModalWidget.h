// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemTiles/FortItemTileButton.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortMulchConfirmationModalWidget.generated.h"

class IFortItemManagementMulchPanel;
class UCommonLoadGuard;
class UCommonTileView;
class UFortInventoryContext;
class UFortItem;
class UFortItemManagementMulchDetailsPanel;
class UHorizontalBox;
enum class EItemRecyclingWarning : uint8;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortMulchConfirmationModalWidget : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Item Management|Mulch")
	void CommitMulch();

	UFUNCTION(BlueprintCallable, Category="Item Management|Mulch")
	TMap<EItemRecyclingWarning, int32> GetMulchWarnings();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Mulch")
	void UpdateConfirmationModal_BP();

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortMulchConfirmationModalWidget")
	TScriptInterface<IFortItemManagementMulchPanel> HostItemManagementMulchPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Mulch", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTileView> RecycleItemTileView;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Mulch", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemManagementMulchDetailsPanel> RecycleDetailsPanel;

private:
	UFUNCTION()
	void UpdateConfirmationModal();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLoadGuard> CommonLoadGuard_LatentSpinner;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HorizontalBox_Buttons;

	UPROPERTY(Transient)
	TObjectPtr<UFortInventoryContext> InventoryContext;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortMulchItemTileButton : public UFortItemTileButton
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Mulch Tile")
	void HandleItemChanged_BP(UFortItem* NewItem);

};

