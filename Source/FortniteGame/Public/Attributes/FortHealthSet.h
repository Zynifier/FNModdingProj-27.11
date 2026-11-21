// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "FortHealthSet.generated.h"

class UFortHealthSet;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_FourParams(FOnDamageDoneOverrideSignature, UFortHealthSet*, HealthSet, float, RawDamageDone, float&, DamageDone, float&, HealthModification);

UCLASS(MinimalAPI, BlueprintType)
class UFortHealthSet : public UFortAttributeSet
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ClearDamageDoneOverrideDelegate();

	UFUNCTION(BlueprintCallable)
	static bool IsTacticalOvershieldEnabled();

	UFUNCTION()
	void OnRep_BlockedDamage(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_CurrentOvershield(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_CurrentShield(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Health(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxHealth(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxOvershield(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxSignalInStorm(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Shield(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_SignalInStorm(const FFortGameplayAttributeData& OldValue);

	UFUNCTION(BlueprintCallable)
	void SetDamageDoneOverrideDelegate(FOnDamageDoneOverrideSignature InOnDamageDoneOverrideDelegate);

	UPROPERTY(BlueprintReadOnly, Category="Health")
	FFortGameplayAttributeData Damage;

	UPROPERTY(BlueprintReadOnly, Category="Health")
	FFortGameplayAttributeData ShieldDamage;

	UPROPERTY(BlueprintReadOnly, Category="Health")
	FFortGameplayAttributeData OvershieldDamage;

	UPROPERTY(BlueprintReadOnly, Category="Health", meta=(HideFromLevelInfos))
	FFortGameplayAttributeData Healing;

private:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health, Category="Health", meta=(AllowPrivateAccess="TRUE", HideFromModifiers))
	FFortGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxHealth, Category="Health", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData MaxHealth;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Shield, Category="Health", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData Shield;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CurrentShield, Category="Health", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData CurrentShield;

	UPROPERTY(ReplicatedUsing=OnRep_MaxOvershield)
	FFortGameplayAttributeData MaxOvershield;

	UPROPERTY(ReplicatedUsing=OnRep_CurrentOvershield)
	FFortGameplayAttributeData CurrentOvershield;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_SignalInStorm, Category="Health", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData SignalInStorm;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxSignalInStorm, Category="Health", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData MaxSignalInStorm;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Damage", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData Armor;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Damage", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData DamageResistance;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Damage", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData DamageVulnerability;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Damage", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData ReflectDamageAbsolute;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Damage", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData ReflectDamageFromSource;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Damage", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData DamageReduction;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Health", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData HealingSourceBaseMultiplier;

	UPROPERTY(Replicated)
	FFortGameplayAttributeData DamageScaleLight;

	UPROPERTY(Replicated)
	FFortGameplayAttributeData DamageScaleNormal;

	UPROPERTY(Replicated)
	FFortGameplayAttributeData DamageScaleCritical;

	UPROPERTY(Replicated)
	FFortGameplayAttributeData DamageScaleVulnerable;

	UPROPERTY(Replicated)
	FFortGameplayAttributeData DamageScaleInvulnerable;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Health", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData HealingSource;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Health", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData HealingBonusTarget;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Blocking", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData BlockingAngle;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Blocking", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData BlockingDamageResistance;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Blocking", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData DamageResistanceCap;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_BlockedDamage, Category="Blocking", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData BlockedDamage;

};

