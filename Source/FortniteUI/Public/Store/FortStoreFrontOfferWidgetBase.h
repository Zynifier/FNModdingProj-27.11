// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "Online/FortMcpContext.h"
#include "Store/FortStoreFrontTileWidgetBase.h"
#include "FortStoreFrontOfferWidgetBase.generated.h"

class UCommonLoadGuard;
class UFortItemThumbnailRenderer;
class UFortMtxStoreRootBase;
class UFortMtxStoreRootBase_Legacy;
class UFortStoreFrontOfferDetailsWidgetBase;
class UFortStoreFrontOfferInfo;
class UMaterialInterface;
class UTexture2D;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI"))
class FORTNITEUI_API UFortStoreFrontOfferWidgetBase : public UFortStoreFrontTileWidgetBase
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
	void SetStoreRoot(UFortMtxStoreRootBase* InStoreRoot);

	UFUNCTION(BlueprintCallable)
	void SetStoreRoot_Legacy(UFortMtxStoreRootBase_Legacy* InStoreRoot);

	UFUNCTION(BlueprintCallable, Category="FortDirectAcquisitionOfferWidgetBase")
	void SetupOffer(UFortStoreFrontOfferInfo* InOfferData);

	UFUNCTION(BlueprintImplementableEvent, Category="FortDirectAcquisitionOfferWidgetBase")
	void UpdateCarousel(float InDeltaTime);

protected:
	UFUNCTION(BlueprintPure)
	UFortMtxStoreRootBase* GetStoreRoot() const;

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

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortStoreFrontOfferWidgetBase")
	TArray<TObjectPtr<UFortStoreFrontOfferInfo>> GroupedOffers;

private:
	UFUNCTION(BlueprintCallable)
	void HandleCarouselOfferChanged();

	UFUNCTION()
	void HandleCurrentlyViewedAccountInfoChanged(FFortPublicAccountInfo NewInfo);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortStoreFrontOfferWidgetBase", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonLoadGuard> MainImageLoadGuard;

	UPROPERTY(EditDefaultsOnly, Category="FortStoreFrontOfferWidgetBase")
	TSubclassOf<UFortItemThumbnailRenderer> ThumbnailRendererClass;

	UPROPERTY(Transient)
	TObjectPtr<UFortStoreFrontOfferInfo> OfferData;

	UPROPERTY(Transient)
	TObjectPtr<UFortItemThumbnailRenderer> ThumbnailRenderer;

};

