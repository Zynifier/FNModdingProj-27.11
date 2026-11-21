// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BuildingFlushManager.generated.h"

class AActor;

USTRUCT()
struct FQueuedFlushNetDormancyInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AActor> Actor;

};

UCLASS()
class UBuildingFlushManager : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FQueuedFlushNetDormancyInfo> FlushNetDormancyQueue;

};

