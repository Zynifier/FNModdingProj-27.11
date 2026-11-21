// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Frontend/Lobby/Social/FortSocialSidebarPanelInterface.h"
#include "FortSidebarPanelKoala.generated.h"

class UCommonButtonBase;
class UFortLazyImage;

UCLASS(Abstract, BlueprintType, meta=(DisableNativeTick))
class UFortSidebarPanelKoala : public UCommonActivatableWidget, public IFortSocialSidebarPanelInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnConnectionChanged(bool bConnected);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarPanelKoala", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_KoalaDummy;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortSidebarPanelKoala", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> QRCodeImage;

	UPROPERTY(EditDefaultsOnly, Category="FortSidebarPanelKoala")
	FString QRCodeURL;

};

