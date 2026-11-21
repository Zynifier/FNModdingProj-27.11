// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetDataUtilityTool/FortAssetDataUtilityTool.h"
#include "FortReleaseVersion.h"
#include "FortAssetDataUtilityToolFilter_ReleaseVersion.generated.h"

USTRUCT(BlueprintType)
struct FFortReleaseVersionBound
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortReleaseVersionBound")
	FFortReleaseVersion ReleaseVersion;

	UPROPERTY(EditAnywhere, Category="FortReleaseVersionBound")
	bool bInclusive;

};

UCLASS(NotBlueprintable)
class UFortAssetDataUtilityToolFilter_ReleaseVersion : public UFortAssetDataUtilityToolFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_ReleaseVersion", meta=(InlineEditConditionToggle))
	bool bCheckVersionMin;

	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_ReleaseVersion", meta=(EditCondition="bCheckVersionMin"))
	FFortReleaseVersionBound ReleaseVersionMin;

	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_ReleaseVersion", meta=(InlineEditConditionToggle))
	bool bCheckVersionMax;

	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_ReleaseVersion", meta=(EditCondition="bCheckVersionMax"))
	FFortReleaseVersionBound ReleaseVersionMax;

	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_ReleaseVersion")
	EAssetDataUtilityToolFilterResult NoVersionBehavior;

};

