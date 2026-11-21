// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "Quests/QuestTypes.h"
#include "QuestManagerEventDispatcherTypes.generated.h"

class AActor;
class UFortControllerComponent_QuestManagerDataReplicator;

USTRUCT()
struct FEventScopeInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EQuestParticipationScope Scope;

	UPROPERTY()
	TWeakObjectPtr<AActor> QuestOwner;

};

USTRUCT()
struct FObjectiveEventRecord : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FEventScopeInfo Scope;

	UPROPERTY()
	FUpdatedQuestObjectiveData Data;

};

USTRUCT()
struct FObjectiveEventRecordArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, NotReplicated, Export)
	TWeakObjectPtr<UFortControllerComponent_QuestManagerDataReplicator> CachedDataReplicatorComponent;

	UPROPERTY(Transient)
	TArray<FObjectiveEventRecord> Objectives;

};

USTRUCT()
struct FQuestEventRecord : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FEventScopeInfo Scope;

	UPROPERTY()
	FFortGrantedQuestData Data;

};

USTRUCT()
struct FQuestEventRecordArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, NotReplicated, Export)
	TWeakObjectPtr<UFortControllerComponent_QuestManagerDataReplicator> CachedDataReplicatorComponent;

	UPROPERTY(Transient)
	TArray<FQuestEventRecord> Quests;

};

