// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortClientEventInterface.h"
#include "Online/FortMcpProfile.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortMtxStoreRootBase_Legacy.generated.h"

class UFortMtxStoreSelectionPopup;
class UFortStoreFrontOfferInfo;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI", DisableNativeTick))
class FORTNITEUI_API UFortMtxStoreRootBase_Legacy : public UFortActivatablePanel, public IFortClientEventInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortDirectAcquisitionWidgetBase_Legacy")
	void SetStorefrontNames(const TArray<FString>& InStorefrontNames);

protected:
	UFUNCTION(BlueprintPure, Category="FortMtxStoreRootBase_Legacy")
	bool AreOffersLoaded() const;

	UFUNCTION(BlueprintNativeEvent, Category="FortMtxStoreRootBase_Legacy")
	void ClearOfferWidgets();

	UFUNCTION(BlueprintNativeEvent, Category="FortDirectAcquisitionWidgetBase_Legacy")
	void GenerateOfferWidget(UFortStoreFrontOfferInfo* OfferData);

	UFUNCTION(BlueprintPure, Category="FortMtxStoreRootBase_Legacy")
	FMtxBreakdown GetMtxBreakdown() const;

	UFUNCTION(BlueprintPure, Category="FortDirectAcquisitionWidgetBase_Legacy")
	TArray<FString> GetStorefrontNames() const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortMtxStoreRootBase_Legacy")
	void NoOffersAvailable();

	UFUNCTION(BlueprintImplementableEvent, Category="FortMtxStoreRootBase_Legacy")
	void OnOffersGenerated();

	UFUNCTION(BlueprintImplementableEvent, Category="FortMtxStoreRootBase_Legacy")
	void OnPurchasingDisabled();

	UFUNCTION(BlueprintNativeEvent, Category="FortMtxStoreRootBase_Legacy")
	void OnStartReadingOffers();

	UFUNCTION(BlueprintImplementableEvent, Category="FortDirectAcquisitionWidgetBase_Legacy")
	void OnUpdateOtherPlatformMTXMessage(bool HasOtherPlatformCurrency, const FText& CurrencyMessageLocText);

	UFUNCTION(Category="FortMtxStoreRootBase_Legacy")
	void PushStoreSelection();

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortMtxStoreSelectionPopup> MtxStoreSelectionWidget;

	UPROPERTY(EditAnywhere, Category="FortMtxStoreRootBase_Legacy")
	TSubclassOf<UFortMtxStoreSelectionPopup> MtxStoreSelectionClass;

	UPROPERTY()
	TArray<TObjectPtr<UFortStoreFrontOfferInfo>> AcquisitionOfferData;

private:
	UPROPERTY(EditAnywhere, Category="FortMtxStoreRootBase_Legacy")
	TArray<FString> StorefrontNames;

};

