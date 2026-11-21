// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/PlayspaceComponent_StreamingController.h"
#include "Net/UnrealNetwork.h"

UPlayspaceComponent_StreamingController* UPlayspaceComponent_StreamingController::GetOrCreateComponent(AFortPlayspace* Owner)
{
	return nullptr;
}

AFortCreativeStreamingController* UPlayspaceComponent_StreamingController::GetStreamingController()
{
	return nullptr;
}

void UPlayspaceComponent_StreamingController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UPlayspaceComponent_StreamingController, FortCreativeStreamingController);
}
