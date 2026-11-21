// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortContrailsComponent.h"

bool UFortContrailsComponent::AreContrailsLoaded() const
{
	return false;
}

UFXSystemComponent* UFortContrailsComponent::GetContrailFXComponent() const
{
	return nullptr;
}

TSoftObjectPtr<UFXSystemAsset> UFortContrailsComponent::GetContrailFXOverride()
{
	return TSoftObjectPtr<UFXSystemAsset>();
}

EFortContrailsState UFortContrailsComponent::GetContrailsState() const
{
	return EFortContrailsState();
}

void UFortContrailsComponent::HandleBeginParachuteMovement()
{
}

void UFortContrailsComponent::HandleBeginSkydiving()
{
}

void UFortContrailsComponent::HandleEndParachuteMovement()
{
}

void UFortContrailsComponent::HandleEndSkydiving()
{
}

void UFortContrailsComponent::HandleLanded(const FHitResult& Hit)
{
}

void UFortContrailsComponent::HandleParachuteSpawned()
{
}

bool UFortContrailsComponent::HasContrailFXOverrde()
{
	return false;
}

void UFortContrailsComponent::RefreshContrailVisibility()
{
}

void UFortContrailsComponent::SetContrailFXOverride(TSoftObjectPtr<UFXSystemAsset> InContrailFXOverride)
{
}
