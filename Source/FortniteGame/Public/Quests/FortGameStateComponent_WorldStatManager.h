// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "FortGameStateComponent_WorldStatManager.generated.h"

class UFortWorldStatDefinition;

USTRUCT()
struct FFortRegisteredWorldStatInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortWorldStatData : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortWorldStatDefinition> WorldStatDefinition;

	UPROPERTY()
	uint32 AchievedCount;

};

USTRUCT()
struct FFortWorldStatDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FFortWorldStatData> WorldStats;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_WorldStatManager : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UFortGameStateComponent_WorldStatManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(Transient)
	TMap<TObjectPtr<UFortWorldStatDefinition>, FFortRegisteredWorldStatInfo> WorldStatsInstanceData;

	UPROPERTY(Transient, Replicated)
	FFortWorldStatDataArray WorldStatsArray;

};

