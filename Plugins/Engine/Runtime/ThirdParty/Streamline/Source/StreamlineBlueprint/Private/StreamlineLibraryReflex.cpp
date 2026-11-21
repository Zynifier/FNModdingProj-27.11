// Copyright Epic Games, Inc. All Rights Reserved.

#include "StreamlineLibraryReflex.h"

UStreamlineReflexMode UStreamlineLibraryReflex::GetDefaultReflexMode()
{
	return UStreamlineReflexMode();
}

float UStreamlineLibraryReflex::GetGameLatencyInMs()
{
	return float();
}

float UStreamlineLibraryReflex::GetGameToRenderLatencyInMs()
{
	return float();
}

UStreamlineReflexMode UStreamlineLibraryReflex::GetReflexMode()
{
	return UStreamlineReflexMode();
}

float UStreamlineLibraryReflex::GetRenderLatencyInMs()
{
	return float();
}

bool UStreamlineLibraryReflex::IsReflexSupported()
{
	return false;
}

UStreamlineFeatureSupport UStreamlineLibraryReflex::QueryReflexSupport()
{
	return UStreamlineFeatureSupport();
}

void UStreamlineLibraryReflex::SetReflexMode(const UStreamlineReflexMode Mode)
{
}
