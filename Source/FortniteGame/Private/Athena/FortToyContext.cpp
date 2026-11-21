// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortToyContext.h"

bool UFortToyContext::ConditionalPrintToMessageFeed(AFortPlayerState* Instigator, FVector MessageLocation, EMessageFeedRelationshipFilter RelationshipFilter, const FText& Message)
{
	return false;
}

FText UFortToyContext::FormatPlayerNameForDisplay(AFortPlayerState* Subject, EMessageFeedSubject SubjectType)
{
	return FText();
}

FString UFortToyContext::GetFilteredPlayerName(AFortPlayerState* Instigator)
{
	return FString();
}

FText UFortToyContext::PickToyOwnerNameStyle(AFortPlayerState* Instigator)
{
	return FText();
}

void UFortToyContext::PrintToMessageFeed(const FText& Message)
{
}
