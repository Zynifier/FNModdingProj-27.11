// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "FortDamageSet.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortDamageSet : public UFortAttributeSet
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_DiceCritChance(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_DiceCritMultiplier(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_HealthDamageScale(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_KnockbackMagnitude(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_KnockbackZAngle(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_OutgoingAbilityDamage(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_OutgoingBaseAbilityDamageMultiplier(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_OutgoingBaseDamage(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_OutgoingBaseEnvironmentalDamage(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_OutgoingBaseImpactDamage(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_ShieldDamageScale(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_StunTime(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponSkill(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_ZoneCritMultiplier(const FFortGameplayAttributeData& OldValue);

	UPROPERTY(BlueprintReadOnly, Category="Damage")
	FFortGameplayAttributeData CritRating;

	UPROPERTY(BlueprintReadOnly, Category="Damage")
	FFortGameplayAttributeData MaxMeleeComboLevel;

private:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_OutgoingBaseDamage, Category="Damage", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData OutgoingBaseDamage;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_OutgoingBaseEnvironmentalDamage, Category="Damage", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData OutgoingBaseEnvironmentalDamage;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_OutgoingBaseImpactDamage, Category="Damage", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData OutgoingBaseImpactDamage;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_OutgoingAbilityDamage, Category="Damage", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData OutgoingAbilityDamage;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_OutgoingBaseAbilityDamageMultiplier, Category="Damage", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData OutgoingBaseAbilityDamageMultiplier;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ZoneCritMultiplier, Category="Damage", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ZoneCritMultiplier;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_DiceCritChance, Category="Damage", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData DiceCritChance;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_DiceCritMultiplier, Category="Damage", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData DiceCritMultiplier;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_KnockbackMagnitude, Category="Damage", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData KnockbackMagnitude;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_KnockbackZAngle, Category="Damage", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData KnockbackZAngle;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_StunTime, Category="Damage", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData StunTime;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponSkill, Category="Damage", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponSkill;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ShieldDamageScale, Category="Damage", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ShieldDamageScale;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_HealthDamageScale, Category="Damage", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData HealthDamageScale;

};

