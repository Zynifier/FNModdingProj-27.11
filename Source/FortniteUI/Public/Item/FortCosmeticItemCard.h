// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "FortRarityData.h"
#include "FortCosmeticItemCard.generated.h"

class UCommonLoadGuard;
class UFortItem;
class UFortItemDefinition;
class UImage;
class UMaterialInterface;
class USizeBox;
class UTexture2D;

UCLASS(Abstract, MinimalAPI, BlueprintType, meta=(DisableNativeTick))
class UFortCosmeticItemCard : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool HasItemToRepresent() const;

	UFUNCTION(BlueprintCallable)
	void NativeHover();

	UFUNCTION(BlueprintCallable)
	void NativeUnhover();

	UFUNCTION(BlueprintCallable)
	void SetCardWidth(float NewWidth);

	UFUNCTION(BlueprintCallable)
	void SetItemDefinitionToRepresent(const UFortItemDefinition* InItemToRepresent);

	UFUNCTION(BlueprintCallable)
	void SetItemToRepresent(const UFortItem* InItemToRepresent);

	UFUNCTION(BlueprintCallable)
	void SetMarked(bool bInIsMarked);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCardTypeChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnHover();

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemIconVisibilityChanged(bool bIsVisible);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSizeChanged(float InCardWidth);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUnhover();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateEnhanced(bool bEnhanced);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateItemCardIcon(UTexture2D* Icon, float IconScale);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateItemCardMaterial(UMaterialInterface* Material);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateSeriesOrRarityColors(const FFortColorPalette& ColorPalette);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateVisuals(bool bIsItem, bool bIsBorderAnimated, bool bIsHero, bool bReward, bool bIsShuffleItem, bool bShowAsArchived, bool bUseAnimations);

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortCosmeticItemCard")
	TSoftObjectPtr<UFortItemDefinition> DesignTimePreviewItemType;
#endif

	UPROPERTY(EditAnywhere, Category="FortCosmeticItemCard")
	bool bIsReward;

	UPROPERTY(EditAnywhere, Category="FortCosmeticItemCard")
	bool bIsItemIconEnabled;

	UPROPERTY(EditAnywhere, Category="FortCosmeticItemCard")
	bool bIsDetailIconEnabled;

	UPROPERTY(EditAnywhere, Category="FortCosmeticItemCard")
	bool bIsQuantityEnabled;

	UPROPERTY(EditAnywhere, Category="FortCosmeticItemCard")
	float WidthToHeightRatio;

	UPROPERTY(EditAnywhere, Category="FortCosmeticItemCard")
	float RewardWidthToHeightRatio;

	UPROPERTY(EditAnywhere, Category="FortCosmeticItemCard")
	float CardWidth;

	UPROPERTY(EditAnywhere, Category="FortCosmeticItemCard")
	float RewardCardWidth;

	UPROPERTY(EditDefaultsOnly, Category="FortCosmeticItemCard")
	TObjectPtr<UMaterialInterface> DefaultItemCardMaterial;

	UPROPERTY(EditDefaultsOnly, Category="FortCosmeticItemCard")
	float MinWidgetWidthForLargeAsset;

	UPROPERTY(EditDefaultsOnly, Category="FortCosmeticItemCard")
	float MinWidgetWidthForLargeAssetMobile;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCosmeticItemCard", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_NewItemCard;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCosmeticItemCard", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_NewItemCard;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLoadGuard> LoadGuard;

	UPROPERTY()
	TObjectPtr<UFortItem> ItemToRepresent;

	UPROPERTY()
	TObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(EditAnywhere, Category="FortCosmeticItemCard")
	TMap<FGameplayTag, float> ItemCardImageScales;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UFortItem> DesignTimePreviewItem;
#endif

};

