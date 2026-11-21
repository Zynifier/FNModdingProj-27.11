// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "Engine/DataAsset.h"
#include "FortGameDeathPenalty.generated.h"

class UCurveFloat;

UCLASS(BlueprintType, Blueprintable)
class UFortGameDeathPenalty : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemDrops")
	float PercentResourcesToDrop;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemDrops")
	float PercentWeaponsToDrop;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemDrops")
	float PercentCraftingIngredientsToDrop;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemDrops")
	float PercentConsumablesToDrop;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemDrops")
	float PercentAmmoToDrop;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemRecovery")
	float PercentResourcesToRecover;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemRecovery")
	float PercentWeaponsToRecover;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemRecovery")
	float PercentCraftingIngredientsToRecover;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemRecovery")
	float PercentConsumablesToRecover;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemRecovery")
	float PercentAmmoToRecover;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Minimums")
	int32 MinResourcesToKeep;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Minimums")
	int32 MinWeaponsToKeep;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Minimums")
	int32 MinCraftingIngredientsToKeep;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Minimums")
	int32 MinConsumablesToKeep;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Minimums")
	int32 MinAmmoToKeep;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Respawn")
	FCurveTableRowHandle RespawnDelays;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Respawn")
	TObjectPtr<UCurveFloat> RespawnDelayOverTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Respawn")
	float MaxRespawnDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Respawn")
	float MinSelfResurrectDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Respawn")
	bool bUseRegenHealthOnRespawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Respawn")
	float PercentHealthOnRespawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Respawn")
	float PercentShieldOnRespawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Respawn")
	float PercentStaminaOnRespawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RespawnPenalty")
	float RespawnDurabilityPenalty;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RespawnPenalty")
	float SelfResurrectDurabilityPenalty;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RespawnPenalty")
	float TeammateResurrectDurabilityPenalty;

};

