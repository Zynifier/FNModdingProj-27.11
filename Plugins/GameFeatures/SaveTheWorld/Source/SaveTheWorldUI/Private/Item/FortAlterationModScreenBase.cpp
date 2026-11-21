// Copyright Epic Games, Inc. All Rights Reserved.

#include "Item/FortAlterationModScreenBase.h"

bool UFortAlterationModScreenBase::AreIngredientRequirementsMent(const TArray<FFortItemQuantityPair>& RequiredIngredients)
{
	return false;
}

void UFortAlterationModScreenBase::CancelSelection()
{
}

void UFortAlterationModScreenBase::ConfirmSelection()
{
}

void UFortAlterationModScreenBase::HandleBackAction(bool& bPassThrough)
{
}

void UFortAlterationModScreenBase::SetItemForAlterationsModding(UFortAlterableItem* InAlterableItem)
{
}
