// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Building/CreatureManagerTypes.h"
#include "Minigame/FortMinigameLogicComponent.h"
#include "FortCreativeCreatureManagerComponent.generated.h"

class AActor;
class AController;
class AFortAIPawn;
class UFortCreativeCreatureManagerComponent;
class UFortCreativeCreatureManagerInfoComponent;
class UGameplayEffect;
class UObject;
class UPrimitiveComponent;
enum class ECreatureManagerAffectedTargets : uint8;
enum class EScoreDistributionType : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreatureClassLoaded, const UClass*, LoadedCreatureClass);

UCLASS(Config=Creative, MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Creative"), meta=(BlueprintSpawnableComponent))
class UFortCreativeCreatureManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnAIPawnDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION(BlueprintCallable)
	void OnInfoComponentAdded(UFortCreativeCreatureManagerInfoComponent* CreatureManagerInfoComponent);

	UFUNCTION(BlueprintCallable)
	void OnInfoComponentRemoved(UFortCreativeCreatureManagerInfoComponent* CreatureManagerInfoComponent);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="OptionData", meta=(EditInline="true"))
	TArray<TObjectPtr<UFortCreativeCreatureManagerInfoComponent>> CreatureManagerInfos;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="OptionData", meta=(EditInline="true"))
	TMap<TSoftClassPtr<AFortAIPawn>, TObjectPtr<UFortCreativeCreatureManagerInfoComponent>> EnabledCreatureManagerInfos;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Creative"), meta=(BlueprintSpawnableComponent))
class UFortCreativeCreatureManagerInfoComponent : public UFortMinigameLogicComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	ECreatureManagerAffectedTargets GetAffectedTargetsType() const;

	UFUNCTION(BlueprintPure)
	TSoftClassPtr<AFortAIPawn> GetCreatureBlueprintClass() const;

	UFUNCTION(BlueprintCallable)
	UFortCreativeCreatureManagerComponent* GetCreatureManagerComponent();

	UFUNCTION(BlueprintPure)
	float GetEnvironmentalDamageOverride() const;

	UFUNCTION(BlueprintPure)
	float GetHearingAggroRange() const;

	UFUNCTION(BlueprintPure)
	float GetInvalidFloat();

	UFUNCTION(BlueprintPure)
	int32 GetInvalidInt32();

	UFUNCTION(BlueprintPure)
	int32 GetMaxHealth() const;

	UFUNCTION(BlueprintPure)
	float GetMovementSpeedMultiplier() const;

	UFUNCTION(BlueprintPure)
	float GetOverrideDamage() const;

	UFUNCTION(BlueprintPure)
	EScoreDistributionType GetScoreDistribution() const;

	UFUNCTION(BlueprintPure)
	int32 GetScorePoints() const;

	UFUNCTION(BlueprintPure)
	bool GetWeaponKnockbackImmunity() const;

	UFUNCTION(BlueprintCallable)
	void ResetEnvironmentalDamageOverride();

	UFUNCTION(BlueprintCallable)
	void ResetHearingAggroRange();

	UFUNCTION(BlueprintCallable)
	void ResetMaxHealth();

	UFUNCTION(BlueprintCallable)
	void ResetMovementSpeedMultiplier();

	UFUNCTION(BlueprintCallable)
	void ResetOverrideDamage();

	UFUNCTION(BlueprintCallable)
	void ResetScoreDistribution();

	UFUNCTION(BlueprintCallable)
	void ResetScorePoints();

	UFUNCTION(BlueprintCallable)
	void ResetWeaponKnockbackImmunity();

	UFUNCTION(BlueprintCallable)
	void SetAffectedTargetsType(ECreatureManagerAffectedTargets InAffectedTargetsType);

	UFUNCTION(BlueprintCallable)
	void SetCreatureBlueprintClass(TSoftClassPtr<AFortAIPawn> InCreatureBlueprintClass);

	UFUNCTION(BlueprintCallable)
	void SetCreatureManagerComponent(UFortCreativeCreatureManagerComponent* InCreatureManagerComponent);

	UFUNCTION(BlueprintCallable)
	void SetDamageOverrideEffect(TSubclassOf<UGameplayEffect> Effect);

	UFUNCTION(BlueprintCallable)
	void SetDamageOverrideTag(FGameplayTag Tag);

	UFUNCTION(BlueprintCallable)
	void SetEnvironmentalDamageOverride(float InOverrideDamage);

	UFUNCTION(BlueprintCallable)
	void SetEnvironmentalDamageOverrideEffect(TSubclassOf<UGameplayEffect> Effect);

	UFUNCTION(BlueprintCallable)
	void SetHearingAggroRange(float InHearingAggroRange);

	UFUNCTION(BlueprintCallable)
	void SetMaxHealth(int32 InMaxHealth);

	UFUNCTION(BlueprintCallable)
	void SetMaxHealthOverrideEffect(TSubclassOf<UGameplayEffect> Effect);

	UFUNCTION(BlueprintCallable)
	void SetMaxHealthOverrideTag(FGameplayTag Tag);

	UFUNCTION(BlueprintCallable)
	void SetMovementOverrideTag(FGameplayTag Tag);

	UFUNCTION(BlueprintCallable)
	void SetMovementSpeedMultiplier(float InOverrideMovementSpeedMultiplier);

	UFUNCTION(BlueprintCallable)
	void SetMovementSpeedOverrideEffect(TSubclassOf<UGameplayEffect> Effect);

	UFUNCTION(BlueprintCallable)
	void SetOverrideDamage(float InOverrideDamage);

	UFUNCTION(BlueprintCallable)
	void SetScoreDistribution(const EScoreDistributionType InScoreDistribution);

	UFUNCTION(BlueprintCallable)
	void SetScorePoints(int32 InScorePoints);

	UFUNCTION(BlueprintCallable)
	void SetWeaponKnockbackImmunity(bool InImmuneToWeaponKnockback);

	UFUNCTION(BlueprintCallable)
	void SetWeaponKnockbackImmunityEffect(TSubclassOf<UGameplayEffect> Effect);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OptionData")
	TSoftClassPtr<AFortAIPawn> CreatureBlueprintClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OptionData")
	int32 MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OptionData")
	float HearingAggroRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OptionData")
	int32 ScorePoints;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OptionData")
	float DamageCaused;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OptionData")
	float EnvironmentalDamageOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OptionData")
	float MovementSpeedMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OptionData")
	bool bImmuneToWeaponKnockback;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="OptionData", meta=(EditInline="true"))
	TObjectPtr<UFortCreativeCreatureManagerComponent> CreatureManagerComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeCreatureManagerInfoComponent")
	TSubclassOf<UGameplayEffect> DamageOverrideEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeCreatureManagerInfoComponent")
	TSubclassOf<UGameplayEffect> EnvironmentalDamageOverrideEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeCreatureManagerInfoComponent")
	TSubclassOf<UGameplayEffect> MovementSpeedOverrideEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeCreatureManagerInfoComponent")
	TSubclassOf<UGameplayEffect> WeaponKnockbackImmunityEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeCreatureManagerInfoComponent")
	TSubclassOf<UGameplayEffect> MaxHealthOverrideEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OptionData")
	EScoreDistributionType ScoreDistribution;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OptionData")
	ECreatureManagerAffectedTargets AffectedTargetsType;

};

