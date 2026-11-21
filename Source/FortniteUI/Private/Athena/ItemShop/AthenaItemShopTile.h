// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "CommonButtonLegacy.h"
#include "FortRarityData.h"
#include "Online/FortMcpContext.h"
#include "AthenaItemShopTile.generated.h"

class AFortItemCaptureActor;
class UAthenaItemShopReactiveTileText;
class UAthenaItemShopTagRotator;
class UAthenaItemShopTileImage;
class UCommonLazyImage;
class UCommonLoadGuard;
class UCommonTextBlock;
class UCommonVisibilitySwitcher;
class UFortItemThumbnailRenderer;
class UFortMtxOfferData;
class UImage;
class UMaterialInterface;
class UTexture2D;
class UWidget;
enum class EItemShopCurrency : uint8;
enum class EItemShopTileSize : uint8;
enum class EViolatorIntensity : uint8;

UCLASS(Abstract)
class UAthenaItemShopTile : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnPeekStateChanged(bool bIsInPeekState);

protected:
	UFUNCTION(BlueprintPure)
	UFortMtxOfferData* GetLegacyDisplayAsset() const;

	UFUNCTION(BlueprintPure)
	bool IsUsingLargeLayout() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnActiveStateChanged(bool bIsActiveState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCurrencySet(EItemShopCurrency Currency);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDefaultBackgroundRequested();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayAssetImageLoaded(UTexture2D* OfferImage);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPrePresentationSwap();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateItemLivePreview(EItemShopTileSize TileSize, UFortItemThumbnailRenderer* ThumbnailRendererPtr, AFortItemCaptureActor* CaptureActor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateSeriesOrRarityColors(const FFortColorPalette& ColorPalette);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateTileSize(EItemShopTileSize TileSize);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateViolator(EViolatorIntensity ViolatorIntensity, const FText& ViolatorText);

	UFUNCTION(BlueprintCallable)
	void ShowNextPresentation();

private:
	UFUNCTION()
	void HandleLocalAccountInfoChanged(FFortPrivateAccountInfo NewInfo);

	UPROPERTY(Transient)
	TObjectPtr<UFortItemThumbnailRenderer> ThumbnailRenderer;

	UPROPERTY(Transient)
	TArray<TSoftObjectPtr<UMaterialInterface>> Presentations;

	UPROPERTY(EditDefaultsOnly, Category="Live Preview")
	TSubclassOf<UFortItemThumbnailRenderer> ThumbnailRendererClass;

	UPROPERTY(EditDefaultsOnly, Category="Live Preview")
	TSubclassOf<AFortItemCaptureActor> ItemCaptureActorClass;

	UPROPERTY(EditAnywhere, Category="Live Preview")
	FVector CaptureActorStartingPosition;

	UPROPERTY(EditAnywhere, Category="Live Preview")
	float CaptureActorZOffset;

	UPROPERTY(EditAnywhere, Category="Presentation Swapping")
	float TimeBetweenPresentationSwaps;

	UPROPERTY(EditDefaultsOnly, Category="Subscription")
	FText SubInactiveStatusText;

	UPROPERTY(EditDefaultsOnly, Category="Subscription")
	FText SubActiveStatusText;

	UPROPERTY(EditDefaultsOnly, Category="Subscription")
	FText SubPaymentErrorStatusText;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaItemShopReactiveTileText> Text_Name;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Details;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Price;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PreviousPrice;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SubInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Overlay_SalePrice;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_RarityStripe;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_OwningStatus;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> TileState_Owned;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> TileState_NotOwned;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> TileState_SubInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Overlay_Violator;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaItemShopTagRotator> TagRotator_ItemTags;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLoadGuard> LoadGuard_Image;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaItemShopTileImage> Image_Offer;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaItemShopTileImage> Image_NextOffer;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> Image_AnimatedWrap;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopTile")
	TObjectPtr<UMaterialInterface> MaterialBacking_Rarity;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopTile")
	TObjectPtr<UMaterialInterface> MaterialBacking_NoRarity;

	UPROPERTY(Transient)
	TObjectPtr<UTexture2D> ExternalSubscriptionTexture;

};

