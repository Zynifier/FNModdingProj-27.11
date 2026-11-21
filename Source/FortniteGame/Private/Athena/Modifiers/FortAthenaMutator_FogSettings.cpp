// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_FogSettings.h"

FLinearColor AFortAthenaMutator_FogSettings::GetFogColorOverride() const
{
	return FLinearColor();
}

EAthenaFogDensityOverride AFortAthenaMutator_FogSettings::GetFogDensityOverride() const
{
	return EAthenaFogDensityOverride();
}

float AFortAthenaMutator_FogSettings::GetFogDensityValue(const EAthenaFogDensityOverride FogDensityOverride)
{
	return float();
}

void AFortAthenaMutator_FogSettings::SetFogColorIndexOverride(FLinearColor NewValue)
{
}

void AFortAthenaMutator_FogSettings::SetFogDensityOverride(EAthenaFogDensityOverride NewValue)
{
}

void AFortAthenaMutator_FogSettings::UnsetFogOverrides()
{
}
