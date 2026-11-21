// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Athena/AthenaRewardSchedule.h"
#include "Items/AthenaSeasonItemDefinitionTypes.h"
#include "AthenaSeasonItemDefinitionSubDataAsset.generated.h"

class UFortItemDefinition;

UCLASS(Abstract)
class UAthenaSeasonItemDefinitionSubDataAsset : public UDataAsset
{
	GENERATED_BODY()

};

UCLASS()
class UAthenaMidSeasonUpdatesDataAsset : public UAthenaSeasonItemDefinitionSubDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaMidSeasonUpdatesDataAsset")
	TArray<FAthenaMidSeasonUpdate> MidSeasonUpdates;

};

UCLASS()
class UAthenaProfileItemsToRemoveAtSeasonEndDataAsset : public UAthenaSeasonItemDefinitionSubDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaProfileItemsToRemoveAtSeasonEndDataAsset")
	TArray<TSoftObjectPtr<UFortItemDefinition>> ProfileItemsToRemoveAtSeasonEnd;

};

UCLASS()
class UAthenaRewardScheduleLevelDataAsset : public UAthenaSeasonItemDefinitionSubDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaRewardScheduleLevelDataAsset")
	FAthenaRewardScheduleLevel RewardScheduleLevel;

};

UCLASS()
class UAthenaSuperChargedBonusQuestDataAsset : public UAthenaSeasonItemDefinitionSubDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaSuperChargedBonusQuestDataAsset")
	TArray<FAthenaSuperChargedBonusQuestLevel> BonusQuestLevels;

};

