// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCreativeBudgeter.h"
#include "FortCreativeBudgetTracker.generated.h"

class UObject;

USTRUCT()
struct FFortCreativeBudgetTracker
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<FFortCreativeBudget> Budgets;

	UPROPERTY()
	TArray<uint32> AssetInstances;

	UPROPERTY()
	TArray<uint32> AssetLastInstances;

private:
	UPROPERTY(Transient, NotReplicated)
	TMap<TSoftObjectPtr<UObject>, int32> UsedAssetDependencies;

	UPROPERTY()
	bool bUseMapProjectionForBounds;

};

