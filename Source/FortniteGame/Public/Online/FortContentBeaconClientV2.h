// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Online/ContentBeaconClientV2.h"
#include "FortContentBeaconClientV2.generated.h"

UCLASS(MinimalAPI)
class AFortContentBeaconClientV2 : public AContentBeaconClientV2
{
	GENERATED_BODY()

protected:
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetPlatform(const FString& PlatformName);

	UPROPERTY(Transient)
	bool IsPendingProjectIDSet;

	UPROPERTY(Transient)
	FString PendingProjectID;

private:
	UFUNCTION(Server, Reliable, WithValidation)
	void PartyLeaderConnected(const FString& ProjectID);

};

