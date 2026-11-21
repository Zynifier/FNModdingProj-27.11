// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AsyncTaskQueue.h"
#include "Tests/Controllers/IslandInspector/IslandInspectorCommand.h"
#include "IslandInspectorLoadIslandCommand.generated.h"

UCLASS()
class UIslandInspectorLoadIslandCommand : public UIslandInspectorCommand
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnIslandLoaded(const FAsyncTaskResult& Result);

};

