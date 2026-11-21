// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VoiceReportingFeature.generated.h"

UENUM(BlueprintType)
enum class EVoiceRepUploadRecordResult : uint8
{
	Success = 0,
	// User cancelled the report

	Cancelled = 1,
	// There's no audio record

	NoAudioToUpload = 2,
	// Failed to communicate with the Emerald sercice

	EmeraldError = 3,
	// Generic error

	FailedUpload = 4,
};

