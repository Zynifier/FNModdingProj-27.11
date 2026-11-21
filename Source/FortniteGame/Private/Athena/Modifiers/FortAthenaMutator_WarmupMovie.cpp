// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_WarmupMovie.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_WarmupMovie::OnMediaClosedOrEndReached()
{
}

void AFortAthenaMutator_WarmupMovie::ShowMovieWidget(UCommonActivatablePanelLegacy* InMovieWidget, UMediaPlayer* InMediaPlayer)
{
}

void AFortAthenaMutator_WarmupMovie::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_WarmupMovie, bServerMovieStart);
}

void UWarmupMovieComponent::ServerFinishedWatchingMovie_Implementation()
{
}
