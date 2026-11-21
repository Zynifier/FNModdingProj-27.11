// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortItemQuantityPair.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortAlterationModScreenBase.generated.h"

class UFortAlterableItem;
class UFortAlterationModOptinScreenBase;
class UFortAlterationOption;
class UFortAlterationOptionsBase;
class UFortAlterationsWidget;
class UFortItemDetailsHostPanel;

UCLASS(Abstract, BlueprintType, meta=(DisableNativeTick))
class UFortAlterationModScreenBase : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortAlterationModScreenBase")
	void SetItemForAlterationsModding(UFortAlterableItem* InAlterableItem);

protected:
	UFUNCTION(BlueprintCallable, Category="FortAlterationOptionsBase")
	bool AreIngredientRequirementsMent(const TArray<FFortItemQuantityPair>& RequiredIngredients);

	UFUNCTION(BlueprintCallable, Category="FortAlterationOptionsBase")
	void CancelSelection();

	UFUNCTION(BlueprintCallable, Category="FortAlterationOptionsBase")
	void ConfirmSelection();

	UFUNCTION(BlueprintImplementableEvent, Category="FortAlterationModScreenBase")
	void OnAlterationModificationCompleted();

	UFUNCTION(BlueprintImplementableEvent, Category="FortAlterationModScreenBase")
	void OnAlterationModificationStarted();

	UFUNCTION(BlueprintImplementableEvent, Category="FortAlterationModScreenBase")
	void OnAlterationModificationSucess(int32 ModifiedSlotIndex);

	UFUNCTION(BlueprintImplementableEvent, Category="FortAlterationModScreenBase")
	void OnAlterationOptionChanged(UFortAlterationOption* CurrentAlterationOption);

	UFUNCTION(BlueprintImplementableEvent, Category="FortAlterationModScreenBase")
	void OnItemSlotChanged(bool SelectedSlot);

	UFUNCTION(BlueprintImplementableEvent, Category="FortAlterationModScreenBase")
	void RefreshItemAndAlterationsBP();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAlterationModScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortAlterationsWidget> AlterationsToEdit;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAlterationModScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortAlterationOptionsBase> AlterationSlotOptions;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAlterationModScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemDetailsHostPanel> ItemInspectionMainItemDetailsHostPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAlterationModScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemDetailsHostPanel> AlterationsExtraDetailsPanel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAlterationModScreenBase")
	TSubclassOf<UFortAlterationModOptinScreenBase> AlterationModOptinScreenClass;

	UPROPERTY(EditAnywhere, Category="FortAlterationModScreenBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackInputAction;

	UPROPERTY(BlueprintReadOnly, Category="FortAlterationModScreenBase")
	TWeakObjectPtr<UFortAlterableItem> AlterableItem;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAlterationModScreenBase", meta=(EditInline="true"))
	TObjectPtr<UFortAlterationOption> CurrentAlterationOptionInternal;

private:
	UFUNCTION()
	void HandleBackAction(bool& bPassThrough);

};

