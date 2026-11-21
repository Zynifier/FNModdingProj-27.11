// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "MoverTypes.generated.h"

// Contains a group of different FMoverDataStructBase-derived data, and supports net serialization of them. Note that
//	each contained data must have a unique type.  This is to support dynamic composition of Mover simulation model
//  definitions (input cmd, sync state, aux state).

USTRUCT(BlueprintType)
struct MOVER_API FMoverDataCollection
{
	GENERATED_BODY()

};

// Base type for all data structs used to compose Mover simulation model definition dynamically (input cmd, sync state, aux state)
// NOTE: for simulation state data (sync/aux), derive from FMoverStateData instead 

USTRUCT(BlueprintType)
struct MOVER_API FMoverDataStructBase
{
	GENERATED_BODY()

};

// Struct to hold params for when an impact happens. This contains all of the data for impacts including what gets passed to the FMover_OnImpact delegate

USTRUCT(BlueprintType, meta=(DisplayName="Impact Data"))
struct MOVER_API FMoverOnImpactParams
{
	GENERATED_BODY()

public:
	// Name of the movement mode this actor is currently in at the time of the impact

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	FName MovementModeName;

	// The hit result of the impact

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	FHitResult HitResult;

	// The original move that was being performed when the impact happened

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	FVector AttemptedMoveDelta;

};

USTRUCT(BlueprintType)
struct MOVER_API FMoverTimeStep
{
	GENERATED_BODY()

public:
	// The server simulation frame this timestep is associated with

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	int32 ServerFrame;

	// Starting simulation time (in server simulation timespace)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	float BaseSimTimeMs;

	// The delta time step for this tick

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	float StepMs;

};

// Blueprint helper functions for working with a Mover data collection

UCLASS()
class MOVER_API UMoverDataCollectionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	* Add a data struct to the collection, overwriting an existing one with the same type
	* @param SourceAsRawBytes		The data struct instance to add by copy, which must be a FMoverDataStructBase sub-type
	*/
	UFUNCTION(CustomThunk, BlueprintCallable, Category="Mover|Data", meta=(AllowAbstract="false", CustomStructureParam="SourceAsRawBytes", DisplayName="Add Data To Collection"))
	static void K2_AddDataToCollection(UPARAM(ref) FMoverDataCollection& Collection, const int32& SourceAsRawBytes);
	DECLARE_FUNCTION(execK2_AddDataToCollection);

	/**
	 * Retrieves data from a collection, by writing to a target instance if it contains one of the matching type.  Changes must be written back using AddDataToCollection.
	 * @param DidSucceed			Flag indicating whether data was actually written to target struct instance
	 * @param TargetAsRawBytes		The data struct instance to write to, which must be a FMoverDataStructBase sub-type
	 */
	UFUNCTION(CustomThunk, BlueprintCallable, Category="Mover|Data", meta=(AllowAbstract="false", CustomStructureParam="TargetAsRawBytes", DisplayName="Get Data From Collection"))
	static void K2_GetDataFromCollection(bool& DidSucceed, const FMoverDataCollection& Collection, int32& TargetAsRawBytes);
	DECLARE_FUNCTION(execK2_GetDataFromCollection);

};

