// Copyright Epic Games, Inc. All Rights Reserved.

#include "StreamlineLibrary.h"

void UStreamlineLibrary::BreakStreamlineFeatureRequirements(UStreamlineFeatureRequirementsFlags Requirements, bool& D3D11Supported, bool& D3D12Supported, bool& VulkanSupported, bool& VSyncOffRequired, bool& HardwareSchedulingRequired)
{
}

FStreamlineFeatureRequirements UStreamlineLibrary::GetStreamlineFeatureInformation(UStreamlineFeature Feature)
{
	return FStreamlineFeatureRequirements();
}

bool UStreamlineLibrary::IsStreamlineFeatureSupported(UStreamlineFeature Feature)
{
	return false;
}

UStreamlineFeatureSupport UStreamlineLibrary::QueryStreamlineFeatureSupport(UStreamlineFeature Feature)
{
	return UStreamlineFeatureSupport();
}
