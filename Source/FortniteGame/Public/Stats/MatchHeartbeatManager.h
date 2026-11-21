// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "UObject/NoExportTypes.h"
#include "MatchHeartbeatManager.generated.h"

class AFortGameMode;
class USlowStatReader;

USTRUCT()
struct FMatchHeartbeatManagerTickFunction : public FTickFunction
{
	GENERATED_BODY()

};

template<>
struct TStructOpsTypeTraits<FMatchHeartbeatManagerTickFunction> : public TStructOpsTypeTraitsBase2<FMatchHeartbeatManagerTickFunction>
{
	enum
	{
		WithCopy = false
	};
};

UCLASS(Config=Game)
class UMatchHeartbeatManager : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<AFortGameMode> OwningGameMode;

	UPROPERTY(Transient)
	TObjectPtr<USlowStatReader> SlowStatReader;

	UPROPERTY(Transient)
	FMatchHeartbeatManagerTickFunction MatchHearbeatTick;

	UPROPERTY(Config)
	int32 ServerMetricsLOD;

	UPROPERTY(Config)
	int32 HighFrequencyServerMetricsDurationSec;

	UPROPERTY(Config)
	int32 HighFrequencyEventsLOD;

};

