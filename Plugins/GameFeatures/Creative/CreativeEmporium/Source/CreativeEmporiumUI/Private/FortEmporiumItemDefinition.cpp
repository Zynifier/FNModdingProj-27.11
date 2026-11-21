// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortEmporiumItemDefinition.h"

const FFortEmporiumItemData& UFortEmporiumItemDefinition::GetEmporiumItemData() const
{
	static FFortEmporiumItemData Dummy;
	return Dummy;
}
