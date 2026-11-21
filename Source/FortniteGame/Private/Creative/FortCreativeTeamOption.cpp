// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeTeamOption.h"

EFortTeam::Type UCreativeTeamOptionBlueprintLibrary::ConvertToTeam(const FCreativeTeamOption& TeamOption)
{
	return EFortTeam::Type();
}

int32 UCreativeTeamOptionBlueprintLibrary::GetLegacyTeamIndex(const FCreativeTeamOption& TeamOption, const bool bShiftIndex)
{
	return int32();
}

bool UCreativeTeamOptionBlueprintLibrary::IsTeamType(const FCreativeTeamOption& TeamOption, const ECreativeTeamType TeamType)
{
	return false;
}

FCreativeTeamOption UCreativeTeamOptionBlueprintLibrary::MakeFromLegacyTeamIndex(const int32 LegacyTeamIndex)
{
	return FCreativeTeamOption();
}

void UCreativeTeamOptionBlueprintLibrary::SetLegacyTeamIndex(FCreativeTeamOption& TeamOption, const int32 LegacyTeamIndex)
{
}
