// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "UIManager/FortHUDShutdownTimerInterface.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "FortWebPurchaseScreen.generated.h"

class UPanelWidget;
class UWidget;

UCLASS(meta=(DisableNativeTick))
class UFortWebPurchaseScreen : public UCommonActivatablePanelLegacy, public IFortHUDShutdownTimerInterface, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="WebPurchaseScreen")
	bool CanShowBottomBar() const;

	UFUNCTION(BlueprintPure, Category="WebPurchaseScreen")
	bool CanShowChatWidget() const;

	UFUNCTION(BlueprintPure, Category="WebPurchaseScreen")
	bool CanShowTopBar() const;

	UFUNCTION(BlueprintCallable, Category="WebPurchaseScreen")
	void Dismiss();

	UFUNCTION(BlueprintCallable, Category="WebPurchaseScreen")
	void Display(UWidget* WebWidget);

protected:
	UPROPERTY(EditDefaultsOnly, Category="WebPurchaseScreen")
	FPrimaryContentSetup PrimaryContentSetup;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortWebPurchaseScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> WebContent;

};

