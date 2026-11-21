// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Quests/FortQuestObjectiveType.h"
#include "FortQuestIndicatorData.generated.h"

class UDataTable;
class UFortQuestItemDefinition;
class UTexture2D;

USTRUCT()
struct FCaptureCameraFrontendData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="CaptureCameraFrontendData")
	int32 OrthoWidth;

	UPROPERTY(VisibleAnywhere, Category="CaptureCameraFrontendData")
	FVector2D WorldOffset;

	UPROPERTY(VisibleAnywhere, Category="CaptureCameraFrontendData")
	float Rotation;

};

USTRUCT(BlueprintType)
struct FFortChallengeMapPoiData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Config, Category="FortChallengeMapPoiData")
	FText Text;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortChallengeMapPoiData")
	FVector WorldLocation;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortChallengeMapPoiData")
	FGameplayTag LocationTag;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortChallengeMapPoiData")
	TArray<FString> CalendarEventsRequired;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortChallengeMapPoiData")
	TSoftObjectPtr<UFortQuestItemDefinition> DiscoveryQuest;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortChallengeMapPoiData")
	FName DiscoverObjectiveBackendName;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortChallengeMapPoiData")
	TArray<int32> ActiveDiscoverableBlodIds;

};

USTRUCT()
struct FFortQuestIndicatorCustomCategory
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortQuestIndicatorCustomCategory")
	FGameplayTag CategoryTag;

	UPROPERTY(EditAnywhere, Category="FortQuestIndicatorCustomCategory")
	FText DisplayName;

	UPROPERTY(EditAnywhere, Category="FortQuestIndicatorCustomCategory")
	FText AllChallengesText;

	UPROPERTY(EditAnywhere, Category="FortQuestIndicatorCustomCategory")
	int32 Priority;

};

USTRUCT()
struct FFortQuestTagToCategoryDataRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortQuestTagToCategoryDataRow")
	FText DisplayName;

	UPROPERTY(EditAnywhere, Category="FortQuestTagToCategoryDataRow")
	FText AllChallengesText;

	UPROPERTY(EditAnywhere, Category="FortQuestTagToCategoryDataRow")
	int32 Priority;

};

USTRUCT(BlueprintType)
struct FFortQuestTagToIconDataRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestTagToIconDataRow")
	TSoftObjectPtr<UTexture2D> Icon;

};

USTRUCT(BlueprintType)
struct FFortQuestTagToLocationDataRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestTagToLocationDataRow")
	FVector WorldLocation;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FName ActorName;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FName ActorPath;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	int32 NumChildTagsAvailable;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	int32 NumChildTagsFound;
#endif

};

UCLASS()
class UFortQuestIndicatorData : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuestLocation")
	TObjectPtr<UDataTable> QuestTagToLocationDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuestIcon")
	TSoftObjectPtr<UTexture2D> DefaultQuestIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuestIcon")
	TObjectPtr<UDataTable> QuestTagToIconDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuestIcon")
	TMap<EFortQuestObjectiveStatEvent, TSoftObjectPtr<UTexture2D>> QuestOjectiveTypeToIconMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuestCategory")
	TObjectPtr<UDataTable> QuestTagToCategoryDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CaptureCamera")
	FName CaptureCameraName;

	UPROPERTY(VisibleAnywhere, Category="CaptureCamera")
	FCaptureCameraFrontendData CaptureCameraData;

	UPROPERTY(VisibleAnywhere, Category="POI")
	TArray<FFortChallengeMapPoiData> ChallengeMapPoiData;

};

