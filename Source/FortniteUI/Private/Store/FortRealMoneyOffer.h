// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Store/FortStoreFrontOfferWidgetBase.h"
#include "FortRealMoneyOffer.generated.h"

class UFortPurchaseUnavailableModal;
class UFortRealMoneyOfferDetails;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortRealMoneyOffer : public UFortStoreFrontOfferWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateStorePrice(const FText& InStorePrice);

protected:
	UFUNCTION(BlueprintPure)
	bool GetSalePriceFromLastAppStore(const int32 PriceIndex, FText& SalePrice, const int32 ItemQuantity) const;

	UPROPERTY(EditDefaultsOnly, Category="FortRealMoneyOffer")
	TSubclassOf<UFortPurchaseUnavailableModal> PurchaseUnavailableModalClass;

	UPROPERTY(EditDefaultsOnly, Category="FortRealMoneyOffer")
	TSubclassOf<UFortRealMoneyOfferDetails> RealMoneyDetailsClass;

};

