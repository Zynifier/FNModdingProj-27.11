// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "Athena/Modifiers/SpecialRelevancyComponentBase.h"
#include "SpecialRelevancyHealthComponent.generated.h"

class AActor;
class AFortAthenaMutator_SpecialRelevancy;
class AFortPlayerState;
class UDamageRecordEntry;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SevenParams(FOnSpecialRelevancyDamage, const AFortPlayerState*, InstigatingPlayerState, const FGameplayEffectContextHandle, EffectContext, const FGameplayCueParameters, GameplayCueParams, const int32, RelevancyGroupIndex, const float, DealtDamage, const FGameplayTagContainer&, DeathTags, const bool, bKilled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpecialRelevancyDeath, const FGameplayTagContainer, DamageTags);

UCLASS(DefaultToInstanced)
class UDamageRecordEntry : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_DamageTotal();

	UPROPERTY(ReplicatedUsing=OnRep_DamageTotal)
	float DamageTotal;

	UPROPERTY(Replicated)
	float EndReplicationTime;

	UPROPERTY(Replicated)
	FGameplayTagContainer DamageTags;

	UPROPERTY(Replicated)
	FGameplayEffectContextHandle EffectContext;

	UPROPERTY()
	FGameplayCueParameters GameplayCueParams;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Activation", "AssetUserData", "Collision", "ComponentReplication", "ComponentTick", "Cooking", "Tags"), meta=(BlueprintSpawnableComponent))
class USpecialRelevancyHealthComponent : public USpecialRelevancyComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float ClientGetHealth() const;

	UFUNCTION(BlueprintPure)
	float ClientGetHealthPercent() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	float GetHealth(const AActor* RelevancyActor) const;

	UFUNCTION(BlueprintPure)
	float GetHealthFromRelevancyIndex(int32 Index) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	float GetHealthPercent(const AActor* RelevancyActor) const;

	UFUNCTION(BlueprintPure)
	float GetHealthPercentFromRelevancyIndex(int32 Index) const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDamaged(const AFortPlayerState* DamagingPlayerState, const int32 RelevancyGroupIndex, const float DealtDamage, const float ActualDealtDamage, const float TotalDamage, const float DealtDamagePercent, const float ActualDealtDamagePercent, const float TotalDamagePercent, const float MaxHealth, const bool bKilled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnKilled(const AFortPlayerState* KillingPlayerState, const int32 RelevancyGroupIndex);

	UPROPERTY(EditAnywhere, Category="SpecialRelevancyHealthComponent")
	FScalableFloat RelevancyDeathTimeLength;

	UPROPERTY(EditAnywhere, Category="SpecialRelevancyHealthComponent")
	bool bSetLifespanOnLastRelevancyDeath;

	UPROPERTY(Replicated)
	float OwnerMaxHealthCached;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UDamageRecordEntry>> ReplicatedDamageRecords;

	UPROPERTY(BlueprintAssignable)
	FOnSpecialRelevancyDeath OnSpecialRelevancyDeath;

	UPROPERTY(BlueprintAssignable)
	FOnSpecialRelevancyDamage OnSpecialRelevancyDamage;

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaMutator_SpecialRelevancy> CachedMutator;

};

