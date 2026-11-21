// Copyright Epic Games, Inc. All Rights Reserved.

#include "StreamlineLibraryDLSSG.h"

UStreamlineDLSSGMode UStreamlineLibraryDLSSG::GetDefaultDLSSGMode()
{
	return UStreamlineDLSSGMode();
}

void UStreamlineLibraryDLSSG::GetDLSSGFrameTiming(float& FrameRateInHertz, int32& FramesPresented)
{
}

UStreamlineDLSSGMode UStreamlineLibraryDLSSG::GetDLSSGMode()
{
	return UStreamlineDLSSGMode();
}

TArray<UStreamlineDLSSGMode> UStreamlineLibraryDLSSG::GetSupportedDLSSGModes()
{
	return TArray<UStreamlineDLSSGMode>();
}

bool UStreamlineLibraryDLSSG::IsDLSSGModeSupported(UStreamlineDLSSGMode DLSSGMode)
{
	return false;
}

bool UStreamlineLibraryDLSSG::IsDLSSGSupported()
{
	return false;
}

UStreamlineFeatureSupport UStreamlineLibraryDLSSG::QueryDLSSGSupport()
{
	return UStreamlineFeatureSupport();
}

void UStreamlineLibraryDLSSG::SetDLSSGMode(UStreamlineDLSSGMode DLSSGMode)
{
}
