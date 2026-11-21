// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PegasusTimelineEventTypes.generated.h"

UENUM()
enum class EPegasusTimelineCategories : uint8
{
	Unassigned = 0,
	Player = 1,
	Combat = 2,
	Building = 3,
	Inventory = 4,
	Social = 5,
	Resources = 6,
};

USTRUCT()
struct FPegasusAdditionalTagInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float PGS_ScalarValue;

	UPROPERTY()
	FString PGS_StringValue;

	UPROPERTY()
	FString PGS_TagKeyContext;

};

USTRUCT()
struct FPegasusTimelineEventHit
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 PGS_HitCount;

	UPROPERTY()
	float PGS_ScalarValue;

	UPROPERTY()
	float PGS_ReplayStartTimeStamp;

	UPROPERTY()
	float PGS_ReplayEndTimeStamp;

	UPROPERTY()
	TMap<FString, FPegasusAdditionalTagInfo> PGS_AdditionalTags;

	UPROPERTY()
	float PGS_ClipRelativeStartTime;

	UPROPERTY()
	float PGS_ClipRelativeEndTime;

};

USTRUCT()
struct FPegasusTimelineEvent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString PGS_TagName;

	UPROPERTY()
	bool PGS_IsScalarValueRelevant;

	UPROPERTY()
	FString PGS_ScalarValueDescription;

	UPROPERTY()
	EPegasusTimelineCategories PGS_Category;

	UPROPERTY()
	TArray<FPegasusTimelineEventHit> EventHits;

};

