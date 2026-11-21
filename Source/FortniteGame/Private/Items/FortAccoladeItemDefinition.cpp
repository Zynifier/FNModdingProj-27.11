// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortAccoladeItemDefinition.h"

float UFortAccoladeItemDefinition::GetAccoladeLevel() const
{
	return float();
}

EFortAccoladeSubtype UFortAccoladeItemDefinition::GetAccoladeSubtype() const
{
	return EFortAccoladeSubtype();
}

EFortAccoladeType UFortAccoladeItemDefinition::GetAccoladeType() const
{
	return EFortAccoladeType();
}

int32 UFortAccoladeItemDefinition::GetAccoladeXpValue() const
{
	return int32();
}

int32 UFortAccoladeItemDefinition::GetAccoladeXpValueWithCountScalar(const int32 Count) const
{
	return int32();
}

USoundCue* UFortAccoladeItemDefinition::GetAwardedSound() const
{
	return nullptr;
}

TSoftObjectPtr<UTexture2D> UFortAccoladeItemDefinition::GetPreviousAccoladeLargePreviewImage() const
{
	return TSoftObjectPtr<UTexture2D>();
}

TSoftObjectPtr<UTexture2D> UFortAccoladeItemDefinition::GetPreviousAccoladeSmallPreviewImage() const
{
	return TSoftObjectPtr<UTexture2D>();
}

EXPEventPriorityType UFortAccoladeItemDefinition::GetPriority() const
{
	return EXPEventPriorityType();
}
