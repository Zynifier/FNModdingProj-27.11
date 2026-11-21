// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortEditorUtilityLibrary.h"

void UFortEditorUtilityLibrary::ExitEditor()
{
}

UObject* UFortEditorUtilityLibrary::FindServerPlayWorld()
{
	return nullptr;
}

void UFortEditorUtilityLibrary::GetAvailableMaterialParameters(const UMaterial* Material, UMaterialInstance* MaterialInstance, TArray<FMaterialParameterInfo>& VisibleExpressions)
{
}

bool UFortEditorUtilityLibrary::IsMaterialParameterAvailable(UMaterialInstance* MaterialInstance, FName ParameterName)
{
	return false;
}

bool UFortEditorUtilityLibrary::SaveAssetsWhilePlaying(const TArray<UObject*>& AssetsToSave, bool bOnlyIfIsDirty)
{
	return false;
}
