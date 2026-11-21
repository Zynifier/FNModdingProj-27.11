// Copyright Epic Games, Inc. All Rights Reserved.

#include "Unicorn/UnicornDriver.h"

void AUnicornDriver::HandleDemoPlaybackFinish(UWorld* InWorld)
{
}

void AUnicornDriver::HandleDemoRecordingFinish(UWorld* InWorld)
{
}

void AUnicornDriver::RunHighlightExtractors()
{
}

void AUnicornDriver::UnicornClearDebugPlayer()
{
}

void AUnicornDriver::UnicornCreateAndPlayServerGameHighlights(int32 TargetSeconds, uint8 ReelId, uint8 MessageSetting, bool bExportSequenceFile)
{
}

void AUnicornDriver::UnicornDebugCurrentPlayerPlayerLog()
{
}

void AUnicornDriver::UnicornDebugCurrentPlayerSampler()
{
}

void AUnicornDriver::UnicornDebugCurrentReplayPlayer()
{
}

void AUnicornDriver::UnicornDebugHighlight(int32 HighlightId)
{
}

void AUnicornDriver::UnicornDebugHighlightTime(int32 HighlightId)
{
}

void AUnicornDriver::UnicornDebugPlayerWithIdString(const FString& PlayerIdString)
{
}

void AUnicornDriver::UnicornDebugUploadPayloadFile()
{
}

void AUnicornDriver::UnicornFakeAndUpload(int32 NumHighlights)
{
}

void AUnicornDriver::UnicornFakeAndUploadAndShutdown(int32 NumHighlights)
{
}

void AUnicornDriver::UnicornFollowPlayerWithHighlight(int32 HighlightId)
{
}

void AUnicornDriver::UnicornPlayHighlight(int32 HighlightId)
{
}

void AUnicornDriver::UnicornPlayLastEliminationHighlights(int32 NumHighlights, uint8 ReelId)
{
}

void AUnicornDriver::UnicornPlayOrderedHighlightsWithFeature(int32 FeatureAsInt, uint8 ReelId)
{
}

void AUnicornDriver::UnicornPlayOrderedHighlightsWithSocialFeature(int32 FeatureAsInt, uint8 ReelId)
{
}

void AUnicornDriver::UnicornPlayThroughPlayerHighlightReel(uint8 ReelId, uint8 MessageSettings, bool bExportSequenceFile)
{
}

void AUnicornDriver::UnicornPlayTopEliminationHighlights(int32 NumHighlights, uint8 ReelId)
{
}

void AUnicornDriver::UnicornPlayTopHighlights(int32 NumHighlights, uint8 ReelId, uint8 MessageSetting, bool bExportSequenceFile)
{
}

void AUnicornDriver::UnicornPlayUnionAllPlayersHighlights(uint8 ReelId, uint8 MessageSettings, bool bExportSequenceFile)
{
}

void AUnicornDriver::UnicornResetAll()
{
}

void AUnicornDriver::UnicornSetLoggingEnabled(bool bEnabled)
{
}

void AUnicornDriver::UnicornStartStreamPlayback()
{
}

void AUnicornDriver::UnicornStartStreamPlaybackToNow()
{
}

void AUnicornDriver::UnicornStartStreamRecording()
{
}

void AUnicornDriver::UnicornStopStreamRecording()
{
}
