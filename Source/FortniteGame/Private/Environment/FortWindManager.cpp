// Copyright Epic Games, Inc. All Rights Reserved.

#include "Environment/FortWindManager.h"

FFortWindImpulseHandle AFortWindManager::AddWindImpulse(const FFortWindImpulseRadius& WindImpulse)
{
	return FFortWindImpulseHandle();
}

FFortWindImpulseHandle AFortWindManager::AddWindImpulseCylinder(const FFortWindImpulseCylinder& WindImpulseCylinder, float BlendTime)
{
	return FFortWindImpulseHandle();
}

void AFortWindManager::BreakWindImpulseCylinder(const FFortWindImpulseCylinder& InWindImpulseCylinder, FVector& ImpulseLocation, float& ImpulseInnerRadius, float& ImpulseOuterRadius, float& ImpulseMagnitude, FVector& ImpulseDirection)
{
}

void AFortWindManager::BreakWindImpulseCylinderAdvanced(const FFortWindImpulseCylinder& WindImpulseCylinder, FVector& WindLocation, float& WindInnerRadius, float& WindOuterRadius, FVector& WindWorldDirection, float& WindMagnitude, FBox& WindWorldBounds, bool& bIsWindChanging, bool& bIsWindChangePending)
{
}

void AFortWindManager::BreakWindImpulseCylinderDelta(const FFortWindImpulseCylinderDelta& WindImpulseCylinderDelta, FVector& WindDeltaCenter, bool& bWindImpulseInitialized, bool& bWindRipplesOutward, float& WindDeltaSectionWidth, float& WindDeltaInnerSectionRadius, float& WindDeltaOuterSectionRadius, float& WindDeltaMaximumRadius, float& WindDeltaDesiredOverallBlendTime, float& WindDeltaSectionBlendTime, float& WindDeltaSectionCurrentBlendTime, float& WindDeltaPreviousMagnitude, float& WindDeltaSectionCurrentMagnitude, float& WindDeltaDesiredMagnitude, FBox& WindDeltaOuterWorldBounds, FBox& WindDeltaInnerWorldBounds, FBox& WindImpulseBounds, FFortWindImpulseHandle& WindImpulseHandleToModify)
{
}

void AFortWindManager::BreakWindImpulseRadius(const FFortWindImpulseRadius& InWindImpulseRadius, FVector& ImpulseLocation, float& ImpulseRadius, float& ImpulseMagnitude, float& ImpulseBlendTime)
{
}

bool AFortWindManager::GetCurrentWindImpulseCylinderDelta(FFortWindImpulseCylinder& WindImpulseCylinder, FFortWindImpulseCylinderDelta& WindImpulseCylinderDelta) const
{
	return false;
}

void AFortWindManager::GetGlobalWindIntensityAndDirection(float& WindIntensity, FVector& WindDirection) const
{
}

AFortWindManager* AFortWindManager::GetWindManager(const UObject* WorldContextObject)
{
	return nullptr;
}

bool AFortWindManager::HasWindImpulse(const FFortWindImpulseHandle& WindImpulseHandle) const
{
	return false;
}

FFortWindImpulseCylinder AFortWindManager::MakeWindImpulseCylinder(const FVector& ImpulseLocation, float ImpulseInnerRadius, float ImpulseOuterRadius, float ImpulseMagnitude, const FVector& ImpulseDirection)
{
	return FFortWindImpulseCylinder();
}

FFortWindImpulseRadius AFortWindManager::MakeWindImpulseRadius(const FVector& ImpulseLocation, float ImpulseRadius, float ImpulseMagnitude, float ImpulseBlendTime)
{
	return FFortWindImpulseRadius();
}

void AFortWindManager::RemoveWindImpulse(const FFortWindImpulseHandle& ImpulseHandle, float BlendTime)
{
}

bool AFortWindManager::SetWindImpulse(const FFortWindImpulseHandle& ImpulseHandle, const FFortWindImpulseRadius& WindImpulse)
{
	return false;
}

bool AFortWindManager::SetWindImpulseCylinderMagnitude(const FFortWindImpulseHandle& ImpulseHandle, float NewMagnitude, float BlendTime)
{
	return false;
}
