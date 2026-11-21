// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Abilities/FortAbilityTypes.h"
#include "STW/AI/GameDifficulty/FortGameDifficultyCalculationData.h"
#include "STW/FortTieredCollectionLayout.h"
#include "STW/GameDataSTW.h"
#include "FortDeployableBaseLibrary.generated.h"

class ADeployableBaseCore;
class AFortMission;
class AFortPlayerController;
class UFortTieredCollectionLayout;
class UFortWorldItemDefinition;
class UObject;
enum class EFortCompletionResult : uint8;
enum class EHordeTierStartStatus : uint8;

UENUM(BlueprintType)
enum class EHordeTierStartStatus : uint8
{
	ReadyToStart = 0,
	WaitingForPlayer = 1,
	WaitingForDBM = 2,
	GenericNotReadyToStart = 3,
};

UCLASS()
class UFortDeployableBaseLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="DeployableBase", meta=(WorldContext="WorldContextObject"))
	static void ApplyTieredModifierSet(UObject* WorldContextObject, const TArray<FTieredModifierSetData>& ModifierSetData, int32 Tier, int32 WaveNum, bool bDeferTemporaryModifiers, TArray<FActiveGameplayModifierHandle>& OutAppliedModifiers);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="DeployableBase", meta=(WorldContext="WorldContextObject"))
	static void BroadcastHordeTierComplete(UObject* WorldContextObject, EFortCompletionResult Result);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="DeployableBase", meta=(WorldContext="WorldContextObject"))
	static void ForceClearAllDefenders(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="DeployableBase", meta=(WorldContext="WorldContextObject"))
	static void ForceDeployableBaseHordePlayersToResetAndRespawn(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="DeployableBase", meta=(WorldContext="WorldContextObject"))
	static void ForceRestartDeployableBasePlayers(UObject* WorldContextObject, bool bRestartInvulnerable);

	UFUNCTION(BlueprintCallable, Category="DeployableBase")
	static FGameDifficultyInfo GetGameDifficultyInfo(const FName& RowName);

	UFUNCTION(BlueprintPure, Category="DeployableBase", meta=(WorldContext="WorldContextObject"))
	static EHordeTierStartStatus GetHordeTierStartStatus(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="DeployableBase", meta=(WorldContext="WorldContextObject"))
	static AFortMission* GetPrimaryHordeMission(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="DeployableBase")
	static void GetTieredModifierSet(FName TieredModifierSetName, TArray<FTieredModifierSetData>& OutModifierSetData);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="DeployableBase", meta=(WorldContext="WorldContextObject"))
	static void GrantPlayersCompletedWaveRewards(UObject* WorldContextObject, int32 Tier, int32 Wave, int32 NumberOfPlayers, const TArray<ADeployableBaseCore*>& TargetCores, const TArray<ADeployableBaseCore*>& AllCores, const FFortTierCollectionLayoutOutput& CollectionData, const TArray<FName>& TierGroups);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="DeployableBase")
	static bool IsWorldItemDefValidToPersistForDeployableBasePlayerInventory(const UFortWorldItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="DeployableBase", meta=(WorldContext="WorldContextObject"))
	static void OnPreHordeTierStart(UObject* WorldContextObject, int32 Tier, int32 ModifierRRVSeed);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="DeployableBase", meta=(WorldContext="WorldContextObject"))
	static void ResetDeployableBaseHordePlayerInventories(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="DeployableBase", meta=(WorldContext="WorldContextObject"))
	static void SetDeployableBaseMatchJoinability(UObject* WorldContextObject, bool bMatchJoinable);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="DeployableBase", meta=(WorldContext="WorldContextObject"))
	static void SetupDeployableBaseCombatZoneInventoriesOnPlayers(UObject* WorldContextObject, const TArray<FName>& TierGroups, const TArray<AFortPlayerController*>& PlayerControllers);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="DeployableBase", meta=(WorldContext="WorldContextObject"))
	static void UpdateDeployableBaseTierProgressionForPlayers(UObject* WorldContextObject, const UFortTieredCollectionLayout* CollectionLayout, int32 TierDefeated);

};

