// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Pawns/FortPawnStats.h"
#include "FortAIPawnStats.generated.h"

class UCurveTable;

USTRUCT()
struct FFortAIPawnStats : public FFortPawnStats
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	int32 ScoreValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	bool bDormantSightEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	float DormantSightRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	float DormantHearingThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	bool bDormantCanHearHostile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	bool bDormantCanHearNeutral;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	bool bDormantCanHearFriendly;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	float DormantPeripheralVisionAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	bool bAlertSightEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	float AlertSightRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	float AlertHearingThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	bool bAlertCanHearHostile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	bool bAlertCanHearNeutral;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	bool bAlertCanHearFriendly;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	float AlertPeripheralVisionAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	float AutoSuccessRangeFromLastSeenLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	float MaxConvertResistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	TObjectPtr<UCurveTable> HealthScalingTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	FName HealthScalingTableRow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	TObjectPtr<UCurveTable> ControlResistanceScalingTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	FName ControlResistanceScalingTableRow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	TObjectPtr<UCurveTable> DifficultyRatingTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	FName DifficultyRatingTableRow;

};

