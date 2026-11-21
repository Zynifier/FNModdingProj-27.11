// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortEmporiumUtilities.h"

const FText& UFortEmporiumUtilities::GetCategoryDisplayName(const FName& CategoryID)
{
	static FText Dummy;
	return Dummy;
}

const FText& UFortEmporiumUtilities::GetTextFromEmporiumLicense(const EFortEmporiumItemLicense License)
{
	static FText Dummy;
	return Dummy;
}

void UFortEmporiumUtilities::RequestJSON(const UObject* WorldContextObject, const FUniqueNetIdRepl& UniqueNetId, const FString& JSONURL, const FOnEmporiumJSONReceived& Callback)
{
}

void UFortEmporiumUtilities::RequestLicenseText(const EFortEmporiumItemLicense License, const FOnEmporiumLicenseTextReceived& Callback)
{
}
