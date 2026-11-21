// Copyright Epic Games, Inc. All Rights Reserved.

#include "DaySequenceDirector.h"

AActor* UDaySequenceDirector::GetBoundActor(FMovieSceneObjectBindingID ObjectBinding)
{
	return nullptr;
}

TArray<AActor*> UDaySequenceDirector::GetBoundActors(FMovieSceneObjectBindingID ObjectBinding)
{
	return TArray<AActor*>();
}

UObject* UDaySequenceDirector::GetBoundObject(FMovieSceneObjectBindingID ObjectBinding)
{
	return nullptr;
}

TArray<UObject*> UDaySequenceDirector::GetBoundObjects(FMovieSceneObjectBindingID ObjectBinding)
{
	return TArray<UObject*>();
}

FQualifiedFrameTime UDaySequenceDirector::GetCurrentTime() const
{
	return FQualifiedFrameTime();
}

FQualifiedFrameTime UDaySequenceDirector::GetMasterSequenceTime() const
{
	return FQualifiedFrameTime();
}

FQualifiedFrameTime UDaySequenceDirector::GetRootSequenceTime() const
{
	return FQualifiedFrameTime();
}

UMovieSceneSequence* UDaySequenceDirector::GetSequence()
{
	return nullptr;
}
