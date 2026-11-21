// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_PhysicsObjectSetupData.generated.h"

class UFortPluginPhysicsObjectAssetSetupData;

UCLASS(MinimalAPI, meta=(DisplayName="Physics Object Setup Data"))
class UFortGameFeatureAction_PhysicsObjectSetupData : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Instanced, Category="Physics Objects|Setup Data")
	TObjectPtr<UFortPluginPhysicsObjectAssetSetupData> SetupAsset;

};

