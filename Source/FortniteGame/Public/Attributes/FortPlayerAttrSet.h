// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TickableAttributeSetInterface.h"
#include "Attributes/FortAttributeSet.h"
#include "FortPlayerAttrSet.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortPlayerAttrSet : public UFortAttributeSet, public ITickableAttributeSetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_BuildCostModifier(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_BuildSpeedModifier(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_CraftingTimeMultiplier(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_CraftItemLevelBonusMax(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_CraftItemLevelBonusMin(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_DoubleCraftChance(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_DoubleItemLootChance(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_DoubleLootRollChance(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_ExtraLives(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Fortitude_Team(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_HarvestingTool(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_ItemMaxStack(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_ItemRegenCooldown(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_ItemRegenMaxStack(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxStamina(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Offense_Team(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Resistance_Team(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_ResourceHarvesting(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_ResurrectTeammateDuration(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_SprintCost(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Stamina(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_StaminaCost(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_StaminaRegenDelay(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_StaminaRegenRate(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Tech_Team(const FFortGameplayAttributeData& OldValue);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Stamina, Category="Stamina", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData Stamina;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_StaminaRegenRate, Category="Stamina", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData StaminaRegenRate;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_StaminaRegenDelay, Category="Stamina", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData StaminaRegenDelay;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxStamina, Category="Stamina", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData MaxStamina;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_StaminaCost, Category="Stamina", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData StaminaCost;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_SprintCost, Category="Stamina", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData SprintCost;

	UPROPERTY(meta=(HideFromModifiers))
	FFortGameplayAttributeData ActiveEffectDuration;

	virtual void Tick(float DeltaTime) override;

	virtual bool ShouldTick() const override;

private:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ItemRegenMaxStack, Category="Item", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ItemRegenMaxStack;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ItemRegenCooldown, Category="Item", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ItemRegenCooldown;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ItemMaxStack, Category="Item", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ItemMaxStack;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_DoubleLootRollChance, Category="Loot", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData DoubleLootRollChance;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_DoubleItemLootChance, Category="Loot", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData DoubleItemLootChance;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_DoubleCraftChance, Category="Crafting", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData DoubleCraftChance;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CraftingTimeMultiplier, Category="Crafting", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData CraftingTimeMultiplier;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CraftItemLevelBonusMin, Category="Crafting", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData CraftItemLevelBonusMin;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CraftItemLevelBonusMax, Category="Crafting", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData CraftItemLevelBonusMax;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ResourceHarvesting, Category="Harvesting", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ResourceHarvesting;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_HarvestingTool, Category="Harvesting", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData HarvestingTool;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ExtraLives, Category="Resurrection", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ExtraLives;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ResurrectTeammateDuration, Category="Resurrection", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ResurrectTeammateDuration;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Fortitude_Team, Category="Meta Stats", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData Fortitude_Team;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Offense_Team, Category="Meta Stats", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData Offense_Team;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Tech_Team, Category="Meta Stats", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData Tech_Team;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Resistance_Team, Category="Meta Stats", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData Resistance_Team;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Turbo Building", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData TurboBuildFirstInterval;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Turbo Building", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData TurboBuildInterval;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_BuildSpeedModifier, Category="Building Modifier", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData BuildSpeedModifier;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_BuildCostModifier, Category="Building Modifier", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData BuildCostModifier;

};

