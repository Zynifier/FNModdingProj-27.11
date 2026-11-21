// Copyright Epic Games, Inc. All Rights Reserved.

#include "Stats/FortAttributeListItem.h"

UFortAttributeListItem::UFortAttributeListItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortAttributeListItem::ClearPreview()
{
}

void UFortAttributeListItem::GetCurrentAttributeCopy(FFortDisplayAttribute& OutDisplayAttribute) const
{
}

void UFortAttributeListItem::GetDisplayAttributeCopy(FFortDisplayAttribute& OutDisplayAttribute) const
{
}

void UFortAttributeListItem::GetDisplayPreviewCopy(FFortDisplayAttribute& OutPreviewAttribute) const
{
}

bool UFortAttributeListItem::SetDisplayAttribute(const FFortDisplayAttribute& InDisplayAttribute, FFortDisplayAttribute& DeltaAttribute)
{
	return false;
}

void UFortAttributeListItem::SetPreviewAttribute(const FFortDisplayAttribute& InPreviewAttribute)
{
}
