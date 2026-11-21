// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ValkyrieContentWorkerDebugManager.generated.h"

UCLASS()
class AValkyrieContentWorkerDebugManager : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Content Worker Actions")
	bool bCrashContentWorker;

	UPROPERTY(EditAnywhere, Category="Content Worker Actions")
	bool bEmitErrorFromContentWorker;

};

