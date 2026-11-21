// Copyright Epic Games, Inc. All Rights Reserved.

#include "DiscoveryShared/FortActivityBrowserTag.h"

UFortActivityBrowserTag::UFortActivityBrowserTag(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

EFortActivityBrowserTagType UFortActivityBrowserTag::GetTagType() const
{
	return EFortActivityBrowserTagType();
}

void UFortActivityBrowserTag::SetTextAndType(const FText& InText, EFortActivityBrowserTagType NewTagType)
{
}
