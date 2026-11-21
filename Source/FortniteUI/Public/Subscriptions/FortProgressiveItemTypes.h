// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortProgressiveItemTypes.generated.h"

class UFortItemDefinition;
class UMaterialInterface;

UENUM(BlueprintType)
enum class EProgressiveSetProgress : uint8
{
	// enum order defines sorting order when comparing by set progress

	NoProgress = 0,
	PartialProgress = 1,
	Completed = 2,
	Expired = 3,
};

USTRUCT(BlueprintType)
struct FProgressiveSetInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ProgressiveSetInfo")
	FText SetName;

	UPROPERTY(BlueprintReadOnly, Category="ProgressiveSetInfo")
	TSoftObjectPtr<UMaterialInterface> TileMaterial;

	UPROPERTY(BlueprintReadOnly, Category="ProgressiveSetInfo")
	EProgressiveSetProgress SetProgress;

	UPROPERTY(BlueprintReadOnly, Category="ProgressiveSetInfo")
	int32 UnlockedStagesCount;

	UPROPERTY(BlueprintReadOnly, Category="ProgressiveSetInfo")
	int32 TotalStagesCount;

};

USTRUCT(BlueprintType)
struct FORTNITEUI_API FProgressiveStageItemInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ProgressiveStageItemInfo")
	TArray<TObjectPtr<UFortItemDefinition>> RewardTokens;

	UPROPERTY(BlueprintReadOnly, Category="ProgressiveStageItemInfo")
	FText OverrideName;

	UPROPERTY(BlueprintReadOnly, Category="ProgressiveStageItemInfo")
	TSoftObjectPtr<UMaterialInterface> TileMaterial;

	UPROPERTY(BlueprintReadOnly, Category="ProgressiveStageItemInfo")
	bool bHidden;

	UPROPERTY(BlueprintReadOnly, Category="ProgressiveStageItemInfo")
	bool bAllowPreviewStyles;

	UPROPERTY(BlueprintReadOnly, Category="ProgressiveStageItemInfo")
	bool bIsLocked;

	UPROPERTY(BlueprintReadOnly, Category="ProgressiveStageItemInfo")
	int32 AdditionalMonthsRequired;

	UPROPERTY(BlueprintReadOnly, Category="ProgressiveStageItemInfo")
	int32 StageIndex;

};

