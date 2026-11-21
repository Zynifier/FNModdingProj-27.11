// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Components/FortGameStateComponent_PickupManagement.h"
#include "FortGameStateZone.h"
#include "FortRarityEnum.h"
#include "FortGameStatePvE.generated.h"

class AFortAIPawn;
class AFortAircraft;
class AFortPlayerStateZone;
class UFortItem;
class UFortItemDefinition;
enum class EDefenderSpawnFailureReason : uint8;

UENUM(BlueprintType)
enum class EDefenderSpawnFailureReason : uint8
{
	None = 0,
	AllPlayerSlotsFull = 1,
	DefendersNotUnlocked = 2,
	CurrentlySimulatingDefender = 3,
	NotOutpostOwner = 4,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMaxMatchLengthTimerComplete);

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameStatePvE : public AFortGameStateZone
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Defenders")
	bool CanSpawnDefender(AFortPlayerStateZone* PlayerCausingRemoval, const FName& RemoveFromDefenderSquadId, AFortAIPawn*& OutDefenderToBeRemoved, EDefenderSpawnFailureReason& OutFailureReason) const;

	UFUNCTION(BlueprintPure, Category="GameState")
	bool CanSwapWeapon(const UFortItemDefinition* ItemDefinition) const;

	UFUNCTION(BlueprintPure, Category="Mission")
	AFortAircraft* GetAircraft() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="PickupManagement")
	void GetPickupManagementSettings(FPickupManagementSettings& PickupSettings);

	UFUNCTION(BlueprintPure, Category="Defenders")
	bool IsDefenderItemDeployed(UFortItem* DefenderItem, AFortPlayerStateZone* RequestingPlayer) const;

	UFUNCTION(BlueprintPure, Category="GameState")
	bool IsMulchingAllowed() const;

	UFUNCTION(BlueprintPure, Category="GameState")
	bool IsSwappableWeaponType(const UFortItemDefinition* ItemDefinition) const;

	UFUNCTION(BlueprintPure, Category="GameState")
	bool IsWeaponSwappingEnabled() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Defenders")
	void OnDefenderDeployed(AFortAIPawn* Defender);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Defenders")
	void OnDefenderRemoved(AFortAIPawn* Defender);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="GameDifficulty")
	void SetGameDifficultyExplicitly(const float InGameDifficulty);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="GameDifficulty")
	void SetGameDifficultyRow(const FDataTableRowHandle& GameDifficultyInfo);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="PickupManagement")
	void SetPickupManagementSettings(UPARAM(ref) FPickupManagementSettings& PickupSettings);

	UFUNCTION(BlueprintPure, Category="GameState")
	bool ShouldUseMoonbeamGameplayFunctionality() const;

	UFUNCTION(BlueprintPure, Category="GameState")
	bool ShouldUseMoonbeamHUD() const;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="GameState")
	bool bAllowMulching;

protected:
	UFUNCTION(BlueprintCallable)
	void StartMaxMatchWarningTimer();

	UPROPERTY(Replicated)
	TArray<TObjectPtr<AFortAIPawn>> DeployedDefenders;

	UPROPERTY(Replicated)
	TObjectPtr<AFortAircraft> Aircraft;

	UPROPERTY(Replicated)
	bool bUseMoonbeamHUD;

	UPROPERTY(Config)
	uint32 PickupsAllowedMax;

	UPROPERTY(Config)
	uint32 PickupsDesiredSlack;

	UPROPERTY(Config)
	float PickupDespawnDelaySeconds;

	UPROPERTY(Config)
	bool bDebugPickupManagement;

	UPROPERTY(Config)
	bool bEnablePickupManagement;

	UPROPERTY(Config)
	EFortRarity ImportantPickupThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameStatePvE")
	bool bWeaponSwappingEnabled;

	UPROPERTY(BlueprintAssignable)
	FOnMaxMatchLengthTimerComplete OnMaxMatchWarningTimerComplete;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortGameStatePvE")
	float MaxMatchLength;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortGameStatePvE")
	float EndMatchWarningTime;

};

