// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "Attributes/FortBuildingActorSet.h"
#include "FortBuildingTrapSet.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortBuildingTrapSet : public UFortBuildingActorSet
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_Durability();

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Durability, Category="Trap", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData Durability;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Trap", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData MaxDurability;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Trap", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData DurabilityCostPerFire;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Trap", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData ArmTime;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Trap", meta=(AllowPrivateAccess="TRUE"))
	FFortGameplayAttributeData ReloadTime;

};

