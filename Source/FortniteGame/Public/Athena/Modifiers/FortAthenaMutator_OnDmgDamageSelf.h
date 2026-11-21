// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_OnDmgDamageSelf.generated.h"

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_OnDmgDamageSelf : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="OnDmgDamageSelfValues")
	float DamageToDeal;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="OnDmgDamageSelfValues")
	bool bRequiresNonZeroDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="OnDmgDamageSelfValues")
	int32 TargetQueryIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="OnDmgDamageSelfValues")
	int32 WeaponQueryIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="OnDmgDamageSelfValues")
	TArray<FGameplayTagQuery> TargetQueries;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="OnDmgDamageSelfValues")
	TArray<FGameplayTagQuery> WeaponQueries;

};

