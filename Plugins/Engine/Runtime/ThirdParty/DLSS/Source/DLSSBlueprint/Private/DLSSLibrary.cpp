// Copyright Epic Games, Inc. All Rights Reserved.

#include "DLSSLibrary.h"

void UDLSSLibrary::EnableDLAA(bool bEnabled)
{
}

void UDLSSLibrary::EnableDLSS(bool bEnabled)
{
}

UDLSSMode UDLSSLibrary::GetDefaultDLSSMode()
{
	return UDLSSMode();
}

void UDLSSLibrary::GetDLSSMinimumDriverVersion(int32& MinDriverVersionMajor, int32& MinDriverVersionMinor)
{
}

UDLSSMode UDLSSLibrary::GetDLSSMode()
{
	return UDLSSMode();
}

void UDLSSLibrary::GetDLSSModeInformation(UDLSSMode DLSSMode, FVector2D ScreenResolution, bool& bIsSupported, float& OptimalScreenPercentage, bool& bIsFixedScreenPercentage, float& MinScreenPercentage, float& MaxScreenPercentage, float& OptimalSharpness)
{
}

void UDLSSLibrary::GetDLSSScreenPercentageRange(float& MinScreenPercentage, float& MaxScreenPercentage)
{
}

float UDLSSLibrary::GetDLSSSharpness()
{
	return float();
}

TArray<UDLSSMode> UDLSSLibrary::GetSupportedDLSSModes()
{
	return TArray<UDLSSMode>();
}

bool UDLSSLibrary::IsDLAAEnabled()
{
	return false;
}

bool UDLSSLibrary::IsDLSSEnabled()
{
	return false;
}

bool UDLSSLibrary::IsDLSSModeSupported(UDLSSMode DLSSMode)
{
	return false;
}

bool UDLSSLibrary::IsDLSSSupported()
{
	return false;
}

UDLSSSupport UDLSSLibrary::QueryDLSSSupport()
{
	return UDLSSSupport();
}

void UDLSSLibrary::SetDLSSMode(UObject* WorldContextObject, UDLSSMode DLSSMode)
{
}

void UDLSSLibrary::SetDLSSSharpness(float Sharpness)
{
}
