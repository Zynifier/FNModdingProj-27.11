// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Items/FortAlterationItemDefinition.h"

UNiagaraSystem* UFortAlterationFunctionLibrary::GetAlterationImpactNiagaraPhysicalSurfaceEffects(EPhysicalSurface HitSurface, const FFortCosmeticModification& CosmeticMod)
{
	return nullptr;
}

UParticleSystem* UFortAlterationFunctionLibrary::GetAlterationImpactPhysicalSurfaceEffects(EPhysicalSurface HitSurface, const FFortCosmeticModification& CosmeticMod)
{
	return nullptr;
}

EFortAlteration::Type UFortAlterationItemDefinition::GetAlterationType() const
{
	return EFortAlteration::Type();
}
