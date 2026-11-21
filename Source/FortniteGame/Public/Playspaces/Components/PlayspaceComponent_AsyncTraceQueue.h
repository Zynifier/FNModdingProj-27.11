// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "PlayspaceComponent_AsyncTraceQueue.generated.h"

class AActor;
class UAsyncOverlapQueue;
class UAsyncTraceQueue;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UPlayspaceComponent_AsyncQueue : public UFortPlayspaceComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Utility|OverlapQueue")
	static UAsyncOverlapQueue* GetAsyncOverlapQueue(const AActor* ContextActor);

	UFUNCTION(BlueprintCallable, Category="Utility|TraceQueue")
	static UAsyncTraceQueue* GetAsyncTraceQueue(const AActor* ContextActor);

protected:
	UPROPERTY()
	TObjectPtr<UAsyncTraceQueue> AsyncTraceQueue;

	UPROPERTY()
	TObjectPtr<UAsyncOverlapQueue> AsyncOverlapQueue;

};

