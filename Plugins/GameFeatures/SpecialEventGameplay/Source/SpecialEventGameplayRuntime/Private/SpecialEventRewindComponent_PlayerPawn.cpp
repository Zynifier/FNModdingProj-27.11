// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpecialEventRewindComponent_PlayerPawn.h"
#include "Net/UnrealNetwork.h"

void USpecialEventRewindComponent_PlayerPawn::OnServerLanded(const FHitResult& Hit)
{
}

void USpecialEventRewindComponent_PlayerPawn::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(USpecialEventRewindComponent_PlayerPawn, ReplicatedRecording);
	DOREPLIFETIME(USpecialEventRewindComponent_PlayerPawn, ReplicatedRecordingFastArray);
}
