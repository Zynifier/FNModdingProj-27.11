// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortExpeditionUtilities.generated.h"

class AFortPlayerController;
class UFortExpeditionItem;
class UFortItem;
class UObject;
class UWidget;

USTRUCT()
struct FConsumedCriteriaData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	float PowerMod;

	UPROPERTY(Transient)
	TArray<FName> CriteriaNames;

};

UCLASS()
class UFortExpeditionUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Expedition")
	static bool AreAnyExpeditionsComplete(const UWidget* Widget);

	UFUNCTION(BlueprintCallable, Category="Expedition", meta=(WorldContext="WorldContextObject"))
	static bool AreExpeditionsUnlocked(UObject* WorldContextObject, const FUniqueNetIdRepl& UniqueId);

	UFUNCTION(BlueprintCallable, Category="Expedition")
	static float CalculateExpeditionPercentageChanceForSuccess(const UFortExpeditionItem* Expedition, const float TotalPower);

	UFUNCTION(BlueprintCallable, Category="Expedition", meta=(DisplayName="CalculateGlobalAndItemRatingModValues"))
	static void CalculateGlobalAndItemRatingModValuesBP(const UFortExpeditionItem* Expedition, const TArray<UFortItem*>& SlottedItems, float& GlobalPowerMod, TArray<float>& SlottedItemMods);

	UFUNCTION(BlueprintCallable, Category="Expedition")
	static float CalculateTotalPower(AFortPlayerController* FortPC, const UFortExpeditionItem* Expedition, const FName& SquadId, const TArray<UFortItem*>& SlottedItems);

	UFUNCTION(BlueprintCallable, Category="Expedition")
	static void GetAllExpeditionSquadIds(TArray<FName>& OutExpeditionSquadIds);

	UFUNCTION(BlueprintCallable, Category="Expedition")
	static float GetExpeditionSquadPower(AFortPlayerController* FortPC, const FName& SquadId);

	UFUNCTION(BlueprintCallable, Category="Expedition")
	static bool GetExpeditionSquadsThatMatchRequirements(const FGameplayTagContainer& RequirementTags, AFortPlayerController* FortPC, TArray<FName>& OutExpeditionSquadIds);

	UFUNCTION(BlueprintCallable, Category="Expedition")
	static void GetMatchedCriteriaTags(UFortExpeditionItem* Expedition, const TArray<UFortItem*>& SlottedItems, TArray<FGameplayTag>& OutMatchedCriteria);

	UFUNCTION(BlueprintCallable, Category="Expedition")
	static void GetTotalExpeditionVehiclesAvailable(const UWidget* Widget, AFortPlayerController* FortPC, int32& OutLandVehicles, int32& OutLandVehiclesAvailable, int32& OutSeaVehicles, int32& OutSeaVehiclesAvailable, int32& OutAirVehicles, int32& OutAirVehiclesAvailable);

	UFUNCTION(BlueprintCallable, Category="Expedition")
	static bool GetVehicleTagFromSquadId(const FName& SquadId, FGameplayTag& OutFoundVehicleTag);

	UFUNCTION(BlueprintCallable, Category="Expedition")
	static FGameplayTag GetVehicleTagRequiredForExpedition(const UFortExpeditionItem* Expedition);

	UFUNCTION(BlueprintCallable, Category="Expedition")
	static bool IsSquadOnExpedition(const UWidget* Widget, const FName& SquadId);

	UFUNCTION(BlueprintCallable, Category="Expedition")
	static int32 TotalUnseenExpeditionsForTab(const UWidget* Widget, const FName& TabNameId);

};

