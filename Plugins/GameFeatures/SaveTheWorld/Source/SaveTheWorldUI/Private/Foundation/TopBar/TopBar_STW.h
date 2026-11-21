// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Feature/FortUIFeature.h"
#include "TopBar_STW.generated.h"

class UCommonButtonLegacy;
class UDataTable;
class UFortPhoenixSeasonDisplayInfo;
class UImage;
class UMainMenu_STW;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UTopBar_STW : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnShouldShowPhoenixDisplay(bool bShow, UFortPhoenixSeasonDisplayInfo* PhoenixDisplayInfo);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSocialMenuOpened();

	UFUNCTION(BlueprintImplementableEvent)
	void SetOnlineFriendsCount(int32 NewOnlineFriendsCount);

private:
	UPROPERTY(EditDefaultsOnly, Category="TopBar_STW")
	TObjectPtr<UDataTable> PhoenixSeasonDisplayInfoMap;

	UPROPERTY(EditDefaultsOnly, Category="TopBar_STW")
	TMap<EFortUIFeatureStateReason, FText> ReasonDescriptions;

	UPROPERTY(BlueprintReadOnly, Export, Category="TopBar_STW", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_MainMenu;

	UPROPERTY(BlueprintReadOnly, Export, Category="TopBar_STW", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UMainMenu_STW> MainMenu;

	UPROPERTY(BlueprintReadOnly, Export, Category="TopBar_STW", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ActiveInvitesNotification;

	UPROPERTY(BlueprintReadOnly, Export, Category="TopBar_STW", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Social;

};

