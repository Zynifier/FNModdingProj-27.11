// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ProfileStats/AthenaProfileStatBox.h"

UAthenaBaseStatView* UAthenaProfileStatBox::GetBaseStatView()
{
	return nullptr;
}

const FFortUIStatStyle& UAthenaProfileStatBox::GetStatStyle(const FGameplayTag& InStat) const
{
	static FFortUIStatStyle Dummy;
	return Dummy;
}

void UAthenaProfileStatBox::SetStatView(UAthenaBaseStatView* InStatView, bool RespectParentStatView)
{
}
