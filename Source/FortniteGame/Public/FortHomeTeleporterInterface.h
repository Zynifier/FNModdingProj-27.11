// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHomeTeleporterInterface.generated.h"

class AActor;
class AFortPlayerPawn;

UINTERFACE()
class UFortHomeTeleporterInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortHomeTeleporterInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="HomeTeleporter")
	void OnHomeTeleporterBound(AFortPlayerPawn* PlayerPawn, const AActor* OldHomeActor);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="HomeTeleporter")
	void OnHomeTeleporterBoundServer(AFortPlayerPawn* PlayerPawn, const AActor* OldHomeActor);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="HomeTeleporter")
	void OnHomeTeleporterUnbound(AFortPlayerPawn* PlayerPawn, const AActor* NewHomeActor);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="HomeTeleporter")
	void OnHomeTeleporterUnboundServer(AFortPlayerPawn* PlayerPawn, const AActor* NewHomeActor);

};

