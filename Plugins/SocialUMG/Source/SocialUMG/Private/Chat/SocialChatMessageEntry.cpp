// Copyright Epic Games, Inc. All Rights Reserved.

#include "Chat/SocialChatMessageEntry.h"

USocialChatMessageEntry::USocialChatMessageEntry(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool USocialChatMessageEntry::CanInteract() const
{
	return false;
}
