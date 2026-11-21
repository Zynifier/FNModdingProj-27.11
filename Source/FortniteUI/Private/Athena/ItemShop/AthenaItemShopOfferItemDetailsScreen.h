// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Athena/ItemShop/AthenaItemShopOfferDetailsWidgetBase.h"
#include "AthenaItemShopOfferItemDetailsScreen.generated.h"

class UFortItemDefinition;
class UFortItemPreviewScreen;
class ULockerConfirmationModal;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaItemShopOfferItemDetailsScreen : public UAthenaItemShopOfferDetailsWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool CanEquipItem() const;

	UFUNCTION(BlueprintCallable)
	void Dismiss();

	UFUNCTION(BlueprintCallable)
	void EquipItem();

	UFUNCTION(BlueprintPure)
	bool IsItemEquipped() const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnItemEquipped(bool bSuccess);

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopOfferItemDetailsScreen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="AthenaItemShopOfferItemDetailsScreen")
	TObjectPtr<UFortItemDefinition> TriggeringItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="AthenaItemShopOfferItemDetailsScreen")
	int32 VariantIndex;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopOfferItemDetailsScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortItemPreviewScreen> ItemPreview_Widget;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopOfferItemDetailsScreen")
	TSoftClassPtr<ULockerConfirmationModal> LockerConfirmationModalClass;

};

