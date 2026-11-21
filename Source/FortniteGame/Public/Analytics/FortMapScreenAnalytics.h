// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMapScreenAnalytics.generated.h"

UENUM()
enum class EAccessedMapScreenFrom : uint8
{
	Invalid = 0,
	Play = 1,
	Event = 2,
	InGame = 3,
	Other = 4,
};

USTRUCT()
struct FCollectionPageStats
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float TimeSpent;

	UPROPERTY()
	TSet<int32> ElementsSelected;

};

USTRUCT()
struct FFortCollectionTabAnalytics
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FString, FCollectionPageStats> CollectionPageStats;

	UPROPERTY()
	FString ActivePage;

	UPROPERTY()
	float CurrentPageActivationTimestamp;

};

USTRUCT()
struct FFortQuestsTabAnalytics
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FString, float> CategoriesSelected;

	UPROPERTY()
	FString LastCategorySelected;

	UPROPERTY()
	float LastCategorySelectedTimestamp;

	UPROPERTY()
	TSet<FString> BundlesSeen;

	UPROPERTY()
	TMap<FString, int32> QuestsSelected;

	UPROPERTY()
	TMap<FString, float> TimeViewingQuestMapContent;

	UPROPERTY()
	float QuestMapContentStartViewingTimestamp;

	UPROPERTY()
	FString LastQuestPinned;

};

USTRUCT()
struct FFortMapScreenAnalytics
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortQuestsTabAnalytics QuestsTabAnalytics;

	UPROPERTY()
	FFortCollectionTabAnalytics CollectionTabAnalytics;

	UPROPERTY()
	EAccessedMapScreenFrom AccessedMapScreenFrom;

	UPROPERTY()
	FName FirstActiveTab;

	UPROPERTY()
	FName LastActiveTab;

	UPROPERTY()
	FName ActiveTab;

	UPROPERTY()
	float CurrentTabActivationTimestamp;

	UPROPERTY()
	TMap<FName, float> TabIDToTimeViewed;

};

