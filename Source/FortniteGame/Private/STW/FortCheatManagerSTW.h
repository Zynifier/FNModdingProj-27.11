// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "FortCheatManagerSTW.generated.h"

UCLASS()
class UFortCheatManagerSTW : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void ApplyWeaponAlteration(const FString& AlterationName);

	UFUNCTION(Exec)
	void ChangeHeroClass(const int32 Index);

	UFUNCTION(Exec)
	void ClearKeepSave();

	UFUNCTION(Exec)
	void DevSkipTutorial();

	UFUNCTION(Exec)
	virtual void DumpAppliedHomebaseEffectsWithCoreAttributes();

	UFUNCTION(Exec)
	void EvolveHero();

	UFUNCTION(Exec)
	void ForceHeroType(const FString& HeroPersistentName);

	UFUNCTION(Exec)
	void ForceSetHeroRemoteCharacter(int32 PartyMemberIndex, bool bEnabled);

	UFUNCTION(Exec)
	void ForceUnlockHordeTiers(int32 MaxTierNumber);

	UFUNCTION(Exec)
	void GetWorldDifficulty();

	UFUNCTION(Exec)
	void GetWorldLevel();

	UFUNCTION(Exec)
	void GiveBluGlo(int32 Amount = 50);

	UFUNCTION(Exec)
	void GiveCheatInventory();

	UFUNCTION(Exec)
	void GiveDeployablePlotAllIngredients(int32 NumIngredients = 50);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveUsefulThings(int32 NumOfUsefulThings = 50);

	UFUNCTION(Exec)
	void IronCityAutoAmplifierPlacement(int32 Value);

	UFUNCTION(Exec)
	void McpAddTestStatsMock();

	UFUNCTION(Exec)
	void McpApplyAlteration(const FString& Schematic, const FString& Alteration);

	UFUNCTION(Exec)
	void McpClaimAllAvailableCollectionBookRewards();

	UFUNCTION(Exec)
	void McpClaimAllResourceCollectors(bool bDebugPrint = false);

	UFUNCTION(Exec)
	void McpCompleteHexMission();

	UFUNCTION(Exec)
	void McpConvertItem(const FString& ItemToConvert, int32 ConversionIdx);

	UFUNCTION(Exec)
	void McpGetCachedPersistence();

	UFUNCTION(Exec)
	void McpGetHexMission();

	UFUNCTION(Exec)
	void McpGetPersonnelXP();

	UFUNCTION(Exec)
	void McpGetSchematicXP();

	UFUNCTION(Exec)
	void McpHostGetAllPlayerCachedPersistence();

	UFUNCTION(Exec)
	void McpOpenCardPack(const FString& CardPackItemId, int32 SelectionIdx = 0);

	UFUNCTION(Exec)
	void McpRecycleItem(const FString& ItemToRecycle);

	UFUNCTION(Exec)
	void McpRemoveAllTestProfileMocks();

	UFUNCTION(Exec)
	void McpResetPersistence();

	UFUNCTION(Exec)
	void McpSlotItem(const FString& ItemToSlot);

	UFUNCTION(Exec)
	void McpStorageTransfer(const TArray<FString>& ItemIdsToMoveToOutpost, const TArray<FString>& ItemIdsToMoveToTheater);

	UFUNCTION(Exec)
	void McpUpgradeItem(const FString& ItemToUpgrade);

	UFUNCTION(Exec)
	void SetHeroClass(const FString& NewHeroName, int32 Level = -1);

	UFUNCTION(Exec)
	void SetHeroLevel(int32 Level);

	UFUNCTION(Exec)
	void SetHordePlotExpansionSize(int32 XSize, int32 YSize, int32 ZSize);

	UFUNCTION(Exec)
	void SetWorldLevel(float level);

	UFUNCTION(Exec)
	void TestOutpostUI();

	UFUNCTION(Exec)
	void TestSetOutpostDefenseActive(bool bActive);

	UFUNCTION(Exec)
	void TestUpgradeOutpostItem(const FString& ItemTemplateId);

	UFUNCTION(Exec)
	void UnlockAllZones();

};

