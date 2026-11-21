// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortFootstepComponent.h"

EFortFootstepSurfaceType::Type UFortFootstepComponent::GetSurfaceType() const
{
	return EFortFootstepSurfaceType::Type();
}

void UFortFootstepComponent::HandleSurfaceTypeChanged(AActor* SurfaceActor, EPhysicalSurface CurrentSurfaceType, EPhysicalSurface PrevSurfaceType)
{
}

void UFortFootstepComponent::PlayFootstep(int32 FootDown)
{
}
