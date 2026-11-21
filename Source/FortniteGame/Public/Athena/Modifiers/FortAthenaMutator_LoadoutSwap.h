// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AthenaGamePhaseEnum.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_LoadoutSwap.generated.h"

class UFortWorldItemDefinition;

USTRUCT()
struct FPlayerLoudoutEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PlayerLoudoutEntry")
	TObjectPtr<UFortWorldItemDefinition> ItemToGrant;

	UPROPERTY(EditAnywhere, Category="PlayerLoudoutEntry")
	FScalableFloat NumberOfItemsToGrant;

	UPROPERTY(EditAnywhere, Category="PlayerLoudoutEntry")
	FScalableFloat RemoveItemOnNextSwap;

	UPROPERTY(EditAnywhere, Category="PlayerLoudoutEntry")
	FScalableFloat RandomWeight;

	UPROPERTY(EditAnywhere, Category="PlayerLoudoutEntry")
	int32 DesiredSlot;

};

USTRUCT()
struct FRandomItemEntries
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="RandomItemEntries")
	TArray<FPlayerLoudoutEntry> WeightedEntries;

};

USTRUCT()
struct FPlayerLoadout
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PlayerLoadout")
	TArray<FPlayerLoudoutEntry> AlwaysGrantedLoadoutItems;

	UPROPERTY(EditAnywhere, Category="PlayerLoadout")
	TArray<FRandomItemEntries> RandomlyGrantedLoadoutItems;

	UPROPERTY(EditAnywhere, Category="PlayerLoadout")
	FScalableFloat LoadoutDuration;

};

UCLASS(MinimalAPI, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_LoadoutSwap : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_ServerWorldTimeOfNextSwap();

	UPROPERTY(EditAnywhere, Category="Gameplay")
	EAthenaGamePhase GamePhaseToStart;

	UPROPERTY(EditAnywhere, Category="Load outs")
	TArray<FPlayerLoadout> Loadouts;

	UPROPERTY()
	bool bRandomizeLoadOuts;

	UPROPERTY(EditAnywhere, Category="Load outs")
	FScalableFloat AreLoadoutsRandomized;

	UPROPERTY(EditAnywhere, Category="Load outs")
	FScalableFloat WarningTime;

	UPROPERTY(ReplicatedUsing=OnRep_ServerWorldTimeOfNextSwap)
	float ServerWorldTimeOfNextSwap;

	UPROPERTY(Replicated)
	TArray<FPlayerLoudoutEntry> NextItemsToGrant;

	UPROPERTY()
	TArray<int32> RemainingLoadouts;

	UPROPERTY()
	TArray<TObjectPtr<UFortWorldItemDefinition>> ItemstoAlwaysRemove;

	UPROPERTY(Replicated)
	TArray<TObjectPtr<UFortWorldItemDefinition>> ItemsWithInfiniteAmmo;

};

