// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "FortConstructionSet.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortConstructionSet : public UFortAttributeSet
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_BuildCost(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_BuildingSkill(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_BuildSpeed(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxBuildLevel(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_RepairCost(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_RepairSpeed(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_TrapArmSpeed(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_TrapBaseDamage(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_TrapDiceCritChance(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_TrapDiceCritMultiplier(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_TrapHealingSource(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_TrapMaxDurability(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_TrapReloadSpeed(const FFortGameplayAttributeData& OldValue);

private:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_BuildSpeed, Category="Building", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData BuildSpeed;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_RepairSpeed, Category="Building", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData RepairSpeed;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_BuildCost, Category="Building", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData BuildCost;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_RepairCost, Category="Building", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData RepairCost;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxBuildLevel, Category="Building", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData MaxBuildLevel;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_BuildingSkill, Category="Building", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData BuildingSkill;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_TrapArmSpeed, Category="Trap", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData TrapArmSpeed;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_TrapReloadSpeed, Category="Trap", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData TrapReloadSpeed;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_TrapBaseDamage, Category="Trap", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData TrapBaseDamage;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_TrapMaxDurability, Category="Trap", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData TrapMaxDurability;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_TrapDiceCritChance, Category="Trap", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData TrapDiceCritChance;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_TrapDiceCritMultiplier, Category="Trap", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData TrapDiceCritMultiplier;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_TrapHealingSource, Category="Trap", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData TrapHealingSource;

};

