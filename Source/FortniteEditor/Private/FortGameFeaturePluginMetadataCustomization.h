// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortReleaseVersion.h"
#include "FortGameFeaturePluginMetadataCustomization.generated.h"

USTRUCT()
struct FFortGameFeaturePluginMetadata
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortGameFeaturePluginMetadata", meta=(DisplayName="Fort Release Version"))
	FFortReleaseVersion ReleaseVersion;

};

