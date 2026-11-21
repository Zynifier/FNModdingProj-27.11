// Copyright Epic Games, Inc. All Rights Reserved.

#include "PapayaTimedEvents.h"
#include "Net/UnrealNetwork.h"

void APapayaTimedEvents::AddTimedEvent_Native(const FString& EventName, int64 Time, const FString& EventParam)
{
}

void APapayaTimedEvents::OnRep_ScreenName(const FString& PreviousValue)
{
}

void APapayaTimedEvents::OnRep_TimedEventsArray(const FMediaTimeEventArray& PreviousValue)
{
}

void APapayaTimedEvents::ResetTimedEvents_Native()
{
}

void APapayaTimedEvents::SetupTimedEvents_Native(const FString& ScreenName)
{
}

void APapayaTimedEvents::ShutdownTimedEvents_Native()
{
}

void APapayaTimedEvents::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(APapayaTimedEvents, TimedEventsArray);
	DOREPLIFETIME(APapayaTimedEvents, ScreenName);
}
