// Copyright Epic Games, Inc. All Rights Reserved.

#include "AssetDataUtilityTool/FortAssetDataUtilityTool.h"

bool UFortAssetDataUtilityTool::RunActionsOnAssets(const TArray<FAssetData>& AssetsToRunActions) const
{
	return false;
}

TArray<FAssetData> UFortAssetDataUtilityTool::RunFiltersAndPostFilterModifiers(const TArray<FAssetData>& AssetsToFilter) const
{
	return TArray<FAssetData>();
}

TArray<FAssetData> UFortAssetDataUtilityTool::RunFiltersOnAssets(const TArray<FAssetData>& AssetsToFilter) const
{
	return TArray<FAssetData>();
}

TArray<FAssetData> UFortAssetDataUtilityTool::RunGatherers() const
{
	return TArray<FAssetData>();
}

TArray<FAssetData> UFortAssetDataUtilityTool::RunGatherersAndPostGatherModifiers() const
{
	return TArray<FAssetData>();
}

void UFortAssetDataUtilityTool::RunPostFilterModifiers(TArray<FAssetData>& InOutArrayToModify) const
{
}

void UFortAssetDataUtilityTool::RunPostGatherModifiers(TArray<FAssetData>& InOutArrayToModify) const
{
}

void UFortAssetDataUtilityTool::RunTool() const
{
}

bool UFortAssetDataUtilityToolAction::RunActionOnAssetDataArray_Implementation(const TArray<FAssetData>& AssetDataArray) const
{
	return false;
}

void UFortAssetDataUtilityToolArrayModifier::RunArrayModifier_Implementation(TArray<FAssetData>& InOutAssetDataArray) const
{
}

void UFortAssetDataUtilityToolEditorWidget::MakeTempToolAssetDataToModify()
{
}

void UFortAssetDataUtilityToolEditorWidget::RunActionsOnAssets(const TArray<FAssetData>& AssetsToRunActions) const
{
}

TArray<FAssetData> UFortAssetDataUtilityToolEditorWidget::RunFiltersOnAssets(const TArray<FAssetData>& AssetsToFilter) const
{
	return TArray<FAssetData>();
}

bool UFortAssetDataUtilityToolFilter::AssetDataPassesFilter_Implementation(const FAssetData& AssetData) const
{
	return false;
}

void UFortAssetDataUtilityToolFilter::CleanupFilterData_Implementation()
{
}

void UFortAssetDataUtilityToolFilter::InitializeFilterData_Implementation()
{
}

TArray<FAssetData> UFortAssetDataUtilityToolGatherer::RunGatherer_Implementation() const
{
	return TArray<FAssetData>();
}
