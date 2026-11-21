// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortConversationUtilites.h"

bool UFortConversationContextCondition::DoesContextPass(const FConversationContext& Context) const
{
	return false;
}

bool UFortConversationContextConditionHelpers::GetMessageForContext(const FFortConversationNodeConditionalMessages& Messages, const FConversationContext& Context, FText& OutText)
{
	return false;
}

bool UFortConversationParamLibrary::ExtractConversationParameterValue(const TArray<FConversationNodeParameterPair>& ConversationParameters, const FString& DesiredParameterName, FString& ParameterValueOut)
{
	return false;
}
