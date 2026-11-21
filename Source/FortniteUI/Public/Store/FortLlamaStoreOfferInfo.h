// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Store/FortStoreFrontOfferInfo.h"
#include "Store/FortStoreFrontOfferWidgetBase.h"
#include "FortLlamaStoreOfferInfo.generated.h"

class UFortCardPackItemDefinition;
class UFortPackPersonality;
class UTexture2D;
class UTexture;

UCLASS(BlueprintType, meta=(Category="Fortnite UI"))
class FORTNITEUI_API UFortLlamaStoreOfferInfo : public UFortStoreFrontOfferInfo
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferInfo")
	UFortCardPackItemDefinition* GetLlamaOfferDisplayAsset() const;

protected:
	UFUNCTION(BlueprintPure, Category="FortLlamaStoreOfferInfo")
	UTexture* GetDisplayAssetIcon() const;

	UFUNCTION(BlueprintPure, Category="FortLlamaStoreOfferInfo")
	TSoftObjectPtr<UTexture2D> GetDisplayAssetImage() const;

	UFUNCTION(BlueprintPure, Category="FortLlamaStoreOfferInfo")
	UFortPackPersonality* GetDisplayAssetPersonality() const;

	UFUNCTION(BlueprintPure, Category="FortLlamaStoreOfferInfo")
	TSoftObjectPtr<UTexture2D> GetDisplayAssetXrayImage() const;

private:
	UPROPERTY()
	TObjectPtr<UFortCardPackItemDefinition> LlamaOfferDisplayAsset;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI"))
class FORTNITEUI_API UFortLlamaStoreOfferWidgetBase : public UFortStoreFrontOfferWidgetBase
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

