// Copyright Epic Games, Inc. All Rights Reserved.

#include "Media/FortMediaStreamingRadio.h"
#include "Net/UnrealNetwork.h"

void AFortMediaStreamingRadio::OnFailedURL(const FString& URL)
{
}

void AFortMediaStreamingRadio::OnMediaClosed()
{
}

void AFortMediaStreamingRadio::OnMediaOpened(const FString& String)
{
}

void AFortMediaStreamingRadio::OnSuccessfulURL(const FString& URL)
{
}

void AFortMediaStreamingRadio::Start(const int32 StationIndex)
{
}

void AFortMediaStreamingRadio::Stop()
{
}

void AFortMediaStreamingRadio::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortMediaStreamingRadio, MediaStartTimeFromInit);
}
