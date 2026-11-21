// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/FortDeployableBaseLibrary.h"

void UFortDeployableBaseLibrary::ApplyTieredModifierSet(UObject* WorldContextObject, const TArray<FTieredModifierSetData>& ModifierSetData, int32 Tier, int32 WaveNum, bool bDeferTemporaryModifiers, TArray<FActiveGameplayModifierHandle>& OutAppliedModifiers)
{
}

void UFortDeployableBaseLibrary::BroadcastHordeTierComplete(UObject* WorldContextObject, EFortCompletionResult Result)
{
}

void UFortDeployableBaseLibrary::ForceClearAllDefenders(UObject* WorldContextObject)
{
}

void UFortDeployableBaseLibrary::ForceDeployableBaseHordePlayersToResetAndRespawn(UObject* WorldContextObject)
{
}

void UFortDeployableBaseLibrary::ForceRestartDeployableBasePlayers(UObject* WorldContextObject, bool bRestartInvulnerable)
{
}

FGameDifficultyInfo UFortDeployableBaseLibrary::GetGameDifficultyInfo(const FName& RowName)
{
	return FGameDifficultyInfo();
}

EHordeTierStartStatus UFortDeployableBaseLibrary::GetHordeTierStartStatus(UObject* WorldContextObject)
{
	return EHordeTierStartStatus();
}

AFortMission* UFortDeployableBaseLibrary::GetPrimaryHordeMission(UObject* WorldContextObject)
{
	return nullptr;
}

void UFortDeployableBaseLibrary::GetTieredModifierSet(FName TieredModifierSetName, TArray<FTieredModifierSetData>& OutModifierSetData)
{
}

void UFortDeployableBaseLibrary::GrantPlayersCompletedWaveRewards(UObject* WorldContextObject, int32 Tier, int32 Wave, int32 NumberOfPlayers, const TArray<ADeployableBaseCore*>& TargetCores, const TArray<ADeployableBaseCore*>& AllCores, const FFortTierCollectionLayoutOutput& CollectionData, const TArray<FName>& TierGroups)
{
}

bool UFortDeployableBaseLibrary::IsWorldItemDefValidToPersistForDeployableBasePlayerInventory(const UFortWorldItemDefinition* ItemDefinition)
{
	return false;
}

void UFortDeployableBaseLibrary::OnPreHordeTierStart(UObject* WorldContextObject, int32 Tier, int32 ModifierRRVSeed)
{
}

void UFortDeployableBaseLibrary::ResetDeployableBaseHordePlayerInventories(UObject* WorldContextObject)
{
}

void UFortDeployableBaseLibrary::SetDeployableBaseMatchJoinability(UObject* WorldContextObject, bool bMatchJoinable)
{
}

void UFortDeployableBaseLibrary::SetupDeployableBaseCombatZoneInventoriesOnPlayers(UObject* WorldContextObject, const TArray<FName>& TierGroups, const TArray<AFortPlayerController*>& PlayerControllers)
{
}

void UFortDeployableBaseLibrary::UpdateDeployableBaseTierProgressionForPlayers(UObject* WorldContextObject, const UFortTieredCollectionLayout* CollectionLayout, int32 TierDefeated)
{
}
