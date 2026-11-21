// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ScalableFloat.h"
#include "FortAthenaMutator_SpawningPolicyData.generated.h"

class UEnvQuery;

UCLASS(Abstract, EditInlineNew, BlueprintType)
class UFortAthenaMutator_SpawningPolicyData : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	FScalableFloat NumItemsToSpawn;

	UPROPERTY(EditDefaultsOnly, Category="Placement", meta=(AllowPrivateAccess="true"))
	TSoftObjectPtr<UEnvQuery> ItemPlacementQuery;

	UPROPERTY(EditDefaultsOnly, Category="Removal", meta=(AllowPrivateAccess="true"))
	TSoftObjectPtr<UEnvQuery> ItemRemovalQuery;

	UPROPERTY(EditDefaultsOnly, Category="Removal", meta=(AllowPrivateAccess="true", ClampMin="0.000000", UIMin="0.000000"))
	float RemovalQueryInterval;

};

