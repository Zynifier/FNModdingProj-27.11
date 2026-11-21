// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GenericMessageQueue.generated.h"

USTRUCT()
struct FGenericMessage
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UGenericMessageQueue : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsMessagesQueueEmpty();

	UFUNCTION(BlueprintCallable)
	void ProcessNextMessage();

};

