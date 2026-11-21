// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeClassOption.h"

uint8 UCreativeClassOptionBlueprintLibrary::ConvertToClassSlotIndex(const FCreativeClassOption& ClassOption)
{
	return uint8();
}

int32 UCreativeClassOptionBlueprintLibrary::GetLegacyClassIndex(const FCreativeClassOption& ClassOption)
{
	return int32();
}

bool UCreativeClassOptionBlueprintLibrary::IsClassType(const FCreativeClassOption& ClassOption, const ECreativeClassType ClassType)
{
	return false;
}

FCreativeClassOption UCreativeClassOptionBlueprintLibrary::MakeFromLegacyClassIndex(const int32 LegacyClassIndex)
{
	return FCreativeClassOption();
}

void UCreativeClassOptionBlueprintLibrary::SetLegacyClassIndex(FCreativeClassOption& ClassOption, const int32 LegacyClassIndex)
{
}
