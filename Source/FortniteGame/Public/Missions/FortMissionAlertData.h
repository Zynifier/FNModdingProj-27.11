// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortMissionAlertData.generated.h"

USTRUCT(BlueprintType)
struct FFortMissionAlertCategoryData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MissionAlertCategory", meta=(DataTableImportOptional))
	FName CategoryRowName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MissionAlertCategory")
	int32 Priority;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MissionAlertCategory")
	bool MissionAlertRepeatable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MissionAlertCategory")
	FString Timer;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="MissionAlertCategory")
	FString CategoryTags;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="MissionAlertCategory")
	FString VisualizationTags;
#endif

	UPROPERTY(EditDefaultsOnly, Category="MissionAlertCategory", meta=(DataTableImportOptional))
	FGameplayTagContainer CategoryTagsContainer;

	UPROPERTY(EditDefaultsOnly, Category="MissionAlertCategory", meta=(DataTableImportOptional))
	FGameplayTagContainer VisualizationTagsContainer;

};

USTRUCT(BlueprintType)
struct FFortMissionAlertData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MissionAlert")
	FName CategoryRowName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MissionAlert")
	FName SpreadRowName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MissionAlert")
	FString RequiredEventFlag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MissionAlertSpread")
	bool bOnlyUsedForSpreading;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MissionAlert")
	int32 MinimumTileDifficulty;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MissionAlert")
	int32 MaximumTileDifficulty;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MissionAlert")
	TArray<FString> RestrictedMissionGens;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MissionAlert")
	FString LootTierGroup;

	UPROPERTY(EditAnywhere, Category="GameDifficulty")
	FString ModifierTierGroup;

};

USTRUCT(BlueprintType)
struct FFortMissionAlertSpreadData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MissionAlertSpread")
	float ChanceToSpread;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MissionAlertSpread")
	int32 TotalChancesToSpread;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MissionAlertSpread")
	int32 MaxNumTilesToSpreadTo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MissionAlertSpread")
	int32 SpreadInterval;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MissionAlertSpread")
	FName MissionAlertRowName;

};

