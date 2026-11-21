// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortPlaylistUserOptions.h"

FString UPlaylistUserOptionBase::GetOptionKey(bool bWithScoping, const UPlaylistUserOptionsFilter* Filter) const
{
	return FString();
}

FString UPlaylistUserOptionBase::GetOptionValueNameFromValue(const FString& OptionValue, bool bAllowNoOverride, const UPlaylistUserOptionsFilter* Filter) const
{
	return FString();
}

FString UPlaylistUserDualDataOptionBase::GetSecondaryOptionKey(bool bWithScoping, const UPlaylistUserOptionsFilter* Filter) const
{
	return FString();
}

float UPlaylistUserOptionFloatRange::GetSliderMax() const
{
	return float();
}

float UPlaylistUserOptionFloatRange::GetSliderMin() const
{
	return float();
}

int32 UPlaylistUserOptionIntRange::GetSliderMax() const
{
	return int32();
}

int32 UPlaylistUserOptionIntRange::GetSliderMin() const
{
	return int32();
}

bool UPlaylistUserOptionsFilter::IsValueFiltered_Implementation(const FString& Value) const
{
	return false;
}
