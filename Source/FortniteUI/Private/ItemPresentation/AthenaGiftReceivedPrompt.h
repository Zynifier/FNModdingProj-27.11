// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "AthenaGiftReceivedPrompt.generated.h"

class UCommonButtonLegacy;
class UCommonLazyImage;
class UFortGiftBoxItem;
class UFortItemPresentationScreen;
class UFortItemReceivedHeaderBase;
class UMaterialInterface;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaGiftReceivedPrompt : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void DismissPrompt();

	UFUNCTION()
	void HandleMessageTextFiltered(bool bSuccess, const FString& SanitizedMessage);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCloseButtonClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void OnGiftInfoPopulated();

	UPROPERTY(EditAnywhere, Category="AthenaGiftReceivedPrompt")
	TSubclassOf<UFortItemPresentationScreen> ItemPresentationScreenClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaGiftReceivedPrompt")
	TSoftObjectPtr<UMaterialInterface> GiftMaterial;

private:
	UPROPERTY()
	TObjectPtr<UFortGiftBoxItem> GiftBoxItem;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemReceivedHeaderBase> Widget_HeaderInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Open;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> Image_GiftBox;

};

