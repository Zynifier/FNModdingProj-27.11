// Copyright Epic Games, Inc. All Rights Reserved.

#include "Tweening/TweenManager.h"

bool UTweenManager::HasTween(int32 InTweenId)
{
	return false;
}

bool UTweenManager::KillTween(int32 InTweenId)
{
	return false;
}

void UTweenManager::KillTweens(TArray<int32> InTweenIds)
{
}

bool UTweenManager::PlayTween(int32 InTweenId, ETweenPlayDirection InPlayDirection)
{
	return false;
}

void UTweenManager::PlayTweens(TArray<int32> InTweenIds, ETweenPlayDirection InPlayDirection)
{
}

bool UTweenManager::PlayTweenWithLooping(int32 InTweenId, ETweenLoopType InLoopType, int32 InLoopCount, ETweenPlayDirection InPlayDirection)
{
	return false;
}

bool UTweenManager::ResetTween(int32 InTweenId, ETweenResetDestination InDestination)
{
	return false;
}

void UTweenManager::ResetTweens(TArray<int32> InTweenIds, ETweenResetDestination InDestination)
{
}

bool UTweenManager::SetTweenTiming(int32 InTweenId, float InDuration, float InDelayAtBeginning, float InDelayAtEnd) const
{
	return false;
}

bool UTweenManager::StopTween(int32 InTweenId)
{
	return false;
}

void UTweenManager::StopTweens(TArray<int32> InTweenIds)
{
}
