// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ListViewBase.h"
#include "SocialChatMessageList.generated.h"

class USocialChatChannel;

UCLASS(meta=(EntryClass="SocialChatMessageEntry"))
class SOCIALUMG_API USocialChatMessageList : public UListViewBase
{
	GENERATED_BODY()

public:
	USocialChatMessageList(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditInstanceOnly, Category="SocialChatMessageList")
	bool bIsFocusable;

private:
	UPROPERTY()
	TObjectPtr<USocialChatChannel> ActiveChannel;

};

