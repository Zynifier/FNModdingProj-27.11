// Copyright Epic Games, Inc. All Rights Reserved.

#include "Item/FortItemQuantityListBase.h"

TArray<UFortItemDefinition*> UFortItemQuantityListBase::GetItemDefinitions()
{
	return TArray<UFortItemDefinition*>();
}

bool UFortItemQuantityListBase::IsEmptyList() const
{
	return false;
}

void UFortItemQuantityListBase::SetItemDefinitionsAndQuantities(const TArray<FFortItemQuantityPair>& ItemQuantityPairs, const bool ShouldResetWidgets)
{
}

void UFortItemQuantityListBase::SetItemInspectMode(EFortItemInspectionMode InspectMode)
{
}

void UFortItemQuantityListBase::SetItemInstancesAndQuantities(const TArray<FFortItemInstanceQuantityPair>& ItemQuantityPairs, const bool ShouldResetWidgets)
{
}

void UFortItemQuantityListBase::SetItemToCompareDefinitionsAndQuantities(const TArray<FFortItemQuantityPair>& ItemToCompareQuantityPairs)
{
}

void UFortItemQuantityListEntryBase::ClearPreviewData()
{
}

UFortItemDefinition* UFortItemQuantityListEntryBase::GetItemDefinition() const
{
	return nullptr;
}

UFortItem* UFortItemQuantityListEntryBase::GetItemInstance() const
{
	return nullptr;
}

void UFortItemQuantityListEntryBase::GetPreviewData(FFortItemEntryPreviewData& OutPreviewData) const
{
}

bool UFortItemQuantityListEntryBase::IsBeingPreviewed() const
{
	return false;
}

void UFortItemQuantityListEntryBase::SetItemDefinitionAndQuantity(const FFortItemQuantityPair& ItemQuantityPair, const bool ShouldTreatAsReset)
{
}

void UFortItemQuantityListEntryBase::SetItemInstanceAndQuantity(const FFortItemInstanceQuantityPair& ItemQuantityPair, const bool ShouldTreatAsReset)
{
}

void UFortItemQuantityListEntryBase::SetPreviewData(const FFortItemEntryPreviewData& PreviewData)
{
}
