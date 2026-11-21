// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortAthenaLivingWorldSpawnAction.h"
#include "FortAthenaLivingWorldSpawnAction_SeatPawnInVehicle.generated.h"

USTRUCT()
struct FFortAthenaLivingWorldTagQueryToSeatMapping
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldTagQueryToSeatMapping")
	FGameplayTagQuery TagQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldTagQueryToSeatMapping", meta=(ClampMin="0"))
	int32 SeatIndex;

};

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaLivingWorldSpawnAction_SeatPawnInVehicle : public UFortAthenaLivingWorldSpawnAction
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldSpawnAction_SeatPawnInVehicle")
	TArray<FFortAthenaLivingWorldTagQueryToSeatMapping> SeatMappings;

};

