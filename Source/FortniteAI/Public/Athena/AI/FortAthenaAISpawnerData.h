// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/FortAthenaSpawnerDataBase.h"
#include "FortAthenaAISpawnerData.generated.h"

class UFortAthenaAISpawnerData;
class UFortAthenaAISpawnerDataComponent;
class UFortAthenaAISpawnerDataComponentList;
class UFortAthenaAISpawnerDataComponent_AffiliationBase;
class UFortAthenaAISpawnerDataComponent_AnalyticBase;
class UFortAthenaAISpawnerDataComponent_BehaviorBase;
class UFortAthenaAISpawnerDataComponent_ChanceEncounterBase;
class UFortAthenaAISpawnerDataComponent_ConversationBase;
class UFortAthenaAISpawnerDataComponent_CosmeticBase;
class UFortAthenaAISpawnerDataComponent_DebugBase;
class UFortAthenaAISpawnerDataComponent_GameplayAbilityBase;
class UFortAthenaAISpawnerDataComponent_GameplayBase;
class UFortAthenaAISpawnerDataComponent_GroupBase;
class UFortAthenaAISpawnerDataComponent_InventoryBase;
class UFortAthenaAISpawnerDataComponent_LODBase;
class UFortAthenaAISpawnerDataComponent_OptimBase;
class UFortAthenaAISpawnerDataComponent_PerceptionBase;
class UFortAthenaAISpawnerDataComponent_ScriptBase;
class UFortAthenaAISpawnerDataComponent_SmartObjectBase;
class UFortAthenaAISpawnerDataComponent_SpawnParamsBase;
class UFortAthenaAISpawnerDataComponent_TokenBase;
class UFortAthenaAISpawnerDataComponent_VoiceBase;
class UObject;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAISpawnerData : public UFortAthenaSpawnerDataBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponentList* CreateComponentList(UObject* OuterObject) const;

	UFUNCTION(BlueprintCallable)
	static UFortAthenaAISpawnerDataComponentList* CreateComponentListFromClass(const TSubclassOf<UFortAthenaAISpawnerData> AISpawnerDataClass, UObject* OuterObject);

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_AffiliationBase* GetAffiliationComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_LODBase* GetAILODComponent() const;

	UFUNCTION(BlueprintPure)
	virtual UFortAthenaAISpawnerDataComponent_AnalyticBase* GetAnalyticComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_BehaviorBase* GetBehaviorComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_ChanceEncounterBase* GetChanceEncounterComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_ConversationBase* GetConversationComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_CosmeticBase* GetCosmeticComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_DebugBase* GetDebugComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_GameplayAbilityBase* GetGameplayAbilityComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_GameplayBase* GetGameplayComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_GroupBase* GetGroupComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_InventoryBase* GetInventoryComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_OptimBase* GetOptimizationComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_PerceptionBase* GetPerceptionComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_ScriptBase* GetScriptComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_SmartObjectBase* GetSmartObjectComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_SpawnParamsBase* GetSpawnParamsComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_TokenBase* GetTokenComponent() const;

	UFUNCTION(BlueprintPure)
	UFortAthenaAISpawnerDataComponent_VoiceBase* GetVoiceComponent() const;

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="Editor Scripting | AI Spawner Data")
	void SetAffiliationComponent(UFortAthenaAISpawnerDataComponent_AffiliationBase* NewAffiliationComponent);
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="Editor Scripting | AI Spawner Data")
	void SetConversationComponent(UFortAthenaAISpawnerDataComponent_ConversationBase* NewConversationComponent);
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="Editor Scripting | AI Spawner Data")
	void SetCosmeticComponent(UFortAthenaAISpawnerDataComponent_CosmeticBase* NewCosmeticComponent);
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="Editor Scripting | AI Spawner Data")
	void SetGameplayAbilityComponent(UFortAthenaAISpawnerDataComponent_GameplayAbilityBase* NewGameplayAbilityComponent);
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="Editor Scripting | AI Spawner Data")
	void SetGameplayComponent(UFortAthenaAISpawnerDataComponent_GameplayBase* NewGameplayComponent);
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="Editor Scripting | AI Spawner Data")
	void SetInventoryComponent(UFortAthenaAISpawnerDataComponent_InventoryBase* NewInventoryComponent);
#endif

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortAthenaAISpawnerDataComponent>> ClassComponentList;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_InventoryBase> InventoryComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_SpawnParamsBase> SpawnParamsComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_BehaviorBase> BehaviorComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_AffiliationBase> AffiliationComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_LODBase> LODComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_DebugBase> DebugComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_AnalyticBase> AnalyticComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_GameplayBase> GameplayComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_ConversationBase> ConversationComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_VoiceBase> VoiceComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_CosmeticBase> CosmeticComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_ChanceEncounterBase> ChanceEncounterComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_OptimBase> OptimizationComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_GameplayAbilityBase> GameplayAbilityComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_PerceptionBase> PerceptionComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_SmartObjectBase> SmartObjectComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_GroupBase> GroupComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_ScriptBase> ScriptComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerDataComponent_TokenBase> TokenComponent;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(AllowPrivateAccess="true"))
	FScalableFloat SpawnIntervalOverride;

};

