// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Attributes/FortAttributeSet.h"
#include "FortBuildingEnergyComponent.generated.h"

class UFortBuildingEnergyComponentAttrSet;
class UGameplayAbility;

UCLASS(BlueprintType, Blueprintable)
class UFortBuildingEnergyComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Energy")
	void OnCurrentEnergyAttributesChanged();

	UFUNCTION(BlueprintCallable, Category="Energy")
	void UpdateCurrentEnergyLevelAttr(float NewEnergyLevel);

	UFUNCTION(BlueprintCallable, Category="Energy")
	void UpdateEnergyCapacityAttr(float NewEnergyCapacity);

	UFUNCTION(BlueprintCallable, Category="Energy")
	void UpdateEnergyCostAttr(float NewEnergyCost);

	UFUNCTION(BlueprintCallable, Category="Energy")
	void UpdateEnergyRechargeDelayAttr(float NewEnergyRechargeDelay);

	UFUNCTION(BlueprintCallable, Category="Energy")
	void UpdateRegenRateAttr(float NewRegenRate);

protected:
	UFUNCTION()
	void OnRep_EnergyAttrSet();

	UPROPERTY(ReplicatedUsing=OnRep_EnergyAttrSet, Export, meta=(EditInline="true"))
	TObjectPtr<UFortBuildingEnergyComponentAttrSet> EnergyComponentAttrSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Abilities")
	TSubclassOf<UGameplayAbility> EnergyComponentRechargeAbility;

};

UCLASS(BlueprintType)
class UFortBuildingEnergyComponentAttrSet : public UFortAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CurrentEnergyLevel, Category="Energy")
	FFortGameplayAttributeData CurrentEnergyLevel;

	UPROPERTY(BlueprintReadOnly, Category="Energy")
	FFortGameplayAttributeData RegenRate;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Energy")
	FFortGameplayAttributeData EnergyCost;

	UPROPERTY(BlueprintReadOnly, Category="Energy")
	FFortGameplayAttributeData EnergyRechargeDelay;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_EnergyCapacity, Category="Energy")
	FFortGameplayAttributeData EnergyCapacity;

protected:
	UFUNCTION()
	void OnRep_CurrentEnergyLevel(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_EnergyCapacity(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_EnergyCost(const FFortGameplayAttributeData& OldValue);

};

