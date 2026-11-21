// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortUserOptionDefinitions.h"

void IUserOptionDefinitionContainerInterface::GetGrantedContextTagsFromObject(const UObject* Object, FGameplayTagContainer& ContextTags) const
{
}

TArray<FUserOptionDefinition> IUserOptionDefinitionContainerInterface::GetUserOptionDefinitions() const
{
	return TArray<FUserOptionDefinition>();
}

const UPlaylistUserOptions* IUserOptionDefinitionContainerInterface::GetUserOptionList(const bool bAllowGenerated) const
{
	return nullptr;
}

FText IUserOptionDefinitionContainerInterface::GetUserOptionsDescription() const
{
	return FText();
}

FText IUserOptionDefinitionContainerInterface::GetUserOptionsDisplayName() const
{
	return FText();
}

FCurveTableRowHandle IUserOptionDefinitionContainerInterface::GetUserOptionsInteractionSpeed() const
{
	return FCurveTableRowHandle();
}

FText IUserOptionDefinitionContainerInterface::GetUserOptionsInteractionText() const
{
	return FText();
}
