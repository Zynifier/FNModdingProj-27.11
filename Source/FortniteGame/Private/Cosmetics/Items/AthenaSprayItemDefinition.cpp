// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cosmetics/Items/AthenaSprayItemDefinition.h"

TSoftObjectPtr<UMaterialInterface> UAthenaSprayItemDefinition::GetDecalMaterial() const
{
	return TSoftObjectPtr<UMaterialInterface>();
}

TSoftObjectPtr<UTexture2D> UAthenaSprayItemDefinition::GetDecalTexture() const
{
	return TSoftObjectPtr<UTexture2D>();
}

bool UAthenaSprayItemDefinition::ShouldUseBannerAsTexture() const
{
	return false;
}
