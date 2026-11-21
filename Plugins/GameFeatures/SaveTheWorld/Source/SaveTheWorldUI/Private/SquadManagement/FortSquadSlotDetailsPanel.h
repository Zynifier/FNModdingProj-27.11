// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortSquadSlotDetailsPanel.generated.h"

class IFortItemViewContextInterface;
class UFortItem;
class UFortSquadSlotItemDetailsHostPanel;
class ULocalPlayer;
enum class EFortSquadSlottingRestrictionReason : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSquadSlotDetailsPanel : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Squad Slot Management")
	void GetIdOfSquadSlotToManageBP(FName& OutSquadId, int32& OutSquadSlotIndex) const;

	UFUNCTION(BlueprintPure, Category="Squad Slot Management")
	UFortItem* GetItemInSquadSlotBP(const ULocalPlayer* LocalPlayer) const;

	UFUNCTION(BlueprintPure)
	TArray<EFortSquadSlottingRestrictionReason> GetSlottingRestrictionReasons() const;

	UFUNCTION(BlueprintPure, Category="Squad Slot Management")
	bool IsSquadSlotLockedBP() const;

	UFUNCTION(BlueprintCallable, Category="Squad Slot Management")
	void SetIdOfSquadSlotToManageBP(const FName& SquadId, const int32 SquadSlotIndex);

	UFUNCTION(BlueprintCallable)
	void SetScrollWidget();

	UFUNCTION(BlueprintPure, Category="Squad Slot Management")
	bool TryGetItemToPreviewInSlot(UFortItem*& OutItemToPreviewInSlot) const;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Squad Slot Management")
	void HandleDifferentSquadSlotSetBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Squad Slot Management")
	void HandleSquadSlotRestrictionFactorsChangedBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Squad Slot Management")
	void HandleSquadSlotStateChangedBP();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSquadSlotDetailsPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSquadSlotItemDetailsHostPanel> ItemDetailsPanel;

	UPROPERTY()
	TScriptInterface<IFortItemViewContextInterface> ItemViewContext;

};

