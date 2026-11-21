// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetDataUtilityTool/FortAssetDataUtilityTool.h"
#include "FortAssetDataUtilityTool_CompoundFilters.generated.h"

class UFortAssetDataUtilityToolFilter;

UCLASS(NotBlueprintable)
class UFortAssetDataUtilityToolFilter_All : public UFortAssetDataUtilityToolFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category="FortAssetDataUtilityToolFilter_All")
	TArray<TObjectPtr<UFortAssetDataUtilityToolFilter>> Filters;

};

UCLASS(NotBlueprintable)
class UFortAssetDataUtilityToolFilter_Any : public UFortAssetDataUtilityToolFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category="FortAssetDataUtilityToolFilter_Any")
	TArray<TObjectPtr<UFortAssetDataUtilityToolFilter>> Filters;

};

UCLASS(NotBlueprintable)
class UFortAssetDataUtilityToolFilter_None : public UFortAssetDataUtilityToolFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category="FortAssetDataUtilityToolFilter_None")
	TArray<TObjectPtr<UFortAssetDataUtilityToolFilter>> Filters;

};

