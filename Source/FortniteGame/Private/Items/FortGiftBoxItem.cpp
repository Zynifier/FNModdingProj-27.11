// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortGiftBoxItem.h"

void UFortGiftBoxItem::FilterUserMessageForProfanity(int32 ControllerId, FOnTextFiltered OnTextFiltered)
{
}

FText UFortGiftBoxItem::FormatTextUsingParams(const FText& FormatString) const
{
	return FText();
}

UFortGiftBoxItemDefinition* UFortGiftBoxItem::GetGiftBoxDefinition() const
{
	return nullptr;
}

bool UFortGiftBoxItem::HasAccountID() const
{
	return false;
}

bool UFortGiftBoxItem::HasParam(const FString& ParamName) const
{
	return false;
}

bool UFortGiftBoxItem::IsVisibleIn(const ESubGame SubGame) const
{
	return false;
}

UFortItemDefinition* UFortGiftBoxItem::RetrieveItemDefinitionFromTemplateID(const FString& TemplateParam) const
{
	return nullptr;
}

UFortItemDefinition* UFortGiftBoxItem::RetrieveItemDefintionFromParam(const FString& ParamName) const
{
	return nullptr;
}

bool UFortGiftBoxItem::TryGetCurrencyData(TArray<FCurrencyData>& OutValue) const
{
	return false;
}

bool UFortGiftBoxItem::TryGetLootListParamInt(const UFortItemDefinition* Item, const FString& ParamName, int32& OutValue) const
{
	return false;
}

bool UFortGiftBoxItem::TryGetLootListParamString(const UFortItemDefinition* Item, const FString& ParamName, FString& OutValue) const
{
	return false;
}

bool UFortGiftBoxItem::TryGetLootListParamText(const UFortItemDefinition* Item, const FString& ParamName, FText& OutValue) const
{
	return false;
}

bool UFortGiftBoxItem::TryGetParamInt(const FString& ParamName, int32& OutValue) const
{
	return false;
}

bool UFortGiftBoxItem::TryGetParamString(const FString& ParamName, FString& OutValue) const
{
	return false;
}

bool UFortGiftBoxItem::TryGetParamText(const FString& ParamName, FText& OutValue) const
{
	return false;
}
