// Copyright Epic Games, Inc. All Rights Reserved.

#include "Item/Perks/FortAlterationOptionsBase.h"

bool UFortAlterationOptionsBase::DoAlterationOptionsExist(EFortAlterationOptionType OptionType) const
{
	return false;
}

void UFortAlterationOptionsBase::HandleAlterationsOptionHovered(UCommonButtonLegacy* AlterationOptionButton, int32 GroupIndex)
{
}

void UFortAlterationOptionsBase::HandleAlterationsOptionSelected(UCommonButtonLegacy* AlterationOptionButton, int32 GroupIndex)
{
}

bool UFortAlterationOptionsBase::IsValidAlterationSlot() const
{
	return false;
}

void UFortAlterationOptionsBase::ProcessAlterationOptions(bool bIntroAlterations)
{
}
