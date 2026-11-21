// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Commandlets/ResavePackagesCommandlet.h"
#include "FortUpdatePluginDependenciesForGameFeature.generated.h"

UCLASS(Config=Editor)
class UFortUpdateGameFeaturePluginDependenciesCommandlet : public UResavePackagesCommandlet
{
	GENERATED_BODY()

};

