// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AthenaAIService.generated.h"

class AFortGameModeAthena;
class AFortGameStateAthena;
class UAthenaAIServiceManager;

UCLASS(Abstract, MinimalAPI)
class UAthenaAIService : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<AFortGameModeAthena> CachedGameMode;

	UPROPERTY(Transient)
	TObjectPtr<AFortGameStateAthena> CachedGameState;

private:
	UPROPERTY(Transient)
	TObjectPtr<UAthenaAIServiceManager> AIServiceManager;

};

