// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "AsyncTraceQueue.generated.h"

class AActor;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnTraceProcessComplete, bool, Succeeded, const AActor*, ActorHit, FHitResult, HitResult);

UCLASS()
class UAsyncTraceQueue : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="ActorsToIgnore", WorldContext="WorldContextObject"))
	static void AsyncTrace_Immediate(UObject* WorldContextObject, const FVector& StartLocation, const FVector& EndLocation, const TArray<AActor*>& ActorsToIgnore, ECollisionChannel CollisionChannel, FOnTraceProcessComplete CompletionFunction);

	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="ActorsToIgnore", WorldContext="WorldContextObject"))
	void ThrottledAsyncTrace(UObject* WorldContextObject, const FVector& StartLocation, const FVector& EndLocation, const TArray<AActor*>& ActorsToIgnore, ECollisionChannel CollisionChannel, FOnTraceProcessComplete CompletionFunction);

	UFUNCTION(BlueprintCallable, meta=(AutoCreateRefTerm="ActorsToIgnore", WorldContext="WorldContextObject"))
	void ThrottledAsyncTrace_SourceTarget(UObject* WorldContextObject, const bool bUseLocalCameraAsSource, const AActor* SourceActor, const FVector& SourceOffset, const AActor* TargetActor, const FVector& TargetOffset, const TArray<AActor*>& ActorsToIgnore, ECollisionChannel CollisionChannel, FOnTraceProcessComplete CompletionFunction);

};

