// Copyright Epic Games, Inc. All Rights Reserved.

#include "FrontEnd/ItemPreview/StateTransitionController.h"

void UStateTransitionControlLibrary::AddPauseRequest(const FStateTransitionControllerHandle& Controller, FStateTransitionPauseRequestHandle& Handle)
{
}

void UStateTransitionControlLibrary::ClearPauseRequest(FStateTransitionPauseRequestHandle& Handle, EStateTransitionPauseRequestHandleClearType ClearType)
{
}

bool UStateTransitionControlLibrary::IsStateTransitionPaused(const FStateTransitionControllerHandle& Controller)
{
	return false;
}

void UStateTransitionControlLibrary::RegisterEvent(const FStateTransitionControllerHandle& Controller, FStateTransitionEvent Event, EStateTransitionControlEvent Type)
{
}

void UStateTransitionControlLibrary::RemoveAllEvents(const FStateTransitionControllerHandle& Controller, UObject* Object, EStateTransitionControlEvent Type)
{
}

void UStateTransitionControlLibrary::RemoveEvent(const FStateTransitionControllerHandle& Controller, FStateTransitionEvent Event, EStateTransitionControlEvent Type)
{
}

void UStateTransitionControlLibrary::ResetPauseRequestHandle(FStateTransitionPauseRequestHandle& Handle)
{
}
