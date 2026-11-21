// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortUITypes.h"
#include "FortCollectionBookRecycleSlotResultsWidget.generated.h"

class UFortAccountItem;
class UPanelWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(Category="Collection Book", DisableNativeTick))
class UFortCollectionBookRecycleSlotResultsWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Item Picker")
	void SetCurrentItemToRecycle(UFortAccountItem* InItemToRecycle);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCollectionBookRecycleSlotResultsWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> RecycleResultsWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Collection Book")
	EFortItemCardSize ItemCardSize;

private:
	UPROPERTY()
	TObjectPtr<UFortAccountItem> ItemToRecycle;

};

