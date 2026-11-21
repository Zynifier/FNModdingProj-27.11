// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/CreativeEditOnlyMeshComponent.h"

const TSoftObjectPtr<UStaticMesh>& UCreativeEditOnlyMeshComponent::GetEditMesh() const
{
	static TSoftObjectPtr<UStaticMesh> Dummy;
	return Dummy;
}

const TArray<TSoftObjectPtr<UMaterialInterface>>& UCreativeEditOnlyMeshComponent::GetEditOverrideMaterials() const
{
	static TArray<TSoftObjectPtr<UMaterialInterface>> Dummy;
	return Dummy;
}

const TArray<TSoftObjectPtr<UMaterialInterface>>& UCreativeEditOnlyMeshComponent::GetPreviewOverrideMaterials() const
{
	static TArray<TSoftObjectPtr<UMaterialInterface>> Dummy;
	return Dummy;
}

const TSoftObjectPtr<UStaticMesh>& UCreativeEditOnlyMeshComponent::GetPreviewOverrideMesh() const
{
	static TSoftObjectPtr<UStaticMesh> Dummy;
	return Dummy;
}

bool UCreativeEditOnlyMeshComponent::IsEditorPreview() const
{
	return false;
}

bool UCreativeEditOnlyMeshComponent::IsLoadingAssets() const
{
	return false;
}

void UCreativeEditOnlyMeshComponent::OnMinigamePlayModeChanged(AFortMinigame* Minigame, bool bIsInPlayMode)
{
}

void UCreativeEditOnlyMeshComponent::ReloadMeshAndMaterials()
{
}

void UCreativeEditOnlyMeshComponent::SetAndApplyCachedMeshAndMaterials(UStaticMesh* InCachedMesh, TArray<UMaterialInterface*> InCachedMaterials)
{
}

void UCreativeEditOnlyMeshComponent::SetEditMeshAndMaterials(const TSoftObjectPtr<UStaticMesh>& InEditMesh, const TArray<TSoftObjectPtr<UMaterialInterface>>& InEditMaterials, bool bClobberBuiltInRefs)
{
}

void UCreativeEditOnlyMeshComponent::SetPreviewMeshAndMaterials(const TSoftObjectPtr<UStaticMesh>& InPreviewMesh, const TArray<TSoftObjectPtr<UMaterialInterface>>& InPreviewMaterials, bool bClobberBuiltInRefs)
{
}

bool UCreativeEditOnlyMeshComponent::ShouldShowInPreview() const
{
	return false;
}
