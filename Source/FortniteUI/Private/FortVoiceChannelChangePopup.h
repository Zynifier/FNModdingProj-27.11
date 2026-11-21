// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "FortToastWidget.h"
#include "UI/FortUINotification.h"
#include "FortVoiceChannelChangePopup.generated.h"

class UCommonButtonLegacy;
class UCommonRichTextBlock;
class UCommonWidgetSwitcherLegacy;
class UFortKeybindWidget;
class UInputComponent;
class UWidgetAnimation;

UCLASS()
class UEnableVOIPNotification : public UFortUINotification
{
	GENERATED_BODY()

};

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UFortVoiceChannelChangePopup : public UFortToastWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnInputModeChanged(ECommonInputType NewInputType);

	UPROPERTY(Config)
	bool bEnableVoiceChatNotifyEverySession;

	UPROPERTY(EditInstanceOnly, Category="FortVoiceChannelChangePopup")
	bool bToastMode;

	UPROPERTY(EditInstanceOnly, Category="FortVoiceChannelChangePopup")
	float VisiblityInSeconds;

	UPROPERTY(EditDefaultsOnly, Category="LocalizedText")
	FText GameChannelText;

	UPROPERTY(EditDefaultsOnly, Category="LocalizedText")
	FText PartyChannelText;

	UPROPERTY(EditDefaultsOnly, Category="LocalizedText")
	FText JustJoinedChannelText;

	UPROPERTY(EditDefaultsOnly, Category="LocalizedText")
	FText StayedInChannelText;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVoiceChannelChangePopup", meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_SimplePopup;

private:
	UFUNCTION()
	void HandleOpenCloseAnimationFinished();

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UInputComponent> CachedGameChannelRecommendationInputComponent;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_TopLine;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_MiddleLine;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_BottomLine;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> ActionButton;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_JoinGameChat;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_InputButtons;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> HoldKeybindWidget_Keyboard;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> HoldKeybindWidget_GamePad;

};

