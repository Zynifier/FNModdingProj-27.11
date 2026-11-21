// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortActivatableChatWidget.generated.h"

class UCommonButtonBase;
class UDataTable;
class UFortChatContainer;
class UFortChatModalWrapper;

UCLASS(meta=(DisableNativeTick))
class UFortActivatableChatWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void BacchusFrontendFocusChat();

	UFUNCTION(BlueprintImplementableEvent)
	void FocusChat(bool bFocus);

private:
	UFUNCTION(BlueprintCallable)
	void HandleHoldButtonClicked();

	UFUNCTION(BlueprintCallable)
	void HandleRequestChatClose();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivatableChatWidget", meta=(AllowPrivateAccess="true", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortChatModalWrapper> Activatable_ModalBindings;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_HoldToOpen;

	UPROPERTY(EditAnywhere, Category="FortActivatableChatWidget")
	TObjectPtr<UDataTable> InputActionDataTable;

	UPROPERTY(EditAnywhere, Category="FortActivatableChatWidget")
	bool bActivationTriggeredManually;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortChatModalWrapper : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortChatModalWrapper", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortChatContainer> ChatContainer_Chat;

};

