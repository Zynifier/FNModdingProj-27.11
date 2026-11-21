// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "Online/FortMcpContext.h"
#include "Store/FortStoreFrontTileWidgetBase_Legacy.h"
#include "FortStoreFrontOfferWidgetBase_Legacy.generated.h"

class UCommonLoadGuard;
class UFortItemThumbnailRenderer;
class UFortMtxStoreRootBase_Legacy;
class UFortStoreFrontOfferDetailsWidgetBase;
class UFortStoreFrontOfferInfo;
class UMaterialInterface;
class UTexture2D;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI"))
class FORTNITEUI_API UFortStoreFrontOfferWidgetBase_Legacy : public UFortStoreFrontTileWidgetBase_Legacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortDirectAcquisitionOfferWidgetBase")
	void AddOffer(UFortStoreFrontOfferInfo* InOfferData);

	UFUNCTION(BlueprintPure, Category="FortDirectAcquisitionOfferWidgetBase")
	TSoftObjectPtr<UMaterialInterface> GetFirstOfferSeriesBackgroundMaterial() const;

	UFUNCTION(BlueprintPure, Category="FortDirectAcquisitionOfferWidgetBase")
	TSoftObjectPtr<UTexture2D> GetFirstOfferSeriesBackgroundTexture() const;

	UFUNCTION(BlueprintPure, Category="FortDirectAcquisitionOfferWidgetBase")
	UFortStoreFrontOfferInfo* GetOfferInfo() const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortDirectAcquisitionOfferWidgetBase")
	void OnOfferTileBrushLoaded(const FSlateBrush& OfferBrush);

	UFUNCTION(BlueprintCallable, Category="FortDirectAcquisitionOfferWidgetBase")
	void RemoveAllOffers();

	UFUNCTION(BlueprintCallable, Category="FortDirectAcquisitionOfferWidgetBase")
	void SetIndexInSection(int32 InIndexInSection);

	UFUNCTION(BlueprintCallable)
	void SetStoreRoot(UFortMtxStoreRootBase_Legacy* InStoreRoot);

	UFUNCTION(BlueprintCallable, Category="FortDirectAcquisitionOfferWidgetBase")
	void SetupOffer(UFortStoreFrontOfferInfo* InOfferData);

	UFUNCTION(BlueprintImplementableEvent, Category="FortDirectAcquisitionOfferWidgetBase")
	void UpdateCarousel(float InDeltaTime);

protected:
	UFUNCTION(BlueprintPure)
	UFortMtxStoreRootBase_Legacy* GetStoreRoot() const;

	UFUNCTION()
	void OnDetailsOpened(UFortStoreFrontOfferDetailsWidgetBase* DetailsWidget);

	UFUNCTION(BlueprintImplementableEvent, Category="FortDirectAcquisitionOfferWidgetBase")
	void OnOfferAdded();

	UFUNCTION(BlueprintImplementableEvent, Category="FortDirectAcquisitionOfferWidgetBase")
	void OnOfferSet();

	UFUNCTION(BlueprintImplementableEvent, Category="FortDirectAcquisitionOfferWidgetBase")
	void OnStoreSelectionOfferSet();

	UFUNCTION(BlueprintImplementableEvent, Category="FortDirectAcquisitionOfferWidgetBase")
	void OnUpdateStatus();

	UFUNCTION(BlueprintImplementableEvent, Category="FortDirectAcquisitionOfferWidgetBase")
	void PreviewNextCarouselOffer();

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="FortDirectAcquisitionOfferWidgetBase")
	void SendRealMoneyStoreInteractionAnalytic(const FString& Interaction) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="FortDirectAcquisitionOfferWidgetBase")
	void SendSeasonPassInteractionAnalytic(const FString& Interaction) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="FortDirectAcquisitionOfferWidgetBase")
	void SendShopInteractionAnalytic(const FString& Interaction) const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortDirectAcquisitionOfferWidgetBase")
	void SetupThumbnailRenderer(UFortItemThumbnailRenderer* InThumbnailRenderer);

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortStoreFrontOfferWidgetBase_Legacy")
	TArray<UFortStoreFrontOfferInfo*> GroupedOffers;

private:
	UFUNCTION(BlueprintCallable)
	void HandleCarouselOfferChanged();

	UFUNCTION()
	void HandleCurrentlyViewedAccountInfoChanged(FFortPublicAccountInfo NewInfo);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortStoreFrontOfferWidgetBase_Legacy", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, BlueprintProtected="TRUE", EditInline="true"))
	UCommonLoadGuard* MainImageLoadGuard;

	UPROPERTY(EditDefaultsOnly, Category="FortStoreFrontOfferWidgetBase_Legacy")
	TSubclassOf<UFortItemThumbnailRenderer> ThumbnailRendererClass;

	UPROPERTY(Transient)
	UFortStoreFrontOfferInfo* OfferData;

	UPROPERTY(Transient)
	UFortItemThumbnailRenderer* ThumbnailRenderer;

};

