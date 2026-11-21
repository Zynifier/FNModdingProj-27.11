// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortItemQuantityPair.h"
#include "Items/FortAccountItem.h"
#include "FortAlterableItem.generated.h"

class UFortAlterationItemDefinition;

USTRUCT(BlueprintType)
struct FAlterationOption
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSoftObjectPtr<UFortAlterationItemDefinition> AlterationDef;

	UPROPERTY()
	TArray<FFortItemQuantityPair> Costs;

};

UCLASS(MinimalAPI, NotBlueprintable)
class UFortAlterableItem : public UFortAccountItem
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<FString> alterations;

	UPROPERTY()
	TArray<TObjectPtr<UFortAlterationItemDefinition>> AlterationInstances;

};

