// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortSafeZoneBlueprintLibrary.h"

TScriptInterface<IFortSafeZoneInterface> UFortSafeZoneBlueprintLibrary::GetGlobalSafeZoneInterface(UObject* WorldContextObject)
{
	return TScriptInterface<IFortSafeZoneInterface>();
}

TScriptInterface<IFortSafeZoneInterface> UFortSafeZoneBlueprintLibrary::GetRelevantSafeZoneInterface(APlayerState* PlayerContext)
{
	return TScriptInterface<IFortSafeZoneInterface>();
}

FVector UFortSafeZoneBlueprintLibrary::GetSafeZoneNextCenter(const TScriptInterface<IFortSafeZoneInterface>& InSafeZoneInterface)
{
	return FVector();
}

FVector UFortSafeZoneBlueprintLibrary::GetSafeZoneNextNextCenter(const TScriptInterface<IFortSafeZoneInterface>& InSafeZoneInterface)
{
	return FVector();
}
