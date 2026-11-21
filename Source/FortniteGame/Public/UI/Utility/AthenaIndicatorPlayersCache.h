// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Athena/FortGameStateAthena.h"
#include "AthenaIndicatorPlayersCache.generated.h"

class AFortPlayerStateAthena;
class AFortVolume;
class APlayerState;

USTRUCT()
struct FPlayerWithIndicatorState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AFortPlayerStateAthena> PlayerState;

	UPROPERTY()
	EPlayerIndicatorFlags IndicatorState;

};

UCLASS(MinimalAPI)
class UAthenaIndicatorPlayersCache : public UObject
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandlePlayerEnterVolume(APlayerState* Client, AFortVolume* Volume);

	UFUNCTION()
	void HandleRefreshIndicatorPlayersCache();

};

