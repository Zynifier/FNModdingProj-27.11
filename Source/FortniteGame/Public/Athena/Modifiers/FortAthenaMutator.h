// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Modifiers/FortGameplayMutator.h"
#include "FortAthenaMutator.generated.h"

class AFortGameModeAthena;
class AFortGameStateAthena;
class AFortGameplayMutator;
class APlayerController;
class UObject;

UENUM(BlueprintType)
enum class EFortMutatorOverridePriority : uint8
{
	None = 0,
	Low = 1,
	Medium = 2,
	High = 3,
};

UENUM(BlueprintType)
enum class EFortMutatorReturnValue : uint8
{
	// functions returning this value want to be ignored and not processed by the calling code

	Ignore = 0,
	// functions returning this value should be handled by the calling code

	Override = 1,
	// functions returning this value should be handled by the calling code and want to return from the function they were called from

	OverrideReturn = 2,
};

USTRUCT(BlueprintType)
struct FFortRespawnLogicData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortRespawnLogicData")
	FScalableFloat DirectionDeviation;

	UPROPERTY(EditDefaultsOnly, Category="FortRespawnLogicData")
	FScalableFloat MinDistFromCenterPercent;

	UPROPERTY(EditDefaultsOnly, Category="FortRespawnLogicData")
	FScalableFloat MaxDistFromCenterPercent;

	UPROPERTY(EditDefaultsOnly, Category="FortRespawnLogicData")
	FScalableFloat SingleBusRespawnNearDeathLocation;

	UPROPERTY(EditDefaultsOnly, Category="FortRespawnLogicData")
	FScalableFloat MinHeightFromGround;

	UPROPERTY(EditDefaultsOnly, Category="FortRespawnLogicData")
	FScalableFloat MinHeightFromZero;

	UPROPERTY(EditDefaultsOnly, Category="FortRespawnLogicData")
	FScalableFloat CameraDistance;

	UPROPERTY(EditDefaultsOnly, Category="FortRespawnLogicData")
	FScalableFloat RespawnTraceHeight;

};

USTRUCT()
struct FFortRespawnLogicData_Teams : public FFortRespawnLogicData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortRespawnLogicData_Teams")
	FScalableFloat TryPlaceByTeammates;

	UPROPERTY(EditDefaultsOnly, Category="FortRespawnLogicData_Teams")
	FScalableFloat AlsoPlaceBehindTeammates;

	UPROPERTY(EditDefaultsOnly, Category="FortRespawnLogicData_Teams")
	FScalableFloat MaxDistanceFromTeammates;

	UPROPERTY(EditDefaultsOnly, Category="FortRespawnLogicData_Teams")
	FScalableFloat MinDistanceFromTeammates;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator : public AFortGameplayMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Mutator", meta=(DeterminesOutputType="MutatorClass", WorldContext="ContextObject"))
	static FORTNITEGAME_API AFortGameplayMutator* GetGameplayMutatorByClass(const UObject* ContextObject, const TSubclassOf<AFortGameplayMutator> MutatorClass);

	UPROPERTY(EditAnywhere, Category="FortAthenaMutator")
	uint8 bMutatesGameMode : 1;

	UPROPERTY(EditAnywhere, Category="FortAthenaMutator")
	uint8 bMutatesGameState : 1;

protected:
	UPROPERTY(Transient)
	TObjectPtr<AFortGameModeAthena> CachedGameMode;

	UPROPERTY(Transient)
	TObjectPtr<AFortGameStateAthena> CachedGameState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator")
	EFortMutatorOverridePriority OverridePriority;

private:
	UPROPERTY(Transient)
	TSet<TWeakObjectPtr<APlayerController>> InitializedPlayerControllers;

};

