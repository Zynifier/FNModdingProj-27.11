// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator_SpawningPolicyData.h"
#include "FortAthenaMutator_SupplyDropSpawningPolicyData.generated.h"

class AFortGameStateAthena;
class UFortSupplyDropInfo;

UCLASS(BlueprintType)
class UFortAthenaMutator_SupplyDropSpawningPolicyData : public UFortAthenaMutator_SpawningPolicyData
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Placement", meta=(AllowPrivateAccess="true", AssetBundles="Zone"))
	TSoftObjectPtr<UFortSupplyDropInfo> SupplyDropInfo;

	UPROPERTY(Transient)
	TObjectPtr<AFortGameStateAthena> CachedGameState;

};

