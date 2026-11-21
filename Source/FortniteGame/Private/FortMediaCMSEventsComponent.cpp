// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortMediaCMSEventsComponent.h"

const TArray<UMediaCMSEvent*>& UFortMediaCMSEventsComponent::GetAllMediaEvents() const
{
	static TArray<UMediaCMSEvent*> Dummy;
	return Dummy;
}

const TArray<UMediaCMSEvent*>& UFortMediaCMSEventsComponent::GetValidMediaEvents() const
{
	static TArray<UMediaCMSEvent*> Dummy;
	return Dummy;
}

void UFortMediaCMSEventsComponent::InitializeEventPage(const FString& InEventPageName)
{
}

void UFortMediaCMSEventsComponent::InitializeEventPageCustomData(const FString& InEventPageName, TSubclassOf<UMediaCMSEvent> InCMSType)
{
}
