// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "FortVehicleTrickSet.generated.h"

USTRUCT(BlueprintType)
struct FFortVehicleTrick
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Trick")
	FText Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Trick")
	int32 BaseScore;

};

USTRUCT(BlueprintType)
struct FFortVehicleGenericTrick : public FFortVehicleTrick
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Trick")
	int32 IncrementScore;

};

USTRUCT(BlueprintType)
struct FFortVehicleIncrementTrick : public FFortVehicleTrick
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Trick", meta=(MinValue="1"))
	int32 HalfSpinsNeeded;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Trick", meta=(MinValue="1"))
	int32 Repeats;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Trick", meta=(MinValue="1"))
	int32 RepeatsHalfSpinsPerTrick;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Trick")
	int32 MultiplierIncrement;

};

USTRUCT()
struct FVehicleTrickSequenceBasics : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Start")
	float TrickStartTime;

	UPROPERTY(EditAnywhere, Category="Start")
	float TrickStartDistance;

	UPROPERTY(EditAnywhere, Category="Start")
	float TrickStartHeight;

	UPROPERTY(EditAnywhere, Category="Points")
	float TrickPointsPerAirSecond;

	UPROPERTY(EditAnywhere, Category="Points")
	float TrickPointsPerAirDistance;

	UPROPERTY(EditAnywhere, Category="Points")
	float TrickPointsPerAirHeight;

};

UCLASS()
class UFortVehicleTrickSet : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Trick", meta=(RowType="/Script/FortniteGame.VehicleTrickSequenceBasics"))
	FDataTableRowHandle Basics;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="IncrementalTricks", meta=(DisplayName="Rolls"))
	TArray<FFortVehicleIncrementTrick> RollTricks;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="IncrementalTricks", meta=(DisplayName="Reverse Rolls"))
	TArray<FFortVehicleIncrementTrick> ReverseRollTricks;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="IncrementalTricks", meta=(DisplayName="Spins"))
	TArray<FFortVehicleIncrementTrick> YawTricks;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="IncrementalTricks", meta=(DisplayName="Reverse Spins"))
	TArray<FFortVehicleIncrementTrick> ReverseYawTricks;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="IncrementalTricks", meta=(DisplayName="Front Flips"))
	TArray<FFortVehicleIncrementTrick> PitchTricks;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="IncrementalTricks", meta=(DisplayName="Back Flips"))
	TArray<FFortVehicleIncrementTrick> ReversePitchTricks;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="IncrementalTricks", meta=(DisplayName="Trick 1"))
	FFortVehicleGenericTrick GenericTrick1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="IncrementalTricks", meta=(DisplayName="Trick 2"))
	FFortVehicleGenericTrick GenericTrick2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="IncrementalTricks", meta=(DisplayName="Trick 3"))
	FFortVehicleGenericTrick GenericTrick3;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="IncrementalTricks", meta=(DisplayName="Trick 4"))
	FFortVehicleGenericTrick GenericTrick4;

};

