// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "ValkyrieAssetAdapterActorFactory.h"
#include "ValkyrieAssetAdapterConfig.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Add Asset Adapter"))
class UValkyrieGameFeatureAction_AddAssetAdapter : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Config")
	TArray<FAssetAdapterInfo> AdapterInfos;

};

