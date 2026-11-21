// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortEmporiumFilterCategoryHeader.h"

UFortEmporiumFilterCategoryHeader::UFortEmporiumFilterCategoryHeader(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortEmporiumFilterCategoryHeader::ActivateCategory(bool bExpanded)
{
}

TArray<UWidget*> UFortEmporiumFilterCategoryHeader::GetSubcategoryWidgets_Implementation() const
{
	return TArray<UWidget*>();
}
