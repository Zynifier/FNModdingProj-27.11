// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ProfileStats/AthenaProfileStatWidgetBase.h"

TArray<FStatGroupData> UAthenaProfileStatWidgetBase::CreateWeaponGroupData(int32 MaxToReturn, bool bIncludeOtherCategory, bool bPercentages)
{
	return TArray<FStatGroupData>();
}

void UAthenaProfileStatWidgetBase::HandleStatViewChanged(UAthenaBaseStatView* StatView)
{
}

void UAthenaProfileStatWidgetBase::SetAsStat(const FGameplayTag& InStat)
{
}

void UAthenaProfileStatWidgetBase::SetStatView(UAthenaBaseStatView* InStatView, bool RespectParentStatView)
{
}
