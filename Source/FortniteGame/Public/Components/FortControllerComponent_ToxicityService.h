// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_ToxicityService.generated.h"

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_ToxicityService : public UFortControllerComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION(Client, Reliable)
	void ClientReturnSanitizedString(bool bSuccess, const FString& SanitizedString, int32 RequestID);

	UFUNCTION(Client, Reliable)
	void ClientReturnSanitizedStrings(bool bSuccess, const TArray<FString>& SanitizedStrings, int32 RequestID);

	UFUNCTION(Server, Reliable)
	void ServerSanitizeString(const FString& StringToSanitize, int32 RequestID);

	UFUNCTION(Server, Reliable)
	void ServerSanitizeStrings(const TArray<FString>& StringsToSanitize, int32 RequestID);

};

