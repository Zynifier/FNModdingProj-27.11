// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_SkillsetBase.h"
#include "FortAthenaAISpawnerDataComponent_AIBotSkillset.generated.h"

class UDataTable;
class UFortAthenaAIBotAimingSkillSet;
class UFortAthenaAIBotAttackingSkillSet;
class UFortAthenaAIBotBuildingSkillSet;
class UFortAthenaAIBotDBNOSkillSet;
class UFortAthenaAIBotEmoteSkillSet;
class UFortAthenaAIBotEvasiveManeuversSkillSet;
class UFortAthenaAIBotHarvestSkillSet;
class UFortAthenaAIBotHealingSkillSet;
class UFortAthenaAIBotInventorySkillSet;
class UFortAthenaAIBotLootingSkillSet;
class UFortAthenaAIBotMovementSkillSet;
class UFortAthenaAIBotPerceptionSkillSet;
class UFortAthenaAIBotPlayStyleSkillSet;
class UFortAthenaAIBotPropagateAwarenessSkillSet;
class UFortAthenaAIBotRangeAttackSkillSet;
class UFortAthenaAIBotReactToVerbSkillSet;
class UFortAthenaAIBotReviveSkillSet;
class UFortAthenaAIBotUnstuckSkillSet;
class UFortAthenaAIBotVehicleSkillSet;

UCLASS(MinimalAPI)
class UFortAthenaAISpawnerDataComponent_AIBotSkillset : public UFortAthenaAISpawnerDataComponent_SkillsetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetSkill(const float InSKill);

private:
	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotAimingSkillSet> AimingSkillSet;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotAttackingSkillSet> AttackingSkillSet;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotBuildingSkillSet> BuildingSkillSet;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotDBNOSkillSet> DBNOSkillSet;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotEmoteSkillSet> EmoteSkillSet;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotEvasiveManeuversSkillSet> EvasiveManeuversSkillSet;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotHarvestSkillSet> HarvestSkillSet;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotHealingSkillSet> HealingSkillSet;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotInventorySkillSet> InventorySkillSet;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotLootingSkillSet> LootingSkillSet;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotMovementSkillSet> MovementSkillSet;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotPerceptionSkillSet> PerceptionSkillSet;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotPlayStyleSkillSet> PlayStyleSkillSet;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotPropagateAwarenessSkillSet> PropagateAwarenessSkillSet;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotRangeAttackSkillSet> RangeAttackSkillSet;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotReviveSkillSet> ReviveSkillSet;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotUnstuckSkillSet> UnstuckSkillSet;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotVehicleSkillSet> VehicleSkillSet;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAIBotReactToVerbSkillSet> ReactToVerbSkillSet;

	UPROPERTY(EditDefaultsOnly, Category="SkillLevel", meta=(AllowPrivateAccess="true"))
	uint8 bUseMatchMMRToOverrideSkillLevel : 1;

	UPROPERTY(EditDefaultsOnly, Category="SkillLevel", meta=(AllowPrivateAccess="true", AssetBundles="Server", DisplayAfter="bUseMatchMMRToOverrideSkillLevel", EditCondition="bUseMatchMMRToOverrideSkillLevel"))
	TSoftObjectPtr<UDataTable> OverrideSkillLevelMMRTable;

	UPROPERTY(EditAnywhere, Category="SkillLevel", meta=(AllowPrivateAccess="true", EditCondition="!bUseMatchMMRToOverrideSkillLevel"))
	FScalableFloat Skill;

	UPROPERTY(Transient)
	float SkillOverride;

};

