// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DirectedAcquisition/FortDirectAcquisitionWidgetBase_Legacy.h"
#include "Store/FortLlamaStoreBase.h"
#include "FortLlamaStoreBase_Legacy.generated.h"

class UCommonActivatablePanelLegacy;
class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UDynamicEntryBox;
class UFortLlamaStoreData;
class UFortLlamaStoreDetailsBase;
class UFortLlamaStoreOfferInfo;
enum class EFortStoreState : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"))
class UFortLlamaStoreBase_Legacy : public UFortDirectAcquisitionWidgetBase_Legacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="FortLlamaStoreBase_Legacy")
	void CreateTencentPuchaseOpenModal();

	UFUNCTION()
	void OnStoreStateChanged(EFortStoreState NewStoreState);

	UFUNCTION(BlueprintCallable, Category="FortLlamaStoreBase_Legacy")
	void SetupFocus();

	UFUNCTION(BlueprintImplementableEvent, Category="FortLlamaStoreBase_Legacy")
	void SwapToCardEnterState();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortLlamaStoreBase_Legacy")
	TArray<FOfferGroup> OfferCategoriesToDisplay;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortLlamaStoreBase_Legacy", meta=(BindWidget, EditInline="true"))
	UDynamicEntryBox* OfferEntryBox;

	UPROPERTY()
	UCommonButtonGroupLegacy* OfferButtonGroup;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortLlamaStoreBase_Legacy", meta=(BindWidgetOptional, EditInline="true"))
	UFortLlamaStoreDetailsBase* OfferDetails;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortLlamaStoreBase_Legacy")
	TObjectPtr<UFortLlamaStoreData> StoreData;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortllamaStoreBase", meta=(BindWidget, EditInline="true"))
	UCommonButtonLegacy* Button_UnopenedLlamas;

private:
	UFUNCTION()
	void OnStorePurchaseCompleted();

	UPROPERTY()
	UFortLlamaStoreOfferInfo* PendingPurchaseOffer;

	UPROPERTY(Export, meta=(EditInline="true"))
	UCommonActivatablePanelLegacy* StoreOpeningCardPack;

	UPROPERTY(EditAnywhere, Category="FortllamaStoreBase", meta=(AllowPrivateAccess="true"))
	bool bHideSoldOffers;

};

