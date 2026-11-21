// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/ItemComponent_DisplayUI.h"

const FText& UItemComponent_DisplayUI::GetItemDescription() const
{
	static FText Dummy;
	return Dummy;
}

const TSoftObjectPtr<UTexture2D>& UItemComponent_DisplayUI::GetItemIcon() const
{
	static TSoftObjectPtr<UTexture2D> Dummy;
	return Dummy;
}

const TSoftObjectPtr<UMaterialInterface>& UItemComponent_DisplayUI::GetItemMaterial() const
{
	static TSoftObjectPtr<UMaterialInterface> Dummy;
	return Dummy;
}

const FText& UItemComponent_DisplayUI::GetItemName() const
{
	static FText Dummy;
	return Dummy;
}

const FName& UItemComponent_DisplayUI::GetMaterialTextureParameter() const
{
	static FName Dummy;
	return Dummy;
}

const TSoftObjectPtr<UTexture2D>& UItemComponent_DisplayUI::GetSmallItemIcon() const
{
	static TSoftObjectPtr<UTexture2D> Dummy;
	return Dummy;
}
