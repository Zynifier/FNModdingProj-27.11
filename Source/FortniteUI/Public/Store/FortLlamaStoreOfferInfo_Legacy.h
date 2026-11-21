// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Store/FortStoreFrontOfferWidgetBase_Legacy.h"
#include "FortLlamaStoreOfferInfo_Legacy.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI"))
class FORTNITEUI_API UFortLlamaStoreOfferWidgetBase_Legacy : public UFortStoreFrontOfferWidgetBase_Legacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortLlamaStoreOfferWidgetBase")
	int32 GetCurrentRarity();

	UFUNCTION(BlueprintImplementableEvent, Category="FortDirectAcquisitionOfferDetailsWidgetBase")
	void OnOfferShown();

	UFUNCTION(BlueprintImplementableEvent, Category="FortLlamaStoreDetailsBase")
	void ShowHovered();

	UFUNCTION(BlueprintImplementableEvent, Category="FortLlamaStoreDetailsBase")
	void ShowRarity(int32 Rarity);

	UFUNCTION(BlueprintImplementableEvent, Category="FortLlamaStoreDetailsBase")
	void ShowUnhovered();

	UFUNCTION(BlueprintImplementableEvent, Category="FortLlamaStoreDetailsBase")
	void UpgradeRarity(int32 RarityToUpgradeTo);

protected:
	UFUNCTION(BlueprintCallable, Category="FortLlamaStoreOfferWidgetBase")
	int32 GetPriceIndexToShow();

	UFUNCTION(BlueprintCallable, Category="FortLlamaStoreOfferWidgetBase")
	bool IsParentActivatablePanelActive();

	UFUNCTION(BlueprintCallable, Category="FortLlamaStoreOfferWidgetBase")
	void LoadInFinished();

	UFUNCTION(BlueprintCallable, Category="FortLlamaStoreOfferWidgetBase")
	void RequestPurchase(int32 PriceIndex = -1, int32 Quantity = 1);

	UFUNCTION(BlueprintCallable, Category="FortLlamaStoreOfferWidgetBase")
	void RequestToInspect();

	UFUNCTION(BlueprintCallable, Category="FortLlamaStoreOfferWidgetBase")
	void ShowInitialRarityState();

	UFUNCTION(BlueprintCallable, Category="FortLlamaStoreOfferWidgetBase")
	void SilverUpgradeFinished();

	UFUNCTION(BlueprintCallable, Category="FortLlamaStoreOfferWidgetBase")
	void UpgradingFinished();

};

