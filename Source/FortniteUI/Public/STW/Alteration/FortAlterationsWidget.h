// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidgetPool.h"
#include "CommonUserWidget.h"
#include "STW/Alteration/FortAlterations.h"
#include "FortAlterationsWidget.generated.h"

class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UCommonUserWidget;
class UFortAlterationButtonWidget;
class UFortAlterationInfo;
class UFortItem;
enum class EFortAlterationWidgetState : uint8;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortAlterationsWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortAlterationsWidget")
	UCommonUserWidget* GetOrCreateWidget();

	UFUNCTION(BlueprintImplementableEvent, Category="FortAlterationsWidget")
	void OnAlterationSlotIndexModifiedBP(int32 ModifiedIndex);

	UFUNCTION(BlueprintImplementableEvent, Category="FortAlterationsWidget")
	void OnGenerateAlteration(UFortAlterationInfo* AlterationInfo);

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemChanged(bool bIntroAlterations, bool bWasFavoritedChanged);

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemToCompareWithChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStateChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpgradeLevelDeltaChanged();

	UFUNCTION(BlueprintCallable, Category="FortAlterationsWidget")
	void ProcessAlterations();

	UFUNCTION(BlueprintCallable, Category="FortAlterationsWidget")
	void ReleaseWidgets();

	UFUNCTION(BlueprintCallable, Category="FortAlterationsWidget")
	void SetItem(UFortItem* InItem, bool bInPreviewNewAlterations, bool bIntroAlterations = false);

	UFUNCTION(BlueprintCallable, Category="FortAlterationsWidget")
	void SetItemToCompareWith(UFortItem* InItem);

	UFUNCTION(BlueprintCallable, Category="FortAlterationsWidget")
	void SetState(EFortAlterationWidgetState InState);

	UFUNCTION(BlueprintCallable, Category="FortAlterationsWidget")
	void SetUpgradeLevelDelta(int32 InUpgradeLevelDelta);

	UFUNCTION(BlueprintCallable, Category="FortAlterationsWidget")
	void SetupInteractionEvents(UFortAlterationButtonWidget* Buttion);

	UPROPERTY(BlueprintReadOnly, Category="FortAlterationsWidget", meta=(ExposeOnSpawn="TRUE"))
	TObjectPtr<UFortItem> Item;

	UPROPERTY(BlueprintReadOnly, Category="FortAlterationsWidget", meta=(ExposeOnSpawn="TRUE"))
	EFortAlterationWidgetState State;

	UPROPERTY(BlueprintReadOnly, Category="FortAlterationsWidget", meta=(ExposeOnSpawn="TRUE"))
	TObjectPtr<UFortItem> ItemToCompareWith;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAlterationsWidget", meta=(ExposeOnSpawn="TRUE"))
	bool bUseButtons;

	UPROPERTY(EditDefaultsOnly, Category="FortAlterationsWidget")
	TSubclassOf<UCommonUserWidget> AlterationWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="FortAlterationsWidget")
	TSubclassOf<UCommonUserWidget> AlterationButtonWidgetClass;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnFocusFirstItem();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAlterationsWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> EmptyText;

	UPROPERTY(BlueprintReadOnly, Category="FortAlterationsWidget")
	TObjectPtr<UCommonButtonGroupLegacy> ButtonGroup;

private:
	UFUNCTION()
	void HandleAlterationsSlotHovered(UCommonButtonLegacy* InAlterationButton, int32 SelectedIndex);

	UFUNCTION()
	void HandleAlterationsSlotSelected(UCommonButtonLegacy* InAlterationButton, int32 SelectedIndex);

	UPROPERTY(Transient)
	FUserWidgetPool EntryWidgetPool;

};

