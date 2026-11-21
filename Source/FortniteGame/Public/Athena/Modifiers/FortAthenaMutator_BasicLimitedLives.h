// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_BasicLimitedLives.generated.h"

class AActor;
class AFortPlayerState;

USTRUCT()
struct FLimitedLifeByTeamData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="LimitedLifeByTeamData")
	bool bUseTeamPooledLives;

	UPROPERTY(EditAnywhere, Category="LimitedLifeByTeamData")
	int32 Lives;

};

USTRUCT()
struct FLimitedLifeDataEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AActor> BackingActor;

	UPROPERTY()
	uint8 TeamID;

	UPROPERTY()
	int32 Lives;

};

USTRUCT()
struct FLimitedLifeDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FLimitedLifeDataEntry> Entries;

};

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_BasicLimitedLives : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_LiveData();

	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_BasicLimitedLives")
	FLimitedLifeByTeamData DefaultData;

	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_BasicLimitedLives")
	TMap<uint8, FLimitedLifeByTeamData> SpecificTeamData;

	UPROPERTY(ReplicatedUsing=OnRep_LiveData)
	FLimitedLifeDataArray LiveData;

	UPROPERTY()
	TSet<TObjectPtr<AFortPlayerState>> AlreadySeenStates;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_BasicLimitedLives")
	FScalableFloat bShouldCalculateRespawnLocation;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_BasicLimitedLives")
	FScalableFloat bPreferSpectateTeammates;

	UPROPERTY()
	bool bAlwaysShowSquadInfo;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_BasicLimitedLives", meta=(EditCondition="bShouldCalculateRespawnLocation"))
	FFortRespawnLogicData RespawnLogicData;

};

