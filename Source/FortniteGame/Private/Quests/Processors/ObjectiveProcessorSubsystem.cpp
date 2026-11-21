// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/Processors/ObjectiveProcessorSubsystem.h"

FFilteredEventReceiverHandle UObjectiveProcessorSubsystem::BP_StartListeningToFilteredEvent(const UObject* WorldContextObject, const UObject* EventManager, const UObject* EventParticipant, const FInstancedStruct& VerbFilter, const bool bStopListeningOnSuccess, FOnBlueprintFilteredEventSuccessEvent DelegateSignature)
{
	return FFilteredEventReceiverHandle();
}

void UObjectiveProcessorSubsystem::BP_StopListeningToFilteredEvent(const UObject* WorldContextObject, FFilteredEventReceiverHandle& EventHandle)
{
}
