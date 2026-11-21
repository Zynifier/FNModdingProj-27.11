// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortExpeditionBuildSquadWidget.generated.h"

class UFortExpeditionItem;
class UFortItemViewContext_ExpeditionSquadSlotItemPicker;
class UFortItemViewContext_ExpeditionSquadSlotsView;
class UFortSquadSlotDetailsPanel;
class UFortSquadSlotItemPicker;
class UFortSquadSlotsView;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortExpeditionBuildSquadWidget : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Expedition")
	void ClearTemporaryExpeditionSquadState(bool bPreviewOnly);

	UFUNCTION(BlueprintCallable, Category="Expedition")
	bool IsExpeditionValidToStart();

	UFUNCTION(BlueprintPure, Category="Expedition")
	bool IsSquadSlotLocked(int32 SlotIndex) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Expedition")
	void OnRequestClosePicker();

	UFUNCTION(BlueprintCallable, Category="Expedition")
	void SetCurrentSquadId(FName SquadId);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Expedition")
	void SetData(UFortExpeditionItem* InItem);

protected:
	UFUNCTION(BlueprintCallable, Category="Expedition")
	void HandleRequestStartExpedition(bool& bPassthrough);

	UFUNCTION(BlueprintNativeEvent, Category="Expedition")
	void OnRefreshBuildSquadWidget();

	UPROPERTY(BlueprintReadOnly, Category="Expedition")
	TWeakObjectPtr<UFortExpeditionItem> Item;

	UPROPERTY(BlueprintReadWrite, Category="Expedition")
	FName CurrentSquadId;

	UPROPERTY(BlueprintReadOnly, Export, Category="Expedition", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSquadSlotsView> ExpeditionSquadSlotsView;

	UPROPERTY(BlueprintReadOnly, Export, Category="Expedition", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSquadSlotDetailsPanel> ExpeditionSquadSlotDetails;

	UPROPERTY(BlueprintReadOnly, Export, Category="Expedition", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSquadSlotItemPicker> ExpeditionSquadSlotPicker;

private:
	UFUNCTION()
	void HandleDifferentSquadSlotSelected(const int32 SquadSlotIndex);

	UPROPERTY(Instanced)
	TObjectPtr<UFortItemViewContext_ExpeditionSquadSlotsView> ItemViewContext_ExpeditionSlotsView;

	UPROPERTY(Instanced)
	TObjectPtr<UFortItemViewContext_ExpeditionSquadSlotItemPicker> ItemViewContext_ExpeditionSlotItemPicker;

};

