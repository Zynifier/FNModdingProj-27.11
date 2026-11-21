// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortUserOptionValues.h"

TScriptInterface<IUserOptionDefinitionContainerInterface> IUserOptionValuesInterface::BP_GetUserOptionDefinitions() const
{
	return TScriptInterface<IUserOptionDefinitionContainerInterface>();
}

bool IUserOptionValuesInterface::GetUserOptionValue(const FString& UserOptionKey, FString& UserOptionValue) const
{
	return false;
}

bool IUserOptionValuesInterface::GetUserOptionValues(TMap<FString, FString>& UserOptionValues) const
{
	return false;
}

bool IUserOptionValuesInterface::SetUserOptionValue(APlayerController* PlayerController, const FString& UserOptionKey, const FString& UserOptionValue)
{
	return false;
}

bool IUserOptionValuesInterface::SetUserOptionValues(APlayerController* PlayerController, const TMap<FString, FString>& UserOptionValues)
{
	return false;
}
