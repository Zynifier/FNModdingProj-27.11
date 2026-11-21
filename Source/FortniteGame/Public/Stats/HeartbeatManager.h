// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HeartbeatManager.generated.h"

class UFortAnalyticsClientEngagementsManager;

UCLASS(Config=Game)
class UHeartbeatManager : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	bool bShouldTrackLocation;

	UPROPERTY(Config)
	float TrackLocationFrequencySec;

	UPROPERTY(Config)
	bool bShouldSendPerMinuteResourceAndDamageEvents;

	UPROPERTY(Config)
	bool bShouldSendPerMinuteVehicleEvents;

	UPROPERTY()
	TObjectPtr<UFortAnalyticsClientEngagementsManager> AnalyticsClientEngagementsManager;

};

