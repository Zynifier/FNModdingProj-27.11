// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureStateChangeObserver.h"
#include "UObject/NoExportTypes.h"
#include "VkInstallBundleRegistrar.generated.h"

UCLASS()
class VKCONTENTSERVICE_API UVkInstallBundleRegistrar : public UObject, public IGameFeatureStateChangeObserver
{
	GENERATED_BODY()

};

