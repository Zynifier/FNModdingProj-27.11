// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "FortToastWidget.h"
#include "FortSocialNotificationWidget.generated.h"

class UFortKeybindWidget;
class UFortPlayerAvatar;
class UFortSocialAvatarIcon;
class USidebarSocialTagListBase;
class UUserWidget;

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UFortSocialNotificationWidget : public UFortToastWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	bool GetIsInGame() const;

	UFUNCTION(BlueprintPure)
	bool GetIsPlayerJoiningParty() const;

	UFUNCTION(BlueprintPure)
	bool GetIsPlayerLeavingParty() const;

	UFUNCTION(BlueprintCallable)
	void HoldAction();

	UFUNCTION(BlueprintCallable)
	void HoldPressed();

	UFUNCTION(BlueprintCallable)
	void HoldReleased();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCancelNotification();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCursorModeChanged(bool bCursorModeEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnInputModeChanged(ECommonInputType NewInputType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewAvatarsEnabledChanged(bool bUsingNewAvatars);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTakeActionNotification();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUserStartedHoldActionNotification();

	UPROPERTY(BlueprintReadWrite, Export, Category="FortSocialNotificationWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> Avatar_MemberIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialNotificationWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortPlayerAvatar> PlayerAvatar;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialNotificationWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<USidebarSocialTagListBase> SidebarSocialTagList;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> Action_HoldKeybindWidget;

private:
	UFUNCTION()
	void HandleCursorModeChanged(bool bCursorModeEnabled, FName ActionName, UUserWidget* CustomWidget);

	UFUNCTION()
	void HandleInputMethodChanged(ECommonInputType NewInputType);

};

