// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortControllerComponent_ToxicityService.h"

void UFortControllerComponent_ToxicityService::ClientReturnSanitizedString_Implementation(bool bSuccess, const FString& SanitizedString, int32 RequestID)
{
}

void UFortControllerComponent_ToxicityService::ClientReturnSanitizedStrings_Implementation(bool bSuccess, const TArray<FString>& SanitizedStrings, int32 RequestID)
{
}

void UFortControllerComponent_ToxicityService::ServerSanitizeString_Implementation(const FString& StringToSanitize, int32 RequestID)
{
}

void UFortControllerComponent_ToxicityService::ServerSanitizeStrings_Implementation(const TArray<FString>& StringsToSanitize, int32 RequestID)
{
}
