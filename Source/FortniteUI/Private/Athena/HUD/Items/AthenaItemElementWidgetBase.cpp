// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/HUD/Items/AthenaItemElementWidgetBase.h"

const UFortItem* UAthenaItemElementWidgetBase::GetItemToRepresent() const
{
	return nullptr;
}

void UAthenaItemElementWidgetBase::HandleItemChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged)
{
}

void UAthenaItemElementWidgetBase::SetItemToRepresent(const UFortItem* ItemToRepresent)
{
}
