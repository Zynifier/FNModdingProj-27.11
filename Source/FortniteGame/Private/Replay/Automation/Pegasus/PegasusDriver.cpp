// Copyright Epic Games, Inc. All Rights Reserved.

#include "Replay/Automation/Pegasus/PegasusDriver.h"

void UPegasusDriver::HandleVideoManagerFinishedAllJobs()
{
}

void UPegasusDriver::HandleVideoManagerJobBeganProcessing(const FVideoManagerExtractionJob& ExtractionJob)
{
}

void UPegasusDriver::HandleVideoManagerJobComplete(const FVideoManagerExtractionJob& ExtractionJob)
{
}

void UPegasusDriver::HandleVideoManagerJobFailed(const FVideoManagerExtractionJob& ExtractionJob, const FString& FailureReason, const FString& ErrorCode)
{
}

void UPegasusDriver::HandleVideoManagerJobShotExported(const FVideoManagerExtractionJob& VideoManagerJob, int32 ShotIndex, const FString& VideoPath)
{
}

void UPegasusDriver::HandleVideoManagerJobShotWatched(const FVideoManagerExtractionJob& VideoManagerJob, const FWatchedReplayShotInfo& WatchedInfo)
{
}
