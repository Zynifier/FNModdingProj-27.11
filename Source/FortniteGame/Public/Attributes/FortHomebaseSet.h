// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "FortHomebaseSet.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortHomebaseSet : public UFortAttributeSet
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_InventorySizeBonus(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Keep_AmmoStash_Level(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Keep_Armory_Level(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Keep_Level(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Keep_Medical_Level(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Keep_PermaniteCap(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Keep_Storage_Level(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Keep_StructureCap(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Keep_Workshop_Level(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Manor_Level(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Manor_StructureCap(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_max_capacity_collector_Token_collectionresource_nodegatetoken01(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxLevelBonus_Alterations(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxLevelBonus_Global(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxLevelBonus_Personnel(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxLevelBonus_Schematics(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxLevelBonus_Schematics_Melee(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxLevelBonus_Schematics_Ranged(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxLevelBonus_Schematics_Traps(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_rate_per_second_collector_Token_collectionresource_nodegatetoken01(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_ResearchPointMaxBonus(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_StorageInventorySizeBonus(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_SupplyDrop_Level(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_SupplyDrop_Magnitude(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WorldInventorySizeBonus(const FFortGameplayAttributeData& OldValue);

	UPROPERTY(BlueprintReadOnly, Category="Homebase")
	FFortGameplayAttributeData ExpeditionSquadOne_Power;

	UPROPERTY(BlueprintReadOnly, Category="Homebase")
	FFortGameplayAttributeData ExpeditionSquadTwo_Power;

	UPROPERTY(BlueprintReadOnly, Category="Homebase")
	FFortGameplayAttributeData ExpeditionSquadThree_Power;

	UPROPERTY(BlueprintReadOnly, Category="Homebase")
	FFortGameplayAttributeData ExpeditionSquadFour_Power;

	UPROPERTY(BlueprintReadOnly, Category="Homebase")
	FFortGameplayAttributeData ExpeditionSquadFive_Power;

	UPROPERTY(BlueprintReadOnly, Category="Homebase")
	FFortGameplayAttributeData ExpeditionSquadSix_Power;

private:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Keep_Level, Category="Homebase", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData Keep_Level;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Keep_AmmoStash_Level, Category="Homebase", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData Keep_AmmoStash_Level;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Keep_Armory_Level, Category="Homebase", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData Keep_Armory_Level;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Keep_Medical_Level, Category="Homebase", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData Keep_Medical_Level;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Keep_Storage_Level, Category="Homebase", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData Keep_Storage_Level;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Keep_Workshop_Level, Category="Homebase", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData Keep_Workshop_Level;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Keep_StructureCap, Category="Homebase", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData Keep_StructureCap;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Keep_PermaniteCap, Category="Homebase", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData Keep_PermaniteCap;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Manor_Level, Category="Homebase", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData Manor_Level;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Manor_StructureCap, Category="Homebase", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData Manor_StructureCap;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_InventorySizeBonus, Category="Homebase", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData InventorySizeBonus;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WorldInventorySizeBonus, Category="Homebase", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WorldInventorySizeBonus;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_StorageInventorySizeBonus, Category="Homebase", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData StorageInventorySizeBonus;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ResearchPointMaxBonus, Category="Homebase", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ResearchPointMaxBonus;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxLevelBonus_Global, Category="MaxLevel", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData MaxLevelBonus_Global;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxLevelBonus_Schematics, Category="MaxLevel", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData MaxLevelBonus_Schematics;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxLevelBonus_Schematics_Ranged, Category="MaxLevel", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData MaxLevelBonus_Schematics_Ranged;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxLevelBonus_Schematics_Melee, Category="MaxLevel", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData MaxLevelBonus_Schematics_Melee;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxLevelBonus_Schematics_Traps, Category="MaxLevel", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData MaxLevelBonus_Schematics_Traps;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxLevelBonus_Personnel, Category="MaxLevel", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData MaxLevelBonus_Personnel;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxLevelBonus_Alterations, Category="MaxLevel", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData MaxLevelBonus_Alterations;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_rate_per_second_collector_Token_collectionresource_nodegatetoken01, Category="Homebase", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData rate_per_second_collector_Token_collectionresource_nodegatetoken01;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_max_capacity_collector_Token_collectionresource_nodegatetoken01, Category="Homebase", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData max_capacity_collector_Token_collectionresource_nodegatetoken01;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_SupplyDrop_Magnitude, Category="Homebase", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData SupplyDrop_Magnitude;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_SupplyDrop_Level, Category="Homebase", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData SupplyDrop_Level;

};

