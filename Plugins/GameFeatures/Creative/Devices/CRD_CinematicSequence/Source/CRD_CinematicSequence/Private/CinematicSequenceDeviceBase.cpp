// Copyright Epic Games, Inc. All Rights Reserved.

#include "CinematicSequenceDeviceBase.h"
#include "Net/UnrealNetwork.h"

int32 ACinematicSequenceDeviceBase::GetPlaybackFrame() const
{
	return int32();
}

float ACinematicSequenceDeviceBase::GetPlaybackTime() const
{
	return float();
}

float ACinematicSequenceDeviceBase::GetPlayRate() const
{
	return float();
}

UMovieSceneSequencePlayer* ACinematicSequenceDeviceBase::GetSequencePlayer() const
{
	return nullptr;
}

void ACinematicSequenceDeviceBase::GoToEndAndStop()
{
}

void ACinematicSequenceDeviceBase::HandleSequencePlayerCreated_Implementation(ULevelSequencePlayer* Player)
{
}

void ACinematicSequenceDeviceBase::Pause()
{
}

void ACinematicSequenceDeviceBase::Play()
{
}

void ACinematicSequenceDeviceBase::SetPlaybackFrame(int32 Frame)
{
}

void ACinematicSequenceDeviceBase::SetPlaybackTime(float Time)
{
}

void ACinematicSequenceDeviceBase::SetPlayRate(float PlayRate)
{
}

void ACinematicSequenceDeviceBase::SetSequence(ULevelSequence* Sequence)
{
}

void ACinematicSequenceDeviceBase::Stop()
{
}

void ACinematicSequenceDeviceBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ACinematicSequenceDeviceBase, InstigatingController);
	DOREPLIFETIME(ACinematicSequenceDeviceBase, InstigatingTeam);
}

bool ACinematicSequenceDeviceBase::CanObserveSequence() const
{
	return false;
}
