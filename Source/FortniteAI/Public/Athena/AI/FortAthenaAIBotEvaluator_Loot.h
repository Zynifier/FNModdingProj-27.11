// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "Athena/AI/FortAthenaAIEvaluator.h"
#include "FortAthenaAIBotEvaluator_Loot.generated.h"

class AFortTeamInfoAthena;
class UAthenaAIServiceLoot;
class UFortAthenaAIBotLootingDigestedSkillSet;

UENUM()
enum class EAILootExcludeListReason : uint8
{
	Invalid = 0,
	ExecutionError = 1,
	CannotReachLootLocation = 2,
	OutsideSafeZoneRadius = 3,
	NoInventorySpace = 4,
	LootStateUnavailable = 5,
	PathNotFound = 6,
	GoalOffNavmesh = 7,
	AgentBlocked = 8,
	IsolatedIsland = 9,
	/** Unsupported items are added to the octree for other AIs than bots using it */
	UnsupportedItem = 10,
	Count = 11,
};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_Loot : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<UAthenaAIServiceLoot> CachedAIServiceLoot;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotLootingDigestedSkillSet> LootingSkillSet;

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LootDestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LootObjectKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LootTypeKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName POINavigationExecutionStatusKeyName;

	UPROPERTY(Transient)
	EExecutionStatus POINavigationExecutionStatus;

	UPROPERTY(Transient)
	uint32 CurrentLootOctreeElementId;

	UPROPERTY(Transient)
	TObjectPtr<AFortTeamInfoAthena> CachedTeamInfo;

};

