// Copyright Epic Games, Inc. All Rights Reserved.

#include "Track/FortTrack.h"
#include "Net/UnrealNetwork.h"

void AFortTrack::GetOutgoingNeighborFromSpline(USplineComponent* InSpline, bool InReverseDirection, AFortTrack*& OutNeighbor)
{
}

float AFortTrack::GetPathDistanceToTrack(AFortTrack* TargetTrack, USplineComponent* InCurrentSpline, float CurrentDistanceAlongSpline, bool InReverseDirection)
{
	return float();
}

void AFortTrack::GetSplineFromIncomingNeighbor(AFortTrack* InNeighbor, USplineComponent*& OutSpline, bool& OutReverseDirection)
{
}

void AFortTrack::GetSplineFromPositionAndOrientation(const FVector& InLocation, const FRotator& InRotation, USplineComponent*& OutSpline, float& OutDistanceAlongSpline, bool& OutReverseDirection)
{
}

void AFortTrack::InitializeTrack(UPrimitiveComponent* InSwitchComp)
{
}

bool AFortTrack::IsConnectedToTrack(AFortTrack* TargetTrack)
{
	return false;
}

bool AFortTrack::IsConnectedToTrackList(const TArray<AFortTrack*>& TargetTracks)
{
	return false;
}

void AFortTrack::OnRep_ConfigurationIdx()
{
}

void AFortTrack::OnRep_NeighborsByDirection()
{
}

void AFortTrack::OnRep_SwitchState()
{
}

void AFortTrack::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortTrack, NeighborsByDirection);
	DOREPLIFETIME(AFortTrack, SwitchState);
	DOREPLIFETIME(AFortTrack, ConfigurationIdx);
}
