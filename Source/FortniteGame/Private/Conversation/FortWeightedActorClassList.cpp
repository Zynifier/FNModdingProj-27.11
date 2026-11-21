// Copyright Epic Games, Inc. All Rights Reserved.

#include "Conversation/FortWeightedActorClassList.h"

bool UWeightedActorClassListLibrary::IsListValid(const FFortWeightedActorTypeList& QueryList)
{
	return false;
}

TSubclassOf<AActor> UWeightedActorClassListLibrary::SelectRandomActorTypeFromList(const FFortWeightedActorTypeList& QueryList)
{
	return TSubclassOf<AActor>();
}

TSubclassOf<AActor> UWeightedActorClassListLibrary::SelectRandomActorTypeFromListWithDebug(const FFortWeightedActorTypeList& QueryList, AActor* DebugContextActor)
{
	return TSubclassOf<AActor>();
}
