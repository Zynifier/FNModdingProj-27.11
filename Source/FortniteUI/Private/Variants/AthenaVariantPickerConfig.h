// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "AthenaVariantPickerConfig.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FAthenaVariantFilterTabInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Display", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> Icon;

	UPROPERTY(EditAnywhere, Category="Display")
	FText Label;

	UPROPERTY(EditAnywhere, Category="Filter")
	FGameplayTagContainer IncludedVariantChannels;

	UPROPERTY(EditAnywhere, Category="Filter")
	TArray<FMcpVariantChannelInfo> ForcedVariantSelections;

	UPROPERTY(EditAnywhere, Category="Camera")
	float ZoomLevel;

	UPROPERTY(EditAnywhere, Category="Advanced")
	bool bDisableScrollBox;

};

USTRUCT(BlueprintType)
struct FAthenaVariantFilterTabInfo_Primary
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaVariantFilterTabInfo_Primary")
	FAthenaVariantFilterTabInfo PrimaryTab;

	UPROPERTY(EditAnywhere, Category="AthenaVariantFilterTabInfo_Primary")
	TArray<FAthenaVariantFilterTabInfo> SubTabs;

};

USTRUCT(BlueprintType)
struct FAthenaVariantFilterSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaVariantFilterSet")
	TArray<FAthenaVariantFilterTabInfo_Primary> PrimaryTabs;

};

UCLASS()
class UAthenaVariantPickerConfig : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="AthenaVariantPickerConfig")
	TMap<FGameplayTag, FAthenaVariantFilterSet> FilterSets;

};

