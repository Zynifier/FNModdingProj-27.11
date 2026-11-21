// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortServerDebugActor.generated.h"

UCLASS(Transient, NotPlaceable)
class AFortServerDebugActor : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(Replicated)
	uint64 ServerMemSharedInKb;

	UPROPERTY(Replicated)
	uint64 ServerMemUniqueInKb;

	UPROPERTY(Replicated)
	uint64 ServerMemVirtualInKb;

	UPROPERTY(Replicated)
	uint64 ServerMemPhysicalInKb;

	UPROPERTY(Replicated)
	int64 SharedDeltaInLastMinute;

	UPROPERTY(Replicated)
	int64 SharedDeltaSinceProcessStart;

	UPROPERTY(Replicated)
	int64 SharedDeltaSinceDebugStart;

	UPROPERTY(Replicated)
	int64 UniqueDeltaInLastMinute;

	UPROPERTY(Replicated)
	int64 UniqueDeltaSinceProcessStart;

	UPROPERTY(Replicated)
	int64 UniqueDeltaSinceDebugStart;

};

