// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PersistenceFrameworkActionQueueContainerBackendRequests.generated.h"

class UPersistenceFrameworkActionQueue;

UCLASS()
class FORTNITEGAME_API UPersistenceFrameworkActionQueueContainerBackendRequests : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	UPersistenceFrameworkActionQueue* ActionQueue;

};

