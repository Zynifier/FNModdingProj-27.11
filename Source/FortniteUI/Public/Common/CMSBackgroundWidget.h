// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "CMSBackgroundWidget.generated.h"

class UCommonButtonBase;
class UImage;
class UTexture2D;

UCLASS(Abstract, MinimalAPI, BlueprintType, meta=(DisableNativeTick))
class UCMSBackgroundWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnDownloadBackgroundComplete(UTexture2D* NewBackground);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnStartingDownloadBackground();

private:
	UPROPERTY(EditDefaultsOnly, Category="CMSBackgroundWidget")
	float OlderBackgroundStreamoutSeconds;

	UPROPERTY(EditInstanceOnly, Category="CMSBackgroundWidget")
	bool bDeactivateOnClose;

	UPROPERTY(BlueprintReadOnly, Export, Category="CMSBackgroundWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Background;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Close;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TouchClose;

};

