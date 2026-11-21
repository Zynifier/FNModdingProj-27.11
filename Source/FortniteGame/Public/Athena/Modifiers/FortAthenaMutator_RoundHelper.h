// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_RoundHelper.generated.h"

class AFortPOICameraActor;
class AFortPlayerPawn;
class AFortPlayerStart;

USTRUCT()
struct FPlayerStartInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	uint8 TeamNum;

	UPROPERTY(EditAnywhere, Category="PlayerStartInfo")
	FGameplayTagContainer RequiredTags;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerStart>> PlayerStartActors;

};

USTRUCT()
struct FPOIRoundInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="POIRoundInfo")
	FScalableFloat bIsPOIEnabled;

	UPROPERTY(EditAnywhere, Category="POIRoundInfo")
	FGameplayTag POITag;

	UPROPERTY(EditAnywhere, Category="POIRoundInfo")
	FText POIOverrideName;

	UPROPERTY(EditAnywhere, Category="POIRoundInfo")
	TArray<FPlayerStartInfo> PlayerStartInfos;

	UPROPERTY(NotReplicated)
	TObjectPtr<AFortPOICameraActor> CameraActor;

};

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_RoundHelper : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetCurrentRound() const;

	UFUNCTION(BlueprintPure)
	int32 GetNumOfRounds() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetCurrentRound(int32 NewRound);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void StartNextRound();

protected:
	UFUNCTION()
	void OnInitialTeleportComplete(AFortPlayerPawn* PlayerPawn);

	UPROPERTY(EditAnywhere, Category="Teams")
	int32 NumOfRounds;

	UPROPERTY(EditAnywhere, Category="Teams")
	int32 NumOfTeams;

	UPROPERTY(VisibleAnywhere, Category="Teams")
	uint8 StartingTeamNum;

	UPROPERTY(EditAnywhere, Category="Round Info")
	TArray<FPOIRoundInfo> RoundInfos;

	UPROPERTY()
	TArray<FPOIRoundInfo> GeneratedRoundInfo;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerStart>> UsedSpawnSlots;

};

