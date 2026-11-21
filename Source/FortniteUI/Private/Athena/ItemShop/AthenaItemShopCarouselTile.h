// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "AthenaItemShopCarouselTile.generated.h"

class UCommonTextBlock;
class UImage;
class UTexture2D;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaItemShopCarouselTile : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnActiveStateChanged(bool bIsSelected);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnFadeInTransitionToNext();

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnFadeInTransitionToPrevious();

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnFadeOutTransitionToNext();

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnFadeOutTransitionToPrevious();

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnIntro();

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnPeekStateChanged(bool bIsInPeekState);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Background;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Foreground;

	UPROPERTY(Transient)
	TObjectPtr<UTexture2D> ExternalMedia;

};

