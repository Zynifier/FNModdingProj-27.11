// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetRegistry/ARFilter.h"
#include "AssetDataUtilityTool/FortAssetDataUtilityTool.h"
#include "FortAssetDataUtilityToolGatherer_ARFilter.generated.h"

UCLASS(NotBlueprintable, meta=(DisplayName="Gather by Asset Registry Filter"))
class UFortAssetDataUtilityToolGatherer_ARFilter : public UFortAssetDataUtilityToolGatherer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolGatherer_ARFilter")
	FARFilter AssetRegistryFilter;

};

