// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_PrimaryAssetBehaviors.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Primary Asset Behaviors"))
class UFortGameFeatureAction_PrimaryAssetBehaviors : public UGameFeatureAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Asset Manager")
	TArray<FName> AdditionalPrimaryAssetTypesToLoad;

};

