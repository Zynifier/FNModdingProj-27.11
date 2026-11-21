// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Misc/DateTime.h"
#include "Misc/Timespan.h"
#include "Items/FortAccountItem.h"
#include "STW/Expeditions/FortExpeditionItemDefinition.h"
#include "FortExpeditionItem.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortExpeditionItem : public UFortAccountItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Expedition", meta=(DisplayName="GetBonusCriteria"))
	void GetBonusCriteriaBP(TArray<FFortCriteriaRequirementData>& OutBonusCriteria) const;

	UFUNCTION(BlueprintPure, Category="Expedition")
	void GetBonusCriteriaTags(TArray<FGameplayTag>& OutBonusCriteria) const;

	UFUNCTION(BlueprintPure, Category="Expedition")
	FName GetExpeditionSquadId() const;

	UFUNCTION(BlueprintPure, Category="Expedition")
	float GetExpeditionSuccessChance() const;

	UFUNCTION(BlueprintPure, Category="Expedition")
	float GetMinTargetPowerLevelToBegin() const;

	UFUNCTION(BlueprintPure, Category="Expedition")
	FTimespan GetRemainingExpeditionDuration(FDateTime UtcNow) const;

	UFUNCTION(BlueprintPure, Category="Expedition")
	FTimespan GetRemainingExpeditionExpirationDuration(FDateTime UtcNow) const;

	UFUNCTION(BlueprintPure, Category="Expedition")
	float GetTargetPowerLevel() const;

	UFUNCTION(BlueprintPure, Category="Expedition")
	bool HasExpeditionExpired(FDateTime UtcNow) const;

	UFUNCTION(BlueprintPure, Category="Expedition")
	bool IsExpeditionCompleted(FDateTime UtcNow) const;

	UFUNCTION(BlueprintPure, Category="Expedition")
	bool IsExpeditionInProgress() const;

	UPROPERTY()
	int32 expedition_max_target_power;

	UPROPERTY()
	int32 expedition_min_target_power;

	UPROPERTY()
	FDateTime expedition_start_time;

	UPROPERTY()
	FDateTime expedition_end_time;

	UPROPERTY()
	FDateTime expedition_expiration_start_time;

	UPROPERTY()
	FDateTime expedition_expiration_end_time;

	UPROPERTY()
	FString expedition_squad_id;

	UPROPERTY()
	FString expedition_slot_id;

	UPROPERTY()
	TArray<FString> expedition_criteria;

	UPROPERTY()
	float expedition_success_chance;

};

