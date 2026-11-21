// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CreativeDeferredTaskComponent.generated.h"

class AActor;

USTRUCT()
struct FDeferredCreativeTask
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AActor> ActorPtr;

};

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UCreativeDeferredTaskComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void CancelAllTasks();

	UPROPERTY()
	TArray<FDeferredCreativeTask> DeferredFunctionsToExecute;

};

