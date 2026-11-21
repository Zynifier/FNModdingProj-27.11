// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SolarisCoroutineLibrary.generated.h"

class UObject;

/*
 * Internal BPVM library for handling tasks from script code
 */
UCLASS()
class USolarisCoroutineLibrary : public UObject
{
	GENERATED_BODY()

public:
	// Abort a suspended coroutine task and any subtasks

	UFUNCTION()
	static void TaskCancel(UObject* Task);

	UFUNCTION()
	static void TaskFree(UObject* Task);

	// Get the return value for a task

	UFUNCTION(CustomThunk)
	static void TaskGetReturnProperty(UObject* Task);
	DECLARE_FUNCTION(execTaskGetReturnProperty);

	// Get state from a coroutine task

	UFUNCTION()
	static int64 TaskGetState(UObject* Task);

	UFUNCTION()
	static UObject* TaskMake(UClass* Type, UObject* Caller, int64 CallerResumeState, int64 CallerCancelState, UObject* OwnerInstance);

};

