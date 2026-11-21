// Copyright Epic Games, Inc. All Rights Reserved.

#include "Store/FortLlamaStoreInspectionScreen.h"

EInputActionState UFortLlamaStoreInspectionScreen::GetInspectChoiceInputState() const
{
	return EInputActionState();
}

UFortCardPackItem* UFortLlamaStoreInspectionScreen::GetSelectedCardPack() const
{
	return nullptr;
}

bool UFortLlamaStoreInspectionScreen::IsItemChoicePack(UObject* ItemToCheck) const
{
	return false;
}
