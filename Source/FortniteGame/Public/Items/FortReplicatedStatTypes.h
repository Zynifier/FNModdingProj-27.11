// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortReplicatedStatTypes.generated.h"

UENUM(BlueprintType)
namespace EFortReplicatedStat
{
	enum Type
	{
		// Monster kills

		MonsterKills = 0,
		// Points gained by damaging monsters

		MonsterDamagePoints = 1,
		// Player kills

		PlayerKills = 2,
		// Total wood gathered

		WoodGathered = 3,
		// Total stone gathered

		StoneGathered = 4,
		// Total metal gathered

		MetalGathered = 5,
		// Deaths

		Deaths = 6,
		// Blu-Glo Activity

		BluGloActivity = 7,
		// Total # of buildings built

		BuildingsBuilt = 8,
		// Wood buildings built

		BuildingsBuilt_Wood = 9,
		// Stone buildings built

		BuildingsBuilt_Stone = 10,
		// Metal buildings built

		BuildingsBuilt_Metal = 11,
		// Upgraded a building to Wood 2

		BuildingsUpgraded_Wood2 = 12,
		// Upgraded a building to Wood 3

		BuildingsUpgraded_Wood3 = 13,
		// Upgraded a building to Stone 2

		BuildingsUpgraded_Stone2 = 14,
		// Upgraded a building to Stone 3

		BuildingsUpgraded_Stone3 = 15,
		// Upgraded a building to Metal 2

		BuildingsUpgraded_Metal2 = 16,
		// Upgraded a building to Metal 3

		BuildingsUpgraded_Metal3 = 17,
		// Total # of buildings destroyed

		BuildingsDestroyed = 18,
		// Total # of wood resources spent on repair

		Repair_Wood = 19,
		// Total # of stone resources spent on repair

		Repair_Stone = 20,
		// Total # of metal resources spent on repair

		Repair_Metal = 21,
		// Total # of pvp flags captured

		FlagsCaptured = 22,
		// Total # of pvp flags returned

		FlagsReturned = 23,
		// Total # of containers looted

		ContainersLooted = 24,
		// Total # of crafting points acquired

		CraftingPoints = 25,
		// Total # of trap placement points

		TrapPlacementPoints = 26,
		// Total # of trap activation points

		TrapActivationPoints = 27,
		// Total score. KEEP THIS RIGHT BELOW NONE! If you iterate to < Score it is all of the stats that are not derived

		TotalScore = 28,
		// Total score at the last time you tried to give the team XP. Used to deduce the delta, which is what we earn XP on

		OldTotalScore = 29,
		// Combat score. KEEP THIS BETWEEN MAX AND SCORE!

		CombatScore = 30,
		// Building score. KEEP THIS BETWEEN MAX AND SCORE!

		BuildingScore = 31,
		// Utility score. KEEP THIS BETWEEN MAX AND SCORE!

		UtilityScore = 32,
		// Badges score. KEEP THIS BETWEEN MAX AND SCORE!

		BadgesScore = 33,
		// Dummy value. KEEP THIS BETWEEN MAX AND SCORE! This is just here so that if you try to insert into an array of MAX size with NONE you won't crash.

		None = 34,
		MAX = 35,
	};
}

USTRUCT()
struct FReplicatedStatValues
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 StatValue;

	UPROPERTY()
	int32 ScoreValue;

};

