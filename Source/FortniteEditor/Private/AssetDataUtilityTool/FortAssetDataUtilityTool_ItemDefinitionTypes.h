// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetDataUtilityTool/FortAssetDataUtilityTool.h"
#include "FortReleaseVersion.h"
#include "Items/FortItemTypeEnum.h"
#include "FortAssetDataUtilityTool_ItemDefinitionTypes.generated.h"

UENUM(BlueprintType)
enum class ESortOrderingType : uint8
{
	Ascending = 0,
	Descending = 1,
};

UCLASS(NotBlueprintable, meta=(DisplayName="Array Modifier Sort By AssetName"))
class UFortAssetDataUtilityToolArrayModifier_SortByAssetName : public UFortAssetDataUtilityToolArrayModifier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolArrayModifier_SortByAssetName")
	ESortOrderingType SortType;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="FortAssetDataUtilityToolArrayModifier_SortByAssetName")
	bool bUseStableSort;

};

UCLASS(NotBlueprintable)
class UFortAssetDataUtilityToolFilter_FortItemDefinition_ReleaseVersionMax : public UFortAssetDataUtilityToolFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_FortItemDefinition_ReleaseVersionMax")
	FFortReleaseVersion ReleaseVersionMax;

	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_FortItemDefinition_ReleaseVersionMax")
	bool bInclusive;

};

UCLASS(NotBlueprintable)
class UFortAssetDataUtilityToolFilter_FortItemDefinition_ReleaseVersionMin : public UFortAssetDataUtilityToolFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_FortItemDefinition_ReleaseVersionMin")
	FFortReleaseVersion ReleaseVersionMin;

	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolFilter_FortItemDefinition_ReleaseVersionMin")
	bool bInclusive;

};

UCLASS(BlueprintType, meta=(DisplayName="Gather By FortItemType"))
class UFortAssetDataUtilityToolGatherer_FortItemType : public UFortAssetDataUtilityToolGatherer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAssetDataUtilityToolGatherer_FortItemType")
	EFortItemType ItemTypeToGather;

};

UCLASS(NotBlueprintable, meta=(DisplayName="Log AssetData Contents"))
class UFortAssetDataUtilityTool_LogAssetDataResults : public UFortAssetDataUtilityToolAction
{
	GENERATED_BODY()

};

UCLASS(NotBlueprintable, meta=(DisplayName="Log Asset Name"))
class UFortAssetDataUtilityTool_LogResults : public UFortAssetDataUtilityToolAction
{
	GENERATED_BODY()

};

