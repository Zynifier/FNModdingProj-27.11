// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Styling/SlateBrush.h"
#include "Aircraft/FortAircraft.h"
#include "Athena/AircraftFlightInfo.h"
#include "FortAthenaAircraft.generated.h"

class ABattleBusCosmeticInstanceBase;
class AFortAthenaAircraft;
class UAthenaBattleBusItemDefinition;
class UFortMiniMapIndicator;
class UWorld;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class AFortAthenaAircraft : public AFortAircraft
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortAthenaAircraftDelegate, AFortAthenaAircraft*, FortAthenaAircraft);

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Aircraft")
	void EjectPlayersInAircraft();

	UFUNCTION(BlueprintPure, Category="Aircraft")
	float GetDropEndTime() const;

	UFUNCTION(BlueprintPure, Category="Aircraft")
	float GetDropStartTime() const;

	UFUNCTION(BlueprintCallable, Category="Aircraft")
	static AFortAthenaAircraft* SpawnAircraft(UWorld* World, TSubclassOf<AFortAthenaAircraft> AircraftClass, const FAircraftFlightInfo& InFlightInfo);

	UFUNCTION(BlueprintCallable, Category="Aircraft")
	void StartFlightPath(float StartTime);

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FLinearColor MinimapIconColorTeammate;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FLinearColor MinimapIconColorEnemy;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, Category="FortAthenaAircraft")
	FFortAthenaAircraftDelegate OnDropZoneExited;

protected:
	UFUNCTION()
	void OnRep_ReplicatedFlightTimestamp();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aircraft", meta=(ClampMax="100", ClampMin="1", UIMax="100", UIMin="1"))
	int32 NumSpawnSlots;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Aircraft")
	float SpawnOffsetRadius;

	UPROPERTY(Replicated)
	FAircraftFlightInfo FlightInfo;

	UPROPERTY(Replicated)
	float FlightStartTime;

	UPROPERTY(Replicated)
	float FlightEndTime;

	UPROPERTY(Replicated)
	float DropStartTime;

	UPROPERTY(Replicated)
	float DropEndTime;

	UPROPERTY()
	bool bWasSpawnedForAircraftPhase;

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedFlightTimestamp)
	float ReplicatedFlightTimestamp;

	UPROPERTY(Transient)
	float FlightElapsedTime;

	UPROPERTY(Transient)
	float ClientFlightTimerDrift;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MiniMap")
	float MiniMapIconScale;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FSlateBrush MiniMapIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MiniMap")
	float MiniMapTeamIndicatorIconScale;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	FSlateBrush MiniMapTeamIndicatorIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAircraft")
	TObjectPtr<UAthenaBattleBusItemDefinition> DefaultBusSkin;

	UPROPERTY(BlueprintReadOnly, Category="FortAthenaAircraft")
	TObjectPtr<ABattleBusCosmeticInstanceBase> SpawnedCosmeticActor;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaBattleBusItemDefinition> AsyncLoadingSkin;

	UPROPERTY(Replicated)
	int32 AircraftIndex;

	UPROPERTY(Transient)
	TObjectPtr<UFortMiniMapIndicator> Indicator;

	UPROPERTY(Transient)
	TObjectPtr<UFortMiniMapIndicator> TeamIndicator;

};

