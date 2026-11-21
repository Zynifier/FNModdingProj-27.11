// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "Blueprint/UserWidget.h"
#include "Fonts/SlateFontInfo.h"
#include "Math/Color.h"
#include "SocialChatMessageEntry.generated.h"

class UButton;
class UCommonRichTextBlock;

USTRUCT()
struct FSocialChatMessageEntryTextStyle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SocialChatMessageEntryTextStyle")
	FSlateFontInfo FontInfo;

	UPROPERTY(EditDefaultsOnly, Category="SocialChatMessageEntryTextStyle")
	FLinearColor ColorAndOpacity;

};

USTRUCT()
struct FSocialChatMessageEntryStyle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SocialChatMessageEntryStyle")
	FSocialChatMessageEntryTextStyle SenderNameStyle;

	UPROPERTY(EditDefaultsOnly, Category="SocialChatMessageEntryStyle")
	FSocialChatMessageEntryTextStyle ChannelNameStyle;

	UPROPERTY(EditDefaultsOnly, Category="SocialChatMessageEntryStyle")
	FSocialChatMessageEntryTextStyle MessageTextStyle;

};

UCLASS(Abstract)
class SOCIALUMG_API USocialChatMessageEntry : public UUserWidget, public IUserListEntry
{
	GENERATED_BODY()

public:
	USocialChatMessageEntry(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintPure, Category="Social Chat Room Log Entry")
	bool CanInteract() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Social Chat Room Log Entry")
	void OnMessageSet();

	UPROPERTY(EditAnywhere, Category="SocialChatMessageEntry")
	FSocialChatMessageEntryStyle DefaultStyle;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Message;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UButton> Button_MessageButton;

};

