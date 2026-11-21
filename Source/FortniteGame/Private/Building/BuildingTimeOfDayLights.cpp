// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingTimeOfDayLights.h"

void ABuildingTimeOfDayLights::AnimateLightParameters(const TArray<FTimeOfDayControlledLightData>& LightData, const FNativeDayPhaseFloats& LightIntensityByTimeOfDay, const float DayPhaseTransitionLength)
{
}

void ABuildingTimeOfDayLights::AnimateMidValuesForLightsFourLayer(const FNativeDayPhaseFloats& EmissiveIntensityByTimeOfDay, const float DayPhaseTransitionLength)
{
}

void ABuildingTimeOfDayLights::DoDayPhaseChangedLightAnimation(const bool bIsAtCreation, TArray<FLinearColor>& EmissiveMultipliers, TArray<float>& LightConeOpacities, const TArray<FTimeOfDayControlledLightData>& LightData, const FNativeDayPhaseFloats& LightIntensityByTimeOfDay, const float DayPhaseTransitionLength, const FNativeDayPhaseFloats& EmissiveIntensityByTimeOfDay)
{
}

float ABuildingTimeOfDayLights::FindScalarValueAcrossTimeOfDayPhaseFloats(const FNativeDayPhaseFloats& DayPhaseFloats, const float Alpha)
{
	return float();
}

void ABuildingTimeOfDayLights::GetTimeOfDayBlueprintDefaultVariables_Implementation(FTimeOfDayBlueprintDefaultVariables& OutVariables)
{
}

void ABuildingTimeOfDayLights::HandleBaseSimpleFourLayerMaterials(const float Duration, const float Start, const float End)
{
}

void ABuildingTimeOfDayLights::InitializeLightValuesAndStoreMaterials(TArray<FLinearColor>& EmissiveMultipliers, TArray<float>& LightConeOpacities, const TArray<FTimeOfDayControlledLightData>& LightData, const FNativeDayPhaseFloats& LightIntensityByTimeOfDay, const float DayPhaseTransitionLength, const FNativeDayPhaseFloats& EmissiveIntensityByTimeOfDay)
{
}

void ABuildingTimeOfDayLights::SetLightIntensityByDayPhase(ULightComponent* LightComponent, const FNativeDayPhaseFloats& LightIntensityByTimeOfDay)
{
}

void ABuildingTimeOfDayLights::SetMidValuesForLights(const FNativeDayPhaseFloats& EmissiveIntensityByTimeOfDay, const TArray<float>& LightConeOpacities, const float DayPhaseTransitionLength, const TArray<FLinearColor>& EmissiveMultipliers)
{
}

bool ABuildingTimeOfDayLights::UseNativeLightAnimation() const
{
	return false;
}
