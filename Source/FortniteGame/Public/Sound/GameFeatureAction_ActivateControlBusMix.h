// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameFeatureAction_ActivateControlBusMix.generated.h"

class USoundControlBusMix;

UCLASS(MinimalAPI, meta=(DisplayName="Activate Control Bus Mix"))
class UGameFeatureAction_ActivateControlBusMix : public UGameFeatureAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Mixes", meta=(AssetBundles="Client"))
	TArray<TSoftObjectPtr<USoundControlBusMix>> Mixes;

};

