// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Building/BuildingProp.h"
#include "Building/CreatureManagerTypes.h"
#include "BuildingProp_CreatureManager.generated.h"

class AActor;
class AController;
class AFortAIPawn;
class AFortMinigame;
class UFortCreativeCreatureManagerInfoComponent;
class UFortGameplayTriggerMessageComponent;
class UGameplayEffect;
class UMaterialInterface;
class USkeletalMesh;
class UStaticMeshComponent;
enum class EFortMinigameState : uint8;

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ABuildingProp_CreatureManager : public ABuildingProp
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AdjustCollisionOfStaticMesh(bool bIgnore, UStaticMeshComponent* Mesh);

	UFUNCTION(BlueprintCallable)
	void LoadSkeletalMeshDisplayOption();

	UFUNCTION(BlueprintNativeEvent)
	void MinigameStateChange(AFortMinigame* Minigame, EFortMinigameState NewMinigameState);

	UFUNCTION(BlueprintCallable)
	void NotifyDeviceEnableChanged(const bool bEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnManagedCreatureDied(AController* InstigatingController, AActor* DamagedActor);

	UFUNCTION(BlueprintImplementableEvent)
	void SetupConfigurables();

	UFUNCTION(BlueprintImplementableEvent)
	void SkeletalMeshLoadComplete(UMaterialInterface* Material, USkeletalMesh* Mesh);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CustomizeOptions")
	TArray<TSoftClassPtr<AFortAIPawn>> AITypeOptions;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_CreatureManager")
	TSoftClassPtr<AFortAIPawn> SelectedAIType;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_CreatureManager")
	float SelectedOverrideAggroDistance;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_CreatureManager")
	int32 SelectedOverrideHealth;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_CreatureManager")
	int32 SelectedOverrideScoreValue;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_CreatureManager")
	EScoreDistributionType SelectedOverrideScoreDistribution;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_CreatureManager")
	ECreatureManagerAffectedTargets SelectedAffectedTargetsType;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_CreatureManager")
	float SelectedOverrideDamage;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_CreatureManager")
	float SelectedEnvironmentalDamageOverride;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_CreatureManager")
	float SelectedMovementSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="BuildingProp_CreatureManager")
	TSubclassOf<UGameplayEffect> DamageOverrideEffect;

	UPROPERTY(EditDefaultsOnly, Category="BuildingProp_CreatureManager")
	TSubclassOf<UGameplayEffect> EnvironmentalDamageOverrideEffect;

	UPROPERTY(EditDefaultsOnly, Category="BuildingProp_CreatureManager")
	TSubclassOf<UGameplayEffect> MovementSpeedOverrideEffect;

	UPROPERTY(EditDefaultsOnly, Category="BuildingProp_CreatureManager")
	TSubclassOf<UGameplayEffect> MaxHealthOverrideEffect;

	UPROPERTY(EditDefaultsOnly, Category="BuildingProp_CreatureManager")
	FGameplayTag DamageOverrideTag;

	UPROPERTY(EditDefaultsOnly, Category="BuildingProp_CreatureManager")
	FGameplayTag MovementOverrideTag;

	UPROPERTY(EditDefaultsOnly, Category="BuildingProp_CreatureManager")
	FGameplayTag MaxHealthOverrideTag;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_CreatureManager")
	bool bImmuneToWeaponKnockback;

	UPROPERTY(EditDefaultsOnly, Category="BuildingProp_CreatureManager")
	TSubclassOf<UGameplayEffect> WeaponKnockbackImmunityEffect;

protected:
	UFUNCTION()
	void CreatureManagerComponentAIHasDied(AController* InstigatingController, AActor* FortAIPawn);

	UPROPERTY(BlueprintReadWrite, Export, Category="BuildingProp_CreatureManager", meta=(EditInline="true"))
	TObjectPtr<UFortCreativeCreatureManagerInfoComponent> CreatureInfoComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="BuildingProp_CreatureManager", meta=(EditInline="true"))
	TObjectPtr<UFortGameplayTriggerMessageComponent> CreatureAIDiedTriggerComponent;

};

