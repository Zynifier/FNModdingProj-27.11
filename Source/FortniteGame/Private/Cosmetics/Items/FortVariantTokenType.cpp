// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cosmetics/Items/FortVariantTokenType.h"

UFortItemDefinition* UFortVariantTokenType::GetCosmeticItem() const
{
	return nullptr;
}

FGameplayTag UFortVariantTokenType::GetVariantChannelTag() const
{
	return FGameplayTag();
}

FGameplayTag UFortVariantTokenType::GetVariantNameTag() const
{
	return FGameplayTag();
}
