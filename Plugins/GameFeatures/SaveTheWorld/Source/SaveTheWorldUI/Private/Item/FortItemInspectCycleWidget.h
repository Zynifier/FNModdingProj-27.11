// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Engine/DataTable.h"
#include "FortItemInspectCycleWidget.generated.h"

class UFortItem;
class UFortItemInspectionScreen;
class UFortItemTileView;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemToRepresentChanged, UFortItem*, NewItemToRepresent);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortItemInspectCycleWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UFortItem* GetItemWithOffset_BP(int32 IndexOffset) const;

	UFUNCTION(BlueprintCallable)
	void SelectItemWithOffset(int32 Offset);

	UFUNCTION(BlueprintCallable)
	void SelectNextItem();

	UFUNCTION(BlueprintCallable)
	void SelectPreviousItem();

	UFUNCTION(BlueprintCallable)
	void SetItemToRepresent(const UFortItem* NewItemToRepresent);

	UFUNCTION(BlueprintCallable)
	void SetOwningItemInspectScreen(UFortItemInspectionScreen* ItemInspect);

	UFUNCTION(BlueprintCallable)
	void SetupActionHandlers();

	UPROPERTY(BlueprintAssignable)
	FOnItemToRepresentChanged OnItemToRepresentChanged;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnItemCycled(UFortItem* OldItem, UFortItem* NewItem, int32 OffsetFromPreviousItem);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemInspectCycleWidget")
	TWeakObjectPtr<UFortItemTileView> ItemTileView;

	UPROPERTY(BlueprintReadOnly, Category="FortItemInspectCycleWidget")
	TWeakObjectPtr<UFortItem> ItemToRepresent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Management Screen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PreviousItemActionRowHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Management Screen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle NextItemActionRowHandle;

};

