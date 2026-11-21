// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "K2Node_AsyncAction.h"
#include "K2Node_GameplayMessageAsyncAction.generated.h"

/**
 * Blueprint node which is spawned to handle the async logic for UAsyncAction_RegisterGameplayMessageReceiver
 */
UCLASS()
class GAMEPLAYMESSAGESEDITOR_API UK2Node_GameplayMessageAsyncAction : public UK2Node_AsyncAction
{
	GENERATED_BODY()

};

