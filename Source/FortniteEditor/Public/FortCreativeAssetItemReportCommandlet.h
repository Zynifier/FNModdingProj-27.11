// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Commandlets/Commandlet.h"
#include "FortCreativeAssetItemReportCommandlet.generated.h"

UENUM()
enum class ECreativessetItemReportColumn : uint8
{
	DisplayName = 0,
	Rarity = 1,
	Version = 2,
	ValidThisVersion = 3,
	Category = 4,
	AssetType = 5,
	PackagePath = 6,
	Permissions = 7,
	Entitlements = 8,
	CreativeTags = 9,
	CreativeOptionSummaries = 10,
	Max = 11,
};

USTRUCT()
struct FCreativeAssetReportData
{
	GENERATED_BODY()

};

USTRUCT()
struct FItemOptionData
{
	GENERATED_BODY()

};

UCLASS()
class UFortCreativeAssetItemReportCommandlet : public UCommandlet
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FCreativeAssetReportData> CreativeAssets;

};

