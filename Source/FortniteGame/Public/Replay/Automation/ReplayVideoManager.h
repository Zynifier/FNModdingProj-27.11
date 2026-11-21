// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Replay/Automation/Pegasus/PegasusTimelineEventTypes.h"
#include "ReplayVideoManager.generated.h"

class UPegasusGameEventCollector;

UENUM()
enum class EVideoManagerJobTypes : uint8
{
	EliminationExtraction = 0,
	DefinedShotSequence = 1,
};

UENUM()
enum class EVideoManagerStates : uint8
{
	INVALID = 0,
	LoadingReplay = 1,
	ScrubbingReplay = 2,
	WaitingForShotSetup = 3,
	WatchingShot = 4,
	ExportingShot = 5,
	PostExportedShot = 6,
};

USTRUCT()
struct FVideoManagerExtractionJob
{
	GENERATED_BODY()

};

USTRUCT()
struct FWatchedReplayShotInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 ShotIndex;

	UPROPERTY()
	TArray<FPegasusTimelineEvent> TimelineEvents;

};

UCLASS()
class UReplayVideoManager : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPegasusGameEventCollector> ActiveTimelineCollector;

};

