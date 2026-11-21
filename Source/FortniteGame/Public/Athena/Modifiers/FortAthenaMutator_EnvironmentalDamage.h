// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Athena/Modifiers/FortAthenaMutator_EnvironmentalDamageTypes.h"
#include "FortAthenaMutator_EnvironmentalDamage.generated.h"

enum class EEnvironmentDamageFilter : uint8;

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_EnvironmentalDamage : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	EEnvironmentDamageFilter GetDamageFilterFromValue(float Value) const;

	UFUNCTION(BlueprintPure)
	float GetValueFromDamageFilter(EEnvironmentDamageFilter DamageFilter) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator")
	FGameplayTagQuery DamageTagQuery;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator")
	float DamageMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator")
	bool bExcludeActorsAddedToVolume;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="Mutator")
	float WorldActivationTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator")
	EBuildingDamageTeamFilter TeamDamageFilter;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator")
	EEnvironmentDamageFilter EnvironmentDamageFilter;

};

