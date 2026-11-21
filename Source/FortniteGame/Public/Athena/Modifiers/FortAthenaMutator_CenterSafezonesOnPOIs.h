// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_CenterSafezonesOnPOIs.generated.h"

class AFortPoiVolume;

USTRUCT()
struct FCenterSafeZoneOnPOIInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CenterSafeZoneOnPOIInfo")
	FScalableFloat Enabled;

	UPROPERTY(EditAnywhere, Category="CenterSafeZoneOnPOIInfo")
	FScalableFloat WithinRadius;

	UPROPERTY(EditAnywhere, Category="CenterSafeZoneOnPOIInfo")
	FScalableFloat RejectRadius;

};

USTRUCT()
struct FCenterOnLocationPOI : public FCenterSafeZoneOnPOIInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CenterOnLocationPOI")
	FScalableFloat RelativeToPreviousChosenLocation;

	UPROPERTY(EditAnywhere, Category="CenterOnLocationPOI")
	FVector LocationForPOI;

};

USTRUCT()
struct FCenterOnTaggedPOI : public FCenterSafeZoneOnPOIInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CenterOnTaggedPOI")
	FGameplayTag TagForPOI;

};

USTRUCT()
struct FLocationPOIList
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="LocationPOIList")
	FScalableFloat Enabled;

	UPROPERTY(EditAnywhere, Category="LocationPOIList")
	FScalableFloat ChanceToApply;

	UPROPERTY(EditAnywhere, Category="LocationPOIList")
	TArray<FCenterOnLocationPOI> List;

};

USTRUCT()
struct FTaggedPOIList
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="TaggedPOIList")
	FScalableFloat Enabled;

	UPROPERTY(EditAnywhere, Category="TaggedPOIList")
	FScalableFloat ChanceToApply;

	UPROPERTY(EditAnywhere, Category="TaggedPOIList")
	TArray<FCenterOnTaggedPOI> List;

};

UCLASS(MinimalAPI, HideCategories=("Actor", "Replication", "FortAthenaMutator", "LOD", "Cooking", "Mutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_CenterSafezonesOnPOIs : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Safezones")
	FScalableFloat UseFirstEntryForAllSafezones;

	UPROPERTY(EditDefaultsOnly, Category="Safezones")
	FScalableFloat InitialSafezoneForcedToMapCenter;

	UPROPERTY(EditDefaultsOnly, Category="Safezones")
	TMap<int32, FTaggedPOIList> CenterSafezonesOnPOITag;

	UPROPERTY(EditDefaultsOnly, Category="Safezones")
	TMap<int32, FLocationPOIList> CenterSafezonesOnLiteralLocation;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPoiVolume>> SafezonePOITaggedVolumes;

};

