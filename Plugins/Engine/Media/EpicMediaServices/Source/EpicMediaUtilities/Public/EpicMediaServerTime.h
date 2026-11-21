// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Misc/DateTime.h"
#include "EpicMediaServerTime.generated.h"

UCLASS(BlueprintType, meta=(BlueprintSpawnableActor))
class EPICMEDIAUTILITIES_API AEpicMediaServerTime : public AActor
{
	GENERATED_BODY()

public:
	/**
     * Reports the current server time to clients in response to ServerRequestServerTime
     *
     * @param requestUtcTime Original request time
     * @param serverUtcTime Time from server
     */
	UFUNCTION(Client, Reliable)
	void ClientReportServerTime(double requestUtcTime, double serverUtcTime);

	/**
	 * Gets the UTC time estimate according to the server
	 *
	 * If return value is false, time is not available. @see ServerRequestServerTime
	 * 
	 * @param OutDateTime updated with the UTC time when available
	 * @returns false when time is not available.
	 */
	UFUNCTION(BlueprintPure, Category="MediaTime")
	bool GetTimeUtc(UPARAM(ref) FDateTime& OutDateTime) const;

	/**
	 * Requests current server time so accurate lag compensation can be performed in ClientReportServerTime
	 * based on the round-trip duration
	 *
	 * @param requestUtcTime Request time
	 */
	UFUNCTION(Server, Reliable, BlueprintCallable, Category="MediaTime")
	void ServerRequestServerTime(double requestUtcTime);

};

