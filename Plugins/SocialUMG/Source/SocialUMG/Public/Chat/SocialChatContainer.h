// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/SlateEnums.h"
#include "CommonButtonLegacy.h"
#include "SocialChatContainer.generated.h"

class UCommonButtonBase;
class UCommonButtonGroupLegacy;
class UCommonTextBlock;
class UDynamicEntryBox;
class UScrollBox;
class USocialChatChannel;
class USocialChatEditableText;
class USocialChatManager;
class USocialChatMessageList;

UCLASS(Abstract)
class SOCIALUMG_API USocialChatChannelTab : public UCommonButtonLegacy
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<USocialChatChannel> ChatChannel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> CommonText_ChannelName;

};

UCLASS(Abstract)
class SOCIALUMG_API USocialChatContainer : public UUserWidget
{
	GENERATED_BODY()

public:
	USocialChatContainer(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void FocusEditableText();

	UFUNCTION(BlueprintCallable)
	void HandleLeftTabPressed();

	UFUNCTION(BlueprintCallable)
	void HandleRightTabPressed();

	UFUNCTION(BlueprintCallable)
	void SendCurrentMessage();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnChatOpenChanged(bool bShouldBeOpen);

	UPROPERTY()
	TObjectPtr<USocialChatManager> ChatManager;

	UPROPERTY(BlueprintReadOnly, Export, Category="SocialChatContainer", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<USocialChatMessageList> ChatList_Messages;

	UPROPERTY(BlueprintReadOnly, Export, Category="SocialChatContainer", meta=(BindWidget, EditInline="true"))
	TObjectPtr<USocialChatEditableText> ChatEditableText_MessageEntry;

private:
	UFUNCTION()
	void DynamicHandleMessageTextCommitted(const FText& MessageText, ETextCommit::Type CommitMethod);

	UPROPERTY()
	TArray<TObjectPtr<USocialChatChannel>> JoinedChannels;

	UPROPERTY()
	TObjectPtr<USocialChatChannel> ActiveChannel;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupLegacy> TabButtonGroup;

	UPROPERTY(BlueprintReadOnly, Export, Category="SocialChatContainer", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_SendMessage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="SocialChatChannelTab"))
	TObjectPtr<UDynamicEntryBox> EntryBox_JoinedChannels;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_Channels;

};

