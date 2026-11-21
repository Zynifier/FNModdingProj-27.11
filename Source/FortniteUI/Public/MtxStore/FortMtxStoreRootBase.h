// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortClientEventInterface.h"
#include "Online/FortMcpProfile.h"
#include "FortMtxStoreRootBase.generated.h"

class UFortMtxStoreSelectionPopup;
class UFortStoreFrontOfferInfo;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNativeOnOffersGenerated);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI", DisableNativeTick))
class FORTNITEUI_API UFortMtxStoreRootBase : public UCommonActivatableWidget, public IFortClientEventInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortDirectAcquisitionWidgetBase")
	void SetStorefrontNames(const TArray<FString>& InStorefrontNames);

protected:
	UFUNCTION(BlueprintPure, Category="FortMtxStoreRootBase")
	bool AreOffersLoaded() const;

	UFUNCTION(BlueprintNativeEvent, Category="FortMtxStoreRootBase")
	void ClearOfferWidgets();

	UFUNCTION(BlueprintNativeEvent, Category="FortDirectAcquisitionWidgetBase")
	void GenerateOfferWidget(UFortStoreFrontOfferInfo* OfferData);

	UFUNCTION(BlueprintPure, Category="FortMtxStoreRootBase")
	FMtxBreakdown GetMtxBreakdown() const;

	UFUNCTION(BlueprintPure, Category="FortDirectAcquisitionWidgetBase")
	TArray<FString> GetStorefrontNames() const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortMtxStoreRootBase")
	void NoOffersAvailable();

	UFUNCTION(BlueprintImplementableEvent, Category="FortMtxStoreRootBase")
	void OnOffersGenerated();

	UFUNCTION(BlueprintImplementableEvent, Category="FortMtxStoreRootBase")
	void OnPurchasingDisabled();

	UFUNCTION(BlueprintNativeEvent, Category="FortMtxStoreRootBase")
	void OnStartReadingOffers();

	UFUNCTION(BlueprintImplementableEvent, Category="FortDirectAcquisitionWidgetBase")
	void OnUpdateOtherPlatformMTXMessage(bool HasOtherPlatformCurrency, const FText& CurrencyMessageLocText);

	UFUNCTION(Category="FortMtxStoreRootBase")
	void PushStoreSelection();

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortMtxStoreSelectionPopup> MtxStoreSelectionWidget;

	UPROPERTY(EditAnywhere, Category="FortMtxStoreRootBase")
	TSubclassOf<UFortMtxStoreSelectionPopup> MtxStoreSelectionClass;

	UPROPERTY()
	TArray<TObjectPtr<UFortStoreFrontOfferInfo>> AcquisitionOfferData;

private:
	UPROPERTY(EditAnywhere, Category="FortMtxStoreRootBase")
	TArray<FString> StorefrontNames;

};

