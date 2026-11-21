// Copyright Epic Games, Inc. All Rights Reserved.

#include "Sound/FortFeedbackManager.h"
#include "Net/UnrealNetwork.h"

AFortPawn_FeedbackAnnouncer* AFortFeedbackManager::GetAnnouncerPawn(UObject* WorldContextObject)
{
	return nullptr;
}

AFortFeedbackManager* AFortFeedbackManager::GetFeedbackManager(UObject* WorldContextObject)
{
	return nullptr;
}

void AFortFeedbackManager::SuppressProceduralFeedback(TArray<AController*> ControllersToSuppress)
{
}

void AFortFeedbackManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortFeedbackManager, Announcer);
	DOREPLIFETIME(AFortFeedbackManager, SuppressedControllers);
}
