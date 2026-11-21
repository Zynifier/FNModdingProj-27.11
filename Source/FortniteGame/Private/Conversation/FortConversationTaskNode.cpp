// Copyright Epic Games, Inc. All Rights Reserved.

#include "Conversation/FortConversationTaskNode.h"

TSoftObjectPtr<USoundBase> UFortConversationTaskNode::GetChoiceSound() const
{
	return TSoftObjectPtr<USoundBase>();
}

TSoftObjectPtr<UObject> UFortConversationTaskNode::GetDisplayAssetForChoice_Implementation(const FConversationContext& Context, const FClientConversationOptionEntry& InOptionEntry) const
{
	return TSoftObjectPtr<UObject>();
}

TSoftObjectPtr<USoundBase> UFortConversationTaskNode::GetHoverChoiceSound() const
{
	return TSoftObjectPtr<USoundBase>();
}

TSoftObjectPtr<UObject> UFortConversationTaskNode::GetTaskIcon() const
{
	return TSoftObjectPtr<UObject>();
}

void UFortConversationTaskNode::OnPreviewedChoicePickedByUser_Implementation(const FConversationContext& Context, const FClientConversationOptionEntry& ClientChoice) const
{
}
