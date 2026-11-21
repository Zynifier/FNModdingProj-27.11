// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Items/FortCardPackItemDefinition.h"

int32 UFortCardPackItemDefinition::GetDisplayRarityLevel() const
{
	return int32();
}

FLinearColor UFortCardPackItemDefinition::GetPackColor() const
{
	return FLinearColor();
}

UTexture* UFortCardPackItemDefinition::GetPackImage() const
{
	return nullptr;
}

UFortPackPersonality* UFortCardPackItemDefinition::GetPackPersonality() const
{
	return nullptr;
}

TSoftObjectPtr<UTexture2D> UFortCardPackItemDefinition::GetXRayImage() const
{
	return TSoftObjectPtr<UTexture2D>();
}

bool UFortCardPackItemDefinition::IsChoicePack() const
{
	return false;
}

bool UFortCardPackItemDefinition::IsLlama() const
{
	return false;
}
