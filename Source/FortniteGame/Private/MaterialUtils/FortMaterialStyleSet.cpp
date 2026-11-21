// Copyright Epic Games, Inc. All Rights Reserved.

#include "MaterialUtils/FortMaterialStyleSet.h"

bool UFortMaterialStyleLibrary::ApplyStyleToMaterial(const UFortMaterialStyleSet* StyleSet, AActor* TargetActor, UMaterialInstanceDynamic* MaterialInstanceDynamic, FName DesiredStyleName, FName OptionalFallbackStyleName)
{
	return false;
}

const UFortMaterialStyle* UFortMaterialStyleLibrary::ResolveStyleFromName(const UFortMaterialStyleSet* StyleSet, const AActor* TargetActor, FName DesiredStyleName, FName OptionalFallbackStyleName)
{
	return nullptr;
}
