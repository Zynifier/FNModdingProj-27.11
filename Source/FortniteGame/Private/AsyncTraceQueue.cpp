// Copyright Epic Games, Inc. All Rights Reserved.

#include "AsyncTraceQueue.h"

void UAsyncTraceQueue::AsyncTrace_Immediate(UObject* WorldContextObject, const FVector& StartLocation, const FVector& EndLocation, const TArray<AActor*>& ActorsToIgnore, ECollisionChannel CollisionChannel, FOnTraceProcessComplete CompletionFunction)
{
}

void UAsyncTraceQueue::ThrottledAsyncTrace(UObject* WorldContextObject, const FVector& StartLocation, const FVector& EndLocation, const TArray<AActor*>& ActorsToIgnore, ECollisionChannel CollisionChannel, FOnTraceProcessComplete CompletionFunction)
{
}

void UAsyncTraceQueue::ThrottledAsyncTrace_SourceTarget(UObject* WorldContextObject, const bool bUseLocalCameraAsSource, const AActor* SourceActor, const FVector& SourceOffset, const AActor* TargetActor, const FVector& TargetOffset, const TArray<AActor*>& ActorsToIgnore, ECollisionChannel CollisionChannel, FOnTraceProcessComplete CompletionFunction)
{
}
