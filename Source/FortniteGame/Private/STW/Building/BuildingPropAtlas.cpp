// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Building/BuildingPropAtlas.h"

float ABuildingPropAtlas::GetDefenseAnimSpeed() const
{
	return float();
}

float ABuildingPropAtlas::GetDefenseProgress() const
{
	return float();
}

void ABuildingPropAtlas::InitializeAudio(UAudioComponent* InPortalLoopingComp)
{
}

void ABuildingPropAtlas::InitializeRings(UPrimitiveComponent* InRing1Comp, UPrimitiveComponent* InRing2Comp, UPrimitiveComponent* InRing3Comp)
{
}

void ABuildingPropAtlas::PlayRingDamage(float DurationMin, float DurationMax, float MagnitudeMin, float MagnitudeMax)
{
}

void ABuildingPropAtlas::PlayRingsIdleLoop(float AnimDuration, float Ring1ZOffset)
{
}

void ABuildingPropAtlas::PlayRingSpinning(const FRotator& Ring1RateMin, const FRotator& Ring1RateMax, const FRotator& Ring2Rate, const FRotator& Ring3Rate)
{
}

void ABuildingPropAtlas::PlayRingsReset(float AnimDuration)
{
}

void ABuildingPropAtlas::RestoreRingsHierarchy()
{
}

void ABuildingPropAtlas::SetupAnimationSpeed(float InActivationTime, float InTotalDefenseTime, float InAnimSpeedStart, float InAnimSpeedEnd)
{
}

void ABuildingPropAtlas::SetupAnimationTransition(UMaterialInstanceDynamic* MID, FName ParamName, float InTransitionTime)
{
}

void ABuildingPropAtlas::StopRingSpinning()
{
}
