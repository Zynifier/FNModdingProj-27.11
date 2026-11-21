// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AthenaPlayerMatchReport.h"
#include "FortTravelLogMap.generated.h"

UCLASS(BlueprintType)
class UFortTravelLogMap : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortTravelLogMap(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void InitializeFromTravelRecord(const FAthenaTravelRecord& Record);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortTravelLogMap")
	float MapSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortTravelLogMap")
	float CurrentTimeFraction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortTravelLogMap")
	int32 DistanceToCoalescePositions;

};

