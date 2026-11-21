// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "TagTableManagerHelper.h"
#include "GameplayStatMetadataTableRow.generated.h"

UENUM()
enum class EEpicLeaderboardDataType : uint8
{
	Integer = 0,
	Double = 1,
};

UENUM()
enum class EEpicLeaderboardTimeWindow : uint8
{
	Daily = 0,
	Weekly = 1,
	Monthly = 2,
	AllTime = 3,
};

UENUM()
enum class EEpicLeaderboardUpdateFunction : uint8
{
	// The lowest of the current or updated value is kept (e.g., best lap time)

	Min = 0,
	// The highest of the current or updated value is kept (e.g., most kills in a match)

	Max = 1,
	// An update is summed into the existing value (e.g., total kills)

	Sum = 2,
	// Any update wins (not sure when you'd really want to use this, maybe a timed event that you can keep trying but risk your previous score on?)

	MostRecent = 3,
};

USTRUCT(BlueprintType)
struct EPICGAMEPLAYSTATSRUNTIME_API FGameplayStatMetadataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="GameplayStatMetadataTableRow")
	FString BackendName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayStatMetadataTableRow")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayStatMetadataTableRow")
	TArray<EEpicLeaderboardTimeWindow> Windows;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayStatMetadataTableRow")
	EEpicLeaderboardUpdateFunction Metric;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayStatMetadataTableRow")
	EEpicLeaderboardDataType DataType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayStatMetadataTableRow")
	bool bPublish;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayStatMetadataTableRow")
	int32 WeeklyRefreshInterval;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayStatMetadataTableRow")
	bool bExportToBackEnd;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayStatMetadataTableRow")
	bool bShowInFrontEnd;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="GameplayStatMetadataTableRow")
	FString DeveloperComment;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Transient, Category="GameplayStatMetadataTableRow", meta=(HideFromDataTableEditorColumn))
	FGameplayTag PreviewTag;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Create New Gameplay Stat", meta=(Categories="GameplayStat", HideFromDataTableEditorColumn))
	FGameplayTagCreationWidgetHelper NewGameplayStat;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Manage Keyword DataTable", meta=(Categories="ItemKeyword", HideFromDataTableEditorColumn))
	FTagTableManagerHelper TableManagerHelper;
#endif

};

