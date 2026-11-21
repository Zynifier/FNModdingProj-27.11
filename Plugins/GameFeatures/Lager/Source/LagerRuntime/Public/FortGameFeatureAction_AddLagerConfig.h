// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortAthenaLivingWorldManager.h"
#include "FortGameFeatureAction_AddLagerConfig.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Add Lager Config"))
class UFortGameFeatureAction_AddLagerConfig : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Config")
	TArray<FFortLivingWorldConfigOverride> LagerConfigOverrides;

};

