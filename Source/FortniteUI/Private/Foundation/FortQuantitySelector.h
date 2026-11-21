// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortQuantitySelector.generated.h"

class UCommonButtonLegacy;
class UFortItem;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortQuantitySelector : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UFortItem* GetItem() const;

	UFUNCTION(BlueprintCallable)
	void InitializeQuantitySelector(UFortItem* InItem, const FText TitleText, const FText ConfirmButtonText, const FText AdditionalInfoText, const int32 InitialQuantity, const int32 MaximumQuantity);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnQuantitySelectorInitialized(UFortItem* InItem, const FText& TitleText, const FText& ConfirmButtonText, const FText& AdditionalInfoText, const int32 InitialQuantity, const int32 MaximumQuantity);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuantitySelector", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Confirm;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuantitySelector", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Cancel;

	UPROPERTY(BlueprintReadWrite, Category="FortQuantitySelector", meta=(AllowPrivateAccess))
	TObjectPtr<UFortItem> Item;

	UPROPERTY(BlueprintReadWrite, Category="FortQuantitySelector", meta=(AllowPrivateAccess))
	int32 CurrentQuantity;

};

