// Copyright Epic Games, Inc. All Rights Reserved.

#include "Verbs/VerbMessage_Custom.h"

void UCustomVerbMessageLibrary::AddTagsForSubject(FVerbMessage_Custom& CustomVerb, FName SubjectName, const FGameplayTagContainer& SubjectTags, FVerbMessage_Custom& Result)
{
}

void UCustomVerbMessageLibrary::AddTagsFromSubject(FVerbMessage_Custom& CustomVerb, FName SubjectName, UObject* SubjectObject, FVerbMessage_Custom& Result)
{
}

void UCustomVerbMessageLibrary::AddValue(FVerbMessage_Custom& CustomVerb, FName ValueName, float Value, FVerbMessage_Custom& Result)
{
}

void UCustomVerbMessageLibrary::BroadcastCustomVerbMessage(const FVerbMessage_Custom& CustomVerb)
{
}

FVerbMessage_Custom UCustomVerbMessageLibrary::MakeCustomVerbMessage(UObject* const& Author, FGameplayTag VerbName, int32 Amount)
{
	return FVerbMessage_Custom();
}

void UCustomVerbMessageLibrary::OverrideContextLocation(FVerbMessage_Custom& CustomVerb, const FVector& ContextLocation, FVerbMessage_Custom& Result)
{
}
