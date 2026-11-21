// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortEncounterSettings.h"
#include "STW/CollectionBook/FortCollectionBookDirectPurchaseData.h"
#include "STW/Heroes/FortHeroSpecialization.h"
#include "STW/TieredWaveSet.h"
#include "BlueprintLibrarySTW.generated.h"

class AFortPlayerController;
class UFortAbilityKit;
class UObject;

UCLASS(MinimalAPI)
class UBlueprintLibrarySTW : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Wave Data")
	static FFortEncounterSettings ApplyEncounterOptionOverridesFromWaveDataToEncounterSettings(const FTieredWaveSetData& WaveData, UPARAM(ref) FFortEncounterSettings& EncounterSettings);

	UFUNCTION(BlueprintPure, Category="Difficulty", meta=(DeprecatedFunction, WorldContext="WorldContextObject"))
	static float GetCalculatedGameDifficulty(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Difficulty", meta=(DeprecatedFunction))
	static float GetGameDifficulty();

	UFUNCTION(BlueprintPure, Category="FortSpecializationSlot")
	static UFortAbilityKit* GetGrantedAbilityKit(const FFortSpecializationSlot& Slot);

	UFUNCTION(BlueprintPure, Category="Character Customization", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool GetLocalPlayerHasHeroBackpack(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Character Customization", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool GetLocalPlayerHasHeroHeadAccessories(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static bool GetPurchaseCostsRow(FDataTableRowHandle DataTableRowHandle, FFortCollectionBookDirectPurchaseData& OutRow);

	UFUNCTION(BlueprintPure, Category="FortSpecializationSlot")
	static UFortAbilityKit* GetRemovedAbilityKit(const FFortSpecializationSlot& Slot);

	UFUNCTION(BlueprintPure, Category="Character Customization", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool GetShowHeroBackpackForLocalPlayer(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Character Customization", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool GetShowHeroHeadAccessoriesForLocalPlayer(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Matchmaking", meta=(WorldContext="WorldContextObject"))
	static void SetCriticalMissionJoinability(UObject* WorldContextObject, bool bJoinable);

	UFUNCTION(BlueprintCallable, Category="Idle Detection", meta=(WorldContext="WorldContextObject"))
	static void SetIdleKickEnabled(UObject* WorldContextObject, bool bEnabled);

	UFUNCTION(BlueprintCallable, Category="Fortnite")
	static bool SwitchHeroType(AFortPlayerController* FortPC, const FString& NewHeroName);

};

