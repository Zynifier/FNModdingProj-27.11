// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PersistenceFrameworkActionQueue.generated.h"

UENUM()
enum class EPersistenceFrameworkActionEnd : uint8
{
	/** The operation failed */
	Finished = 0,
	/** The operation Succeeded */
	Aborted = 1,
};

UENUM()
enum class EPersistenceFrameworkExecutionOption : uint8
{
	/** Claers all the actions in a action queue, once it finises executing. Without this, a action queue can be run multiple times */
	RemoveAllActionsOnFinish = 0,
	/** If any action fails, abort the remaining actions */
	AbortIfAnyActionFails = 1,
	// TODO Add ExecuteInParalell

	EPersistenceFrameworkActionQueueOptions_MaxFlags = 2,
};

UCLASS()
class FORTNITEGAME_API UPersistenceFrameworkActionQueue : public UObject
{
	GENERATED_BODY()

};

