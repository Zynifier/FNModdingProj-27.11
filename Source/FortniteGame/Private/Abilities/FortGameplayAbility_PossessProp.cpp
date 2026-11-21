// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/FortGameplayAbility_PossessProp.h"

TSubclassOf<ABuildingActor> UFortGameplayAbility_PossessProp::GetAllowedPropClassByIndex(int32 AllowedPropIndex) const
{
	return TSubclassOf<ABuildingActor>();
}

FPossessPropClasses UFortGameplayAbility_PossessProp::GetAllowedPropDataByIndex(int32 AllowedPropIndex) const
{
	return FPossessPropClasses();
}

float UFortGameplayAbility_PossessProp::GetPreviewScaleByIndex(int32 AllowedPropIndex) const
{
	return float();
}

void UFortGameplayAbility_PossessProp::SetAllowedPropTable(UDataTable* InAllowedPropTable)
{
}
