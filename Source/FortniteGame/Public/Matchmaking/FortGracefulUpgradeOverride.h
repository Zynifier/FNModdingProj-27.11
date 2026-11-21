// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "UObject/NoExportTypes.h"
#include "FortGracefulUpgradeOverride.generated.h"

UCLASS()
class UEmptyUpdater : public UObject
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, meta=(DisplayName="Overrides Graceful Upgrade Logic"))
class UFortGameFeatureAction_OverrideGracefulUpgradeLogic : public UGameFeatureAction
{
	GENERATED_BODY()

};

