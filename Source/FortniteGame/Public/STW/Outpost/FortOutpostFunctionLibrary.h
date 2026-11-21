// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "STW/GameDataSTW.h"
#include "FortOutpostFunctionLibrary.generated.h"

class AFortPlayerController;
class AFortPlayerControllerFrontEnd;
class AFortPlayerControllerOutpost;
class UFortMissionConfigData;
class UFortOutpostItemDefinition;
class UFortWorldItem;
class UObject;
enum class EOutpostBuildings : uint8;
enum class EStormShieldDefense : uint8;

UCLASS()
class UFortOutpostFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Outpost", meta=(WorldContext="WorldContextObject"))
	static bool BuildingActorRecordUpdatesEnabled(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void CacheIronCityDifficultyInfo(UObject* WorldContextObject, int32 AccountLevel);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Outpost", meta=(WorldContext="WorldContextObject"))
	static bool DeployOutpostBuildingTagOnPlacementTag(UObject* WorldContextObject, const FGameplayTag& BuildingTag, const FGameplayTag& PlacementTag);

	UFUNCTION(BlueprintCallable, Category="NewOutpost|StorageVault")
	static void FlushTransferRequests(AFortPlayerController* Player);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="MissionHelpers", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static FIronCityDifficultyInfo GetCachedIronCityDifficultyInfo(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Outpost", meta=(WorldContext="WorldContextObject"))
	static int32 GetIronCityAveragePlayerAccountLevel(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Outpost", meta=(WorldContext="WorldContextObject"))
	static UFortOutpostItemDefinition* GetOutpostBuildingItemDefinition(UObject* WorldContextObject, EOutpostBuildings Building);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Outpost", meta=(WorldContext="WorldContextObject"))
	static FGameplayTag GetOutpostBuildingTagFromPlacementTag(UObject* WorldContextObject, const FGameplayTag& PlacementTag);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Outpost", meta=(WorldContext="WorldContextObject"))
	static AFortPlayerControllerOutpost* GetOutpostOwner(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Outpost", meta=(WorldContext="WorldContextObject"))
	static UFortMissionConfigData* GetOutpostQuestMissionConfigData(UObject* WorldContextObject, FGameplayTagContainer ConfigTagContainer);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Outpost", meta=(WorldContext="WorldContextObject"))
	static UFortMissionConfigData* GetOutpostQuestMissionConfigDataFrontEnd(AFortPlayerControllerFrontEnd* FortPC, FGameplayTagContainer ConfigTagContainer);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Outpost", meta=(WorldContext="WorldContextObject"))
	static FGameplayTag GetPlacementTagFromOutpostBuildingTag(UObject* WorldContextObject, const FGameplayTag& BuildingTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Outpost", meta=(WorldContext="WorldContextObject"))
	static void SaveIronCityEarlyPlayerInfos(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Outpost", meta=(WorldContext="WorldContextObject"))
	static void SaveIronCityLowestPlayerAccountLevel(UObject* WorldContextObject, int32 AccountLevel);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Outpost", meta=(WorldContext="WorldContextObject"))
	static void SetEnduranceWaveCompleted(UObject* WorldContextObject, const int32 WaveNumber, bool& bNewHighest);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Outpost", meta=(WorldContext="WorldContextObject"))
	static void SetIronCityMinMaxPowerLevels(UObject* WorldContextObject, float MinPowerLevel, float MaxPowerLevel);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Outpost", meta=(WorldContext="WorldContextObject"))
	static void SetOutpostDefenseActive(UObject* WorldContextObject, bool bActive);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Outpost", meta=(WorldContext="WorldContextObject"))
	static void SetOutpostGameDifficultyRow(UObject* WorldContextObject, const FDataTableRowHandle& GameDifficultyInfo);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Outpost", meta=(WorldContext="WorldContextObject"))
	static void SetStormShieldDefenseType(UObject* WorldContextObject, EStormShieldDefense Type);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Outpost", meta=(WorldContext="WorldContextObject"))
	static void SetWargameActive(UObject* WorldContextObject, bool bActive);

	UFUNCTION(BlueprintCallable, Category="NewOutpost|StorageVault")
	static void TransferItemFromStorage(AFortPlayerController* Player, UFortWorldItem* Item, int32 Count);

	UFUNCTION(BlueprintCallable, Category="NewOutpost|StorageVault")
	static void TransferItemToStorage(AFortPlayerController* Player, UFortWorldItem* Item, int32 Count);

};

